#ifndef DIALOGRESOURCEMANAGER_H
#define DIALOGRESOURCEMANAGER_H

#include <QDialog>

namespace Ui {
class DialogResourceManager;
}

class DialogResourceManager : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogResourceManager(QWidget *parent = 0);
    ~DialogResourceManager();
    
private:
    Ui::DialogResourceManager *ui;
};

#endif // DIALOGRESOURCEMANAGER_H
