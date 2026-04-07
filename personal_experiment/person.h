#ifndef PERSON_H
#define PERSON_H
#include<QString>
#include<QDate>


class Person
{
public:
    Person();
    Person(QString name,QDate birthday,QString phone,QString email,QString type);

    QString getName();
    QString getPhone();
    QString getEmail();
    QString getType();
    QDate getBirthday();
    virtual QString getExIn()=0;

    void setPhone(QString phone);
    void setEmail(QString email);
    void setType(QString type); 
    virtual void setExIn(QString exIn)=0;

    virtual ~Person() = default;

private:
    QString p_name;
    QDate p_birthday;
    QString p_phone;
    QString p_email;
    QString p_type;
};

#endif // PERSON_H
