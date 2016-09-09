#ifndef DIALOGSEARCH_H
#define DIALOGSEARCH_H

#include <QDialog>

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

private slots:
    void on_button_search_clicked();

    void on_list_result_doubleClicked(const QModelIndex &index);

private:
    Ui::DialogSearch *ui;
    std::vector<std::tuple<int, int, int, int, std::vector<int>>> objectData;
};

#endif // DIALOGSEARCH_H
