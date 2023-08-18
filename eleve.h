#ifndef ELEVE_H
#define ELEVE_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>

class Eleve
{
public:
    Eleve();

    Eleve(int ,QString,QString,QString,QString,QDate,QString,QString,QString ,int);
    Eleve(QString,QString,QString,QString,QDate,QString,QString,QString ,int);

    int getId();
    QString getNom();
    QString getPrenom();
    QString getNiveau();
    QString getClasse();
    QDate getDate_naissance();
    QString getSexe();
    QString getAdresse();
     QString getEmail();
    int getAge();
    bool ajouter();
    bool supprimer(int);
    bool modifier (int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(QString tst);
    QSqlQueryModel * triParNom(QString tst);
    QSqlQueryModel * triParAge(QString tst);
    QSqlQueryModel * triParNiveau(QString tst);
    QSqlQueryModel * triParDate(QString tst);
private:
    int id,age;
    QDate date_naissance;
  QString nom,prenom,niveau,classe,sexe,adresse,email;

};

#endif // ELEVE_H
