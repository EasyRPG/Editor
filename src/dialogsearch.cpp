#include "dialogsearch.h"
#include "ui_dialogsearch.h"
#include "mainwindow.h"
#include "core.h"

#include <data.h>
#include <lmu_reader.h>
#include <functional>
#include <vector>
#include <tuple>
#include <QMessageBox>

DialogSearch::DialogSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSearch)
{
    ui->setupUi(this);

    ui->list_result->setColumnCount(5);
    ui->list_result->setRowCount(0);
    ui->list_result->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->list_result->setEditTriggers(QAbstractItemView::NoEditTriggers);

    enableCache(false);
}

DialogSearch::~DialogSearch()
{
    delete ui;
}

void DialogSearch::updateUI()
{
    const QString format("%1: %2");

    for (auto &v : Data::variables)
        ui->combo_variable->addItem(format.arg(QString::number(v.ID), QString::fromStdString(v.name)));
    for (auto &s : Data::switches)
        ui->combo_switch->addItem(format.arg(QString::number(s.ID), QString::fromStdString(s.name)));
    for (auto &i : Data::items)
        ui->combo_item->addItem(format.arg(QString::number(i.ID), QString::fromStdString(i.name)));
    for (auto &e : Data::commonevents)
        ui->combo_eventname->addItem(format.arg(QString::number(e.ID), QString::fromStdString(e.name)));
}

void DialogSearch::enableCache(bool enable)
{
    useCache = enable;

    if (enable)
        map_cache = std::vector<std::shared_ptr<RPG::Map>>(Data::treemap.maps.size());
    else
        map_cache.clear();

}

void DialogSearch::on_button_search_clicked()
{
    objectData.clear();
    ui->list_result->clear();
    ui->list_result->setRowCount(0);
    QStringList sl;
    sl << "Map" << "Event" << "Event Page" << "Sourceline" << "Action";
    ui->list_result->setHorizontalHeaderLabels(sl);



    std::function<std::vector<std::tuple<int, int, int, int, std::vector<int>>>(const RPG::Map &)> func;


    if (ui->radio_variable->isChecked())
    {
        //TODO implement me
    }
    else if (ui->radio_switch->isChecked())
    {
        //TODO implement me
    }
    else if (ui->radio_item->isChecked())
    {
        auto itemfunc = [](const int itemID, const RPG::Map& map){
            std::vector<std::tuple<int, int, int, int, std::vector<int>>> res;
            for (auto &e : map.events)
                for (auto &p : e.pages)
                    for (size_t line = 0; line < p.event_commands.size(); line++)
                    {
                        auto ev = p.event_commands[line];
                        if (ev.code == RPG::EventCommand::Code::ChangeItems)
                        {
                            if (ev.parameters[2] == itemID)
                                res.push_back({map.ID, e.ID, p.ID, line, ev.parameters});
                        }
                    }
            return res;
        };


        QRegularExpression re("^(\\d+):?.*$");
        auto itemID = re.match(ui->combo_item->currentText()).captured(1).toInt();
        func = std::bind(itemfunc, itemID, std::placeholders::_1);
    }
    else //if (ui->radio_eventname->isChecked())
    {
        //TODO implement me
    }

    if (!func)
    {
        QMessageBox::warning(this, "", "This search parameter isn't supported yet.");
        return;
    }

    if (ui->scope_current->isChecked())
    {
        const auto mapID = static_cast<MainWindow*>(parent())->currentScene()->id();
        auto map = loadMap(mapID);

        map->ID = mapID; // FIX: currently XML serialization is broken
        auto res = func(*map);
        for (auto &r : res)
        {
            int mapID, eventID, eventPage,  sourceLine;
            std::vector<int> parameters;
            std::tie(mapID, eventID, eventPage, sourceLine, parameters) = r;

        }
    }
    else if (ui->scope_events->isChecked())
    {
        //TODO implement me
    }
    else // if (ui->scope_project->isChecked())
    {
        for (auto &map : Data::treemap.maps)
        {
            ui->label_status->setText(QString("Parsing Map %1 / %2").arg(QString::number(map.ID + 1), QString::number(Data::treemap.maps.size())));
            QApplication::processEvents(); //FIXME: can this be done better?!

            auto mapp = loadMap(map.ID);

            if (!mapp) continue;

            mapp->ID = map.ID; // FIX: currently XML serialization is broken
            auto res = func(*mapp);
            for (auto &r : res)
            {
                int mapID, eventID, eventPage,  sourceLine;
                std::vector<int> parameters;
                std::tie(mapID, eventID, eventPage, sourceLine, parameters) = r;

                std::vector<std::string> maps;
                auto mm = mapID;
                do
                {
                    auto mapinfo = Data::treemap.maps[mm];
                    maps.push_back(mapinfo.name);
                    mm = mapinfo.parent_map;
                } while (mm != 0);

                const auto descr = QString("%1 %2")
                        .arg(parameters[0] == 1 ? "Remove" : "Add",
                             QString(parameters[3] == 0 ? "%1" : "V[%1]").arg(QString::number(parameters[4])));

                QStringList maps_rev;
                std::for_each(maps.crbegin(), maps.crend(), [&maps_rev](const std::string &m) { maps_rev << QString::fromStdString(m); });

                const int rows = ui->list_result->rowCount();
                ui->list_result->setRowCount(rows+1);
                ui->list_result->setItem(rows, 0, new QTableWidgetItem(maps_rev.join(" > ")));
                ui->list_result->setItem(rows, 1, new QTableWidgetItem(QString::number(eventID)));
                ui->list_result->setItem(rows, 2, new QTableWidgetItem(QString::number(eventPage)));
                ui->list_result->setItem(rows, 3, new QTableWidgetItem(QString::number(sourceLine)));
                ui->list_result->setItem(rows, 4, new QTableWidgetItem(descr));

                objectData.push_back(r);
            }

        }
    }
    ui->list_result->resizeColumnsToContents();
}

void DialogSearch::on_list_result_doubleClicked(const QModelIndex &index)
{
    auto *par = static_cast<MainWindow*>(parent());
    par->openScene(std::get<0>(objectData[index.row()]));
    auto *event = (*par->currentScene()->mapEvents())[std::get<1>(objectData[index.row()])];
    par->selectTile(event->x, event->y);
    par->currentScene()->centerOnTile(event->x, event->y);
}

std::shared_ptr<RPG::Map> DialogSearch::loadMap(int mapID)
{
    if (!(useCache && map_cache[mapID]))
    {
        const QString file = QString("Map%1.emu").arg(QString::number(mapID), 4, QLatin1Char('0'));
        const std::shared_ptr<RPG::Map> res_map{LMU_Reader::LoadXml(mCore->filePath(ROOT, file).toStdString())};

        if (useCache)
            map_cache[mapID] = res_map;

        return res_map;
    }

    return map_cache[mapID];
}

