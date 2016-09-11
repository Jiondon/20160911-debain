#include "mainwindow.h"
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    timer->setSingleShot(false);
    connect(timer,SIGNAL(timeout()),this,SLOT(slotUpdateNetInfo()));
    timer->start();

    m_pProcess = new QProcess(this);
    QString program;
    program = "sar";
    QStringList arguments;
       arguments << "-n" << "DEV"<<"1"<<"100";
    m_pProcess->start(program, arguments);
    m_arrayResult = m_pProcess->readAll();
    qDebug()<<"get sar  result::: "<<m_arrayResult;
    m_pLabel = new QLabel(this);
    m_pLabel->resize(300,100);
}

MainWindow::~MainWindow()
{

}

void MainWindow::slotUpdateNetInfo()
{

    QString program;
    program = "sar";
    QStringList arguments;
       arguments << "-n" << "DEV"<<"1"<<"100";
    m_pProcess->start(program, arguments);
    m_arrayResult = m_pProcess->readAll();
    qDebug()<<"get sar  result::: "<<m_arrayResult;
    m_pLabel->setText(m_arrayResult);
}
