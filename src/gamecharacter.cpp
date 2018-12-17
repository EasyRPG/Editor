#include "gamecharacter.h"



GameCharacter::GameCharacter() :
	m_name(""),
	m_title(""),
	m_minlvl(1),
	m_maxlvl(99),
	m_docritical(true),
	m_critical(30),
	m_dualweapons(false),
	m_fixedequip(false),
	m_ai(false),
	m_strongdefense(false),
	m_profession(-1),
	m_facename("<none>"),
	m_faceindex(0),
	m_charaname("<none>"),
	m_charaindex(0),
	m_charatranslucent(false),
	m_battleset(-1),
	m_expinitial(300),
	m_expincrement(300),
	m_expcorrection(0),
	m_initialweapon(-1),
	m_initialshield(-1),
	m_initialarmor(-1),
	m_initialhelmet(-1),
	m_initialother(-1),
	m_battleranimation(-1)
  {
	  for (int i = 0; i < 100; i++) {
		  m_hpcurve.append(1);
		  m_mpcurve.append(0);
		  m_attackcurve.append(1);
		  m_defensecurve.append(1);
		  m_intelligencecurve.append(1);
		  m_agilitycurve.append(1);
	  }
}

GameCharacter::GameCharacter(const GameCharacter &other) :
	m_name(other.m_name),
	m_title(other.m_title),
	m_minlvl(other.m_minlvl),
	m_maxlvl(other.m_maxlvl),
	m_docritical(other.m_docritical),
	m_critical(other.m_critical),
	m_dualweapons(other.m_dualweapons),
	m_fixedequip(other.m_fixedequip),
	m_ai(other.m_ai),
	m_strongdefense(other.m_strongdefense),
	m_profession(other.m_profession),
	m_facename(other.m_facename),
	m_faceindex(other.m_faceindex),
	m_charaname(other.m_charaname),
	m_charaindex(other.m_charaindex),
	m_charatranslucent(other.m_charatranslucent),
	m_battleset(other.m_battleset),
	m_expinitial(other.m_expinitial),
	m_expincrement(other.m_expincrement),
	m_expcorrection(other.m_expcorrection),
	m_initialweapon(other.m_initialweapon),
	m_initialshield(other.m_initialshield),
	m_initialarmor(other.m_initialarmor),
	m_initialhelmet(other.m_initialhelmet),
	m_initialother(other.m_initialother),
	m_battleranimation(other.m_battleranimation)
  {
	  for (int i = 0; i < 100; i++) {
		  m_hpcurve.append(other.m_hpcurve[i]);
		  m_mpcurve.append(other.m_mpcurve[i]);
		  m_attackcurve.append(other.m_attackcurve[i]);
		  m_defensecurve.append(other.m_defensecurve[i]);
		  m_intelligencecurve.append(other.m_intelligencecurve[i]);
		  m_agilitycurve.append(other.m_agilitycurve[i]);
	  }
}

GameCharacter::~GameCharacter()
{

}

GameCharacter &GameCharacter::operator=(const GameCharacter &other)
{
	if (this != &other){
		this->~GameCharacter();
		new (this) GameCharacter(other);
	}
	return *this;
}

bool GameCharacter::operator==(const GameCharacter &other)
{
#define check(var) var == other.var
	return (check(m_name) &&
			check(m_title) &&
			check(m_minlvl) &&
			check(m_maxlvl) &&
			check(m_docritical) &&
			check(m_critical) &&
			check(m_dualweapons) &&
			check(m_fixedequip) &&
			check(m_ai) &&
			check(m_strongdefense) &&
			check(m_profession) &&
			check(m_battleset) &&
			check(m_initialweapon) &&
			check(m_initialshield) &&
			check(m_initialarmor) &&
			check(m_initialhelmet) &&
			check(m_initialother) &&
			check(m_battleranimation) &&
			check(m_faceindex) &&
			check(m_facename) &&
			check(m_charaindex) &&
			check(m_charaname) &&
			check(m_charatranslucent) &&
			check(m_expinitial) &&
			check(m_expincrement) &&
			check(m_expcorrection) &&
			check(m_hpcurve) &&
			check(m_mpcurve) &&
			check(m_attackcurve) &&
			check(m_defensecurve) &&
			check(m_intelligencecurve) &&
			check(m_agilitycurve));
#undef check
}

bool GameCharacter::operator!=(const GameCharacter &other)
{
	return !(this->operator ==(other));
}

void GameCharacter::name(QString n_name) {m_name = n_name;}

void GameCharacter::title(QString n_title) {m_title = n_title;}

void GameCharacter::minlvl(int n_lvl) {m_minlvl = n_lvl;}

void GameCharacter::maxlvl(int n_lvl) {m_maxlvl = n_lvl;}

void GameCharacter::docritical(bool n_crit) {m_docritical = n_crit;}

void GameCharacter::critical(int n_critical) {m_critical = n_critical;}

void GameCharacter::dualweapons(bool n_dual) {m_dualweapons = n_dual;}

void GameCharacter::fixedequip(bool n_fixed) {m_fixedequip = n_fixed;}

void GameCharacter::ai(bool n_ai) {m_ai = n_ai;}

void GameCharacter::strongdefense(bool n_sdef) {m_strongdefense = n_sdef;}

void GameCharacter::profession(int n_profession) {m_profession = n_profession;}

void GameCharacter::faceset(QString n_facename, int n_faceindex) {m_facename = n_facename;
																  m_faceindex = n_faceindex;}

void GameCharacter::facename(QString n_facename) {m_facename = n_facename;}

void GameCharacter::faceindex(int n_faceindex) {m_faceindex = n_faceindex;}

void GameCharacter::charaset(QString n_charaname, int n_charaindex) {m_charaname = n_charaname;
																	 m_charaindex = n_charaindex;}

void GameCharacter::charaname(QString n_charaname) {m_charaname = n_charaname;}

void GameCharacter::charaindex(int n_charaindex) {m_charaindex = n_charaindex;}

void GameCharacter::charatranslucent(bool n_charatranslucent) {m_charatranslucent = n_charatranslucent;}

void GameCharacter::battleset(int n_battleset) {m_battleset = n_battleset;}

void GameCharacter::hpcurve(QVector<int> n_curve) {m_hpcurve = n_curve;}

void GameCharacter::mpcurve(QVector<int> n_curve) {m_mpcurve = n_curve;}

void GameCharacter::attackcurve(QVector<int> n_curve) {m_attackcurve = n_curve;}

void GameCharacter::defensecurve(QVector<int> n_curve) {m_defensecurve = n_curve;}

void GameCharacter::intelligencecurve(QVector<int> n_curve) {m_intelligencecurve = n_curve;}

void GameCharacter::agilitycurve(QVector<int> n_curve) {m_agilitycurve = n_curve;}

void GameCharacter::expcurve(int n_expinitial, int n_expincrement, int n_expcorrection) {m_expinitial = n_expinitial;
																						 m_expincrement = n_expincrement;
																																											  m_expcorrection = n_expcorrection;}

void GameCharacter::expinitial(int n_expinitial) {m_expinitial = n_expinitial;}

void GameCharacter::expincrement(int n_expincrement) {m_expincrement = n_expincrement;}

void GameCharacter::expcorrection(int n_expcorrection) {m_expcorrection = n_expcorrection;}

void GameCharacter::initialweapon(int n_initialequip) {m_initialweapon = n_initialequip;}

void GameCharacter::initialshield(int n_initialequip) {m_initialshield = n_initialequip;}

void GameCharacter::initialarmor(int n_initialequip) {m_initialarmor = n_initialequip;}

void GameCharacter::initialhelmet(int n_initialequip) {m_initialhelmet = n_initialequip;}

void GameCharacter::initialother(int n_initialequip) {m_initialother = n_initialequip;}

int GameCharacter::battleranimation() const {return m_battleranimation;}

void GameCharacter::battleranimation(int n_animation) {m_battleranimation = n_animation;}

QMap<int, int> *GameCharacter::skills() {return &m_skills;}

void GameCharacter::regskill(int skill_id, int lvl) {m_skills.insert(skill_id, lvl);}

void GameCharacter::unregskill(int skill_id) {m_skills.remove(skill_id);}

QList<int> GameCharacter::skilllist() {return m_skills.keys();}

QMap<int, int> *GameCharacter::attributeranks() {return &m_attranks;}

QMap<int, int> *GameCharacter::statusranks() {return &m_stsranks;}

void GameCharacter::setattrank(int n_rankid, int n_rankvalue) {m_attranks.insert(n_rankid, n_rankvalue);}

void GameCharacter::setstsrank(int n_rankid, int n_rankvalue) {m_stsranks.insert(n_rankid, n_rankvalue);}

int GameCharacter::getattrank(int att_id) const {if (att_id >= 0 && att_id < m_attranks.keys().count()) return m_attranks[att_id]; else return 0;}

int GameCharacter::getstsrank(int sts_id) const {if (sts_id >= 0 && sts_id < m_stsranks.keys().count()) return m_stsranks[sts_id]; else return 0;}

QMap<int, QVariant> *GameCharacter::customProperties() {return &m_customProperties;}

QVariant GameCharacter::getcustom(const int c_id) const {return m_customProperties[c_id];}

void GameCharacter::setcustom(const int c_id, QVariant n_custom) {m_customProperties[c_id] = n_custom;}

int GameCharacter::initialother() const {return m_initialother;}

int GameCharacter::initialhelmet() const {return m_initialhelmet;}

int GameCharacter::initialarmor() const {return m_initialarmor;}

int GameCharacter::initialshield() const {return m_initialshield;}

int GameCharacter::initialweapon() const {return m_initialweapon;}

int GameCharacter::expcorrection() const {return m_expcorrection;}

int GameCharacter::expincrement() const {return m_expincrement;}

int GameCharacter::expinitial() const {return m_expinitial;}

QVector<int> GameCharacter::agilitycurve() const {return m_agilitycurve;}

QVector<int> GameCharacter::intelligencecurve() const {return m_intelligencecurve;}

QVector<int> GameCharacter::defensecurve() const {return m_defensecurve;}

QVector<int> GameCharacter::attackcurve() const {return m_attackcurve;}

QVector<int> GameCharacter::mpcurve() const {return m_mpcurve;}

QVector<int> GameCharacter::hpcurve() const {return m_hpcurve;}

int GameCharacter::battleset() const {return m_battleset;}

bool GameCharacter::charatranslucent() const {return m_charatranslucent;}

int GameCharacter::charaindex() const {return m_charaindex;}

QString GameCharacter::charaname() const {return m_charaname;}

int GameCharacter::faceindex() const {return m_faceindex;}

QString GameCharacter::facename() const {return m_facename;}

int GameCharacter::profession() const {return m_profession;}

bool GameCharacter::strongdefense() const {return m_strongdefense;}

bool GameCharacter::ai() const {return m_ai;}

bool GameCharacter::fixedequip() const {return m_fixedequip;}

bool GameCharacter::dualweapons() const {return m_dualweapons;}

int GameCharacter::critical() const {return m_critical;}

bool GameCharacter::docritical() const {return m_docritical;}

int GameCharacter::maxlvl() const {return m_maxlvl;}

int GameCharacter::minlvl() const {return m_minlvl;}

QString GameCharacter::title() const {return m_title;}

QString GameCharacter::name() const {return m_name;}
