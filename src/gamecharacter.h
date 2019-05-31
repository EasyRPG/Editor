/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
#include <QString>
#include <QVariant>
#include <QVector>
#include <QMap>

class GameCharacter
{
public:
	GameCharacter();

	GameCharacter(const GameCharacter& other);

	~GameCharacter();

	GameCharacter& operator=(const GameCharacter& other);

	bool operator==(const GameCharacter& other);

	bool operator!=(const GameCharacter& other);


	/*Name*/
	QString name() const;
	void name(QString n_name);

	/*Title*/
	QString title() const;
	void title(QString n_title);

	/*Minimum Level*/
	int minlvl()const;
	void minlvl(int n_lvl);

	/*Maximum Level*/
	int maxlvl()const;
	void maxlvl(int n_lvl);

	/*Do Critical*/
	bool docritical() const;
	void docritical(bool n_crit);

	/*Critical*/
	int critical() const;
	void critical(int n_critical);

	/*Dual*/
	bool dualweapons() const;
	void dualweapons(bool n_dual);

	/*Fixed Equipment*/
	bool fixedequip() const;
	void fixedequip(bool n_fixed);

	/*AI*/
	bool ai() const;
	void ai(bool n_ai);

	/*Strong Defense*/
	bool strongdefense() const;
	void strongdefense(bool n_sdef);

	/*Profession*/
	int profession() const;
	void profession(int n_profession);

	/*Faceset*/
	void faceset(QString n_facename, int n_faceindex);
	QString facename() const;
	void facename(QString n_facename);
	int faceindex() const;
	void faceindex(int n_faceindex);

	/*Charset*/
	void charaset(QString n_charaname, int n_charaindex);
	QString charaname() const;
	void charaname(QString n_charaname);
	int charaindex() const;
	void charaindex(int n_charaindex);
	bool charatranslucent() const;
	void charatranslucent(bool n_charatranslucent);


	/*Battleset*/
	int battleset() const;
	void battleset(int n_battleset);

	/*Curves*/
	QVector<int> hpcurve() const;
	QVector<int> mpcurve() const;
	QVector<int> attackcurve() const;
	QVector<int> defensecurve() const;
	QVector<int> intelligencecurve() const;
	QVector<int> agilitycurve() const;
	void hpcurve(QVector<int> n_curve);
	void mpcurve(QVector<int> n_curve);
	void attackcurve(QVector<int> n_curve);
	void defensecurve(QVector<int> n_curve);
	void intelligencecurve(QVector<int> n_curve);
	void agilitycurve(QVector<int> n_curve);

	/*Experience Curve*/
	void expcurve(int n_expinitial, int n_expincrement, int n_expcorrection);
	int expinitial () const;
	void expinitial(int n_expinitial);
	int expincrement () const;
	void expincrement (int n_expincrement);
	int expcorrection () const;
	void expcorrection (int n_expcorrection);

	/*InitialEquipment*/
	int initialweapon() const;
	int initialshield() const;
	int initialarmor() const;
	int initialhelmet() const;
	int initialother() const;
	void initialweapon(int n_initialequip);
	void initialshield(int n_initialequip);
	void initialarmor(int n_initialequip);
	void initialhelmet(int n_initialequip);
	void initialother(int n_initialequip);

	/*Battler Animation*/
	int battleranimation() const;
	void battleranimation(int n_animation);

	/*Skills*/
	QMap<int,int>* skills();
	void regskill(int skill_id, int lvl);
	void unregskill(int skill_id);
	QList<int> skilllist();

	/*Ranks*/
	QMap<int,int>* attributeranks();
	QMap<int,int>* statusranks();
	void setattrank(int n_rankid, int n_rankvalue);
	void setstsrank(int n_rankid, int n_rankvalue);
	int getattrank(int att_id) const;
	int getstsrank(int sts_id) const;

	/*Custom Properties*/
	QMap<int,QVariant>* customProperties ();
	QVariant getcustom(const int c_id) const;
	void setcustom(const int c_id, QVariant n_custom);

private:
	QString m_name;
	QString m_title;
	int m_minlvl;
	int m_maxlvl;
	bool m_docritical;
	int m_critical;
	bool m_dualweapons;
	bool m_fixedequip;
	bool m_ai;
	bool m_strongdefense;
	int m_profession;
	QString m_facename;
	int m_faceindex;
	QString m_charaname;
	int m_charaindex;
	bool m_charatranslucent;
	int m_battleset;
	QVector<int> m_hpcurve;
	QVector<int> m_mpcurve;
	QVector<int> m_attackcurve;
	QVector<int> m_defensecurve;
	QVector<int> m_intelligencecurve;
	QVector<int> m_agilitycurve;
	int m_expinitial;
	int m_expincrement;
	int m_expcorrection;
	int m_initialweapon;
	int m_initialshield;
	int m_initialarmor;
	int m_initialhelmet;
	int m_initialother;
	int m_battleranimation;
	QMap<int,int> m_skills;
	QMap<int,int> m_attranks;
	QMap<int,int> m_stsranks;
	QMap<int, QVariant> m_customProperties;
};

#endif // GAMECHARACTER_H
