#include "mainwindow.h"
#include <QGraphicsEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Login Form");
    this->resize(640,480);
    this->setStyleSheet("background-color:#e5ecef");
    this->setMinimumSize(300,250);
    wgt = new QWidget(this);
    wgt->setFixedSize(300,250);
    wgt->setStyleSheet("background-color:white; border-radius: 5px;");

    lay = new QGridLayout(this);

    linestyle = "QLineEdit{ border-width: 2px; border-style: solid; border-color:#e0e0e0; padding: 5px } "
                        "QLineEdit::focus {border-color:#4c83e0}";
    linestyleRed = "QLineEdit{ border-width: 2px; border-style: solid; border-color:#8b0000; color: #8b0000; padding: 5px } "
                     "QLineEdit::focus {border-color:#4c83e0}";
    QString buttonstyle = "QPushButton {background-color: #f6f6f6; color: #5c575e; font-weight: bold} "
                          "QPushButton::hover{background-color:#d6d6d6;} "
                          "QPushButton::pressed {background-color:#bbbbbb;}";

    login = new QLineEdit(this);
    login->setPlaceholderText("Логин");
    login->setStyleSheet(linestyle);
    login->setFixedSize(200,40);
    pass = new QLineEdit(this);
    pass->setPlaceholderText("Пароль");
    pass->setStyleSheet(linestyle);
    pass->setFixedSize(200,40);
    pass->setEchoMode(QLineEdit::Password);
    btn = new QPushButton("Вход",this);
    btn->setFixedSize(200,40);
    btn->setStyleSheet(buttonstyle);

    lay->addWidget(login,0,0);
    lay->addWidget(pass,1,0);
    lay->addWidget(btn,2,0);

    wgt->setLayout(lay);

    connect(btn, SIGNAL(clicked()), this, SLOT(checkStates()));

}

MainWindow::~MainWindow()
{
    delete wgt;
    delete login;
    delete pass;
    delete btn;
    delete lay;
}

void MainWindow::checkStates()
{
    if(login->text() == "login" && pass->text() == "password")
    {
        Animationtrue();
    }
    else{
        Animationfalse();
    }
}

void MainWindow::deleteWgt()
{
    wgt->close();
}

void MainWindow::deleteObj()
{
    login->close();
    pass->close();
    btn->close();
}

void MainWindow::resizeanim()
{
    wgt->move((this->size().width()-wgt->width()) / 2, (this->size().height()-wgt->height()) / 2);
    login->setStyleSheet(linestyle);
    pass->setStyleSheet(linestyle);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if(!wgt->isHidden()){
    wgt->move((event->size().width()-wgt->width()) / 2, (event->size().height()-wgt->height()) / 2);
    }
}

void MainWindow::Animationtrue()
{
    QGraphicsOpacityEffect  *eff1 = new QGraphicsOpacityEffect(this);
    login->setGraphicsEffect(eff1);
    pass->setGraphicsEffect(eff1);
    btn->setGraphicsEffect(eff1);

    QPropertyAnimation *anim1 = new QPropertyAnimation(eff1, "opacity");
    anim1->setDuration(400);
    anim1->setStartValue(1.0);
    anim1->setEndValue(0.0);

    QGraphicsOpacityEffect  *eff2 = new QGraphicsOpacityEffect(this);
    wgt->setGraphicsEffect(eff2);
    QPropertyAnimation *anim2 = new QPropertyAnimation(eff2, "opacity");
    anim2->setDuration(600);
    anim2->setStartValue(1.0);
    anim2->setEndValue(0.0);

    QSequentialAnimationGroup *group = new QSequentialAnimationGroup(this);
    group->addAnimation(anim1);
    group->addAnimation(anim2);
    group->start();

    connect(anim1, SIGNAL(finished()), this, SLOT(deleteObj()));
    connect(anim2, SIGNAL(finished()), this, SLOT(deleteWgt()));
}

void MainWindow::Animationfalse()
{
    login->setStyleSheet(linestyleRed);
    pass->setStyleSheet(linestyleRed);


    QPropertyAnimation *anim1 = new QPropertyAnimation(wgt, "pos");
    anim1->setDuration(50);
    anim1->setStartValue(QPoint(wgt->x(), wgt->y()));
    anim1->setEndValue(QPoint(wgt->x()-5, wgt->y()));
    QPropertyAnimation *anim2 = new QPropertyAnimation(wgt, "pos");
    anim2->setDuration(100);
    anim2->setStartValue(QPoint(wgt->x(), wgt->y()));
    anim2->setEndValue(QPoint(wgt->x()+10, wgt->y()));
    QPropertyAnimation *anim3 = new QPropertyAnimation(wgt, "pos");
    anim3->setDuration(50);
    anim3->setStartValue(QPoint(wgt->x(), wgt->y()));
    anim3->setEndValue(QPoint(wgt->x()-5, wgt->y()));
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup(this);
    group->addAnimation(anim1);
    group->addAnimation(anim2);
    group->addAnimation(anim3);
    group->start();
    connect(anim3, SIGNAL(finished()), this, SLOT(resizeanim()));

}

