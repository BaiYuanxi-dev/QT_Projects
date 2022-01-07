#ifndef REGIS_H
#define REGIS_H

#include <QSqlTableModel>
#include <QWidget>

namespace Ui {class Regis;}

class Regis : public QWidget{
    Q_OBJECT

public:
    explicit Regis(QWidget *parent = nullptr);
    ~Regis();
    QSqlTableModel *model;

private slots:
    void on_confirm_clicked();

    void on_cancel_clicked();

private:
    Ui::Regis *ui;
};

#endif // REGIS_H
