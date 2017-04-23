#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

#include "ui_settings.h"

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    Ui::Settings& getUi()const;
private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
