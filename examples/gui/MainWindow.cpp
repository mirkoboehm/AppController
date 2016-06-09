#include <QApplication>

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect( ui->quit, SIGNAL( clicked() ), QApplication::instance(), SLOT( quit() ) );
    connect( ui->updateTime, SIGNAL( clicked() ), SIGNAL( requestTimeOfDay() ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveTimeOfDay(QString time)
{
    ui->label->setText( time );
}
