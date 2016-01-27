#include "mainwindow.h"
#include <QBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setGeometry(400,300,400,400);
    QVBoxLayout* layout = new QVBoxLayout();
    mainWidget = new MainWidget(this);

    //ui->centralWidget = mainWidgetn;

    QPushButton* btnRestart = new QPushButton(tr("Restart"));
    btnRestart->setGeometry(QRect(QPoint(10, 305), QSize(30, 20)));
    connect(btnRestart, SIGNAL (released()), this, SLOT (handleButton()));

    layout->addWidget(mainWidget);
    layout->addWidget(btnRestart);
    ui->centralWidget->setLayout(layout);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), mainWidget, SLOT(nextTact()));
    timer->start(8*100/24);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton() {
     mainWidget->restart();
}
