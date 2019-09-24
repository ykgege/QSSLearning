#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void initFrom();

signals:
    void sendCount(int);

private:
    Ui::MainWidget *ui;
    QStringList m_list;
};

#endif // MAINWIDGET_H
