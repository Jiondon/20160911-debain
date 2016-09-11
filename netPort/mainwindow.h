#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QByteArray m_arrayResult;
    QProcess *m_pProcess;
    QLabel *m_pLabel;

private slots:
    void slotUpdateNetInfo();
};

#endif // MAINWINDOW_H
