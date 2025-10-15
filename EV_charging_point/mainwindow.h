#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include "session.h"
#include "arduino.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_3_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_mode_charge_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_stat_clicked();

    void on_pushButton_effacer_tout_clicked();

    void on_pushButton_chercher_clicked();

private:
    Ui::MainWindow *ui;
     session Etmp;
         arduino a;
         QByteArray data;
};
#endif // MAINWINDOW_H

