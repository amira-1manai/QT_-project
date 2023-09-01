#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;

    bool test=c.createconnect();
    MainWindow w;
    QFile file("C:/Users/AMIRA/Downloads/Atelier_Connexion/Combinear.qss");
                      file.open(QFile::ReadOnly);

                      QString styleSheet { QLatin1String(file.readAll()) };

                      //setup stylesheet
                      a.setStyleSheet(styleSheet);
    if(test)
    {w.show();
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
