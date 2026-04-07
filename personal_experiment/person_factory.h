#ifndef PERSON_FACTORY_H
#define PERSON_FACTORY_H

#include "person.h"
#include <QString>

class Schoolfellow:public Person
{
public:
    Schoolfellow();
    Schoolfellow(QString name,QDate birthday,QString phone,QString email,QString type,QString school);
    QString getExIn();
    void setExIn(QString exIn);
protected:
    QString p_school;
};
class Colleague : public Person
{
public:
    Colleague();
    Colleague(QString name, QDate birthday, QString phone, QString email, QString type, QString company);
    QString getExIn();
    void setExIn(QString exIn);
protected:
    QString p_company;
};
class Friend : public Person
{
public:
    Friend();
    Friend(QString name, QDate birthday, QString phone, QString email, QString type, QString meetPlace);
    QString getExIn();
    void setExIn(QString exIn);
protected:
    QString p_meetPlace;
};
class Relative : public Person
{
public:
    Relative();
    Relative(QString name, QDate birthday, QString phone, QString email, QString type, QString relation);
    QString getExIn();
    void setExIn(QString exIn);
protected:
    QString p_relation;
};
Person* createPerson( QString name,  QDate birthday,QString phone,  QString email,QString type, QString extra);


#endif // PERSON_FACTORY_H
