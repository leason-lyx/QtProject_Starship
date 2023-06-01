#include "mainwindow.h"
#include "gamewidget.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createGameWidget()
{
    gamewidget game=gamewidget(this);
    game.setFixedHeight(768);
    game.setFixedWidth(1024);
    game.show();
}

void MainWindow::on_pushButton_clicked()
{
    this->createGameWidget();
}

