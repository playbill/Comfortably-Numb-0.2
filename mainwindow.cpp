#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),leCalculateur(new Calculateur())
{
    waitingForOperand = true;
    ui->setupUi(this);
    mapper = new QSignalMapper(this);
    if(this->leCalculateur->isComplexe())
    {
        ui->modeComplexe->setChecked(true);
    }
    if(this->leCalculateur->isEntier())
    {
        ui->modeEntier->setChecked(true);
    }
    else if(this->leCalculateur->isRationnel())
    {
        ui->modeRationnel->setChecked(true);
    }
    else if(this->leCalculateur->isReel())
    {
        ui->modeReel->setChecked(true);
    }
    else
    {
        ui->modeBestFit->setChecked(true);
    }
    if(this->leCalculateur->isDegre())
    {
        ui->modeDegre->setChecked(true);
    }
    if(this->leCalculateur->isRadian())
    {
        ui->modeRadiant->setChecked(true);
    }
    connect(ui->modeComplexe, SIGNAL(toggled(bool)), this, SLOT(toModeComplexe()));
    connect(ui->modeRationnel, SIGNAL(toggled(bool)), this, SLOT(toModeRationnel()));
    connect(ui->modeReel, SIGNAL(toggled(bool)), this, SLOT(toModeReel()));
    connect(ui->modeDegre, SIGNAL(toggled(bool)), this, SLOT(toModeDegre()));
    connect(ui->modeRadiant, SIGNAL(toggled(bool)), this, SLOT(toModeRadiant()));
    connect(ui->modeEntier, SIGNAL(toggled(bool)), this, SLOT(toModeEntier()));
    connect(ui->opEgalButton, SIGNAL(clicked()), this, SLOT(evaluate()));
    connect(ui->opEvalButton, SIGNAL(clicked()), this, SLOT(eval()));
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
    /**Operateur **/
    connect(ui->opPlusButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opPlusButton, " + ");
    connect(ui->opMoinsButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opMoinsButton, " - ");
    connect(ui->opPointButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opPointButton, ".");
    connect(ui->opSignButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opSignButton, " SIGN ");
    connect(ui->opInvButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opInvButton, " INV ");
    connect(ui->opFoisButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opFoisButton, " * ");
    connect(ui->opDivButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opDivButton, " / ");
    connect(ui->opExpressionButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opExpressionButton, " ' ");
    connect(ui->opPowButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opPowButton, " ^ ");

    //FONCTION
    connect(ui->opFactButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opFactButton, " ! ");
    connect(ui->complexeButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->complexeButton, "$");
    connect(ui->opModButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opModButton, " % ");
    connect(ui->opSinButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opSinButton, " SIN ");
    connect(ui->opSinhButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opSinhButton, " SINH ");
    connect(ui->opCoshButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opCoshButton, " COSH ");
    connect(ui->opCosButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opCosButton, " COS ");
    connect(ui->opTanButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opTanButton, " TAN ");
    connect(ui->opTanhButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opTanhButton, " TANH ");
    connect(ui->opLnButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opLnButton, " LN ");
    connect(ui->opLogButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opLogButton, " LOG ");
    connect(ui->opSqrButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opSqrButton, " SQR ");
    connect(ui->opSqrtButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opSqrtButton, " SQRT ");
    connect(ui->opCubeButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->opCubeButton, " CUBE ");

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


    //txt.replace("+"," + ");
    //txt.replace("-"," - ");
    //txt.replace("*"," * ");
    txt.simplified();
    QString nb;
    QStringList list = txt.split(' ');

    foreach(QString str, list)
    {
      if(str.count(".")>0 && (this->leCalculateur->isEntier() || this->leCalculateur->isRationnel()))
      {
        //\todo warning : attention vous n'êtes pas en en mode reel
      }

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
    bool expression = false;
    QString res;
    int i;
    foreach (QString str, list)
    {
        QChar* c = str.data();
        i = 0;
        if(str.compare("'")==0 && expression == true )
        {
            if(res.isEmpty())
            {
                //\todo trow_error
            }
            else
            {
                Expression* e = new Expression(res);
                CommandPush* push = new CommandPush(leCalculateur,e);
                push->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                res = "";
                expression = false;
            }
        }
        else if(str.compare("'")==0)
        {
            expression = true;
        }
        else if(expression == true)
        {
            res += " " + str;
        }
        else if(c[i].isDigit())
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
            else if(str.contains("sqrt", Qt::CaseInsensitive))
            {
                CommandUnArg* sqrt =  new CommandUnArg(leCalculateur,&Calculateur::sqrt);
                sqrt->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(str.contains("sqr", Qt::CaseInsensitive))
            {
                CommandUnArg* sqr =  new CommandUnArg(leCalculateur,&Calculateur::sqr);
                sqr->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(str.contains("cube", Qt::CaseInsensitive))
            {
                CommandUnArg* cube =  new CommandUnArg(leCalculateur,&Calculateur::cube);
                cube->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(c[i]=='!')
            {
                CommandDeuxArg* fact=  new CommandDeuxArg(leCalculateur,&Calculateur::fact);
                fact->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(c[i]=='%')
            {
                CommandDeuxArg* mod=  new CommandDeuxArg(leCalculateur,&Calculateur::mod);
                mod->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(c[i]=='^')
            {
                CommandDeuxArg* pow =  new CommandDeuxArg(leCalculateur,&Calculateur::pow);
                pow->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(str.contains("ln", Qt::CaseInsensitive))
            {
                CommandUnArg* ln =  new CommandUnArg(leCalculateur,&Calculateur::ln);
                ln->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(str.contains("log", Qt::CaseInsensitive))
            {
                CommandUnArg* log =  new CommandUnArg(leCalculateur,&Calculateur::log);
                log->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(str.contains("cosh", Qt::CaseInsensitive))
            {
                CommandUnArg* cosh =  new CommandUnArg(leCalculateur,&Calculateur::cosh);
                cosh->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(str.contains("cos", Qt::CaseInsensitive))
            {
                CommandUnArg* cos =  new CommandUnArg(leCalculateur,&Calculateur::cos);
                cos->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(str.contains("sinh", Qt::CaseInsensitive))
            {
                CommandUnArg* sinh =  new CommandUnArg(leCalculateur,&Calculateur::sinh);
                sinh->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(str.contains("sin", Qt::CaseInsensitive))
            {
                CommandUnArg* sin =  new CommandUnArg(leCalculateur,&Calculateur::sin);
                sin->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(str.contains("tanh", Qt::CaseInsensitive))
            {
                CommandUnArg* tanh =  new CommandUnArg(leCalculateur,&Calculateur::tanh);
                tanh->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(str.contains("tan", Qt::CaseInsensitive))
            {
                CommandUnArg* tan =  new CommandUnArg(leCalculateur,&Calculateur::tan);
                tan->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
            else if(str.contains("inv", Qt::CaseInsensitive))
            {
                CommandUnArg* inv =  new CommandUnArg(leCalculateur,&Calculateur::inv);
                inv->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
             else if(str.contains("sign", Qt::CaseInsensitive))
            {
                CommandUnArg* sign =  new CommandUnArg(leCalculateur,&Calculateur::sign);
                sign->Execute();
                ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }
        }
    }
}

void MainWindow::toModeEntier()
{
    this->leCalculateur->setToEntier();
}

void MainWindow::toModeReel()
{
    this->leCalculateur->setToReel();
}

void MainWindow::toModeRationnel()
{
    this->leCalculateur->setToRationnel();
}

void MainWindow::toModeRadiant()
{
    this->leCalculateur->setToRadian();
}

void MainWindow::toModeDegre()
{
    this->leCalculateur->setToDegre();
}

void MainWindow::toModeComplexe()
{
    if(!this->leCalculateur->isComplexe())
    {
        this->leCalculateur->setToComplexe();
    }
    else
    {
        this->leCalculateur->setToNoComplexe();
    }
}

void MainWindow::toModeBestFit()
{
    this->leCalculateur->setNoMode();
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
    }
    else if(str.contains("/"))
    {

        e = new Rationnel(str.split('/')[0].toInt(),str.split('/')[1].toInt());
    }
    else
    {
        e = new Entier(str.toInt());
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
    }
    else
    {
        res = e->toReel();
    }
    return res;

}

void MainWindow::eval()
{
    if(typeid(*this->leCalculateur->getPile()->top()) != typeid(Expression))
    {
        //\todo ce n'est pas une expression
         ui->display->setText(this->leCalculateur->getPile()->top()->toQString());

    }
    else
    {
        Element* exp = this->leCalculateur->pop();
        ui->display->setText(exp->toQString());
        this->evaluate();
    }
}

 void MainWindow::clickedBt(QString txt)
 {
     if (waitingForOperand) {
         qDebug()<<"passe par là";
         ui->display->clear();
         waitingForOperand = false;
     }
     ui->display->setText(ui->display->text() + txt);
 }
