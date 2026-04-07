#include "person_factory.h"
#include <QString>
Schoolfellow::Schoolfellow() {}

Schoolfellow::Schoolfellow(QString name,QDate birthday,QString phone,QString email,QString type,QString school):
    Person(name,birthday,phone,email,type),p_school(school){}

QString Schoolfellow::getExIn(){return p_school;}

void Schoolfellow::setExIn(QString exIn){p_school = exIn;}

Colleague::Colleague() {}

Colleague::Colleague(QString name, QDate birthday, QString phone, QString email, QString type, QString company)
    : Person(name, birthday, phone, email, type), p_company(company) {}

QString Colleague::getExIn() { return p_company; }

void Colleague::setExIn(QString exIn) { p_company = exIn; }


Friend::Friend() {}

Friend::Friend(QString name, QDate birthday, QString phone, QString email, QString type, QString meetPlace)
    : Person(name, birthday, phone, email, type), p_meetPlace(meetPlace) {}

QString Friend::getExIn() { return p_meetPlace; }

void Friend::setExIn(QString exIn) { p_meetPlace = exIn; }


Relative::Relative() {}

Relative::Relative(QString name, QDate birthday, QString phone, QString email, QString type, QString relation)
    : Person(name, birthday, phone, email, type), p_relation(relation) {}

QString Relative::getExIn() { return p_relation; }

void Relative::setExIn(QString exIn) { p_relation = exIn; }

Person* createPerson( QString name,  QDate birthday,QString phone,  QString email,QString type, QString extra)
{
    if (type == "同学")
        return new Schoolfellow(name, birthday, phone, email, type, extra);
    else if (type == "同事")
        return new Colleague(name, birthday, phone, email, type, extra);
    else if (type == "朋友")
        return new Friend(name, birthday, phone, email, type, extra);
    else if (type == "亲戚")
        return new Relative(name, birthday, phone, email, type, extra);
    else
        return nullptr;
}
