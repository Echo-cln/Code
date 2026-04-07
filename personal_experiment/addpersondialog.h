#ifndef ADDPERSONDIALOG_H
#define ADDPERSONDIALOG_H

#include <QDialog>
#include"person.h"

namespace Ui {
class AddPersonDialog;
}

class AddPersonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPersonDialog(QWidget *parent = nullptr);

    ~AddPersonDialog();

    Person * getData();
    void setData(Person* p);
private slots:
    void typeChanged(QString type);

private:
    Ui::AddPersonDialog *ui;


};

#endif // ADDPERSONDIALOG_H
