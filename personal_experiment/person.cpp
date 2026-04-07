#include "person.h"

Person::Person() {}

Person::Person(QString name,QDate birthday,QString phone,QString email,QString type):
                p_name(name),p_birthday(birthday),p_phone(phone),p_email(email),p_type(type){}

QString Person::getName ()  { return p_name;    }
QString Person::getPhone()  { return p_phone;   }
QString Person::getEmail()  { return p_email;   }
QString Person::getType ()  { return p_type;    }
QDate Person::getBirthday() { return p_birthday;}

void Person::setPhone(QString phone) { p_phone = phone; }
void Person::setEmail(QString email) { p_email = email; }
void Person::setType(QString type) { p_type = type; }

