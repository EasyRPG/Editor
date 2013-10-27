#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
#include <QString>
#include <QVariant>
#include <QVector>
#include <QMap>

struct Skillbook{
    int lvl;
    int skill_id;
};

struct ExpCurve{
    int initial;
    int increment;
    int correction;
};

class GameCharacter
{
public:
    inline GameCharacter() :
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
      m_battleset(-1),
      m_initialweapon(-1),
      m_initialshield(-1),
      m_initialarmor(-1),
      m_initialhelmet(-1),
      m_initialother(-1),
      m_unarmedanimation(-1),
      m_faceindex(0),
      m_facename("<none>"),
      m_charaindex(0),
      m_charaname("<none>"),
      m_charatranslucent(false),
      m_expinitial(300),
      m_expincrement(300),
      m_expcorrection(0)
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
    inline ~GameCharacter() {}

    /*Name*/
    inline QString name() const {return m_name;}
    inline void name(QString n_name) {m_name = n_name;}

    /*Title*/
    inline QString title() const {return m_title;}
    inline void title(QString n_title) {m_title = n_title;}

    /*Minimum Level*/
    inline int minlvl()const {return m_minlvl;}
    inline void minlvl(int n_lvl) {m_minlvl = n_lvl;}

    /*Maximum Level*/
    inline int maxlvl()const {return m_maxlvl;}
    inline void maxlvl(int n_lvl) {m_maxlvl = n_lvl;}

    /*Do Critical*/
    inline bool docritical() const {return m_docritical;}
    inline void docritical(bool n_crit) {m_docritical = n_crit;}

    /*Critical*/
    inline int critical() const {return m_critical;}
    inline void critical(int n_critical) {m_critical = n_critical;}

    /*Dual*/
    inline bool dualweapons() const {return m_dualweapons;}
    inline void dualweapons(bool n_dual) {m_dualweapons = n_dual;}

    /*Fixed Equipment*/
    inline bool fixedequip() const {return m_fixedequip;}
    inline void fixedequip(bool n_fixed) {m_fixedequip = n_fixed;}

    /*AI*/
    inline bool ai() const {return m_ai;}
    inline void ai(bool n_ai) {m_ai = n_ai;}

    /*Strong Defense*/
    inline bool strongdefense() const {return m_strongdefense;}
    inline void strongdefense(bool n_sdef) {m_strongdefense = n_sdef;}

    /*Profession*/
    inline int profession() const {return m_profession;}
    inline void profession(int n_profession) {m_profession = n_profession;}

    /*Faceset*/
    inline void faceset(QString n_facename, int n_faceindex) {m_facename = n_facename;
                                                              m_faceindex = n_faceindex;}
    inline QString facename() const {return m_facename;}
    inline void facename(QString n_facename) {m_facename = n_facename;}
    inline int faceindex() const {return m_faceindex;}
    inline void faceindex(int n_faceindex) {m_faceindex = n_faceindex;}

    /*Charset*/
    inline void charaset(QString n_charaname, int n_charaindex) {m_charaname = n_charaname;
                                                                 m_charaindex = n_charaindex;}
    inline QString charaname() const {return m_charaname;}
    inline void charaname(QString n_charaname) {m_charaname = n_charaname;}
    inline int charaindex() const {return m_charaindex;}
    inline void charaindex(int n_charaindex) {m_charaindex = n_charaindex;}
    inline bool charatranslucent() const {return m_charatranslucent;}
    inline void charatranslucent(bool n_charatranslucent) {m_charatranslucent = n_charatranslucent;}


    /*Battleset*/
    inline int battleset() const {return m_battleset;}
    inline void battleset(int n_battleset) {m_battleset = n_battleset;}

    /*Curves*/
    inline QVector<int> hpcurve() const {return m_hpcurve;}
    inline QVector<int> mpcurve() const {return m_mpcurve;}
    inline QVector<int> attackcurve() const {return m_attackcurve;}
    inline QVector<int> defensecurve() const {return m_defensecurve;}
    inline QVector<int> intelligencecurve() const {return m_intelligencecurve;}
    inline QVector<int> agilitycurve() const {return m_agilitycurve;}
    inline void hpcurve(QVector<int> n_curve) {m_hpcurve = n_curve;}
    inline void mpcurve(QVector<int> n_curve) {m_mpcurve = n_curve;}
    inline void attackcurve(QVector<int> n_curve) {m_attackcurve = n_curve;}
    inline void defensecurve(QVector<int> n_curve) {m_defensecurve = n_curve;}
    inline void intelligencecurve(QVector<int> n_curve) {m_intelligencecurve = n_curve;}
    inline void agilitycurve(QVector<int> n_curve) {m_agilitycurve = n_curve;}

    /*Experience Curve*/
    inline void expcurve(int n_expinitial, int n_expincrement, int n_expcorrection) {m_expinitial = n_expinitial;
                                                                                     m_expincrement = n_expincrement;
                                                                                     m_expcorrection = n_expcorrection;}
    inline int expinitial () const {return m_expinitial;}
    inline void expinitia(int n_expinitial) {m_expinitial = n_expinitial;}
    inline int expincrement () const {return m_expincrement;}
    inline void expincrement (int n_expincrement) {m_expincrement = n_expincrement;}
    inline int expcorrection () const {return m_expcorrection;}
    inline void expcorrection (int n_expcorrection) {m_expcorrection = n_expcorrection;}

    /*InitialEquipment*/
    inline int initialweapon() const {return m_initialweapon;}
    inline int initialshield() const {return m_initialshield;}
    inline int initialarmor() const {return m_initialarmor;}
    inline int initialhelmet() const {return m_initialhelmet;}
    inline int initialother() const {return m_initialother;}
    inline void initialweapon(int n_initialequip) {m_initialweapon = n_initialequip;}
    inline void initialshield(int n_initialequip) {m_initialshield = n_initialequip;}
    inline void initialarmor(int n_initialequip) {m_initialarmor = n_initialequip;}
    inline void initialhelmet(int n_initialequip) {m_initialhelmet = n_initialequip;}
    inline void initialother(int n_initialequip) {m_initialother = n_initialequip;}

    /*Unarmed Animation*/
    inline int unarmedanimation() const {return m_unarmedanimation;}
    inline void unarmedanimation(int n_animation) {m_unarmedanimation = n_animation;}

    /*Skills*/
    inline QMap<int,int>* skills() {return &m_skills;}
    inline void regskill(int skill_id, int lvl) {m_skills.insert(skill_id, lvl);}
    inline void unregskill(int skill_id) {m_skills.remove(skill_id);}
    inline QList<int> skilllist() {return m_skills.keys();}

    /*Ranks*/
    inline QMap<int,int>* attributeranks() {return &m_attranks;}
    inline QMap<int,int>* statusranks() {return &m_stsranks;}
    inline void setattrank(int n_rankid, int n_rankvalue) {m_attranks.insert(n_rankid, n_rankvalue);}
    inline void setstsrank(int n_rankid, int n_rankvalue) {m_stsranks.insert(n_rankid, n_rankvalue);}
    inline int getattrank(int att_id) const {if (att_id >= 0 && att_id < m_attranks.keys().count()) return m_attranks[att_id]; else return 0;}
    inline int getstsrank(int sts_id) const {if (sts_id >= 0 && sts_id < m_stsranks.keys().count()) return m_stsranks[sts_id]; else return 0;}

    /*Custom Properties*/
    inline QMap<int,QVariant>* customProperties () {return &m_customProperties;}
    inline QVariant getcustom(const int c_id) const {return m_customProperties[c_id];}
    inline void setcustom(const int c_id, QVariant n_custom) {m_customProperties[c_id] = n_custom;}

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
    int m_unarmedanimation;
    QMap<int,int> m_skills;
    QMap<int,int> m_attranks;
    QMap<int,int> m_stsranks;
    QMap<int, QVariant> m_customProperties;
};

#endif // GAMECHARACTER_H
