#ifndef PARTICIPATION_H
#define PARTICIPATION_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>

class Participation
{
public:
    Participation();

    Participation(int ,int,int,QString,int);
    int getId();
    int getId_Eleve();
    int getId_Activite();
    QString getMessage();
    int getEtat();

    bool ajouter();
    bool supprimer(int);
    bool modifier (int);
    QSqlQueryModel * afficher();
private:

    int id,id_eleve,id_activite,etat;

  QString message;
};
#endif // PARTICIPATION_H
