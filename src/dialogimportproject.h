#ifndef DIALOGIMPORTPROJECT_H
#define DIALOGIMPORTPROJECT_H

#include <QDialog>

namespace Ui {
class DialogImportProject;
}

class DialogImportProject : public QDialog
{
    Q_OBJECT

public:
    explicit DialogImportProject(QWidget *parent = nullptr);
    ~DialogImportProject();

    void setDefDir(QString n_defDir);
    QString getDefDir();
    QString getProjectFolder() const;
    QString getSourceFolder() const;
    bool getConvertXYZ() const;
private slots:
    void on_lineGameFolder_textChanged(const QString &arg1);

    void on_toolProjectPath_clicked();

    void on_toolSourcePath_clicked();

private:
    Ui::DialogImportProject *ui;

    QString m_defDir;
};

#endif // DIALOGIMPORTPROJECT_H
