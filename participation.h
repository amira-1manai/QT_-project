#ifndef PARTICIPATION_H
#define PARTICIPATION_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>

class Participation
{
public:
    Participation();

    Participation(int,int,QDateTime,QString);
    int getId();
    int getId_Eleve();
    int getId_Activite();
    QDateTime getDate();
    QString getEtat();

    bool ajouter();
    bool supprimer(int);
    bool modifier (int);
    QSqlQueryModel * afficher();
private:

    int id,id_eleve,id_activite;
    QString etat;

  QDateTime date;
};
#endif // PARTICIPATION_H
