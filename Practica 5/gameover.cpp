#include "gameover.h"
#include "ui_gameover.h"

Gameover::Gameover(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gameover)
{
    ui->setupUi(this);
}

Gameover::~Gameover()
{
    delete ui;
}
