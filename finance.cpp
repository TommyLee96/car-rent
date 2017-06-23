#include "finance.h"
#include "ui_finance.h"

finance::finance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finance)
{
    ui->setupUi(this);
}

finance::~finance()
{
    delete ui;
}
