#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "session.h"
#include "arduino.h"
#include <QtWidgets>
#include <QTabWidget>
#include <QString>
#include <QSqlQuery>
#include <QRegExpValidator>
#include <QSortFilterProxyModel>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QtCharts/QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGraphicsScene>
#include <QtCharts/QChart>



namespace Ui {
class session;
}


MainWindow::MainWindow(QWidget *parent)

    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
QPixmap pix ("C:/Users/MSI/OneDrive/Desktop/test raslen/interface.png");
   ui->label_11->setPixmap(pix);
   ui->label_12->setPixmap(pix);
int ret=a.connect_arduino(); // lancer la connexion à arduino
          switch(ret){
          case(0):qDebug()<< "arduino is available and connected to : "<< a.getarduino_port_name();
              break;
          case(1):qDebug() << "arduino is available but not connected to :" <<a.getarduino_port_name();
             break;
          case(-1):qDebug() << "arduino is not available";
          }

    ui->tableView->setModel(Etmp.afficher_session());
    // Find the QTableWidget using its object name
       QTableWidget *tableWidget = findChild<QTableWidget*>("tableWidget");

       // Use the QTableWidget object as needed
       int row = tableWidget->rowCount();


       //control de saisir
       ui->ID_SESSION->setValidator(new QIntValidator(1, 99999999, this));
       //ui->MODEE->setValidator(new QIntValidator(0, 1, this));
       ui->NIV_BATTERIE->setValidator(new QIntValidator(0, 100, this));
       ui->VITESSE->setValidator(new QIntValidator(0, 10, this));
       ui->PRIX->setValidator(new QIntValidator(1, 99999999, this));


}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{


    //fuction true meloul taa tous les fonctions
    bool isValid = true;


    // Get the input values
   QString ID_SESSION = ui->ID_SESSION->text();
   QString MODEE = ui->MODEE->currentText();
   QString NIV_BATTERIE = ui->NIV_BATTERIE->text();
   QString VITESSE = ui->VITESSE->text();
   QString HAPPY_HOUR = ui->HAPPY_HOUR->currentText();
   QString PRIX = ui->PRIX->text();

//consructeur voiture parametré
session s(ID_SESSION,MODEE,NIV_BATTERIE,VITESSE,HAPPY_HOUR,PRIX );


    //get the id2 for the checkid fucntion
    int id2 = ui->ID_SESSION->text().toInt();


//check for the id_voiture if exist and number or not
    if (s.idExists(id2)) {
        QMessageBox::warning(this, "ID EXISTE", "ID already exists, please enter another ID.");
        isValid = false;
    }


   //check if empty or not

   if ((ID_SESSION.isEmpty()) || (MODEE.isEmpty()) || (NIV_BATTERIE.isEmpty()) ||  (VITESSE.isEmpty()) ||  (HAPPY_HOUR.isEmpty()) ||  (PRIX.isEmpty()))
   {
       QMessageBox::warning(this, "Invalid Inputs", "Vous devez saisir tous les champs pour ajouter ");
       isValid = false;

   }

        //*****************

    if (isValid) {
        s.setID_SESION(ui->ID_SESSION->text());
        s.setMODEE(ui->MODEE->currentText());
        s.setNIV_BATTERIE(ui->NIV_BATTERIE->text());
        s.setVITESSE(ui->VITESSE->text());
        s.setHAPPY_HOUR(ui->HAPPY_HOUR->currentText());
        s.setPRIX(ui->PRIX->text());


        if (s.insert()) {
            //refresh to afficher
            ui->tableView->setModel(Etmp.afficher_session());
            qDebug() << "session inserted successfully";
            QMessageBox::information(nullptr, QObject::tr("OK"),
                          QObject::tr("Ajout effectué\n"
                                      "Click Cancel to exit ."), QMessageBox::Cancel);

            // Add a new row to the QTableWidget and set the item for each column
            QTableWidget *tableWidget = findChild<QTableWidget*>("tableWidget");
            int row = tableWidget->rowCount();
            tableWidget->insertRow(row);
            tableWidget->setItem(row, 0, new QTableWidgetItem(s.get_MODEE()));
            tableWidget->setItem(row, 1,new QTableWidgetItem(s.get_NIV_BATTERIE()));
            tableWidget->setItem(row, 2, new QTableWidgetItem(s.get_VITESSE()));
            tableWidget->setItem(row, 3, new QTableWidgetItem(s.get_HAPPY_HOUR()));
            tableWidget->setItem(row, 4, new QTableWidgetItem(s.get_PRIX()));
        } else {
            qDebug() << "Failed to insert session into database";
        }
    }

}
void MainWindow::on_pushButton_3_clicked(){

    int id1 =ui->lineEdit->text().toUInt();

    //QString license = ui->lineEdit->text();
     session s; // declare and initialize Etmp

     bool test=Etmp.delete_session(id1);

     if (test) {
         ui->tableView->setModel(Etmp.afficher_session());

         QMessageBox::information(nullptr, QObject::tr("OK"),
                           QObject::tr("Suppression effectue.\n"
                                       "Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                           QObject::tr("Suppression NON effectue.\n"
                                       "Cancel to exit."), QMessageBox::Cancel);
}









void MainWindow::on_pushButton_4_clicked()
{
    QString ID_SESSION = ui->ID_SESSION->text();
    QString MODEE = ui->MODEE->currentText();
    QString NIV_BATTERIE = ui->NIV_BATTERIE->text();
    QString VITESSE = ui->VITESSE->text();
    QString HAPPY_HOUR = ui->HAPPY_HOUR->currentText();
    QString PRIX = ui->PRIX->text();


    session s(ID_SESSION,MODEE,NIV_BATTERIE,VITESSE,HAPPY_HOUR,PRIX);

    //get the id2 for the checkid fucntion
    int id2 = ui->ID_SESSION->text().toInt();
    s.update(s.get_ID_SESION());
    ui->tableView->setModel(Etmp.afficher_session());
   /* if (s.idExists(id2)) {

     if (s.update(s.get_ID_SESSION())) {
          // Refresh the table view to show the updated data
          ui->tableView->setModel(Etmp.afficher_session());
          QMessageBox::information(this, "Update session", "session updated successfully.");
      } else {
          QMessageBox::warning(this, "Update session", "Failed to update session.");
      }}else {

        QMessageBox::warning(this, "ID EXISTE", "ID already exists, please enter another ID.");

    }*/
  }





void MainWindow::on_pushButton_7_clicked()
{
    // Prepare SQL query
        QSqlQuery query;
        query.prepare("SELECT * FROM SESION");

        // Execute query
        if (!query.exec()) {
            qDebug() << "Failed to execute query!";
            return;
        }

        // Create PDF document
        QPdfWriter writer("C:/PDF/output.pdf");
        writer.setPageSize(QPageSize(QPageSize::A4));
        writer.setPageMargins(QMarginsF(20, 20, 20, 20));

        // Create PDF painter
        QPainter painter(&writer);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
        painter.setFont(QFont("Arial", 5));



        // Define table cell dimensions
        int cellWidth = 150;
        int cellHeight = 40;

        // Set table position
        int tableX = 20;
        int tableY = 20;

        // Draw table header
        painter.drawText(tableX + cellWidth , tableY, "ID_SESSION");
        painter.drawText(tableX + cellWidth * 6, tableY , "MODEE");
        painter.drawText(tableX + cellWidth * 11, tableY , "NIV_BATTERIE");
        painter.drawText(tableX + cellWidth * 18, tableY, "VITESSE");
        painter.drawText(tableX + cellWidth * 24, tableY, "HAPPY_HOUR");
        painter.drawText(tableX + cellWidth * 30, tableY, "PRIX");


        tableY += cellHeight;

        // Loop through query results and draw table cells
        int row = 5;
        while (query.next()) {
            // Draw ID_VOITURE value
            painter.drawText(tableX + cellWidth , tableY + row * cellHeight, query.value(0).toString());
            // Draw ID_CLIENT value
            painter.drawText(tableX + cellWidth * 6, tableY + row * cellHeight, query.value(1).toString());
            // Draw ID_MAINTENANCE value
            painter.drawText(tableX + cellWidth * 11, tableY + row * cellHeight, query.value(2).toString());
            // Draw MATRICULE value
            painter.drawText(tableX + cellWidth * 18, tableY + row * cellHeight, query.value(3).toString());
            // Draw BATTERIE_LVL value
            painter.drawText(tableX + cellWidth * 24, tableY + row * cellHeight, query.value(4).toString());
            // Draw BATTERIE_CAP value
            painter.drawText(tableX + cellWidth * 30, tableY + row * cellHeight, query.value(5).toString());


            row++;
            row++;
            row++;
            row++;
        }

        // Clean up
        painter.end();

        qDebug() << "PDF generated!";
    }

void MainWindow::on_pushButton_6_clicked()
{
    // khdhit el table View mel ui
          QAbstractItemModel *model = ui->tableView->model();

          // Create a QSortFilterProxyModel  lel tri
          QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
          proxyModel->setSourceModel(model);

          // Sort by id
          proxyModel->setSortRole(Qt::EditRole);
          proxyModel->sort(0, Qt::AscendingOrder);

          //update lel table view
          ui->tableView->setModel(proxyModel);
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{

    QSqlQueryModel *model = new QSqlQueryModel(this);
       model->setQuery(QString("SELECT * FROM SESION WHERE MODEL LIKE '%%1%'").arg(arg1));
       model->setHeaderData(0, Qt::Horizontal, "ID_SESION");
       model->setHeaderData(1, Qt::Horizontal, "MODEE");
       model->setHeaderData(2, Qt::Horizontal, "NIV_BATTERIE");
       model->setHeaderData(3, Qt::Horizontal, "VITESSE");
       model->setHeaderData(4, Qt::Horizontal, "BATTERIE_LVL");
       model->setHeaderData(5, Qt::Horizontal, "HAPPY_HOUR");
       model->setHeaderData(6, Qt::Horizontal, "PRIX");
       ui->tableView_2->setModel(model);
       ui->tableView_2->show();
}




void MainWindow::on_mode_charge_clicked()
{

    int quantity;
    int niv;
    int niv_batt;

        int v=ui->lineEdit_3->text().toInt();
        int id_s=ui->lineEdit_4->text().toInt();
        QSqlQuery query;
        query.prepare("SELECT QUNATITE FROM VOITURE WHERE ID_VOITURE=:idVoi");
        query.bindValue(":idVoi",v );
        if (query.exec() && query.next()) {
             quantity = query.value(0).toInt(); // Get the quantity from Voiture table
            qDebug() << "Quantity: " << quantity;
        } else {
            qDebug() << "Failed to get quantity from Voiture table!";
        }


        query.prepare("SELECT NIV_BATTERIE FROM SESION WHERE ID_SESION=:id");
        query.bindValue(":id",id_s );
        if (query.exec() && query.next()) {
             niv = query.value(0).toInt(); // Get the NIV_BATTERIE from SESION table
            qDebug() << "NIVEAU: " << niv;
        } else {
            qDebug() << "Failed to get NIV_BATTERIE from SESION table!";
        }



        double niv_quantity = quantity*100/1000;
        int new_niv = static_cast<int>(niv - niv_quantity);

if(query.exec() && query.next()){

        if (new_niv <= 20) {
            QSqlQuery query3;

            query3.prepare("UPDATE SESION SET MODEE = 'repos' WHERE ID_SESION = :id");
            query3.bindValue(":id", id_s);
            if (query3.exec()) {
                QMessageBox::warning(this, "REPOS MODE", "la session est en mode repos");
            } else {
                qDebug() << "Failed to update MODEE column in SESSION tableeeeeeeeeeeeeeeeeeeee!";
            }
 }
else {



QSqlQuery query2;
query2.prepare("UPDATE SESION SET NIV_BATTERIE=:new_niv WHERE ID_SESION=:id");
query2.bindValue(":id", id_s);
query2.bindValue(":new_niv", new_niv);
if (query2.exec()) {
    qDebug() << "Updated NIV_BATTERIE in SESION table";
    QMessageBox::warning(this, "Charging", "Mise a jour de la session complete");
}
else {
    qDebug() << "Failed to update NIV_BATTERIE in SESION table!";
    return;
}

        }}




}

void MainWindow::on_pushButton_5_clicked()
{

    int PRICE;
    int id=ui->lineEdit_5->text().toInt();

                                   QSqlQuery query1;
                                   query1.prepare("SELECT PRIX FROM SESION JOIN VOITURE ON VOITURE.ID_SESION=SESION.ID_SESION WHERE VOITURE.ID_VOITURE = :id_voiture");
                                   query1.bindValue(":id_voiture", id);

                                    query1.exec();
                                   if (query1.next()) {
                                  PRICE=query1.value("PRIX").toInt();
                                 qDebug() << "TEST PRIX!" <<PRICE ;
                                    }
                                    if (!query1.exec()) {
                                        qDebug() << "Failed to execute query1!";
                                        return;
                                    }


                                    QByteArray priceData = QByteArray::number(PRICE);
                                 // create an instance of the arduino object
                                   a.write_to_arduino(priceData);
}
void MainWindow::on_pushButton_stat_clicked()
{
    session s  ;
        QSqlQuery q1,q2,q3;
               qreal tot=0,c1=0,c2=0;
               q1.prepare("SELECT ID_SESION FROM SESION");
               q1.exec();
               q2.prepare("SELECT ID_SESION FROM SESION WHERE MODEE='repos'");
               q2.exec();
               q3.prepare("SELECT ID_SESION FROM SESION WHERE MODEE='actif'");
               q3.exec();
               while (q1.next()){tot++;}
               while (q2.next()){c1++;}
               while (q3.next()){c2++;}
               c1=(c1 * 100)/tot;
               c2=(c2 * 100)/tot;
               QString c3= QString::number(c1) ;
               c3="="+c3+"%";
            QString c4= QString::number(c2) ;
            c4="="+c4+"%";
             QString etat1="L" ;
             etat1=etat1+c3 ;
             QString etat2="P" ;
             etat2=etat2+c4 ;
               //Création des pie series
               QPieSeries *series = new QPieSeries();
               series->append(etat1,c1);
               series->append(etat2,c2);
               //Creation d'un charte
               QChart *chart  =new QChart();
               chart->setTitle("Les résultats:");
               chart->addSeries(series);
               chart->legend()->show();
                chart->setBackgroundBrush(QColor(252, 236, 218, 0));
               QChartView *chartView;
               chartView = new QChartView(chart,ui->graphicsView_statistic);
               chartView->setRenderHint(QPainter::Antialiasing);
               chartView->setMinimumSize(280,200);
               chartView->show();
}

void MainWindow::on_pushButton_effacer_tout_clicked()
{
    session s;
        s.delete_all();
        ui->tableView->setModel(s.afficher_session());
}




void MainWindow::on_pushButton_chercher_clicked()
{
    session s;
        ui->tableView_2->setModel(s.afficher_search(ui->lineEdit_2->text()));
}
