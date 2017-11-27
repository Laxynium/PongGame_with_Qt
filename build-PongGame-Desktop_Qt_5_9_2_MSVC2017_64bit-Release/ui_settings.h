/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "customkeysequenceedit.h"

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    CustomKeySequenceEdit *keySequenceEdit;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    CustomKeySequenceEdit *keySequenceEdit_2;
    QSpacerItem *verticalSpacer;
    QPushButton *back_button;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(572, 477);
        verticalLayout = new QVBoxLayout(Settings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_3 = new QFrame(Settings);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(20);
        label_3->setFont(font);
        label_3->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(label_3, 0, Qt::AlignVCenter);


        verticalLayout->addWidget(frame_3, 0, Qt::AlignHCenter);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        frame = new QFrame(Settings);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(12);
        label_4->setFont(font1);
        label_4->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(label_4);

        keySequenceEdit = new CustomKeySequenceEdit(frame);
        keySequenceEdit->setObjectName(QStringLiteral("keySequenceEdit"));
        keySequenceEdit->setFont(font1);
        keySequenceEdit->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(keySequenceEdit);


        verticalLayout_2->addWidget(frame);

        frame_2 = new QFrame(Settings);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);
        label_5->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(label_5);

        keySequenceEdit_2 = new CustomKeySequenceEdit(frame_2);
        keySequenceEdit_2->setObjectName(QStringLiteral("keySequenceEdit_2"));
        keySequenceEdit_2->setFont(font1);
        keySequenceEdit_2->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(keySequenceEdit_2);


        verticalLayout_2->addWidget(frame_2);


        verticalLayout->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        back_button = new QPushButton(Settings);
        back_button->setObjectName(QStringLiteral("back_button"));
        back_button->setFont(font1);
        back_button->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(back_button);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Form", Q_NULLPTR));
        label_3->setText(QApplication::translate("Settings", "Controll settings", Q_NULLPTR));
        label_4->setText(QApplication::translate("Settings", "Move up", Q_NULLPTR));
        keySequenceEdit->setKeySequence(QApplication::translate("Settings", "W", Q_NULLPTR));
        label_5->setText(QApplication::translate("Settings", "Move down", Q_NULLPTR));
        keySequenceEdit_2->setKeySequence(QApplication::translate("Settings", "S", Q_NULLPTR));
        back_button->setText(QApplication::translate("Settings", "Back to main menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
