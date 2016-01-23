/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *addWatingButton;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *ChoseFolderButton;
    QLineEdit *addWatingLine;
    QPushButton *CheckButton;
    QListWidget *watingListWidget;
    QTableWidget *testCaseTable;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *openTestcaseLineEdit;
    QPushButton *ChoseTestCaseButton;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(781, 498);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        addWatingButton = new QPushButton(tab);
        addWatingButton->setObjectName(QStringLiteral("addWatingButton"));
        addWatingButton->setGeometry(QRect(640, 110, 93, 28));
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 10, 191, 22));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 40, 301, 31));
        lineEdit->setReadOnly(true);
        ChoseFolderButton = new QPushButton(tab);
        ChoseFolderButton->setObjectName(QStringLiteral("ChoseFolderButton"));
        ChoseFolderButton->setGeometry(QRect(330, 40, 93, 31));
        addWatingLine = new QLineEdit(tab);
        addWatingLine->setObjectName(QStringLiteral("addWatingLine"));
        addWatingLine->setGeometry(QRect(440, 110, 191, 31));
        CheckButton = new QPushButton(tab);
        CheckButton->setObjectName(QStringLiteral("CheckButton"));
        CheckButton->setGeometry(QRect(470, 40, 93, 31));
        watingListWidget = new QListWidget(tab);
        watingListWidget->setObjectName(QStringLiteral("watingListWidget"));
        watingListWidget->setGeometry(QRect(455, 160, 241, 192));
        testCaseTable = new QTableWidget(tab);
        testCaseTable->setObjectName(QStringLiteral("testCaseTable"));
        testCaseTable->setGeometry(QRect(20, 111, 391, 241));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        openTestcaseLineEdit = new QLineEdit(tab_2);
        openTestcaseLineEdit->setObjectName(QStringLiteral("openTestcaseLineEdit"));

        horizontalLayout_3->addWidget(openTestcaseLineEdit);

        ChoseTestCaseButton = new QPushButton(tab_2);
        ChoseTestCaseButton->setObjectName(QStringLiteral("ChoseTestCaseButton"));

        horizontalLayout_3->addWidget(ChoseTestCaseButton);


        verticalLayout->addLayout(horizontalLayout_3);

        tableWidget = new QTableWidget(tab_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 781, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        addWatingButton->setText(QApplication::translate("MainWindow", "Add", 0));
        lineEdit->setText(QApplication::translate("MainWindow", "C:/", 0));
        ChoseFolderButton->setText(QApplication::translate("MainWindow", "Chose folder", 0));
        CheckButton->setText(QApplication::translate("MainWindow", "Check", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0));
        openTestcaseLineEdit->setText(QApplication::translate("MainWindow", "Chose file", 0));
        ChoseTestCaseButton->setText(QApplication::translate("MainWindow", "Chose testcase", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
