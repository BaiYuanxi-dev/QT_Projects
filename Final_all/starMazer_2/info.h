#ifndef INFO_H
#define INFO_H

#include <QWidget>

namespace Ui {class info;}

class info : public QWidget{
    Q_OBJECT

public:
    explicit info(QWidget *parent = nullptr);
    ~info();

private slots:
    void on_pushButton_clicked();

private:
    Ui::info *ui;
};

#endif // INFO_H
