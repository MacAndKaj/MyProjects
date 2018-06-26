/********************************************************************************
** Form generated from reading UI file 'port.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORT_H
#define UI_PORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Port
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Port)
    {
        if (Port->objectName().isEmpty())
            Port->setObjectName(QStringLiteral("Port"));
        Port->resize(240, 116);
        verticalLayout = new QVBoxLayout(Port);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 93, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        comboBox = new QComboBox(Port);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        verticalSpacer = new QSpacerItem(20, 92, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(Port);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Port);
        QObject::connect(buttonBox, SIGNAL(accepted()), Port, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Port, SLOT(reject()));

        QMetaObject::connectSlotsByName(Port);
    } // setupUi

    void retranslateUi(QDialog *Port)
    {
        Port->setWindowTitle(QApplication::translate("Port", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class Port: public Ui_Port {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORT_H
