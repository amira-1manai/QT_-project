#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int id=ui->id->text().toInt();
    QString titre=ui->titre->text();
       QString lieu=ui->lieu->text();
       QDate date=ui->date->date();
          QString description=ui->description->toPlainText();
             QString type=ui->type->currentText();
                QString responsable=ui->responsable->text();
Activite a(id, date, titre, lieu, type, description, responsable);
bool test=a.ajouter();
if (test)
    {
ui->tableView->setModel(act.afficher());
        QMessageBox :: information (nullptr, QObject ::tr("OK"),
                     QObject ::tr("Ajout effectué\n"
                                  "click cancel to exit"),
                QMessageBox:: Cancel);

}
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                             QObject::tr("try again.\n"
                                         "click cancel to exit."),QMessageBox::Cancel);
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    bool i;
                int id_del;
                id_del=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
                i=act.supprimer(id_del);
             if(i)
                        {
                            QMessageBox::information(nullptr, QObject::tr("database is open"),
                                        QObject::tr("delete successful.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
                            ui->tableView->setModel(act.afficher());

                        }
                        else
                           { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                        QObject::tr("delete failed.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel); }

}
