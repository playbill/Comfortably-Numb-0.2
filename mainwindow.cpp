#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),leCalculateur(new Calculateur()),pileCommande(new GestionCommande())
{
    this->view = new Affichage(parent,this);
    this->leCalculateur->getPile()->addAffichage(view);
    this->pileCommande->addAffichage(view);
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
    connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered()), this, SLOT(redo()));
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
                    this->pileCommande->getUndo()->push(push);
                    this->pileCommande->afficheCommand(push);
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
                this->pileCommande->getUndo()->push(push);
                this->pileCommande->afficheCommand(push);
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
                    CommandDeuxArg* addition =  new CommandDeuxArg(leCalculateur,
                                                                    this->leCalculateur->getPile()->getPile().top(),
                                                                    this->leCalculateur->getPile()->getPile().at(this->leCalculateur->getPile()->size()-2),
                                                                   &Calculateur::addition);
                    addition->Execute();
                     this->pileCommande->getUndo()->push(addition);
                     this->pileCommande->afficheCommand(addition);
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                } else if(c[i]=='-')
                {
                    if(this->leCalculateur->getPile()->size()<2){
                        throw std::logic_error("Il y a moins de 2 élements sur la pile");
                        return;
                    }
                    CommandDeuxArg* soustraction =  new CommandDeuxArg(leCalculateur,
                                                                        this->leCalculateur->getPile()->getPile().top(),
                                                                        this->leCalculateur->getPile()->getPile().at(this->leCalculateur->getPile()->size()-2),
                                                                       &Calculateur::soustraction);
                    soustraction->Execute();
                     this->pileCommande->getUndo()->push(soustraction);
                     this->pileCommande->afficheCommand(soustraction);
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(c[i]=='/')
                {
                    if(this->leCalculateur->getPile()->size()<2){
                        throw std::logic_error("Il y a moins de 2 élements sur la pile");
                        return;
                    }
                    CommandDeuxArg* division =  new CommandDeuxArg(leCalculateur,
                                                                    this->leCalculateur->getPile()->getPile().top(),
                                                                    this->leCalculateur->getPile()->getPile().at(this->leCalculateur->getPile()->size()-2),
                                                                   &Calculateur::division);
                    division->Execute();
                     this->pileCommande->getUndo()->push(division);
                     this->pileCommande->afficheCommand(division);
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(c[i]=='*')
                {
                    if(this->leCalculateur->getPile()->size()<2){
                        throw std::logic_error("Il y a moins de 2 élements sur la pile");
                        return;
                    }
                    CommandDeuxArg* multiplication =  new CommandDeuxArg(leCalculateur,
                                                                        this->leCalculateur->getPile()->getPile().top(),
                                                                        this->leCalculateur->getPile()->getPile().at(this->leCalculateur->getPile()->size()-2),
                                                                         &Calculateur::multiplication);
                    multiplication->Execute();
                    this->pileCommande->getUndo()->push(multiplication);
                    this->pileCommande->afficheCommand(multiplication);
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
                     this->pileCommande->getUndo()->push(sqrt);
                     this->pileCommande->afficheCommand(sqrt);
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
                     this->pileCommande->getUndo()->push(sqr);
                     this->pileCommande->afficheCommand(sqr);
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
                     this->pileCommande->getUndo()->push(cube);
                     this->pileCommande->afficheCommand(cube);
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
                     this->pileCommande->getUndo()->push(fact);
                     this->pileCommande->afficheCommand(fact);
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                 else if(str.contains("swap", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<2){
                        throw std::logic_error("Il y a moins de 2 élements sur la pile");
                    }
                    if(typeid(*this->leCalculateur->getPile()->top()) != typeid(Entier)){
                        throw std::logic_error("Le premier élément n'est pas un entier");
                    }
                    if(typeid(*this->leCalculateur->getPile()->getPile().at(this->leCalculateur->getPile()->size()-2)) != typeid(Entier)){
                        throw std::logic_error("Le deuxième élément n'est pas un entier");
                    }
                    if(this->leCalculateur->getPile()->top()->getXAsInt() > this->leCalculateur->getPile()->size()-3){
                        throw std::logic_error("Le premier élément est un indice non valable (les indices commencent à 0)");
                    }
                    if(this->leCalculateur->getPile()->getPile().at(this->leCalculateur->getPile()->size()-2)->getXAsInt() > this->leCalculateur->getPile()->size()-4){
                        throw std::logic_error("Le deuxième élément est un indice non valable (les indices commencent à 0)");
                    }

                    CommandDeuxArg* swap=  new CommandDeuxArg(leCalculateur,
                                                              this->leCalculateur->getPile()->getPile().top(),
                                                              this->leCalculateur->getPile()->getPile().at(this->leCalculateur->getPile()->size()-2),
                                                              &Calculateur::swap);
                    swap->Execute();
                     this->pileCommande->getUndo()->push(swap);
                     this->pileCommande->afficheCommand(swap);
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
                     this->pileCommande->getUndo()->push(mod);
                     this->pileCommande->afficheCommand(mod);
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
                     this->pileCommande->getUndo()->push(pow);
                     this->pileCommande->afficheCommand(pow);
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
                     this->pileCommande->getUndo()->push(ln);
                     this->pileCommande->afficheCommand(ln);
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
                     this->pileCommande->getUndo()->push(log);
                     this->pileCommande->afficheCommand(log);
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
                     this->pileCommande->getUndo()->push(cosh);
                     this->pileCommande->afficheCommand(cosh);
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
                     this->pileCommande->getUndo()->push(cos);
                     this->pileCommande->afficheCommand(cos);
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
                     this->pileCommande->getUndo()->push(sinh);
                     this->pileCommande->afficheCommand(sinh);
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
                         this->pileCommande->getUndo()->push(mean);
                         this->pileCommande->afficheCommand(mean);
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
                         this->pileCommande->getUndo()->push(sum);
                         this->pileCommande->afficheCommand(sum);
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
                     this->pileCommande->getUndo()->push(sin);
                     this->pileCommande->afficheCommand(sin);
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("tanh", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                    }
                    CommandUnArg* tanh =  new CommandUnArg(leCalculateur,&Calculateur::tanh);
                    tanh->Execute();
                     this->pileCommande->getUndo()->push(tanh);
                     this->pileCommande->afficheCommand(tanh);
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("tan", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                    }
                    CommandUnArg* tan =  new CommandUnArg(leCalculateur,&Calculateur::tan);
                    tan->Execute();
                     this->pileCommande->getUndo()->push(tan);
                     this->pileCommande->afficheCommand(tan);
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                else if(str.contains("inv", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                    }
                    CommandUnArg* inv =  new CommandUnArg(leCalculateur,&Calculateur::inv);
                    inv->Execute();
                     this->pileCommande->getUndo()->push(inv);
                     this->pileCommande->afficheCommand(inv);
                    ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
                }
                 else if(str.contains("sign", Qt::CaseInsensitive))
                {
                    if(this->leCalculateur->getPile()->size()<1){
                        throw std::logic_error("Il y a moins de 1 élements sur la pile");
                    }
                    CommandUnArg* sign =  new CommandUnArg(leCalculateur,&Calculateur::sign);
                    sign->Execute();
                     this->pileCommande->getUndo()->push(sign);
                     this->pileCommande->afficheCommand(sign);
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
        res = e->toReel();
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
        this->pileCommande->getUndo()->push(duplicate);
        this->pileCommande->afficheCommand(duplicate);
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
    {   qDebug()<<"drop";
        CommandUnArg* drop = new CommandUnArg(leCalculateur,&Calculateur::drop);
        drop->Execute();
         this->pileCommande->getUndo()->push(drop);
         this->pileCommande->afficheCommand(drop);
        if(!this->leCalculateur->getPile()->getPile().isEmpty()){
        ui->display->setText(this->leCalculateur->getPile()->top()->toQString());
            }else{
        ui->display->setText(QString::number(0));}

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
         this->pileCommande->getUndo()->push(clear);
         this->pileCommande->afficheCommand(clear);
        ui->display->setText("0");
        this->waitingForOperand = true;

 }
 void MainWindow::undo(){
 try{
     if(this->pileCommande->getUndo()->isEmpty()){
   throw std::logic_error("Aucune action à annuler");
 }

 Command* tmp = this->pileCommande->getUndo()->pop();
 if(typeid(*tmp)==typeid(CommandUnArg))
 {
    CommandUnArg* c = dynamic_cast<CommandUnArg*>(tmp);
    delete this->leCalculateur->pop();
    this->leCalculateur->push(c->getArg()->clone());
    this->pileCommande->getRedo()->push(c);
    this->pileCommande->popCommand();
 }
 else if(typeid(*tmp)==typeid(CommandPush))
 {
     this->pileCommande->getRedo()->push(tmp);
     this->pileCommande->popCommand();
      this->leCalculateur->pop();
 }
  else if(typeid(*tmp)==typeid(CommandDeuxArg))
 {
    CommandDeuxArg* c = dynamic_cast<CommandDeuxArg*>(tmp);
    delete this->leCalculateur->pop();
    this->leCalculateur->push(c->getArg1()->clone());
    this->leCalculateur->push(c->getArg2()->clone());
    this->pileCommande->getRedo()->push(c);
    this->pileCommande->popCommand();
 }
    else if(typeid(*tmp)==typeid(CommandPolyArg))
 {
    CommandPolyArg* c = dynamic_cast<CommandPolyArg*>(tmp);
    delete this->leCalculateur->pop();
    for(unsigned int i = 0; i<c->getN(); i++){
    this->leCalculateur->push(c->getArg(i)->clone());
    }
    this->pileCommande->getRedo()->push(c);
    this->pileCommande->popCommand();
 }}catch(std::logic_error & e){ui->displaytop->setText(e.what());}

 }

 void MainWindow::redo(){
     try{
     if(this->pileCommande->getRedo()->isEmpty()){
   throw std::logic_error("Aucune action à relancer");
 }
 else{
 Command * c = this->pileCommande->getRedo()->pop();
 c->Execute();
 this->pileCommande->afficheCommand(c);
 }
}catch(std::logic_error & e){ui->displaytop->setText(e.what());}
 }
void MainWindow::show(){
     view->show();
    QWidget::show();

}
