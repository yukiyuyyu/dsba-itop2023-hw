#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "authorisation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


    void on_actionInfo_triggered();

    void on_actionLogo_triggered();

private:
    Ui::MainWindow *ui;
    authorisation *sWindow;

};
#endif // MAINWINDOW_H
