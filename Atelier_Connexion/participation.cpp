#include "participation.h"
#include<QSqlQuery>
Participation::Participation()
{
    id =0;
    id_eleve=0;
    id_activite=0;
    message="";
    etat=0;


}
Participation::Participation(int id,int id_eleve,int id_activite,QString message,int etat)
{

    this->id=id;
    this->id_eleve=id_eleve;
    this->id_activite=id_activite;
    this->message=message;
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
QString Participation::getMessage(){
    return message;
}
int Participation::getEtat(){
    return etat;
}
bool Participation::ajouter(){
    QSqlQuery query;
    QString idP=QString::number(id);
    query.prepare("insert into participation(id,id_eleve,id_activite,message,etat) values (:id,:id_eleve,:id_activite,:message,:etat)");
    query.bindValue(":id",idP);
    query.bindValue(":id_eleve",id_eleve);
    query.bindValue(":id_activite",id_activite);
    query.bindValue(":message",message);
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
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("message"));
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
    query.prepare("UPDATE Participation SET id_eleve=:id_eleve,id_activite=:id_activite,message=:message,etat=:etat WHERE id=:id");
    query.bindValue(":id_eleve",id_eleve);
    query.bindValue(":id_activite",id_activite);
    query.bindValue(":message",message);
    query.bindValue(":etat",etat);
    query.bindValue(":id",res);
    return query.exec();
}

