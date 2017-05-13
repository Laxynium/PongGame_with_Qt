#include "settings.h"
#include <QDebug>
#include <QKeySequenceEdit>
#include <QKeySequence>
#include <QFile>
#include <QtGlobal>
Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

Ui::Settings &Settings::getUi()const
{
    return *ui;
}

void Settings::on_keySequenceEdit_keySequenceChanged(const QKeySequence &keySequence)
{
    if(keySequence.count())
    {
        keyToMoveUpChanged(Qt::Key(keySequence[0]));
    }

}

void Settings::on_keySequenceEdit_2_keySequenceChanged(const QKeySequence &keySequence)
{
    if(keySequence.count())
    {
        keyToMoveDownChanged(Qt::Key(keySequence[0]));
    }
}
