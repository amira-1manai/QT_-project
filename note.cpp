#include "note.h"
#include<QSqlQuery>
Note::Note()
{

}
Note::Note(float note,int id_a,QDateTime d)
{
this->id_activite=id_a;
    this->note=note;
    this->datee=d;
}
bool Note::ajouter(){
    QSqlQuery query;

    QString id_a=QString::number(id_activite);
    QString note_string=QString::number(note);
    query.prepare("insert into note(note, id_activite,date_n) values (:note, :id_activite,:date_n)");

    query.bindValue(":note",note_string);
    query.bindValue(":id_activite",id_a);
    query.bindValue(":date_n",datee);

      return query.exec();

}
QSqlQueryModel* Note::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT *  FROM note");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Note"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_activite"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_n"));

    return model;
}
