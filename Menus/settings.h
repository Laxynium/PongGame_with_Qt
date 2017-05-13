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
signals:
    void keyToMoveUpChanged(Qt::Key key);
    void keyToMoveDownChanged(Qt::Key key);
private slots:

    void on_keySequenceEdit_keySequenceChanged(const QKeySequence &keySequence);

    void on_keySequenceEdit_2_keySequenceChanged(const QKeySequence &keySequence);

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
