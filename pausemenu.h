#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <QWidget>
#include "ui_pausemenu.h"
namespace Ui {
class PauseMenu;
}

class PauseMenu : public QWidget
{
    Q_OBJECT

public:
    explicit PauseMenu(QWidget *parent = 0);
    ~PauseMenu();

    Ui::PauseMenu &getUi() const;
private:
    Ui::PauseMenu *ui;
};

#endif // PAUSEMENU_H
