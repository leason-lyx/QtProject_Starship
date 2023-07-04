#include "walkthrough_page1.h"
#include "ui_walkthrough_page1.h"

Walkthrough_page1::Walkthrough_page1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Walkthrough_page1)
{
    ui->setupUi(this);
}

Walkthrough_page1::~Walkthrough_page1()
{
    delete ui;
}
