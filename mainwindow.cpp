#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qlabel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
   // mainWidget(new MainWidget(this))
{
    ui->setupUi(this);
    mainWidget = new MainWidget(this);
    ui->centralWidget = mainWidget;
}

MainWindow::~MainWindow()
{
    delete ui;
}
