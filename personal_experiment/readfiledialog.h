#ifndef READFILEDIALOG_H
#define READFILEDIALOG_H

#include <QDialog>

namespace Ui {
class readFileDialog;
}

class readFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit readFileDialog(QWidget *parent = nullptr);
    ~readFileDialog();

private:
    Ui::readFileDialog *ui;
};

#endif // READFILEDIALOG_H
