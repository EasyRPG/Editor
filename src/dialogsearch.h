#ifndef DIALOGSEARCH_H
#define DIALOGSEARCH_H

#include <QDialog>
#include <memory>
#include <rpg_map.h>

namespace Ui {
class DialogSearch;
}

class DialogSearch : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSearch(QWidget *parent = 0);
    ~DialogSearch();

    void updateUI();
    void enableCache(bool enable);

private slots:
    void on_button_search_clicked();

    void on_list_result_doubleClicked(const QModelIndex &index);

private:
    std::shared_ptr<RPG::Map> loadMap(int mapID);

    Ui::DialogSearch *ui;
    std::vector<std::tuple<int, int, int, int, std::vector<int>>> objectData;
    std::vector<std::shared_ptr<RPG::Map>> map_cache;
    bool useCache;
};

#endif // DIALOGSEARCH_H
