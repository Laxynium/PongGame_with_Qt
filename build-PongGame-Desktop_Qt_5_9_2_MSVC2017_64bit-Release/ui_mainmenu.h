/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

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

class Ui_MainMenu
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *start_button;
    QPushButton *settings_button;
    QPushButton *quit_button;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(400, 300);
        horizontalLayout = new QHBoxLayout(MainMenu);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        start_button = new QPushButton(MainMenu);
        start_button->setObjectName(QStringLiteral("start_button"));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(20);
        start_button->setFont(font);

        verticalLayout->addWidget(start_button);

        settings_button = new QPushButton(MainMenu);
        settings_button->setObjectName(QStringLiteral("settings_button"));
        settings_button->setFont(font);

        verticalLayout->addWidget(settings_button);

        quit_button = new QPushButton(MainMenu);
        quit_button->setObjectName(QStringLiteral("quit_button"));
        quit_button->setFont(font);

        verticalLayout->addWidget(quit_button);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "Form", Q_NULLPTR));
        start_button->setText(QApplication::translate("MainMenu", "Start", Q_NULLPTR));
        settings_button->setText(QApplication::translate("MainMenu", "Settings", Q_NULLPTR));
        quit_button->setText(QApplication::translate("MainMenu", "Quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
