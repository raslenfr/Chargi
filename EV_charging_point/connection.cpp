#include "connection.h"

connection::connection()
{

}

bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("madame");
db.setUserName("raslen");//inserer nom de l'utilisateur
db.setPassword("raslen");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
