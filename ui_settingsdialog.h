/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *applyButton;
    QGroupBox *parametersBox;
    QGridLayout *gridLayout_2;
    QLabel *baudRateLabel;
    QComboBox *baudRateBox;
    QLabel *dataBitsLabel;
    QComboBox *dataBitsBox;
    QLabel *parityLabel;
    QComboBox *parityBox;
    QLabel *stopBitsLabel;
    QComboBox *stopBitsBox;
    QLabel *flowControlLabel;
    QComboBox *flowControlBox;
    QGroupBox *selectBox;
    QGridLayout *gridLayout;
    QComboBox *serialPortInfoListBox;
    QLabel *descriptionLabel;
    QLabel *manufacturerLabel;
    QLabel *serialNumberLabel;
    QLabel *locationLabel;
    QLabel *vidLabel;
    QLabel *pidLabel;
    QGroupBox *additionalOptionsGroupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *localEchoCheckBox;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(327, 263);
        gridLayout_3 = new QGridLayout(SettingsDialog);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(96, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        applyButton = new QPushButton(SettingsDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(10);
        applyButton->setFont(font);

        horizontalLayout->addWidget(applyButton);


        gridLayout_3->addLayout(horizontalLayout, 2, 0, 1, 2);

        parametersBox = new QGroupBox(SettingsDialog);
        parametersBox->setObjectName(QStringLiteral("parametersBox"));
        parametersBox->setFont(font);
        gridLayout_2 = new QGridLayout(parametersBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        baudRateLabel = new QLabel(parametersBox);
        baudRateLabel->setObjectName(QStringLiteral("baudRateLabel"));
        baudRateLabel->setFont(font);

        gridLayout_2->addWidget(baudRateLabel, 0, 0, 1, 1);

        baudRateBox = new QComboBox(parametersBox);
        baudRateBox->setObjectName(QStringLiteral("baudRateBox"));
        baudRateBox->setFont(font);

        gridLayout_2->addWidget(baudRateBox, 0, 1, 1, 1);

        dataBitsLabel = new QLabel(parametersBox);
        dataBitsLabel->setObjectName(QStringLiteral("dataBitsLabel"));
        dataBitsLabel->setFont(font);

        gridLayout_2->addWidget(dataBitsLabel, 1, 0, 1, 1);

        dataBitsBox = new QComboBox(parametersBox);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));
        dataBitsBox->setFont(font);

        gridLayout_2->addWidget(dataBitsBox, 1, 1, 1, 1);

        parityLabel = new QLabel(parametersBox);
        parityLabel->setObjectName(QStringLiteral("parityLabel"));
        parityLabel->setFont(font);

        gridLayout_2->addWidget(parityLabel, 2, 0, 1, 1);

        parityBox = new QComboBox(parametersBox);
        parityBox->setObjectName(QStringLiteral("parityBox"));
        parityBox->setFont(font);

        gridLayout_2->addWidget(parityBox, 2, 1, 1, 1);

        stopBitsLabel = new QLabel(parametersBox);
        stopBitsLabel->setObjectName(QStringLiteral("stopBitsLabel"));
        stopBitsLabel->setFont(font);

        gridLayout_2->addWidget(stopBitsLabel, 3, 0, 1, 1);

        stopBitsBox = new QComboBox(parametersBox);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));
        stopBitsBox->setFont(font);

        gridLayout_2->addWidget(stopBitsBox, 3, 1, 1, 1);

        flowControlLabel = new QLabel(parametersBox);
        flowControlLabel->setObjectName(QStringLiteral("flowControlLabel"));
        flowControlLabel->setFont(font);

        gridLayout_2->addWidget(flowControlLabel, 4, 0, 1, 1);

        flowControlBox = new QComboBox(parametersBox);
        flowControlBox->setObjectName(QStringLiteral("flowControlBox"));
        flowControlBox->setFont(font);

        gridLayout_2->addWidget(flowControlBox, 4, 1, 1, 1);


        gridLayout_3->addWidget(parametersBox, 0, 1, 1, 1);

        selectBox = new QGroupBox(SettingsDialog);
        selectBox->setObjectName(QStringLiteral("selectBox"));
        selectBox->setFont(font);
        gridLayout = new QGridLayout(selectBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        serialPortInfoListBox = new QComboBox(selectBox);
        serialPortInfoListBox->setObjectName(QStringLiteral("serialPortInfoListBox"));
        serialPortInfoListBox->setFont(font);

        gridLayout->addWidget(serialPortInfoListBox, 0, 0, 1, 1);

        descriptionLabel = new QLabel(selectBox);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));
        descriptionLabel->setFont(font);

        gridLayout->addWidget(descriptionLabel, 1, 0, 1, 1);

        manufacturerLabel = new QLabel(selectBox);
        manufacturerLabel->setObjectName(QStringLiteral("manufacturerLabel"));
        manufacturerLabel->setFont(font);

        gridLayout->addWidget(manufacturerLabel, 2, 0, 1, 1);

        serialNumberLabel = new QLabel(selectBox);
        serialNumberLabel->setObjectName(QStringLiteral("serialNumberLabel"));
        serialNumberLabel->setFont(font);

        gridLayout->addWidget(serialNumberLabel, 3, 0, 1, 1);

        locationLabel = new QLabel(selectBox);
        locationLabel->setObjectName(QStringLiteral("locationLabel"));
        locationLabel->setFont(font);

        gridLayout->addWidget(locationLabel, 4, 0, 1, 1);

        vidLabel = new QLabel(selectBox);
        vidLabel->setObjectName(QStringLiteral("vidLabel"));
        vidLabel->setFont(font);

        gridLayout->addWidget(vidLabel, 5, 0, 1, 1);

        pidLabel = new QLabel(selectBox);
        pidLabel->setObjectName(QStringLiteral("pidLabel"));
        pidLabel->setFont(font);

        gridLayout->addWidget(pidLabel, 6, 0, 1, 1);


        gridLayout_3->addWidget(selectBox, 0, 0, 1, 1);

        additionalOptionsGroupBox = new QGroupBox(SettingsDialog);
        additionalOptionsGroupBox->setObjectName(QStringLiteral("additionalOptionsGroupBox"));
        additionalOptionsGroupBox->setFont(font);
        verticalLayout = new QVBoxLayout(additionalOptionsGroupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        localEchoCheckBox = new QCheckBox(additionalOptionsGroupBox);
        localEchoCheckBox->setObjectName(QStringLiteral("localEchoCheckBox"));
        localEchoCheckBox->setFont(font);
        localEchoCheckBox->setChecked(true);

        verticalLayout->addWidget(localEchoCheckBox);


        gridLayout_3->addWidget(additionalOptionsGroupBox, 1, 0, 1, 2);


        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        applyButton->setText(QApplication::translate("SettingsDialog", "\345\272\224\347\224\250", 0));
        parametersBox->setTitle(QApplication::translate("SettingsDialog", "\344\270\262\345\217\243\345\217\202\346\225\260", 0));
        baudRateLabel->setText(QApplication::translate("SettingsDialog", "\346\263\242\347\211\271\347\216\207:", 0));
        dataBitsLabel->setText(QApplication::translate("SettingsDialog", "\346\225\260\346\215\256\344\275\215:", 0));
        parityLabel->setText(QApplication::translate("SettingsDialog", "\346\240\241\351\252\214\346\226\271\345\274\217:", 0));
        stopBitsLabel->setText(QApplication::translate("SettingsDialog", "\345\201\234\346\255\242\344\275\215:", 0));
        flowControlLabel->setText(QApplication::translate("SettingsDialog", "\346\265\201\346\216\247\345\210\266:", 0));
        selectBox->setTitle(QApplication::translate("SettingsDialog", "\351\200\211\346\213\251\344\270\262\345\217\243", 0));
        descriptionLabel->setText(QApplication::translate("SettingsDialog", "Description:", 0));
        manufacturerLabel->setText(QApplication::translate("SettingsDialog", "Manufacturer:", 0));
        serialNumberLabel->setText(QApplication::translate("SettingsDialog", "Serial number:", 0));
        locationLabel->setText(QApplication::translate("SettingsDialog", "Location:", 0));
        vidLabel->setText(QApplication::translate("SettingsDialog", "Vendor ID:", 0));
        pidLabel->setText(QApplication::translate("SettingsDialog", "Product ID:", 0));
        additionalOptionsGroupBox->setTitle(QApplication::translate("SettingsDialog", "\345\205\266\344\273\226\350\256\276\347\275\256", 0));
        localEchoCheckBox->setText(QApplication::translate("SettingsDialog", "Local echo", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
