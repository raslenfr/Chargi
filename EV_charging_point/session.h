#ifndef VOITURE_H
#define VOITURE_H
#include <QString>
#include <QDialog>
#include <QSqlQueryModel>
class session
{
public:
    void setID_SESION(QString n);
    void setMODEE(QString n);
    void setNIV_BATTERIE(QString n);
    void setVITESSE(QString n);
    void setHAPPY_HOUR(QString n);
    void setPRIX(QString n);
    QString get_ID_SESION();
    QString get_MODEE();
    QString get_NIV_BATTERIE();
    QString get_VITESSE();
    QString get_HAPPY_HOUR();
    QString get_PRIX();
    session();
    session(QString,QString,QString,QString,QString,QString);
    void setsession(session s);
    bool insert();
    bool delete_session(int id1);
    QSqlQueryModel* afficher_session();
    bool update(QString);
    bool idExists(int id);
    QSqlQueryModel* afficher_search(QString);
 bool delete_all();
private:

    QString ID_SESION,MODEE,NIV_BATTERIE,VITESSE,HAPPY_HOUR,PRIX ;


};




#endif


