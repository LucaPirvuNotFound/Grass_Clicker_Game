#include "testqt.h"
#include "ui_testqt.h"

TestQt::TestQt(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestQt)
{
    ui->setupUi(this);
}

TestQt::~TestQt()
{
    delete ui;
}
