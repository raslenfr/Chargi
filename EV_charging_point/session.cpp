#include "session.h"
#include <QtWidgets>
#include <QSqlQuery>
#include <QtSql>
#include <QString>
#include <QSqlQueryModel>



session::session()
{
ID_SESION="";
MODEE="";
NIV_BATTERIE="";
VITESSE="";
HAPPY_HOUR="";
PRIX="";
}

session::session (QString ID_SESSION ,QString MODEE ,QString NIV_BATTERIE ,QString VITESSE,QString HAPPY_HOUR ,QString PRIX )
{
    this->ID_SESION=ID_SESSION;
    this->MODEE=MODEE;
    this->NIV_BATTERIE=NIV_BATTERIE;
    this->VITESSE=VITESSE;
    this->HAPPY_HOUR=HAPPY_HOUR;
    this->PRIX=PRIX;
}






void session::setID_SESION(QString n){this->ID_SESION=n;}
void session::setMODEE(QString n){this->MODEE=n;}
void session::setNIV_BATTERIE(QString n){this->NIV_BATTERIE=n;}
void session::setVITESSE(QString n){this->VITESSE=n;}
void session::setHAPPY_HOUR(QString n){this->HAPPY_HOUR=n;}
void session::setPRIX(QString n){this->PRIX=n;}


QString session::get_ID_SESION(){return ID_SESION;}
QString session::get_MODEE(){return MODEE;}
QString session::get_NIV_BATTERIE(){return NIV_BATTERIE;}
QString session::get_VITESSE(){return VITESSE;}
QString session::get_HAPPY_HOUR(){return HAPPY_HOUR;}
QString session::get_PRIX(){return PRIX;}



bool session::idExists(int id2)
{
    QSqlQuery query;
    query.prepare("SELECT ID_SESION FROM VOITURE WHERE ID_SESION=:ID_SESION");
    query.bindValue(":ID_SESION", id2);
    if (query.exec()) {
        if (query.next()) {
            return true;
        }
    }
    // ID does not exist in the database
    return false;
}


bool session::insert()
{
    QSqlQuery query;

    query.prepare("INSERT INTO SESION (ID_SESION, MODEE, NIV_BATTERIE,VITESSE, HAPPY_HOUR, PRIX) "
      "VALUES (:ID_SESION, :MODEE, :NIV_BATTERIE, :VITESSE, :HAPPY_HOUR, :PRIX)");
    query.bindValue(":ID_SESION", ID_SESION);
    query.bindValue(":MODEE", MODEE);
    query.bindValue(":NIV_BATTERIE", NIV_BATTERIE);
    query.bindValue(":VITESSE",VITESSE);
    query.bindValue(":HAPPY_HOUR",  HAPPY_HOUR);
    query.bindValue(":PRIX", PRIX);
    qDebug() <<"test1"<<NIV_BATTERIE;
    if (query.exec()) {
        qDebug() << "New session inserted successfully";
    } else {
        qDebug() << "Failed to insert new session";
        qDebug() << "Error:" << query.lastError().text();
    }
}




bool session::delete_session(int id1) {
    QSqlQuery query;
    QString res = QString::number(id1);
    query.prepare("Delete from SESION where ID_SESION= :id1");
    query.bindValue(":id1", res);
    return query.exec();
}


QSqlQueryModel * session::afficher_session(){
QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("select *from SESION");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_SESION"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("MODEE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("NIV_BATTERIE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("VITESSE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("HAPPY_HOUR"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));

return model;


}




bool session::update(QString id){
    QSqlQuery query;
        query.prepare("UPDATE SESION SET MODEE=:MODEE, NIV_BATTERIE=:NIV_BATTERIE, VITESSE=:VITESSE, HAPPY_HOUR=:HAPPY_HOUR, PRIX=:PRIX WHERE ID_SESION=:id");
        query.bindValue(":id", ID_SESION);
        query.bindValue(":MODEE", MODEE);
        query.bindValue(":NIV_BATTERIE", NIV_BATTERIE);
        query.bindValue(":VITESSE", VITESSE);
        query.bindValue(":HAPPY_HOUR", HAPPY_HOUR);
        query.bindValue(":PRIX", PRIX);
    if (query.exec()) {
        qDebug() << "session updated successfully";
        return true;
    } else {
        qDebug() << "Failed to update session";
        qDebug() << "Error:" << query.lastError().text();
        return false;
    }
}

bool session::delete_all(){

    QSqlQuery query;
        query.prepare("Delete from SESION");
        return query.exec();
}
QSqlQueryModel * session::afficher_search(QString ch)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from SESION WHERE ID_SESION LIKE '%"+ch+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_SESSION"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MODEE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NIV_BATTERIE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("VITESSE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("HAPPY_HOUR"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
    return model;
}
