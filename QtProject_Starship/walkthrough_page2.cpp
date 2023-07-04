#include "walkthrough_page2.h"
#include "ui_walkthrough_page2.h"

Walkthrough_page2::Walkthrough_page2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Walkthrough_page2)
{
    ui->setupUi(this);
}

Walkthrough_page2::~Walkthrough_page2()
{
    delete ui;
}
