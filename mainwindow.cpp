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

void MainWindow::on_pushButton_4_clicked()
{
    int id=ui->lineid->text().toInt();
    QString nom=ui->linenom->text();
       QString prenom=ui->lineprenom->text();
       QDate date=ui->date_n->date();
          QString classe=ui->lineclasse->text();
             QString adresse=ui->adresse->toPlainText();
                QString email=ui->lineemail->text();
                int age=ui->lineage->text().toInt();
                QString sexe=ui->combosexe->currentText();
                QString niveau=ui->comboniveau->currentText();
Eleve e(id,nom,prenom,niveau,classe,date,sexe,adresse,email ,age);
bool test=e.ajouter();
if (test)
    {
ui->tableView_2->setModel(ect.afficher());
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

void MainWindow::on_pushButton_3_clicked()
{
    QString tst;
                  if (ui->radioButton->isChecked()) tst="ASC";
                  else if (ui->radioButton_2->isChecked()) tst="DESC";

                  switch (ui->comboBox->currentIndex()) {
                  case 0:
                      ui->tableView->setModel(act.TriParDate(tst));
                      break;
                  case 1:
                      ui->tableView->setModel(act.TriParTitre(tst));
                      break;
                  case 2:
                      ui->tableView->setModel(act.TriParType(tst));
                      break;

                  case 3:
                      ui->tableView->setModel(act.TriParResponsable(tst));
                      break;
                  }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tableView->setModel(act.recherche(arg1));
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->tableView_2->setModel(ect.recherche(arg1));
}

void MainWindow::on_pushButton_6_clicked()
{
    QString tst;
                  if (ui->radioButton_C_E->isChecked()) tst="ASC";
                  else if (ui->radioButton_D_E->isChecked()) tst="DESC";

                  switch (ui->comboBox_E->currentIndex()) {
                  case 0:
                      ui->tableView_2->setModel(ect.triParNom(tst));
                      break;
                  case 1:
                      ui->tableView_2->setModel(ect.triParNiveau(tst));
                      break;
                  case 2:
                      ui->tableView_2->setModel(ect.triParAge(tst));
                      break;

                  case 3:
                      ui->tableView_2->setModel(ect.triParDate(tst));
                      break;
                  }
}

void MainWindow::on_pushButton_7_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
              model->setQuery("SELECT niveau FROM eleve WHERE  niveau='1ere' ");
              float counta=model->rowCount();
              model->setQuery("SELECT niveau FROM eleve WHERE  niveau='2eme'");
              float countc=model->rowCount();
              model->setQuery("SELECT niveau FROM eleve WHERE  niveau='3eme' ");
              float countp=model->rowCount();
              model->setQuery("SELECT niveau FROM eleve WHERE  niveau='4eme' ");
              float countd=model->rowCount();
              model->setQuery("SELECT niveau FROM eleve WHERE  niveau='5eme' ");
              float counte=model->rowCount();
              model->setQuery("SELECT niveau FROM eleve WHERE  niveau='6eme' ");
              float countf=model->rowCount();

              float total=counta+countp+countc+countd+counte+countf;

                      QPieSeries *series = new QPieSeries();
                      series->append("1ere année",counta);
                      series->append("2éme année",countc);
                      series->append("3éme année",countp);
                      series->append("4éme année",countd);
                      series->append("5éme année",counte);
                      series->append("6éme année",countf);

                      if (counta!=0)
                      {QPieSlice *slice = series->slices().at(0);
                          slice->setLabel("1ére année"+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                          slice->setLabelVisible();
                          slice->setPen(QPen(Qt::black));}
                      if ( countc!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(1);
                          //slice1->setExploded();
                          slice1->setLabel("2éme année "+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::cyan));
                      }
                      if ( countp!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(2);
                          //slice1->setExploded();
                          slice1->setLabel("3éme année"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::red));
                      }
                      if ( countd!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(3);
                          //slice1->setExploded();
                          slice1->setLabel("4éme année"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::yellow));
                      }
                      if ( counte!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(4);
                          //slice1->setExploded();
                          slice1->setLabel("5éme année"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::green));
                      }
                      if ( countf!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(5);
                          //slice1->setExploded();
                          slice1->setLabel("6éme année"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::blue));
                      }


                      // Create the chart widget
                      QChart *chart = new QChart();
                      // Add data to chart with title and hide legend
                      chart->addSeries(series);
                      chart->setTitle("Totale eleves "+ QString::number(total));

                      // Used to display the chart
                      QChartView *chartView = new QChartView(chart);
                      chartView->setRenderHint(QPainter::Antialiasing);
                      chartView->resize(1000,500);


                      chart->legend()->hide();
                      chartView->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
              model->setQuery("SELECT type FROM activite WHERE  type='football' ");
              float counta=model->rowCount();
              model->setQuery("SELECT type FROM activite WHERE  type='literature'");
              float countc=model->rowCount();
              model->setQuery("SELECT type FROM activite WHERE  type='dessin' ");
              float countp=model->rowCount();
              model->setQuery("SELECT type FROM activite WHERE  type='handball' ");
              float countd=model->rowCount();
              model->setQuery("SELECT type FROM activite WHERE  type='musique' ");
              float counte=model->rowCount();


              float total=counta+countp+countc+countd+counte;

                      QPieSeries *series = new QPieSeries();
                      series->append("FootBall",counta);
                      series->append("Literature",countc);
                      series->append("Dessin",countp);
                      series->append("Handball",countd);
                      series->append("Musique",counte);


                      if (counta!=0)
                      {QPieSlice *slice = series->slices().at(0);
                          slice->setLabel("Football"+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                          slice->setLabelVisible();
                          slice->setPen(QPen(Qt::black));}
                      if ( countc!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(1);
                          //slice1->setExploded();
                          slice1->setLabel("Literature "+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::cyan));
                      }
                      if ( countp!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(2);
                          //slice1->setExploded();
                          slice1->setLabel("Dessin"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::red));
                      }
                      if ( countd!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(3);
                          //slice1->setExploded();
                          slice1->setLabel("Handball"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::yellow));
                      }
                      if ( counte!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(4);
                          //slice1->setExploded();
                          slice1->setLabel("Musique"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::green));
                      }


                      // Create the chart widget
                      QChart *chart = new QChart();
                      // Add data to chart with title and hide legend
                      chart->addSeries(series);
                      chart->setTitle("Totale activités "+ QString::number(total));

                      // Used to display the chart
                      QChartView *chartView = new QChartView(chart);
                      chartView->setRenderHint(QPainter::Antialiasing);
                      chartView->resize(1000,500);


                      chart->legend()->hide();
                      chartView->show();
}
