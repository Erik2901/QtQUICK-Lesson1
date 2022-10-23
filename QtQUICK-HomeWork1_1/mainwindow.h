#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QBoxLayout>
#include <QResizeEvent>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void checkStates();
    void deleteWgt();
    void deleteObj();
    void resizeanim();

protected:
    void resizeEvent(QResizeEvent * event);
    void Animationtrue();
    void Animationfalse();
private:
    QWidget *wgt;
    QLineEdit *login;
    QLineEdit *pass;
    QPushButton *btn;
    QGridLayout *lay;
    QString linestyle;
    QString linestyleRed;
};
#endif // MAINWINDOW_H
