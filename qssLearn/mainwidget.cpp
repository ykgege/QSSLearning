#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    m_list << "LineEdit" << "Button"<< "QCheckBox";

    connect(ui->listWidget,&QListWidget::currentRowChanged,ui->widget,&showWidget::getIndex);
    connect(this,&MainWidget::sendCount,ui->widget,&showWidget::initStyle);
    this->initFrom();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::initFrom()
{
    if(m_list.isEmpty()){
        qDebug()<<"The linked list is empty and cannot be added!";
        return;
    }
    foreach(QString item,m_list){
        ui->listWidget->addItem(item);
    }

    emit sendCount(ui->listWidget->count());

}
