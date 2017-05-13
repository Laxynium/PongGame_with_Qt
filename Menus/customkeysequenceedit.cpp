#include "customkeysequenceedit.h"
#include <QKeySequence>
#include <QDebug>
CustomKeySequenceEdit::CustomKeySequenceEdit(QWidget *parent):QKeySequenceEdit(parent)
{

}

CustomKeySequenceEdit::~CustomKeySequenceEdit()
{

}

void CustomKeySequenceEdit::keyPressEvent(QKeyEvent *event)
{
    QKeySequenceEdit::keyPressEvent(event);
    QKeySequence seq(keySequence().toString().split(',').back());
    setKeySequence(seq);
    keySequenceChanged(seq);
}
