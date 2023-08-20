#include "participation.h"
#include<QSqlQuery>
Participation::Participation()
{
    id =0;
    id_eleve=0;
    id_activite=0;

    etat="";


}
Participation::Participation(int id_eleve,int id_activite,QDateTime date,QString etat)
{


    this->id_eleve=id_eleve;
    this->id_activite=id_activite;
    this->date=date;
    this->etat=etat;


}


int Participation::getId(){
    return id;
}
int Participation::getId_Eleve(){
    return id_eleve;
}
int Participation::getId_Activite(){
    return id_activite;
}
QDateTime Participation::getDate(){
    return date;
}
QString Participation::getEtat(){
    return etat;
}
bool Participation::ajouter(){
    QSqlQuery query;
    QString idE=QString::number(id_eleve);
    QString idA=QString::number(id_activite);
    query.prepare("insert into participation(id_eleve,id_activite,dat,etat) values (:id_eleve,:id_activite,:dat,:etat)");

    query.bindValue(":id_eleve",idE);
    query.bindValue(":id_activite",idA);
    query.bindValue(":dat",date);
    query.bindValue(":etat",etat);

      return query.exec();

}
QSqlQueryModel* Participation::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT *  FROM Participation");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_eleve"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_activite"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("dat"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));

    return model;
}
bool Participation::supprimer(int id)
    {
        QSqlQuery query;
        QString id_string=QString::number(id);
        query.prepare("delete from Participation where id=:id");
        query.bindValue(":id",id);
        return query.exec();
    }
bool Participation::modifier(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("UPDATE Participation SET etat='approuvée'  WHERE id=:id");


    query.bindValue(":id",res);
    return query.exec();
}

