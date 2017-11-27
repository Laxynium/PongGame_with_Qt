/********************************************************************************
** Form generated from reading UI file 'pausemenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSEMENU_H
#define UI_PAUSEMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PauseMenu
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *resume_button;
    QPushButton *restart_button;
    QPushButton *backtomenu_button;

    void setupUi(QWidget *PauseMenu)
    {
        if (PauseMenu->objectName().isEmpty())
            PauseMenu->setObjectName(QStringLiteral("PauseMenu"));
        PauseMenu->resize(581, 387);
        horizontalLayout = new QHBoxLayout(PauseMenu);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        resume_button = new QPushButton(PauseMenu);
        resume_button->setObjectName(QStringLiteral("resume_button"));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(20);
        resume_button->setFont(font);

        verticalLayout->addWidget(resume_button);

        restart_button = new QPushButton(PauseMenu);
        restart_button->setObjectName(QStringLiteral("restart_button"));
        restart_button->setFont(font);

        verticalLayout->addWidget(restart_button);

        backtomenu_button = new QPushButton(PauseMenu);
        backtomenu_button->setObjectName(QStringLiteral("backtomenu_button"));
        backtomenu_button->setFont(font);

        verticalLayout->addWidget(backtomenu_button);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(PauseMenu);

        QMetaObject::connectSlotsByName(PauseMenu);
    } // setupUi

    void retranslateUi(QWidget *PauseMenu)
    {
        PauseMenu->setWindowTitle(QApplication::translate("PauseMenu", "Form", Q_NULLPTR));
        resume_button->setText(QApplication::translate("PauseMenu", "Resume", Q_NULLPTR));
        restart_button->setText(QApplication::translate("PauseMenu", "Restart", Q_NULLPTR));
        backtomenu_button->setText(QApplication::translate("PauseMenu", "Back to menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PauseMenu: public Ui_PauseMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSEMENU_H
