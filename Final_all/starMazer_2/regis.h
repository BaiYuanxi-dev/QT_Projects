#ifndef REGIS_H
#define REGIS_H
#include <QSqlTableModel>
#include <QWidget>

namespace Ui {class regis;}

class regis : public QWidget{
    Q_OBJECT

public:
    explicit regis(QWidget *parent = nullptr);
    ~regis();
    QSqlTableModel *model;
    int head;

private slots:
    void on_confirm_clicked();

    void on_cancel_clicked();

    void on_head1_clicked();

    void on_head2_clicked();

    void on_head3_clicked();

    void on_head4_clicked();

    void on_head5_clicked();

    void on_head6_clicked();

    void on_confirm_pressed();

    void on_confirm_released();

    void on_cancel_pressed();

    void on_cancel_released();

private:
    Ui::regis *ui;
};

#endif // REGIS_H
