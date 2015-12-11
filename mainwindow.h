#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwidget.h"
#include "ui_mainwindow.h"
#include "qlabel.h"
#include "QTimer"
#include "constants.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MainWidget *mainWidget;
    int a;
};

#endif // MAINWINDOW_H
