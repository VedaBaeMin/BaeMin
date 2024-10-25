//
// Created by change10 on 24. 10. 25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_loginwindow.h" resolved

#include "loginwindow.h"
#include "ui_loginwindow.h"


Loginwindow::Loginwindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Loginwindow) {
    ui->setupUi(this);
}

Loginwindow::~Loginwindow() {
    delete ui;
}
