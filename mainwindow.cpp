#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainWidget = new MainWidget(this);
    ui->centralWidget = mainWidget;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), mainWidget, SLOT(nextTact()));
    timer->start(300);
}

MainWindow::~MainWindow()
{
    delete ui;
}
