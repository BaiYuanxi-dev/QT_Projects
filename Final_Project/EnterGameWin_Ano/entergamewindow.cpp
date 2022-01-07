#include "entergamewindow.h"

#include "form.h"
EnterGameWindow::EnterGameWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Form* form = new Form;
    form->show();
}

EnterGameWindow::~EnterGameWindow()
{
}

