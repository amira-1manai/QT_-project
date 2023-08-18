#ifndef ACTIVITE_H
#define ACTIVITE_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>


class Activite
{
public:
    Activite();
    Activite(int ,QDate,QString,QString,QString,QString,QString);
    Activite(QDate,QString,QString,QString,QString,QString);
    int getId();
    QDate getDate();
    QString getTitre();
    QString getLieu();
    QString getType();
    QString getDescription();
    QString getResponsable();
    bool ajouter();
    bool supprimer(int);
    bool modifier (int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * TriParDate(QString tst);
    QSqlQueryModel * TriParTitre(QString tst);
    QSqlQueryModel * TriParType(QString tst);
    QSqlQueryModel * TriParResponsable(QString tst);
    QSqlQueryModel * recherche(QString tst);


private:

    int id;
    QDate date;
  QString titre,lieu,type,description,responsable;
};

#endif // ACTIVITE_H
