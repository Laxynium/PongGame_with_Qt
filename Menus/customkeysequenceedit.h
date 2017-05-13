#ifndef CUSTOMKEYSEQUENCEEDIT_H
#define CUSTOMKEYSEQUENCEEDIT_H

#include <QKeySequenceEdit>

class CustomKeySequenceEdit : public QKeySequenceEdit
{
    Q_OBJECT
public:
    explicit CustomKeySequenceEdit(QWidget *parent = 0);
    ~CustomKeySequenceEdit();
protected:


    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // CUSTOMKEYSEQUENCEEDIT_H
