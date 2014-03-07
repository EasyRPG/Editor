#ifndef QEVENTWIDGET_H
#define QEVENTWIDGET_H

#include <QWidget>
#include <rpg_eventpage.h>

namespace Ui {
class QEventWidget;
}

class QEventWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QEventWidget(QWidget *parent = 0);
    ~QEventWidget();

    RPG::EventPage *eventPage() const;
    void setEventPage(RPG::EventPage *eventPage);

private slots:
    void on_comboMoveType_currentIndexChanged(int index);

    void on_checkSwitchA_toggled(bool checked);

    void on_checkSwitchB_toggled(bool checked);

    void on_checkVar_toggled(bool checked);

    void on_checkItem_toggled(bool checked);

    void on_comboVarOperation_currentIndexChanged(int index);

    void on_spinVarValue_valueChanged(int arg1);

    void on_comboItem_currentIndexChanged(int index);

    void on_comboHero_currentIndexChanged(int index);

    void on_checkHero_toggled(bool checked);

    void on_checkTimerA_toggled(bool checked);

    void on_spinTimerAMin_valueChanged(int arg1);

    void on_spinTimerASec_valueChanged(int arg1);

    void on_checkTimerB_toggled(bool checked);

    void on_spinTimerBMin_valueChanged(int arg1);

    void on_spinTimerBSec_valueChanged(int arg1);

    void on_checkTransparent_toggled(bool checked);

    void on_comboMoveSpeed_currentIndexChanged(int index);

    void on_comboCondition_currentIndexChanged(int index);

    void on_comboLayer_currentIndexChanged(int index);

    void on_checkOverlap_toggled(bool checked);

    void on_comboAnimationType_currentIndexChanged(int index);

    void on_comboMoveFrequency_currentIndexChanged(int index);

    void on_pushSetSprite_clicked();

private:
    Ui::QEventWidget *ui;
    RPG::EventPage *m_eventPage;
};

#endif // QEVENTWIDGET_H
