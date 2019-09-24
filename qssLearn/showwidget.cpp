#include "showwidget.h"
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>

showWidget::showWidget(QWidget *parent) :
    QWidget(parent),
    m_index(1000000)
{
    m_layout = new QHBoxLayout();

    //setLayout(m_layout);
    this->setLayout(m_layout);
}

showWidget::~showWidget()
{

}

bool showWidget::clearWidget()
{
    if(m_layout->count() != 0){
        QLayoutItem *child;
         while ((child = m_layout->takeAt(0)) != 0)
         {
                //setParent为NULL，防止删除之后界面不消失
                if(child->widget())
                {
                    child->widget()->setParent(NULL);
                }

                delete child;
         }
         return true;

    }else if (m_layout->count() == 0) {
        return true;
    }
    return false;
}

bool showWidget::testStyleList()
{
    if(m_styleList.isEmpty()){
        qDebug()<<"m_styleList initialization failed";
        return false;
    }
    return true;
}

void showWidget::getIndex(int index)
{
    if(m_index == index){
        return;
    }
    m_index = index;

    this->case_All(index);
}

void showWidget::case_All(int index)
{
    QPair<int,QStringList> style;
    if(this->clearWidget() != true){
        qDebug()<<"case_LineEdit is false";
        return;
    }

    bool flag = this->testStyleList();
    if(!flag){
        return;
    }
    style = m_styleList.at(index);
    switch (index) {
    case 0:
        this->case_LineEdit(index,style);
        break;
    case 1:
        this->case_Button(index,style);
        break;
    case 2:
        this->case_CheckBox(index,style);
        break;
    default:
        qDebug()<<"An error occurred";
    }
}

void showWidget::case_LineEdit(int index,QPair<int,QStringList> style)
{
    for (int i= 0;i<style.second.count();i++) {
        QLineEdit *edit = new QLineEdit;
        edit->setStyleSheet(style.second.at(i));
        m_layout->addWidget(edit);
    }
}

void showWidget::case_Button(int index,QPair<int,QStringList> style)
{
    for (int i= 0;i<style.second.count();i++) {
        QPushButton *button = new QPushButton("Format");
        button->setStyleSheet(style.second.at(i));
        m_layout->addWidget(button);
    }
}

void showWidget::case_CheckBox(int index,QPair<int,QStringList> style)
{
    for (int i= 0;i<style.second.count();i++) {
        QCheckBox *check = new QCheckBox;
        check->setStyleSheet(style.second.at(i));
        m_layout->addWidget(check);
    }
}



void showWidget::initStyle(int count)
{
    QPair<int,QStringList> style;

    for (int i = 0;i<=count;i++) {
        style.first = i;
        QStringList content = this->makeStyle(i);
        style.second = content;
        m_styleList.append(style);
    }

}

QStringList showWidget::makeStyle(int index)
{
    QStringList style;
    switch (index) {
    case 0:
        style = qss_LineEdit();
        break;
    case 1:
        style = qss_Button();
        break;
    case 2:
        style = qss_CheckBox();
        break;

    default:
        qDebug()<<"makeStyle...";
    }

    return style;
}


QStringList showWidget::qss_LineEdit()
{
    QStringList qss;
    qss.append(QString("QLineEdit{color: blue;background-color: yellow;selection-color:yellow;selection-background-color:blue;}"));
    qss.append(QString("QLineEdit{color: yellow;background-color: blue;}"));
    return qss;
}

QStringList showWidget::qss_Button()
{
    QStringList qss;
    qss.append(QString("QPushButton{background-color: red;"
                       "border-style: outset;"
                       "border-width: 2px;"
                       "border-radius: 10px;"
                       "border-color: beige;"
                       "font: bold 14px; "
                       "min-width: 10em; "
                       "padding: 6px; }"
                       "QPushButton:pressed {"
                       "background-color: rgb(224, 0, 0);"
                       "border-style: inset;}"));
    return qss;
}

QStringList showWidget::qss_CheckBox()
{
    QStringList qss;

    return qss;
}
