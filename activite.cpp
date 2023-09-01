#include "activite.h"
#include<QSqlQuery>



Activite::Activite()
{
id =0;
titre="";
description="";
lieu="";
type="";
responsable="";

}
Activite::Activite(int ida,QDate Datea,QString titre,QString lieu,QString type,QString description,QString responsable)
{

    this->id=ida;
    this->date=Datea;
    this->titre=titre;
    this->lieu=lieu;
    this->type=type;
    this->description=description;
    this->responsable=responsable;


}
Activite::Activite(QDate Datea,QString titre,QString lieu,QString type,QString description,QString responsable)
{


    this->date=Datea;
    this->titre=titre;
    this->lieu=lieu;
    this->type=type;
    this->description=description;
    this->responsable=responsable;


}
int Activite::getId(){
    return id;
}
QDate Activite::getDate(){
    return date;
}
QString Activite::getTitre(){
    return titre;
}
QString Activite::getLieu(){
    return lieu;
}
QString Activite::getType(){
    return type;
}
QString Activite::getDescription(){
    return description;
}
QString Activite::getResponsable(){
    return responsable;
}

bool Activite::ajouter(){
    QSqlQuery query;
    QString idS=QString::number(id);
    query.prepare("insert into activite(datee,lieu,type,description,responsable,titre) values (:date,:lieu,:type,:description,:responsable,:titre)");
    query.bindValue(":id",idS);
    query.bindValue(":date",date);
    query.bindValue(":lieu",lieu);
    query.bindValue(":type",type);
    query.bindValue(":description",description);
    query.bindValue(":responsable",responsable);
    query.bindValue(":titre",titre);
      return query.exec();

}
QSqlQueryModel* Activite::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT *  FROM Activite");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("datee"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("responsable"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("titre"));
    return model;
}
bool Activite::supprimer(int id)
    {
        QSqlQuery query;
        QString id_string=QString::number(id);
        query.prepare("delete from Activite where id=:id");
        query.bindValue(":id",id);
        return query.exec();
    }
bool Activite::modifier(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("UPDATE Activite SET titre=:titre,description=:description,type=:type,lieu=:lieu,datee=:datee,responsable=:responsable WHERE id=:id");
    query.bindValue(":titre",titre);
    query.bindValue(":description",description);
    query.bindValue(":type",type);
    query.bindValue(":lieu",lieu);
    query.bindValue(":datee",date);
    query.bindValue(":responsable",responsable);
    query.bindValue(":id",res);

    return query.exec();
}
QSqlQueryModel * Activite::recherche(QString tst)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Activite WHERE ( titre LIKE '%"+tst+"%' OR type LIKE '%"+tst+"%' OR lieu LIKE '%"+tst+"%' OR responsable LIKE '%"+tst+"%') ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("datee"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("responsable"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("titre"));
return model;
}

QSqlQueryModel * Activite::TriParTitre(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Activite ORDER BY titre  "+tst);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("datee"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("responsable"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("titre"));
return model;
}
QSqlQueryModel * Activite::TriParDate(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Activite ORDER BY datee  "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("datee"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("responsable"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("titre"));
return model;
}
QSqlQueryModel * Activite::TriParType(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Activite ORDER BY type  "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("datee"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("responsable"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("titre"));
return model;
}
QSqlQueryModel * Activite::TriParResponsable(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Activite ORDER BY responsable  "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("datee"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("responsable"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("titre"));
return model;
}
