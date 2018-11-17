/********************************************************************************
** Form generated from reading UI file 'CQFishingAI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CQFISHINGAI_H
#define UI_CQFISHINGAI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CQFishingAIClass
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *CQFishingAIClass)
    {
        if (CQFishingAIClass->objectName().isEmpty())
            CQFishingAIClass->setObjectName(QStringLiteral("CQFishingAIClass"));
        CQFishingAIClass->resize(600, 400);
        centralWidget = new QWidget(CQFishingAIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CQFishingAIClass->setCentralWidget(centralWidget);

        retranslateUi(CQFishingAIClass);

        QMetaObject::connectSlotsByName(CQFishingAIClass);
    } // setupUi

    void retranslateUi(QMainWindow *CQFishingAIClass)
    {
        CQFishingAIClass->setWindowTitle(QApplication::translate("CQFishingAIClass", "Crusaders Quest \351\207\243\351\255\232 AI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CQFishingAIClass: public Ui_CQFishingAIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CQFISHINGAI_H
