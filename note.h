#ifndef NOTE_H
#define NOTE_H
#include<QDateTime>
#include<QSqlQueryModel>

class Note
{
public:
    Note();
    Note(int,float,int,QDateTime);
    Note(float,int,QDateTime);
    int getId() {
        return this->id;
    };
    int getId_activite() {
        return this->id_activite;
    };
    float getNote() {
        return this->note;
    };
    bool ajouter();
    QSqlQueryModel * afficher();
private:
    int id,id_activite;
    float note;
    QDateTime datee;

};

#endif // NOTE_H
