#ifndef DIALOGSEARCH_H
#define DIALOGSEARCH_H

#include <QDialog>
#include <memory>
#include <rpg_map.h>
#include <vector>

namespace Ui {
	class DialogSearch;
}

namespace RPG {
	class EventCommand;
}

class DialogSearch : public QDialog
{
	Q_OBJECT

public:
	explicit DialogSearch(QWidget *parent = nullptr);
	~DialogSearch();

	void updateUI();
	void enableCache(bool enable);

private slots:
	void on_button_search_clicked();

	void on_list_result_doubleClicked(const QModelIndex &index);

private:
	std::shared_ptr<RPG::Map> loadMap(int mapID);

	Ui::DialogSearch *ui;
	using command_info = std::tuple<int, int, int, int, const RPG::EventCommand&>; // map id, event id, page index, line, event command
	std::vector<command_info> objectData;
	std::vector<std::shared_ptr<RPG::Map>> map_cache;
	bool useCache;
	void showResults(const std::vector<command_info>& results);
};

#endif // DIALOGSEARCH_H
