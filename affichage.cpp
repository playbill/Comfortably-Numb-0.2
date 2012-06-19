#include "mainwindow.h"
#include "affichage.h"
#include "ui_affichage.h"
#include <QDEBUG>

Affichage::Affichage(QWidget *parent, MainWindow* mainWindow) :
    QTabWidget(parent),
    m_ui(new QVector<Ui::Affichage*>),
    calculatrice(mainWindow)

{   current = 0;
    nbtab = 0;
    Ui::Affichage* nouveau = new Ui::Affichage();
    m_ui->push_front(nouveau);
    m_ui->at(current)->setupUi(this);
    m_ui->at(current)->listStack->setCurrentRow(0);
     //connect(nouveau, SIGNAL(valueChanged(int)), this, SLOT(currentItem(current)));
     int nb = this->calculatrice->getCalculateur()->at(current)->getPile()->getPile().size();


            for (int i = nb -1 ; i >= 0; i--){
                    this->push(this->calculatrice->getCalculateur()->at(current)->getPile()->getPile().at(i)->toQString());
            }
}

Affichage::~Affichage()
{
    delete[] m_ui;
}

void Affichage::changeEvent(QEvent *e)
{
    QTabWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->at(current)->retranslateUi(this);
        break;
    default:
        break;
    }
}
void Affichage::update(QString data, QString ok )
{

}
void Affichage::push(QString data, QString ok )
{
    m_ui->at(current)->listStack->insertItem(0,data);
}

void Affichage::pop(QString data , QString ok )
{
    delete m_ui->at(current)->listStack->item(0);
}

void Affichage::swap(QString data1, QString data2)
{   qDebug()<<"swap papa";
    QString item1 = m_ui->at(current)->listStack->item(data1.toInt())->text();
    QString item2 = m_ui->at(current)->listStack->item(data2.toInt())->text();
    m_ui->at(current)->listStack->item(data1.toInt())->setText(item2);
    m_ui->at(current)->listStack->item(data2.toInt())->setText(item1);}

void Affichage::afficheCommand(QString data){
      m_ui->at(current)->listWidget_2->insertItem(0,data);
    }
void Affichage::popCommand(){
        delete m_ui->at(current)->listWidget_2->item(0);
}
void Affichage::addPile(){
    nbtab++;
    current = nbtab;
    Ui::Affichage* nouveau = new Ui::Affichage();
    //connect(nouveau, SIGNAL(currentChanged()), this, SLOT(currentItem(int)));
    m_ui->push_back(nouveau);
    m_ui->at(current)->setupUi(this);

}



