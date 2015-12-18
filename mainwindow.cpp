#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setGeometry(400,300,400,400);
    mainWidget = new MainWidget(this);
    ui->centralWidget = mainWidget;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), mainWidget, SLOT(nextTact()));
    timer->start(100/24);
}

MainWindow::~MainWindow()
{
    delete ui;
}
