#ifndef DIALOGDATABASE_H
#define DIALOGDATABASE_H

#include <QDialog>

namespace Ui {
class DialogDataBase;
}

class DialogDataBase : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogDataBase(QWidget *parent = 0);
    ~DialogDataBase();
    
private slots:

    void on_toolSwitchStyle_clicked(bool checked);

    void on_tabOld_Pages_currentChanged(int index);

    void on_pushOld_CharacterMax_clicked();

private:
    Ui::DialogDataBase *ui;

};

#endif // DIALOGDATABASE_H
