#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),leCalculateur(new Calculateur())
{
    waitingForOperand = true;
    ui->setupUi(this);
    mapper = new QSignalMapper(this);

    connect(ui->opEgalButton, SIGNAL(clicked()), this, SLOT(evaluate()));
    //connect(ui->BtVider, SIGNAL(clicked()), ui->entreeTxt, SLOT(clear()));
    //connect(ui->BtEnvoyer, SIGNAL(clicked()), this, SLOT(envoyer()));
    // PAVE NUMERIQUE
    connect(ui->num0Button, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->num0Button, "0");
    connect(ui->num1Button, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->num1Button, "1");
    connect(ui->num2Button, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->num2Button, "2");
    connect(ui->num3Button, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->num3Button, "3");
    connect(ui->num4Button, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->num4Button, "4");
    connect(ui->num5Button, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->num5Button, "5");
    connect(ui->num6Button, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->num6Button, "6");
    connect(ui->num7Button, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->num7Button, "7");
    connect(ui->num8Button, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->num8Button, "8");
    connect(ui->num9Button, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->num9Button, "9");
    //opERATEUR
    connect(ui->opPlusButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opPlusButton, "+");
    connect(ui->opMoinsButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opMoinsButton, "-");
    connect(ui->opVirguleButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opVirguleButton, ".");
    connect(ui->opSignButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opSignButton, "SIGN");
    connect(ui->opInvButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opInvButton, "INV");
    connect(ui->opFoisButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opFoisButton, "*");
    connect(ui->opDivButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opDivButton, "/");
    //connect(ui->BtExpression, SIGNAL(clicked()), mapper, SLOT(map()));
    //mapper->setMapping(ui->BtExpression, "'");
    connect(ui->opPowButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opPowButton, "^");
    //connect(ui->BtEspace, SIGNAL(clicked()), mapper, SLOT(map()));
   // mapper->setMapping(ui->BtEspace, " ");
    //FONCTION
    connect(ui->opFactButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opFactButton, "!");
    //connect(ui->BtComplexe, SIGNAL(clicked()), mapper, SLOT(map()));
    //mapper->setMapping(ui->BtComplexe, "$");
    //connect(ui->BtModulo, SIGNAL(clicked()), mapper, SLOT(map()));
    //mapper->setMapping(ui->BtModulo, "%");
    connect(ui->opPowButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opPowButton, "^");
    connect(ui->opSinButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opSinButton, "SIN");
    connect(ui->opSinhButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opSinhButton, "SINH");
    connect(ui->opCoshButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opCoshButton, "COSH");
    connect(ui->opCosButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opCosButton, "COS");
    connect(ui->opTanButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opTanButton, "TAN");
    connect(ui->opTanhButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opTanhButton, "TANH");
    connect(ui->opLnButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opLnButton, "LN");
    connect(ui->opLogButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opLogButton, "LOG");
    connect(ui->opSqrButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opSqrButton, "SQR");
    connect(ui->opSqrtButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opSqrtButton, "SQRT");
    connect(ui->opCubeButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opCubeButton, "CUBE");

//OPERATION SUR LA PILE

    //connect(ui->BtDUP, SIGNAL(clicked()), mapper, SLOT(map()));
    //mapper->setMapping(ui->BtDUP, "DUP");
    //connect(ui->BtDROP, SIGNAL(clicked()), mapper, SLOT(map()));
    //mapper->setMapping(ui->BtDROP, "DROP");
    //connect(ui->BtSWAP, SIGNAL(clicked()), mapper, SLOT(map()));
    //mapper->setMapping(ui->BtSWAP, "SWAP");
    //connect(ui->BtSUM, SIGNAL(clicked()), mapper, SLOT(map()));
    //mapper->setMapping(ui->BtSUM, "SUM");
    //connect(ui->BtMEAN, SIGNAL(clicked()), mapper, SLOT(map()));
    //mapper->setMapping(ui->BtMEAN, "MEAN");
    connect(ui->opEspaceButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opEspaceButton, " ");
    connect(ui->opEvalButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opEvalButton, "EVAL");
    connect(mapper, SIGNAL(mapped(QString)), this, SLOT(clickedBt(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::evaluate()
{
    QString txt = ui->display->text();

    if(txt.count("'")%2 != 0) return; //\todo il manque une quote
    if(txt.contains("$") && !this->leCalculateur->isComplexe()) return; //\todo vous n'êtes pas en mode complexe
    if(txt.isEmpty())
    {
        Command* duplicate = new CommandUnArg(this->leCalculateur,&Calculateur::duplicate);
        duplicate->Execute();
    }


    txt.replace("+"," + ");
    txt.replace("-"," - ");
    txt.replace("*"," * ");
    QString nb;
    QStringList list = txt.split(' ');

    foreach(QString str, list)
    {
      if(str.count(".")>0 && (this->leCalculateur->isEntier() || this->leCalculateur->isRationnel()))
      {
        //\todo warning : attention vous n'êtes pas en en mode reel
      }
      if(str.count(".")>1) return;//\todo throw exception

      if(str.count("$")>1) return;  //\todo throw exception

      if(str.count("/")>0 && (this->leCalculateur->isEntier() || this->leCalculateur->isReel()))
      {
        //\todo warning : attention vous n'êtes pas en mode rationnel
      }
      if(str.count("/")>0 && str.count("."))
      {
        //\todo erreur un rationnel est composé de deux entiers
          return;
      }
      if(str.count("/")>1) return;  //\todo throw exception
    }

    qDebug()<<list;
    int j=0;
    int i;
    foreach (QString str, list)
    {
        qDebug()<<str;
        qDebug()<<str;
        QChar* c = str.data();
        i = 0;
        qDebug()<<"tour "<<j<<" : "<<*c;
        if(c[i].isDigit())
        {

            Element* e;

            if(str.contains("$") && this->leCalculateur->isComplexe())
            {
                e = this->getComplexe(str);

            }
            else
            {
                e = this->getConstante (str);
            }
            CommandPush* push = new CommandPush(leCalculateur,e);
            push->Execute();
            qDebug()<<"test";
            ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            j++;
        }
        else
        {
            if(c[i]=='+')
            {
                CommandUnArg* addition =  new CommandUnArg(leCalculateur,&Calculateur::addition);
                addition->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            } else if(c[i]=='-')
            {
                CommandUnArg* soustraction =  new CommandUnArg(leCalculateur,&Calculateur::soustraction);
                soustraction->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(c[i]=='/')
            {
                CommandUnArg* division =  new CommandUnArg(leCalculateur,&Calculateur::division);
                division->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(c[i]=='*')
            {
                CommandUnArg* multiplication =  new CommandUnArg(leCalculateur,&Calculateur::multiplication);
                multiplication->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }

        }
    }
}

Element* MainWindow::getComplexe(QString str)
{
    Constante* e1 = getConstante(str.split("$")[0]);
    Constante* e2 = getConstante(str.split("$")[1]);
    return new Complexe(e1,e2);
}

Constante* MainWindow::getConstante(QString str)
{
    Constante* e;
    if(str.contains("."))
    {
        e = new Reel(str.toFloat());
        qDebug()<<"reel";
    }
    else if(str.contains("/"))
    {

        e = new Rationnel(str.split('/')[0].toInt(),str.split('/')[1].toInt());
        qDebug()<<"Rationnel";
    }
    else
    {
        e = new Entier(str.toInt());
        qDebug()<<"Entier";
    }
    Constante* res;
    if(this->leCalculateur->isEntier())
    {
        res = e->toEntier();
        delete e;
    }
    else if(this->leCalculateur->isRationnel())
    {
        res = e->toRationnel();
        delete e;
    }
    else if(this->leCalculateur->isReel())
    {
        res = e->toReel();
        qDebug()<<"transormatio en reel";
        qDebug()<<res->toQString();
    }
    else
    {
        res = e->toReel();
    }
    return res;

}

 void MainWindow::clickedBt(QString txt)
 {
     if (waitingForOperand) {
         ui->display->clear();
         waitingForOperand = false;
     }
     ui->display->setText(ui->display->text() + txt);
 }
