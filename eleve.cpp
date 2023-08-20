#include "eleve.h"
#include<QSqlQuery>
Eleve::Eleve()
{
    id =0;
    nom="";
    prenom="";
    niveau="";
    classe="";
    sexe="";
    adresse="";
    email="";
    age=0;
}
Eleve::Eleve(int id,QString nom,QString prenom,QString niveau,QString classe,QDate date_naissance,QString sexe,QString adresse,QString email ,int age)
{

    this->id=id;
      this->nom=nom;
    this->prenom=prenom;
    this->niveau=niveau;
    this->classe=classe;
    this->date_naissance=date_naissance;
    this->sexe=sexe;
    this->adresse=adresse;
    this->email=email;
    this->age=age;


}
Eleve::Eleve(QString nom,QString prenom,QString niveau,QString classe,QDate date_naissance,QString sexe,QString adresse,QString email ,int age)
{


      this->nom=nom;
    this->prenom=prenom;
    this->niveau=niveau;
    this->classe=classe;
    this->date_naissance=date_naissance;
    this->sexe=sexe;
    this->adresse=adresse;
    this->email=email;
    this->age=age;


}
int Eleve::getId(){
    return id;
}
QString Eleve::getNom(){
    return nom;
}
QString Eleve::getPrenom(){
    return prenom;
}
QString Eleve::getNiveau(){
    return niveau;
}
QString Eleve::getClasse(){
    return classe;
}
QDate Eleve::getDate_naissance(){
    return date_naissance;
}
QString Eleve::getSexe(){
    return sexe;
}
QString Eleve::getAdresse(){
    return adresse;
}
QString Eleve::getEmail(){
    return email;
}

int Eleve::getAge(){
    return age;
}
bool Eleve::ajouter(){
    QSqlQuery query;

    QString ages=QString::number(age);
    query.prepare("insert into eleve(nom, prenom,niveau,classe,date_naissance,sexe,adresse,email,age) values (:nom, :prenom,:niveau,:classe,:date_naissance,:sexe,:adresse,:email,:age)");

    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":niveau",niveau);
    query.bindValue(":classe",classe);
    query.bindValue(":date_naissance",date_naissance);
    query.bindValue(":sexe",sexe);
    query.bindValue(":adresse",adresse);
    query.bindValue(":email",email);
     query.bindValue(":age",ages);
      return query.exec();

}
QSqlQueryModel* Eleve::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT *  FROM Eleve");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("niveau"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_naissance"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("sexe"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
          model->setHeaderData(8, Qt::Horizontal, QObject::tr("email"));
          model->setHeaderData(9, Qt::Horizontal, QObject::tr("age"));
    return model;
}
bool Eleve::supprimer(int id)
    {
        QSqlQuery query;
        QString id_string=QString::number(id);
        query.prepare("delete from Eleve where id=:id");
        query.bindValue(":id",id);
        return query.exec();
    }
bool Eleve::modifier(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
      QString ages=QString::number(age);
    query.prepare("UPDATE Eleve SET nom=:nom,prenom=:prenom,niveau=:niveau,classe=:classe,date_naissance=:date_naissance,sexe=:sexe,adresse=:adresse,email=:email,age=:age WHERE id=:id");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":niveau",niveau);
    query.bindValue(":classe",classe);
    query.bindValue(":date_naissance",date_naissance);
    query.bindValue(":sexe",sexe);
    query.bindValue(":adresse",adresse);
    query.bindValue(":email",email);
     query.bindValue(":age",ages);
    query.bindValue(":id",res);

    return query.exec();
}
QSqlQueryModel * Eleve::recherche(QString tst)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve WHERE ( nom LIKE '%"+tst+"%' OR prenom LIKE '%"+tst+"%' OR email LIKE '%"+tst+"%' OR adresse LIKE '%"+tst+"%') ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("niveau"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("age"));
return model;
}
QSqlQueryModel * Eleve::triParNom(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve ORDER BY nom  "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("niveau"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("age"));
return model;
}
QSqlQueryModel * Eleve::triParAge(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve ORDER BY age  "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("niveau"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("age"));
return model;
}
QSqlQueryModel * Eleve::triParDate(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve ORDER BY date_naissance  "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("niveau"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("age"));
return model;
}
QSqlQueryModel * Eleve::triParNiveau(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve ORDER BY niveau  "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("niveau"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("age"));
return model;
}

bool Eleve::ajouter_mod(int id,QString a,QDateTime d)
{
    QSqlQuery query;
    QString res = QString::number(id);
    //QString res1=d.toString();
    query.prepare("INSERT INTO historique(id_eleve,type,date_mod)""VALUES (:id_a,:type,:date_mod)");
    query.bindValue(":id_a",id);
    query.bindValue(":type",a);
    query.bindValue(":date_mod",d);
    return query.exec();
}
QSqlQueryModel * Eleve::afficher_mod()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM historique");
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID Eleve"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date et Temps"));
    return model;
}
