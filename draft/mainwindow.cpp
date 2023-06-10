#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDialog>
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

    QPixmap pix(":/img/1674271836_catherineasquithgallery_com_p_fon_sport_serii_foto_23.png");
    int w = ui->pic->width();
    int h = ui->pic->height();
    ui->pic->setPixmap(pix.scaled(w, h));

    sWindow = new authorisation();

    connect(sWindow, &authorisation::firstWindow, this, &MainWindow::show);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    sWindow ->show();
    this->close();
}


void MainWindow::on_actionInfo_triggered()
{
    QDialog* logoDialog = new QDialog(this);
    QLabel* logoLabel = new QLabel(logoDialog);
    QPixmap pix(":/img/0_2.png");
    int logoWidth = pix.width() / 2;
    int logoHeight = pix.height() / 2;
    QPixmap scaledPix = pix.scaled(logoWidth, logoHeight);
    logoLabel->setPixmap(scaledPix);
    QVBoxLayout* layout = new QVBoxLayout(logoDialog);
    layout->addWidget(logoLabel);
    logoDialog->setLayout(layout);
    logoDialog->exec();
    delete logoDialog;

    QMessageBox::about(this,"About Program", "Student#1609: This application keeps track of purchases of all treadmills of the company. It helps workers to store and analyze the sale of products.");
}


void MainWindow::on_actionLogo_triggered()
{
    QDialog* logoDialog = new QDialog(this);
    QLabel* logoLabel = new QLabel(logoDialog);
    QPixmap pix(":/img/0_2.png");
    int logoWidth = pix.width() / 2;
    int logoHeight = pix.height() / 2;
    QPixmap scaledPix = pix.scaled(logoWidth, logoHeight);
    logoLabel->setPixmap(scaledPix);
    QVBoxLayout* layout = new QVBoxLayout(logoDialog);
    layout->addWidget(logoLabel);
    logoDialog->setLayout(layout);
    logoDialog->exec();
    delete logoDialog;
}
