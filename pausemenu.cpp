#include "pausemenu.h"

PauseMenu::PauseMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PauseMenu)
{
    ui->setupUi(this);
}

PauseMenu::~PauseMenu()
{
    delete ui;
}
Ui::PauseMenu&PauseMenu::getUi() const
{
    return *ui;
}
