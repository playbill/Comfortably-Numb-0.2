/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Tue 19. Jun 04:45:45 2012
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUndo;
    QAction *actionRedo;
    QWidget *centralWidget;
    QPushButton *num6Button;
    QPushButton *num3Button;
    QPushButton *opDivButton;
    QPushButton *opPointButton;
    QPushButton *opFoisButton;
    QPushButton *opPlusButton;
    QPushButton *opMoinsButton;
    QPushButton *num2Button;
    QPushButton *num4Button;
    QPushButton *opEgalButton;
    QPushButton *num1Button;
    QPushButton *num8Button;
    QPushButton *num9Button;
    QPushButton *num7Button;
    QPushButton *num5Button;
    QPushButton *num0Button;
    QLineEdit *display;
    QLineEdit *displaytop;
    QCheckBox *modeComplexe;
    QGroupBox *modeConstante;
    QRadioButton *modeReel;
    QRadioButton *modeRationnel;
    QRadioButton *modeEntier;
    QRadioButton *modeBestFit;
    QGroupBox *modeAngle;
    QRadioButton *modeDegre;
    QRadioButton *modeRadiant;
    QGroupBox *groupBox_3;
    QPushButton *opSinhButton;
    QPushButton *opEspaceButton;
    QPushButton *opCosButton;
    QPushButton *opCubeButton;
    QPushButton *opInvButton;
    QPushButton *opPowButton;
    QPushButton *opSqrButton;
    QPushButton *opTanButton;
    QPushButton *opEvalButton;
    QPushButton *opSinButton;
    QPushButton *opModButton;
    QPushButton *opLogButton;
    QPushButton *complexeButton;
    QPushButton *opTanhButton;
    QPushButton *opLnButton;
    QPushButton *opFactButton;
    QPushButton *opSqrtButton;
    QPushButton *opCoshButton;
    QPushButton *opSignButton;
    QPushButton *opExpressionButton;
    QGroupBox *groupBox;
    QPushButton *opSwapButton;
    QPushButton *opMeanButton;
    QPushButton *opSumButton;
    QPushButton *opDropButton;
    QPushButton *opDupButton;
    QPushButton *opClearButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(551, 399);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        num6Button = new QPushButton(centralWidget);
        num6Button->setObjectName(QString::fromUtf8("num6Button"));
        num6Button->setGeometry(QRect(440, 213, 41, 31));
        num6Button->setLayoutDirection(Qt::LeftToRight);
        num3Button = new QPushButton(centralWidget);
        num3Button->setObjectName(QString::fromUtf8("num3Button"));
        num3Button->setGeometry(QRect(440, 173, 41, 31));
        num3Button->setLayoutDirection(Qt::LeftToRight);
        opDivButton = new QPushButton(centralWidget);
        opDivButton->setObjectName(QString::fromUtf8("opDivButton"));
        opDivButton->setGeometry(QRect(440, 133, 41, 31));
        opDivButton->setLayoutDirection(Qt::LeftToRight);
        opPointButton = new QPushButton(centralWidget);
        opPointButton->setObjectName(QString::fromUtf8("opPointButton"));
        opPointButton->setGeometry(QRect(440, 293, 41, 31));
        opPointButton->setLayoutDirection(Qt::LeftToRight);
        opFoisButton = new QPushButton(centralWidget);
        opFoisButton->setObjectName(QString::fromUtf8("opFoisButton"));
        opFoisButton->setGeometry(QRect(490, 133, 41, 31));
        opFoisButton->setLayoutDirection(Qt::LeftToRight);
        opPlusButton = new QPushButton(centralWidget);
        opPlusButton->setObjectName(QString::fromUtf8("opPlusButton"));
        opPlusButton->setGeometry(QRect(490, 213, 41, 31));
        opPlusButton->setLayoutDirection(Qt::LeftToRight);
        opMoinsButton = new QPushButton(centralWidget);
        opMoinsButton->setObjectName(QString::fromUtf8("opMoinsButton"));
        opMoinsButton->setGeometry(QRect(490, 173, 41, 31));
        opMoinsButton->setLayoutDirection(Qt::LeftToRight);
        num2Button = new QPushButton(centralWidget);
        num2Button->setObjectName(QString::fromUtf8("num2Button"));
        num2Button->setGeometry(QRect(390, 173, 41, 31));
        num2Button->setLayoutDirection(Qt::LeftToRight);
        num4Button = new QPushButton(centralWidget);
        num4Button->setObjectName(QString::fromUtf8("num4Button"));
        num4Button->setGeometry(QRect(340, 213, 41, 31));
        num4Button->setLayoutDirection(Qt::LeftToRight);
        opEgalButton = new QPushButton(centralWidget);
        opEgalButton->setObjectName(QString::fromUtf8("opEgalButton"));
        opEgalButton->setGeometry(QRect(490, 253, 41, 71));
        opEgalButton->setLayoutDirection(Qt::LeftToRight);
        num1Button = new QPushButton(centralWidget);
        num1Button->setObjectName(QString::fromUtf8("num1Button"));
        num1Button->setGeometry(QRect(340, 173, 41, 31));
        num1Button->setLayoutDirection(Qt::LeftToRight);
        num8Button = new QPushButton(centralWidget);
        num8Button->setObjectName(QString::fromUtf8("num8Button"));
        num8Button->setGeometry(QRect(390, 253, 41, 31));
        num8Button->setLayoutDirection(Qt::LeftToRight);
        num9Button = new QPushButton(centralWidget);
        num9Button->setObjectName(QString::fromUtf8("num9Button"));
        num9Button->setGeometry(QRect(440, 253, 41, 31));
        num9Button->setLayoutDirection(Qt::LeftToRight);
        num7Button = new QPushButton(centralWidget);
        num7Button->setObjectName(QString::fromUtf8("num7Button"));
        num7Button->setGeometry(QRect(340, 253, 41, 31));
        num7Button->setLayoutDirection(Qt::LeftToRight);
        num5Button = new QPushButton(centralWidget);
        num5Button->setObjectName(QString::fromUtf8("num5Button"));
        num5Button->setGeometry(QRect(390, 213, 41, 31));
        num5Button->setLayoutDirection(Qt::LeftToRight);
        num0Button = new QPushButton(centralWidget);
        num0Button->setObjectName(QString::fromUtf8("num0Button"));
        num0Button->setGeometry(QRect(340, 293, 91, 31));
        num0Button->setLayoutDirection(Qt::LeftToRight);
        display = new QLineEdit(centralWidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(12, 50, 451, 51));
        QFont font;
        font.setPointSize(36);
        display->setFont(font);
        display->setCursor(QCursor(Qt::SizeVerCursor));
        display->setMouseTracking(false);
        display->setAcceptDrops(false);
        display->setLayoutDirection(Qt::LeftToRight);
        display->setAutoFillBackground(true);
        display->setReadOnly(false);
        displaytop = new QLineEdit(centralWidget);
        displaytop->setObjectName(QString::fromUtf8("displaytop"));
        displaytop->setGeometry(QRect(12, 20, 451, 31));
        modeComplexe = new QCheckBox(centralWidget);
        modeComplexe->setObjectName(QString::fromUtf8("modeComplexe"));
        modeComplexe->setGeometry(QRect(170, 110, 72, 18));
        modeConstante = new QGroupBox(centralWidget);
        modeConstante->setObjectName(QString::fromUtf8("modeConstante"));
        modeConstante->setGeometry(QRect(10, 130, 311, 21));
        modeReel = new QRadioButton(modeConstante);
        modeReel->setObjectName(QString::fromUtf8("modeReel"));
        modeReel->setGeometry(QRect(10, 0, 51, 18));
        modeRationnel = new QRadioButton(modeConstante);
        modeRationnel->setObjectName(QString::fromUtf8("modeRationnel"));
        modeRationnel->setGeometry(QRect(70, 0, 71, 18));
        modeEntier = new QRadioButton(modeConstante);
        modeEntier->setObjectName(QString::fromUtf8("modeEntier"));
        modeEntier->setGeometry(QRect(150, 0, 51, 16));
        modeBestFit = new QRadioButton(modeConstante);
        modeBestFit->setObjectName(QString::fromUtf8("modeBestFit"));
        modeBestFit->setGeometry(QRect(210, 0, 61, 18));
        modeAngle = new QGroupBox(centralWidget);
        modeAngle->setObjectName(QString::fromUtf8("modeAngle"));
        modeAngle->setGeometry(QRect(10, 110, 151, 21));
        modeDegre = new QRadioButton(modeAngle);
        modeDegre->setObjectName(QString::fromUtf8("modeDegre"));
        modeDegre->setGeometry(QRect(10, 0, 61, 18));
        modeRadiant = new QRadioButton(modeAngle);
        modeRadiant->setObjectName(QString::fromUtf8("modeRadiant"));
        modeRadiant->setGeometry(QRect(70, 0, 71, 18));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 200, 311, 141));
        opSinhButton = new QPushButton(groupBox_3);
        opSinhButton->setObjectName(QString::fromUtf8("opSinhButton"));
        opSinhButton->setGeometry(QRect(220, 53, 31, 31));
        opSinhButton->setLayoutDirection(Qt::LeftToRight);
        opEspaceButton = new QPushButton(groupBox_3);
        opEspaceButton->setObjectName(QString::fromUtf8("opEspaceButton"));
        opEspaceButton->setGeometry(QRect(140, 93, 31, 31));
        opEspaceButton->setLayoutDirection(Qt::LeftToRight);
        opCosButton = new QPushButton(groupBox_3);
        opCosButton->setObjectName(QString::fromUtf8("opCosButton"));
        opCosButton->setGeometry(QRect(100, 53, 31, 31));
        opCosButton->setLayoutDirection(Qt::LeftToRight);
        opCubeButton = new QPushButton(groupBox_3);
        opCubeButton->setObjectName(QString::fromUtf8("opCubeButton"));
        opCubeButton->setGeometry(QRect(100, 13, 31, 31));
        opCubeButton->setLayoutDirection(Qt::LeftToRight);
        opInvButton = new QPushButton(groupBox_3);
        opInvButton->setObjectName(QString::fromUtf8("opInvButton"));
        opInvButton->setGeometry(QRect(60, 93, 31, 31));
        opInvButton->setLayoutDirection(Qt::LeftToRight);
        opPowButton = new QPushButton(groupBox_3);
        opPowButton->setObjectName(QString::fromUtf8("opPowButton"));
        opPowButton->setGeometry(QRect(60, 13, 31, 31));
        opPowButton->setLayoutDirection(Qt::LeftToRight);
        opSqrButton = new QPushButton(groupBox_3);
        opSqrButton->setObjectName(QString::fromUtf8("opSqrButton"));
        opSqrButton->setGeometry(QRect(140, 13, 31, 31));
        opSqrButton->setLayoutDirection(Qt::LeftToRight);
        opTanButton = new QPushButton(groupBox_3);
        opTanButton->setObjectName(QString::fromUtf8("opTanButton"));
        opTanButton->setGeometry(QRect(20, 53, 31, 31));
        opTanButton->setLayoutDirection(Qt::LeftToRight);
        opEvalButton = new QPushButton(groupBox_3);
        opEvalButton->setObjectName(QString::fromUtf8("opEvalButton"));
        opEvalButton->setGeometry(QRect(260, 53, 31, 71));
        opEvalButton->setLayoutDirection(Qt::LeftToRight);
        opSinButton = new QPushButton(groupBox_3);
        opSinButton->setObjectName(QString::fromUtf8("opSinButton"));
        opSinButton->setGeometry(QRect(180, 53, 31, 31));
        opSinButton->setLayoutDirection(Qt::LeftToRight);
        opModButton = new QPushButton(groupBox_3);
        opModButton->setObjectName(QString::fromUtf8("opModButton"));
        opModButton->setGeometry(QRect(100, 93, 31, 31));
        opModButton->setLayoutDirection(Qt::LeftToRight);
        opLogButton = new QPushButton(groupBox_3);
        opLogButton->setObjectName(QString::fromUtf8("opLogButton"));
        opLogButton->setGeometry(QRect(220, 13, 31, 31));
        opLogButton->setLayoutDirection(Qt::LeftToRight);
        complexeButton = new QPushButton(groupBox_3);
        complexeButton->setObjectName(QString::fromUtf8("complexeButton"));
        complexeButton->setGeometry(QRect(180, 93, 31, 31));
        complexeButton->setLayoutDirection(Qt::LeftToRight);
        opTanhButton = new QPushButton(groupBox_3);
        opTanhButton->setObjectName(QString::fromUtf8("opTanhButton"));
        opTanhButton->setGeometry(QRect(60, 53, 31, 31));
        opTanhButton->setLayoutDirection(Qt::LeftToRight);
        opLnButton = new QPushButton(groupBox_3);
        opLnButton->setObjectName(QString::fromUtf8("opLnButton"));
        opLnButton->setGeometry(QRect(260, 13, 31, 31));
        opLnButton->setLayoutDirection(Qt::LeftToRight);
        opFactButton = new QPushButton(groupBox_3);
        opFactButton->setObjectName(QString::fromUtf8("opFactButton"));
        opFactButton->setGeometry(QRect(20, 13, 31, 31));
        opFactButton->setLayoutDirection(Qt::LeftToRight);
        opSqrtButton = new QPushButton(groupBox_3);
        opSqrtButton->setObjectName(QString::fromUtf8("opSqrtButton"));
        opSqrtButton->setGeometry(QRect(180, 13, 31, 31));
        opSqrtButton->setLayoutDirection(Qt::LeftToRight);
        opCoshButton = new QPushButton(groupBox_3);
        opCoshButton->setObjectName(QString::fromUtf8("opCoshButton"));
        opCoshButton->setGeometry(QRect(140, 53, 31, 31));
        opCoshButton->setLayoutDirection(Qt::LeftToRight);
        opSignButton = new QPushButton(groupBox_3);
        opSignButton->setObjectName(QString::fromUtf8("opSignButton"));
        opSignButton->setGeometry(QRect(20, 93, 31, 31));
        opSignButton->setLayoutDirection(Qt::LeftToRight);
        opExpressionButton = new QPushButton(groupBox_3);
        opExpressionButton->setObjectName(QString::fromUtf8("opExpressionButton"));
        opExpressionButton->setGeometry(QRect(220, 93, 31, 31));
        opExpressionButton->setLayoutDirection(Qt::LeftToRight);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 150, 311, 51));
        opSwapButton = new QPushButton(groupBox);
        opSwapButton->setObjectName(QString::fromUtf8("opSwapButton"));
        opSwapButton->setGeometry(QRect(10, 10, 41, 31));
        opSwapButton->setLayoutDirection(Qt::LeftToRight);
        opMeanButton = new QPushButton(groupBox);
        opMeanButton->setObjectName(QString::fromUtf8("opMeanButton"));
        opMeanButton->setGeometry(QRect(60, 10, 41, 31));
        opMeanButton->setLayoutDirection(Qt::LeftToRight);
        opSumButton = new QPushButton(groupBox);
        opSumButton->setObjectName(QString::fromUtf8("opSumButton"));
        opSumButton->setGeometry(QRect(110, 10, 41, 31));
        opSumButton->setLayoutDirection(Qt::LeftToRight);
        opDropButton = new QPushButton(groupBox);
        opDropButton->setObjectName(QString::fromUtf8("opDropButton"));
        opDropButton->setGeometry(QRect(160, 10, 41, 31));
        opDropButton->setLayoutDirection(Qt::LeftToRight);
        opDupButton = new QPushButton(groupBox);
        opDupButton->setObjectName(QString::fromUtf8("opDupButton"));
        opDupButton->setGeometry(QRect(210, 10, 41, 31));
        opDupButton->setLayoutDirection(Qt::LeftToRight);
        opClearButton = new QPushButton(groupBox);
        opClearButton->setObjectName(QString::fromUtf8("opClearButton"));
        opClearButton->setGeometry(QRect(260, 10, 41, 31));
        opClearButton->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 551, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0, QApplication::UnicodeUTF8));
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0, QApplication::UnicodeUTF8));
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        num6Button->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        num6Button->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        num3Button->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        num3Button->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        opDivButton->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        opDivButton->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        opPointButton->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        opPointButton->setShortcut(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        opFoisButton->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        opFoisButton->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        opPlusButton->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        opPlusButton->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        opMoinsButton->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        opMoinsButton->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        num2Button->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        num2Button->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        num4Button->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        num4Button->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        opEgalButton->setText(QApplication::translate("MainWindow", "=", 0, QApplication::UnicodeUTF8));
        opEgalButton->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        num1Button->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        num1Button->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        num8Button->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        num8Button->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        num9Button->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        num9Button->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        num7Button->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        num7Button->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        num5Button->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        num5Button->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        num0Button->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        num0Button->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        display->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        modeComplexe->setText(QApplication::translate("MainWindow", "Complexe", 0, QApplication::UnicodeUTF8));
        modeConstante->setTitle(QString());
        modeReel->setText(QApplication::translate("MainWindow", "R\303\251el", 0, QApplication::UnicodeUTF8));
        modeRationnel->setText(QApplication::translate("MainWindow", "Rationnel", 0, QApplication::UnicodeUTF8));
        modeEntier->setText(QApplication::translate("MainWindow", "Entier", 0, QApplication::UnicodeUTF8));
        modeBestFit->setText(QApplication::translate("MainWindow", "Best Fit", 0, QApplication::UnicodeUTF8));
        modeAngle->setTitle(QString());
        modeDegre->setText(QApplication::translate("MainWindow", "Degr\303\251s", 0, QApplication::UnicodeUTF8));
        modeRadiant->setText(QApplication::translate("MainWindow", "Radiants", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        opSinhButton->setText(QApplication::translate("MainWindow", "sinh", 0, QApplication::UnicodeUTF8));
        opEspaceButton->setText(QApplication::translate("MainWindow", "_", 0, QApplication::UnicodeUTF8));
        opEspaceButton->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        opCosButton->setText(QApplication::translate("MainWindow", "cos", 0, QApplication::UnicodeUTF8));
        opCubeButton->setText(QApplication::translate("MainWindow", "cube", 0, QApplication::UnicodeUTF8));
        opInvButton->setText(QApplication::translate("MainWindow", "inv", 0, QApplication::UnicodeUTF8));
        opPowButton->setText(QApplication::translate("MainWindow", "pow", 0, QApplication::UnicodeUTF8));
        opSqrButton->setText(QApplication::translate("MainWindow", "sqr", 0, QApplication::UnicodeUTF8));
        opTanButton->setText(QApplication::translate("MainWindow", "tan", 0, QApplication::UnicodeUTF8));
        opEvalButton->setText(QApplication::translate("MainWindow", "eval", 0, QApplication::UnicodeUTF8));
        opSinButton->setText(QApplication::translate("MainWindow", "sin", 0, QApplication::UnicodeUTF8));
        opModButton->setText(QApplication::translate("MainWindow", "mod", 0, QApplication::UnicodeUTF8));
        opLogButton->setText(QApplication::translate("MainWindow", "log", 0, QApplication::UnicodeUTF8));
        opLogButton->setShortcut(QString());
        complexeButton->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        complexeButton->setShortcut(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        opTanhButton->setText(QApplication::translate("MainWindow", "tanh", 0, QApplication::UnicodeUTF8));
        opLnButton->setText(QApplication::translate("MainWindow", "ln", 0, QApplication::UnicodeUTF8));
        opFactButton->setText(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        opFactButton->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        opSqrtButton->setText(QApplication::translate("MainWindow", "sqrt", 0, QApplication::UnicodeUTF8));
        opCoshButton->setText(QApplication::translate("MainWindow", "cosh", 0, QApplication::UnicodeUTF8));
        opSignButton->setText(QApplication::translate("MainWindow", "sign", 0, QApplication::UnicodeUTF8));
        opExpressionButton->setText(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        opSwapButton->setText(QApplication::translate("MainWindow", "swap", 0, QApplication::UnicodeUTF8));
        opSwapButton->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        opMeanButton->setText(QApplication::translate("MainWindow", "mean", 0, QApplication::UnicodeUTF8));
        opMeanButton->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        opSumButton->setText(QApplication::translate("MainWindow", "sum", 0, QApplication::UnicodeUTF8));
        opSumButton->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        opDropButton->setText(QApplication::translate("MainWindow", "drop", 0, QApplication::UnicodeUTF8));
        opDropButton->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        opDupButton->setText(QApplication::translate("MainWindow", "dup", 0, QApplication::UnicodeUTF8));
        opDupButton->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        opClearButton->setText(QApplication::translate("MainWindow", "clear", 0, QApplication::UnicodeUTF8));
        opClearButton->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
