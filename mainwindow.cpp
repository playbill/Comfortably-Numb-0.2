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
    connect(ui->opDupButton, SIGNAL(clicked()), this, SLOT(duplicate()));
    connect(ui->opDropButton, SIGNAL(clicked()), this, SLOT(drop()));
    connect(ui->opClearButton, SIGNAL(clicked()), this, SLOT(clear()));
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
try{
        if(txt.count("'")%2 != 0)
        {
            throw std::logic_error( "Quote en nombre impair : verifier votre nombre de quote");
            return;
        }
        if(txt.contains("$") && !this->leCalculateur->isComplexe())
        {
            throw std::logic_error("Vous n'êtes pas en mode complexe");
            return;
        }
        if(txt.isEmpty())
        {   qDebug()<<"dup";
            this->duplicate();
            return;
        }

        txt.simplified();
        QString nb;
        QStringList list = txt.split(' ');

        foreach(QString str, list)
        {
          if(str.count(".")>0 && (this->leCalculateur->isEntier() || this->leCalculateur->isRationnel()))
          {
                        QMessageBox cast;
                        cast.setIcon(QMessageBox::Warning);
                        if(this->leCalculateur->isRationnel()){
                        cast.setText("Le nombre "+ str + " est un reel, la calculatrice en en mode Rationnel"); }
                        else{cast.setText("Le nombre "+ str + " est un reel, la calculatrice en en mode Entier");}
                        cast.setInformativeText("Que voulez-vous faire?");
                        QPushButton* annuler = cast.addButton(tr("Annuler"),QMessageBox::ActionRole);
                        QPushButton* modeReel = cast.addButton(tr("Mode Reel"),QMessageBox::ActionRole);
                        QPushButton* modeBestFit = cast.addButton(tr("Mode Best Fit"),QMessageBox::ActionRole);
                        QPushButton* caster = cast.addButton(tr("Caster"),QMessageBox::ActionRole);
                        cast.setDefaultButton(annuler);
                        cast.exec();
                        if (cast.clickedButton() == modeReel) {
                            this->leCalculateur->setToReel();
                            ui->modeReel->setChecked(true);
                        }
                        if (cast.clickedButton() == modeBestFit){
                            this->leCalculateur->setNoMode();
                            ui->modeBestFit->setChecked(true);
                        }
                        if (cast.clickedButton() == annuler){
                            return;
                        }
            }


          if(str.count("$")>1){
            throw std::logic_error("Il y a un complexe dans un complexe");
            return;
          }

          if(str.count("/")>0 && (this->leCalculateur->isEntier() || this->leCalculateur->isReel())){
                         QMessageBox cast;
                        cast.setIcon(QMessageBox::Warning);
                        if(this->leCalculateur->isReel()){
                        cast.setText("Le nombre "+ str + " est un rationnel, la calculatrice en en mode Reel"); }
                        else{cast.setText("Le nombre "+ str + " est un rationnel, la calculatrice en en mode Entier");}
                        cast.setInformativeText("Que voulez-vous faire?");
                        QPushButton* annuler = cast.addButton(tr("Annuler"),QMessageBox::ActionRole);
                        QPushButton* modeRationnel = cast.addButton(tr("Mode Rationnel"),QMessageBox::ActionRole);
                        QPushButton* modeBestFit = cast.addButton(tr("Mode Best Fit"),QMessageBox::ActionRole);
                        QPushButton* caster = cast.addButton(tr("Caster"),QMessageBox::ActionRole);
                        cast.setDefaultButton(annuler);
                        cast.exec();
                        if (cast.clickedButton() == modeRationnel) {
                            this->leCalculateur->setToRationnel();
                            ui->modeRationnel->setChecked(true);
                        }
                        if (cast.clickedButton() == modeBestFit){
                            this->leCalculateur->setNoMode();
                            ui->modeBestFit->setChecked(true);
                        }
                        if (cast.clickedButton() == annuler){
                            return;
                        }
          }
          if(str.count("/")>0 && str.count(".")){
            throw std::logic_error("Un rationnel est composé de deux entiers, pas de reel");
            return;
          }
          if(str.count("/")>1){
            throw std::logic_error("Un rationnel est composé de deux entiers, pas de rationnel");
            return;
          }
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
                    throw std::logic_error("Problème accolade : inclusion d'accolade, double accolade,...");
                    return;
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
                    if(this->leCalculateur->getPile()->size()<2){
                        throw std::logic_error("Il y a moins de 2 élements sur la pile");
                        return;
                    }
                    CommandUnArg* addition =  new CommandUnArg(leCalculateur,&Calculateur::addition);
                    addition->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                } else if(c[i]=='-')
                {
                    if(this->leCalculateur->getPile()->size()<2){
                        throw std::logic_error("Il y a moins de 2 élements sur la pile");
                        return;
                    }
                    CommandUnArg* soustraction =  new CommandUnArg(leCalculateur,&Calculateur::soustraction);
                    soustraction->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(c[i]=='/')
                {
                    if(this->leCalculateur->getPile()->size()<2){
                        throw std::logic_error("Il y a moins de 2 élements sur la pile");
                        return;
                    }
                    CommandUnArg* division =  new CommandUnArg(leCalculateur,&Calculateur::division);
                    division->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(c[i]=='*')
                {
                    if(this->leCalculateur->getPile()->size()<2){
                        throw std::logic_error("Il y a moins de 2 élements sur la pile");
                        return;
                    }
                    CommandUnArg* multiplication =  new CommandUnArg(leCalculateur,&Calculateur::multiplication);
                    multiplication->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("sqrt", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins d' 1 élements sur la pile");
                        return;
                    }
                    CommandUnArg* sqrt =  new CommandUnArg(leCalculateur,&Calculateur::sqrt);
                    sqrt->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("sqr", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                        return;
                    }
                    CommandUnArg* sqr =  new CommandUnArg(leCalculateur,&Calculateur::sqr);
                    sqr->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("cube", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins d' 1 élements sur la pile");
                        return;
                    }
                    CommandUnArg* cube =  new CommandUnArg(leCalculateur,&Calculateur::cube);
                    cube->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(c[i]=='!')
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                        return;
                    }
                    CommandUnArg* fact=  new CommandUnArg(leCalculateur,&Calculateur::fact);
                    fact->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                 else if(str.contains("swap", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<2){
                        throw std::logic_error("Il y a moins de 2 élements sur la pile");
                        return;
                    }
                    CommandDeuxArg* swap=  new CommandDeuxArg(leCalculateur,
                                                              this->leCalculateur->getPile()->getPile().top(),
                                                              this->leCalculateur->getPile()->getPile().at(this->leCalculateur->getPile()->size()-2),
                                                              &Calculateur::swap);
                    swap->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(c[i]=='%')
                {
                    if(this->leCalculateur->getPile()->size()<2){
                        throw std::logic_error("Il y a moins de 2 élements sur la pile");
                        return;
                    }
                    CommandDeuxArg* mod=  new CommandDeuxArg(leCalculateur,
                                                             this->leCalculateur->getPile()->top(),
                                                             this->leCalculateur->getPile()->getPile().at(this->leCalculateur->getPile()->getPile().size()-2),
                                                             &Calculateur::mod);
                    mod->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(c[i]=='^')
                {
                    if(this->leCalculateur->getPile()->size()<2){
                        throw std::logic_error("Il y a moins de 2 élements sur la pile");
                        return;
                    }
                    CommandDeuxArg* pow =  new CommandDeuxArg(leCalculateur,
                                                             this->leCalculateur->getPile()->top(),
                                                             this->leCalculateur->getPile()->getPile().at(this->leCalculateur->getPile()->getPile().size()-2),
                                                             &Calculateur::pow);
                    pow->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("ln", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                        return;
                    }
                    CommandUnArg* ln =  new CommandUnArg(leCalculateur,&Calculateur::ln);
                    ln->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("log", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                        return;
                    }
                    CommandUnArg* log =  new CommandUnArg(leCalculateur,&Calculateur::log);
                    log->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("cosh", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                        return;
                    }
                    CommandUnArg* cosh =  new CommandUnArg(leCalculateur,&Calculateur::cosh);
                    cosh->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("cos", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                        return;
                    }
                    CommandUnArg* cos =  new CommandUnArg(leCalculateur,&Calculateur::cos);
                    cos->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("sinh", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                        return;
                    }
                    CommandUnArg* sinh =  new CommandUnArg(leCalculateur,&Calculateur::sinh);
                    sinh->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("mean", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                    }
                    if(typeid(*this->leCalculateur->getPile()->top())!=typeid(Entier))
                    {
                        QMessageBox cast;
                        cast.setIcon(QMessageBox::Warning);
                        cast.setText("Le nombre n'est pas un entier");
                        cast.setInformativeText("Voulez-vous le casté?");
                        QPushButton* annuler = cast.addButton(tr("Annuler"),QMessageBox::RejectRole);
                        QPushButton* caster = cast.addButton(tr("Caster"),QMessageBox::AcceptRole);
                        cast.setDefaultButton(annuler);
                        int ret = cast.exec();
                        qDebug()<<ret;
                         if(ret == 1){
                            Element* tmp = this->leCalculateur->getPile()->pop();
                                  Entier* e = tmp->toEntier();
                                  this->leCalculateur->getPile()->push(e);
                                  delete tmp;}

                    }
                    if(this->leCalculateur->getPile()->top()->getXAsInt() >= this->leCalculateur->getPile()->size())
                    {
                        throw std::logic_error("L'argument est supérieur au nombre d'élément sur la pile");
                    }
                    else if(typeid(*this->leCalculateur->getPile()->top()) == typeid(Entier))
                    {
                        qDebug()<<this->leCalculateur->getPile()->top()->toQString();
                        CommandPolyArg* mean =  new CommandPolyArg(leCalculateur,this->leCalculateur->getPile()->top()->getXAsInt(),1,&Calculateur::mean);
                        //qDebug()<<passe par là";
                        mean->Execute();
                        ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                    }
                    else
                    {
                        throw std::logic_error("L'argument n'est pas de type entier");
                    }
                }
                else if(str.contains("sum", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                    }
                    if(typeid(*this->leCalculateur->getPile()->top())!=typeid(Entier))
                    {
                        QMessageBox cast;
                        cast.setIcon(QMessageBox::Warning);
                        cast.setText("Le nombre n'est pas un entier");
                        cast.setInformativeText("Voulez-vous le casté?");
                        QPushButton* annuler = cast.addButton(tr("Annuler"),QMessageBox::RejectRole);
                        QPushButton* caster = cast.addButton(tr("Caster"),QMessageBox::AcceptRole);
                        cast.setDefaultButton(annuler);
                        int ret = cast.exec();
                        qDebug()<<ret;
                         if(ret == 1){
                            Element* tmp = this->leCalculateur->getPile()->pop();
                                  Entier* e = tmp->toEntier();
                                  this->leCalculateur->getPile()->push(e);
                                  delete tmp;}

                    }
                    if(this->leCalculateur->getPile()->top()->getXAsInt() >= this->leCalculateur->getPile()->size())
                    {
                        throw std::logic_error("L'argument est supérieur au nombre d'élément sur la pile");
                    }
                    else if(typeid(*this->leCalculateur->getPile()->top()) == typeid(Entier))
                    {
                        qDebug()<<this->leCalculateur->getPile()->top()->toQString();
                        CommandPolyArg* sum =  new CommandPolyArg(leCalculateur,this->leCalculateur->getPile()->top()->getXAsInt(),1,&Calculateur::sum);
                        sum->Execute();
                        ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                    }
                    else
                    {
                        throw std::logic_error("L'argument n'est pas de type entier");
                    }
                }
                else if(str.contains("sin", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                    }
                    CommandUnArg* sin =  new CommandUnArg(leCalculateur,&Calculateur::sin);
                    sin->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("tanh", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                    }
                    CommandUnArg* tanh =  new CommandUnArg(leCalculateur,&Calculateur::tanh);
                    tanh->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("tan", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                    }
                    CommandUnArg* tan =  new CommandUnArg(leCalculateur,&Calculateur::tan);
                    tan->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("inv", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                    }
                    CommandUnArg* inv =  new CommandUnArg(leCalculateur,&Calculateur::inv);
                    inv->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                 else if(str.contains("sign", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                    }
                    CommandUnArg* sign =  new CommandUnArg(leCalculateur,&Calculateur::sign);
                    sign->Execute();
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                 else if(str.isEmpty())
                 {

                 }
                 else
                 {
                     throw std::logic_error("Ce n'est pas une entrée valide");
                 }
            }
        }
    }catch(std::logic_error e){
        ui->displaytop->setText(e.what());
    }
qDebug()<<"yo";
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
        res = e->clone();
    }
    return res;

}

void MainWindow::eval()
{
    try
    {
        if(this->leCalculateur->getPile()->getPile().isEmpty())
        {   qDebug()<<"on est là";
            throw std::logic_error("La pile est vide");
        }
        else if(typeid(*this->leCalculateur->getPile()->top()) != typeid(Expression))
        {
            ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            throw std::logic_error("Ce n'est pas une expression");
        }
        else
        {
            Element* exp = this->leCalculateur->pop();
            ui->display->setText(exp->toQString());
            this->evaluate();
        }
    }
    catch(std::logic_error e)
    {
        ui->displaytop->setText(e.what());
    }

}

 void MainWindow::clickedBt(QString txt)
 {
     if (waitingForOperand) {
         ui->display->clear();
         waitingForOperand = false;
     }
     ui->display->setText(ui->display->text() + txt);
 }

 void MainWindow::duplicate()
 {  qDebug()<<"dup2";
     try{
    if(!this->leCalculateur->getPile()->getPile().isEmpty())
    {   qDebug()<<"là";
        CommandUnArg* duplicate = new CommandUnArg(leCalculateur,&Calculateur::duplicate);
        duplicate->Execute();
        ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
    }
    else
    {
        throw std::logic_error("La pile est vide");
        return;
    }}catch(std::logic_error &e){this->ui->displaytop->setText(e.what());}
 }

 void MainWindow::drop()
 {try{
    if(!this->leCalculateur->getPile()->getPile().isEmpty())
    {
        CommandUnArg* drop = new CommandUnArg(leCalculateur,&Calculateur::drop);
        drop->Execute();
        ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
    }
    else
    {
        throw std::logic_error("La pile est vide");
    }}catch(std::logic_error &e){this->ui->displaytop->setText(e.what());}
 }

 void MainWindow::clear()
 {

        CommandPolyArg* clear = new CommandPolyArg(leCalculateur,leCalculateur->getPile()->getPile().size(),0,&Calculateur::clear);
        clear->Execute();
        ui->display->setText("0");
        this->waitingForOperand = true;

 }
