#include "affichage.h"
#include "ui_affichage.h"
#include <QDEBUG>

Affichage::Affichage(QWidget *parent, MainWindow* mainWindow) :
    QTabWidget(parent),
    m_ui(new Ui::Affichage),
    calculatrice(mainWindow)

{
    m_ui->setupUi(this);
    m_ui->listStack->setCurrentRow(0);
    qDebug()<<m_ui->listStack->currentRow();
}

Affichage::~Affichage()
{
    delete m_ui;
}

void Affichage::changeEvent(QEvent *e)
{
    QTabWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
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
    m_ui->listStack->insertItem(0,data);
}

void Affichage::pop(QString data , QString ok )
{
    delete m_ui->listStack->item(0);
}

void Affichage::swap(QString data1, QString data2)
{   qDebug()<<"swap papa";
    QString item1 = m_ui->listStack->item(data1.toInt())->text();
    QString item2 = m_ui->listStack->item(data2.toInt())->text();
    m_ui->listStack->item(data1.toInt())->setText(item2);
    m_ui->listStack->item(data2.toInt())->setText(item1);}

void Affichage::afficheCommand(QString data){
      m_ui->listWidget_2->insertItem(0,data);
    }
void Affichage::popCommand(){
        delete m_ui->listWidget_2->item(0);
}

