#include "qdbpagevocabulary.h"
#include "ui_qdbpagevocabulary.h"

QDbPageVocabulary::QDbPageVocabulary(RPG::Database &database, QWidget *parent) :
    QWidget(parent),
    m_data(database),
    ui(new Ui::QDbPageVocabulary)
{
    ui->setupUi(this);
    terms=&m_data.terms;

    ui->lineEdit_34->setText(terms->encounter.c_str());
    ui->lineEdit_35->setText(terms->special_combat.c_str());
    ui->lineEdit_36->setText(terms->miss.c_str());
    ui->lineEdit_37->setText(terms->escape_failure.c_str());
    ui->lineEdit_38->setText(terms->victory.c_str());
    ui->lineEdit_39->setText(terms->defeat.c_str());
    ui->lineEdit_40->setText(terms->exp_received.c_str());
    ui->lineEdit_41->setText(terms->gold_recieved_a.c_str());
    ui->lineEdit_42->setText(terms->gold_recieved_b.c_str());
    ui->lineEdit->setText(terms->item_recieved.c_str());
    ui->lineEdit_43->setText(terms->level_up.c_str());
    ui->lineEdit_44->setText(terms->skill_learned.c_str());

    ui->lineEdit_45->setText(terms->shop_greeting1.c_str());
    ui->lineEdit_46->setText(terms->shop_regreeting1.c_str());
    ui->lineEdit_47->setText(terms->shop_buy1.c_str());
    ui->lineEdit_48->setText(terms->shop_buy_select1.c_str());
    ui->lineEdit_49->setText(terms->shop_buy_number1.c_str());
    ui->lineEdit_50->setText(terms->shop_purchased1.c_str());
    ui->lineEdit_51->setText(terms->shop_sell_select1.c_str());
    ui->lineEdit_52->setText(terms->shop_sell_select1.c_str());
    ui->lineEdit_53->setText(terms->shop_sold1.c_str());

    ui->lineEdit_54->setText(terms->shop_greeting2.c_str());
    ui->lineEdit_55->setText(terms->shop_regreeting2.c_str());
    ui->lineEdit_56->setText(terms->shop_buy2.c_str());
    ui->lineEdit_57->setText(terms->shop_buy_select2.c_str());
    ui->lineEdit_58->setText(terms->shop_buy_number2.c_str());
    ui->lineEdit_59->setText(terms->shop_purchased2.c_str());
    ui->lineEdit_60->setText(terms->shop_sell_select2.c_str());
    ui->lineEdit_61->setText(terms->shop_sell_select2.c_str());
    ui->lineEdit_62->setText(terms->shop_sold2.c_str());

    ui->lineEdit_63->setText(terms->shop_greeting3.c_str());
    ui->lineEdit_64->setText(terms->shop_regreeting3.c_str());
    ui->lineEdit_65->setText(terms->shop_buy3.c_str());
    ui->lineEdit_66->setText(terms->shop_buy_select3.c_str());
    ui->lineEdit_67->setText(terms->shop_buy_number3.c_str());
    ui->lineEdit_68->setText(terms->shop_purchased3.c_str());
    ui->lineEdit_69->setText(terms->shop_sell_select3.c_str());
    ui->lineEdit_70->setText(terms->shop_sell_select3.c_str());
    ui->lineEdit_71->setText(terms->shop_sold3.c_str());

    ui->lineEdit_72->setText(terms->inn_a_greeting_1.c_str());
    ui->lineEdit_76->setText(terms->inn_a_greeting_2.c_str());
    ui->lineEdit_73->setText(terms->inn_a_greeting_3.c_str());
    ui->lineEdit_74->setText(terms->inn_a_accept.c_str());
    ui->lineEdit_75->setText(terms->inn_a_cancel.c_str());
    ui->lineEdit_77->setText(terms->inn_b_greeting_1.c_str());
    ui->lineEdit_78->setText(terms->inn_b_greeting_2.c_str());
    ui->lineEdit_79->setText(terms->inn_b_greeting_3.c_str());
    ui->lineEdit_80->setText(terms->inn_b_accept.c_str());
    ui->lineEdit_81->setText(terms->inn_b_cancel.c_str());
    ui->lineEdit_84->setText(terms->possessed_items.c_str());
    ui->lineEdit_85->setText(terms->equipped_items.c_str());
    ui->lineEdit_86->setText(terms->gold.c_str());

    ui->lineEdit_90->setText(terms->level.c_str());
    ui->lineEdit_97->setText(terms->lvl_short.c_str());
    ui->lineEdit_82->setText(terms->health_points.c_str());
    ui->lineEdit_96->setText(terms->hp_short.c_str());
    ui->lineEdit_93->setText(terms->spirit_points.c_str());
    ui->lineEdit_100->setText(terms->sp_short.c_str());
    ui->lineEdit_92->setText(terms->normal_status.c_str());
    ui->lineEdit_99->setText(terms->exp_short.c_str());
    ui->lineEdit_91->setText(terms->sp_cost.c_str());
    ui->lineEdit_95->setText(terms->weapon.c_str());
    ui->lineEdit_89->setText(terms->attack.c_str());
    ui->lineEdit_101->setText(terms->shield.c_str());
    ui->lineEdit_88->setText(terms->defense.c_str());
    ui->lineEdit_102->setText(terms->armor.c_str());
    ui->lineEdit_87->setText(terms->spirit.c_str());
    ui->lineEdit_98->setText(terms->helmet.c_str());
    ui->lineEdit_83->setText(terms->agility.c_str());
    ui->lineEdit_94->setText(terms->accessory.c_str());

    ui->lineEdit_103->setText(terms->battle_fight.c_str());
    ui->lineEdit_107->setText(terms->command_skill.c_str());
    ui->lineEdit_114->setText(terms->status.c_str());
    ui->lineEdit_115->setText(terms->new_game.c_str());
    ui->lineEdit_104->setText(terms->battle_auto.c_str());
    ui->lineEdit_109->setText(terms->menu_equipment.c_str());
    ui->lineEdit_111->setText(terms->row.c_str());
    ui->lineEdit_116->setText(terms->load_game.c_str());
    ui->lineEdit_105->setText(terms->battle_escape.c_str());
    ui->lineEdit_110->setText(terms->menu_save.c_str());
    ui->lineEdit_113->setText(terms->order.c_str());
    ui->lineEdit_117->setText(terms->menu_quit.c_str());
    ui->lineEdit_106->setText(terms->command_item.c_str());
    ui->lineEdit_108->setText(terms->menu_quit.c_str());
    ui->lineEdit_112->setText(terms->wait_on.c_str());
    ui->lineEdit_118->setText(terms->wait_off.c_str());
    ui->lineEdit_119->setText(terms->save_game_message.c_str());
    ui->lineEdit_121->setText(terms->load_game_message.c_str());
    ui->lineEdit_122->setText(terms->exit_game_message.c_str());
    ui->lineEdit_120->setText(terms->file.c_str());
    ui->lineEdit_123->setText(terms->yes.c_str());
    ui->lineEdit_125->setText(terms->no.c_str());

}

QDbPageVocabulary::~QDbPageVocabulary()
{
    delete ui;
}

void QDbPageVocabulary::on_lineEdit_textChanged(const QString &arg1)
{
    if ( terms->item_recieved == arg1.toStdString())
        return;
    terms->item_recieved = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_34_textChanged(const QString &arg1)
{
    if ( terms->encounter == arg1.toStdString())
        return;
    terms->encounter = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_35_textChanged(const QString &arg1)
{
    if ( terms->special_combat == arg1.toStdString())
        return;
    terms->special_combat = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_36_textChanged(const QString &arg1)
{
    if ( terms->miss == arg1.toStdString())
        return;
    terms->miss = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_37_textChanged(const QString &arg1)
{
    if ( terms->escape_failure == arg1.toStdString())
        return;
    terms->escape_failure = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_38_textChanged(const QString &arg1)
{
    if ( terms->victory == arg1.toStdString())
        return;
    terms->victory = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_39_textChanged(const QString &arg1)
{
    if ( terms->defeat == arg1.toStdString())
        return;
    terms->defeat = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_40_textChanged(const QString &arg1)
{
    if ( terms->exp_received == arg1.toStdString())
        return;
    terms->exp_received = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_41_textChanged(const QString &arg1)
{
    if ( terms->gold_recieved_a == arg1.toStdString())
        return;
    terms->gold_recieved_a = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_42_textChanged(const QString &arg1)
{
    if ( terms->gold_recieved_b == arg1.toStdString())
        return;
    terms->gold_recieved_b = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_43_textChanged(const QString &arg1)
{
    if ( terms->level_up == arg1.toStdString())
        return;
    terms->level_up = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_44_textChanged(const QString &arg1)
{
    if ( terms->skill_learned == arg1.toStdString())
        return;
    terms->skill_learned = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_45_textChanged(const QString &arg1)
{
    if ( terms->shop_greeting1 == arg1.toStdString())
        return;
    terms->shop_greeting1 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_46_textChanged(const QString &arg1)
{
    if ( terms->shop_regreeting1 == arg1.toStdString())
        return;
    terms->shop_regreeting1 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_47_textChanged(const QString &arg1)
{
    if ( terms->shop_buy1== arg1.toStdString())
        return;
    terms->shop_buy1 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_48_textChanged(const QString &arg1)
{
    if ( terms->shop_buy_select1== arg1.toStdString())
        return;
    terms->shop_buy_select1 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_49_textChanged(const QString &arg1)
{
    if ( terms->shop_buy_number1== arg1.toStdString())
        return;
   terms->shop_buy_number1 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_50_textChanged(const QString &arg1)
{
    if (terms->shop_purchased1== arg1.toStdString())
        return;
    terms->shop_purchased1 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_51_textChanged(const QString &arg1)
{
    if (terms->shop_sell_select1== arg1.toStdString())
        return;
    terms->shop_sell_select1 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_52_textChanged(const QString &arg1)
{
    if (terms->shop_sell_select1== arg1.toStdString())
        return;
   terms->shop_sell_select1 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_53_textChanged(const QString &arg1)
{
    if (terms->shop_sold1== arg1.toStdString())
        return;
   terms->shop_sold1 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_54_textChanged(const QString &arg1)
{
    if (terms->shop_greeting2== arg1.toStdString())
        return;
   terms->shop_greeting2= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_55_textChanged(const QString &arg1)
{
    if (terms->shop_regreeting2== arg1.toStdString())
        return;
   terms->shop_regreeting2 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_56_textChanged(const QString &arg1)
{
    if (terms->shop_buy2== arg1.toStdString())
        return;
   terms->shop_buy2 = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_57_textChanged(const QString &arg1)
{
    if (terms->shop_buy_select2== arg1.toStdString())
        return;
   terms->shop_buy_select2 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_58_textChanged(const QString &arg1)
{
    if (terms->shop_buy_number2== arg1.toStdString())
        return;
  terms->shop_buy_number2= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_59_textChanged(const QString &arg1)
{
    if (terms->shop_purchased2== arg1.toStdString())
        return;
   terms->shop_purchased2 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_60_textChanged(const QString &arg1)
{
    if (terms->shop_sell_select2== arg1.toStdString())
        return;
   terms->shop_sell_select2 = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_61_textChanged(const QString &arg1)
{
    if (terms->shop_sell_select2== arg1.toStdString())
        return;
   terms->shop_sell_select2 = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_62_textChanged(const QString &arg1)
{
    if (terms->shop_sold2== arg1.toStdString())
        return;
  terms->shop_sold2 = arg1.toStdString();
}


void QDbPageVocabulary::on_lineEdit_63_textChanged(const QString &arg1)
{
    if (terms->shop_greeting3== arg1.toStdString())
        return;
   terms->shop_greeting3= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_64_textChanged(const QString &arg1)
{
    if (terms->shop_regreeting3== arg1.toStdString())
        return;
   terms->shop_regreeting3 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_65_textChanged(const QString &arg1)
{
    if (terms->shop_buy3== arg1.toStdString())
        return;
   terms->shop_buy3 = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_66_textChanged(const QString &arg1)
{
    if (terms->shop_buy_select3== arg1.toStdString())
        return;
   terms->shop_buy_select3 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_67_textChanged(const QString &arg1)
{
    if (terms->shop_buy_number3== arg1.toStdString())
        return;
  terms->shop_buy_number3= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_68_textChanged(const QString &arg1)
{
    if (terms->shop_purchased3== arg1.toStdString())
        return;
   terms->shop_purchased3 = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_69_textChanged(const QString &arg1)
{
    if (terms->shop_sell_select3== arg1.toStdString())
        return;
   terms->shop_sell_select3 = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_70_textChanged(const QString &arg1)
{
    if (terms->shop_sell_select3== arg1.toStdString())
        return;
   terms->shop_sell_select3 = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_71_textChanged(const QString &arg1)
{
    if (terms->shop_sold3== arg1.toStdString())
        return;
  terms->shop_sold3 = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_72_textChanged(const QString &arg1)
{
    if (terms->inn_a_greeting_1== arg1.toStdString())
        return;
  terms->inn_a_greeting_1 = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_76_textChanged(const QString &arg1)
{
    if (terms->inn_a_greeting_2== arg1.toStdString())
        return;
  terms->inn_a_greeting_2 = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_73_textChanged(const QString &arg1)
{
    if (terms->inn_a_greeting_3== arg1.toStdString())
        return;
  terms->inn_a_greeting_3 = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_74_textChanged(const QString &arg1)
{
    if (terms->inn_a_accept== arg1.toStdString())
        return;
  terms->inn_a_accept = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_75_textChanged(const QString &arg1)
{
    if (terms->inn_a_cancel== arg1.toStdString())
        return;
  terms->inn_a_cancel = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_77_textChanged(const QString &arg1)
{
    if (terms->inn_b_greeting_1== arg1.toStdString())
        return;
  terms->inn_b_greeting_1 = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_78_textChanged(const QString &arg1)
{
    if (terms->inn_b_greeting_2== arg1.toStdString())
        return;
  terms->inn_b_greeting_2 = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_79_textChanged(const QString &arg1)
{
    if (terms->inn_b_greeting_3== arg1.toStdString())
        return;
  terms->inn_b_greeting_3 = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_80_textChanged(const QString &arg1)
{
    if (terms->inn_b_accept== arg1.toStdString())
        return;
  terms->inn_b_accept = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_81_textChanged(const QString &arg1)
{
    if (terms->inn_b_cancel== arg1.toStdString())
        return;
  terms->inn_b_cancel = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_84_textChanged(const QString &arg1)
{
    if (terms->possessed_items== arg1.toStdString())
        return;
  terms->possessed_items = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_85_textChanged(const QString &arg1)
{
    if (terms->equipped_items== arg1.toStdString())
        return;
  terms->equipped_items = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_86_textChanged(const QString &arg1)
{
    if (terms->gold== arg1.toStdString())
        return;
  terms->gold = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_90_textChanged(const QString &arg1)
{
    if (terms->level== arg1.toStdString())
        return;
  terms->level = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_97_textChanged(const QString &arg1)
{
    if (terms->lvl_short== arg1.toStdString())
        return;
  terms->lvl_short = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_82_textChanged(const QString &arg1)
{
    if (terms->health_points== arg1.toStdString())
        return;
  terms->health_points = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_96_textChanged(const QString &arg1)
{
    if (terms->hp_short== arg1.toStdString())
        return;
  terms->hp_short = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_93_textChanged(const QString &arg1)
{
    if (terms->spirit_points== arg1.toStdString())
        return;
  terms->spirit_points = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_100_textChanged(const QString &arg1)
{
    if (terms->sp_short== arg1.toStdString())
        return;
  terms->sp_short = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_92_textChanged(const QString &arg1)
{
    if (terms->normal_status== arg1.toStdString())
        return;
  terms->normal_status = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_99_textChanged(const QString &arg1)
{
    if (terms->exp_short== arg1.toStdString())
        return;
  terms->exp_short = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_91_textChanged(const QString &arg1)
{
    if (terms->sp_cost== arg1.toStdString())
        return;
  terms->sp_cost = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_95_textChanged(const QString &arg1)
{
    if (terms->weapon== arg1.toStdString())
        return;
  terms->weapon = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_89_textChanged(const QString &arg1)
{
    if (terms->attack== arg1.toStdString())
        return;
  terms->attack = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_101_textChanged(const QString &arg1)
{
    if (terms->shield== arg1.toStdString())
        return;
  terms->shield = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_88_textChanged(const QString &arg1)
{
    if (terms->defense== arg1.toStdString())
        return;
  terms->defense = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_102_textChanged(const QString &arg1)
{
    if (terms->armor== arg1.toStdString())
        return;
  terms->armor = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_87_textChanged(const QString &arg1)
{
    if (terms->spirit== arg1.toStdString())
        return;
  terms->spirit = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_98_textChanged(const QString &arg1)
{
    if (terms->helmet== arg1.toStdString())
        return;
  terms->helmet = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_83_textChanged(const QString &arg1)
{
    if (terms->agility== arg1.toStdString())
        return;
  terms->agility = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_94_textChanged(const QString &arg1)
{
    if (terms->accessory== arg1.toStdString())
        return;
  terms->accessory = arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_103_textChanged(const QString &arg1)
{
    if (terms->battle_fight== arg1.toStdString())
        return;
  terms->battle_fight = arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_107_textChanged(const QString &arg1)
{
    if (terms->command_skill== arg1.toStdString())
        return;
  terms->command_skill= arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_114_textChanged(const QString &arg1)
{
    if (terms->status== arg1.toStdString())
        return;
  terms->status= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_115_textChanged(const QString &arg1)
{
    if (terms->new_game== arg1.toStdString())
        return;
  terms->new_game= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_104_textChanged(const QString &arg1)
{
    if (terms->battle_auto== arg1.toStdString())
        return;
  terms->battle_auto= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_109_textChanged(const QString &arg1)
{
    if (terms->menu_equipment== arg1.toStdString())
        return;
  terms->menu_equipment= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_111_textChanged(const QString &arg1)
{
    if (terms->row== arg1.toStdString())
        return;
  terms->row= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_116_textChanged(const QString &arg1)
{
    if (terms->load_game== arg1.toStdString())
        return;
 terms->load_game= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_105_textChanged(const QString &arg1)
{
    if (terms->battle_escape==arg1.toStdString())
        return;
 terms->battle_escape= arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_110_textChanged(const QString &arg1)
{
    if (terms->menu_save==arg1.toStdString())
        return;
 terms->menu_save= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_113_textChanged(const QString &arg1)
{
    if (terms->order==arg1.toStdString())
        return;
 terms->order= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_117_textChanged(const QString &arg1)
{
    if (terms->menu_quit==arg1.toStdString())
        return;
 terms->menu_quit= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_106_textChanged(const QString &arg1)
{
    if (terms->command_item==arg1.toStdString())
        return;
 terms->command_item= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_108_textChanged(const QString &arg1)
{
    if (terms->menu_quit==arg1.toStdString())
        return;
 terms->menu_quit= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_112_textChanged(const QString &arg1)
{
    if (terms->wait_on==arg1.toStdString())
        return;
 terms->wait_on= arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_118_textChanged(const QString &arg1)
{
    if (terms->wait_off==arg1.toStdString())
        return;
terms->wait_off= arg1.toStdString();
}

void QDbPageVocabulary::on_lineEdit_119_textChanged(const QString &arg1)
{
    if (terms->save_game_message==arg1.toStdString())
        return;
terms->save_game_message= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_121_textChanged(const QString &arg1)
{
    if (terms->load_game_message==arg1.toStdString())
        return;
terms->load_game_message= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_122_textChanged(const QString &arg1)
{
    if (terms->exit_game_message==arg1.toStdString())
        return;
terms->exit_game_message= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_120_textChanged(const QString &arg1)
{
    if (terms->file==arg1.toStdString())
        return;
terms->file= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_123_textChanged(const QString &arg1)
{
    if (terms->yes==arg1.toStdString())
        return;
terms->yes= arg1.toStdString();
}
void QDbPageVocabulary::on_lineEdit_125_textChanged(const QString &arg1)
{
    if (terms->no==arg1.toStdString())
        return;
terms->no= arg1.toStdString();
}

