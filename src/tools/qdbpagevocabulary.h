#ifndef QDBPAGEVOCABULARY_H
#define QDBPAGEVOCABULARY_H

#include <QWidget>
#include <data.h>

namespace Ui {
class QDbPageVocabulary;
}

class QDbPageVocabulary : public QWidget
{
    Q_OBJECT

    RPG::Terms *terms;
public:
    explicit QDbPageVocabulary(RPG::Database &database, QWidget *parent = nullptr);
    ~QDbPageVocabulary();
private slots:
    void on_lineEdit_34_textChanged(const QString &arg1);
    void on_lineEdit_35_textChanged(const QString &arg1);
    void on_lineEdit_36_textChanged(const QString &arg1);
    void on_lineEdit_37_textChanged(const QString &arg1);
    void on_lineEdit_38_textChanged(const QString &arg1);
    void on_lineEdit_39_textChanged(const QString &arg1);
    void on_lineEdit_40_textChanged(const QString &arg1);
    void on_lineEdit_41_textChanged(const QString &arg1);
    void on_lineEdit_42_textChanged(const QString &arg1);
    void on_lineEdit_textChanged(const QString &arg1);
    void on_lineEdit_43_textChanged(const QString &arg1);
    void on_lineEdit_44_textChanged(const QString &arg1);

    void on_lineEdit_45_textChanged(const QString &arg1);
    void on_lineEdit_46_textChanged(const QString &arg1);
    void on_lineEdit_47_textChanged(const QString &arg1);
    void on_lineEdit_48_textChanged(const QString &arg1);
    void on_lineEdit_49_textChanged(const QString &arg1);
    void on_lineEdit_50_textChanged(const QString &arg1);
    void on_lineEdit_51_textChanged(const QString &arg1);
    void on_lineEdit_52_textChanged(const QString &arg1);
    void on_lineEdit_53_textChanged(const QString &arg1);

    void on_lineEdit_54_textChanged(const QString &arg1);
    void on_lineEdit_55_textChanged(const QString &arg1);
    void on_lineEdit_56_textChanged(const QString &arg1);
    void on_lineEdit_57_textChanged(const QString &arg1);
    void on_lineEdit_58_textChanged(const QString &arg1);
    void on_lineEdit_59_textChanged(const QString &arg1);
    void on_lineEdit_60_textChanged(const QString &arg1);
    void on_lineEdit_61_textChanged(const QString &arg1);
    void on_lineEdit_62_textChanged(const QString &arg1);

    void on_lineEdit_63_textChanged(const QString &arg1);
    void on_lineEdit_64_textChanged(const QString &arg1);
    void on_lineEdit_65_textChanged(const QString &arg1);
    void on_lineEdit_66_textChanged(const QString &arg1);
    void on_lineEdit_67_textChanged(const QString &arg1);
    void on_lineEdit_68_textChanged(const QString &arg1);
    void on_lineEdit_69_textChanged(const QString &arg1);
    void on_lineEdit_70_textChanged(const QString &arg1);
    void on_lineEdit_71_textChanged(const QString &arg1);

    void on_lineEdit_72_textChanged(const QString &arg1);
    void on_lineEdit_73_textChanged(const QString &arg1);
    void on_lineEdit_74_textChanged(const QString &arg1);
    void on_lineEdit_75_textChanged(const QString &arg1);
    void on_lineEdit_76_textChanged(const QString &arg1);
    void on_lineEdit_77_textChanged(const QString &arg1);
    void on_lineEdit_78_textChanged(const QString &arg1);
    void on_lineEdit_79_textChanged(const QString &arg1);
    void on_lineEdit_80_textChanged(const QString &arg1);
    void on_lineEdit_81_textChanged(const QString &arg1);
    void on_lineEdit_84_textChanged(const QString &arg1);
    void on_lineEdit_85_textChanged(const QString &arg1);
    void on_lineEdit_86_textChanged(const QString &arg1);

    void on_lineEdit_82_textChanged(const QString &arg1);
    void on_lineEdit_83_textChanged(const QString &arg1);
    void on_lineEdit_87_textChanged(const QString &arg1);
    void on_lineEdit_88_textChanged(const QString &arg1);
    void on_lineEdit_89_textChanged(const QString &arg1);
    void on_lineEdit_90_textChanged(const QString &arg1);
    void on_lineEdit_91_textChanged(const QString &arg1);
    void on_lineEdit_92_textChanged(const QString &arg1);
    void on_lineEdit_93_textChanged(const QString &arg1);
    void on_lineEdit_94_textChanged(const QString &arg1);
    void on_lineEdit_95_textChanged(const QString &arg1);
    void on_lineEdit_96_textChanged(const QString &arg1);
    void on_lineEdit_97_textChanged(const QString &arg1);
    void on_lineEdit_98_textChanged(const QString &arg1);
    void on_lineEdit_99_textChanged(const QString &arg1);
    void on_lineEdit_100_textChanged(const QString &arg1);
    void on_lineEdit_101_textChanged(const QString &arg1);
    void on_lineEdit_102_textChanged(const QString &arg1);

    void on_lineEdit_103_textChanged(const QString &arg1);
    void on_lineEdit_104_textChanged(const QString &arg1);
    void on_lineEdit_105_textChanged(const QString &arg1);
    void on_lineEdit_106_textChanged(const QString &arg1);
    void on_lineEdit_107_textChanged(const QString &arg1);
    void on_lineEdit_108_textChanged(const QString &arg1);
    void on_lineEdit_109_textChanged(const QString &arg1);
    void on_lineEdit_110_textChanged(const QString &arg1);
    void on_lineEdit_111_textChanged(const QString &arg1);
    void on_lineEdit_112_textChanged(const QString &arg1);
    void on_lineEdit_113_textChanged(const QString &arg1);
    void on_lineEdit_114_textChanged(const QString &arg1);
    void on_lineEdit_115_textChanged(const QString &arg1);
    void on_lineEdit_116_textChanged(const QString &arg1);
    void on_lineEdit_117_textChanged(const QString &arg1);
    void on_lineEdit_118_textChanged(const QString &arg1);
    void on_lineEdit_119_textChanged(const QString &arg1);
    void on_lineEdit_120_textChanged(const QString &arg1);
    void on_lineEdit_121_textChanged(const QString &arg1);
    void on_lineEdit_122_textChanged(const QString &arg1);
    void on_lineEdit_123_textChanged(const QString &arg1);
    void on_lineEdit_125_textChanged(const QString &arg1);



private:
    Ui::QDbPageVocabulary *ui;
    RPG::Database &m_data;

};

#endif // QDBPAGEVOCABULARY_H
