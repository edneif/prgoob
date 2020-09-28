#ifndef FORM_2_H
#define FORM_2_H

#include <QDialog>

namespace Ui {
class form_2;
}

class form_2 : public QDialog
{
    Q_OBJECT

public:
    explicit form_2(QWidget *parent = nullptr,  QVector<double> *vec_temp=NULL, QVector<QTime> *vec_time=NULL, QString titlegraph="");
    ~form_2();


private slots:
    void on_form_2_accepted();

private:
    Ui::form_2 *ui;
    int _value=10;
};

#endif // FORM_2_H
