#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QPair>
#include <QStringList>
#include <QHBoxLayout>


class showWidget : public QWidget
{
    Q_OBJECT
//    Q_ENUMS(ControlType)
public:

//    enum ControlType{
//        LineEdit = 0,
//        Button = 1,
//        CheckBox = 2
//    };

    explicit showWidget(QWidget *parent = nullptr);
    ~showWidget();

    bool clearWidget();

    bool testStyleList();

signals:

public slots:

    void getIndex(int);

    void case_All(int);

    void case_LineEdit(int,QPair<int,QStringList>);
    void case_Button(int,QPair<int,QStringList>);
    void case_CheckBox(int,QPair<int,QStringList>);

    void initStyle(int);

    QStringList makeStyle(int);

    QStringList qss_LineEdit();
    QStringList qss_Button();
    QStringList qss_CheckBox();


private:
    int m_index;
    QHBoxLayout *m_layout;

    QList<QPair<int,QStringList>> m_styleList;

};

#endif // SHOWWIDGET_H
