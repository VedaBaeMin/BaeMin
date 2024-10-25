//
// Created by change10 on 24. 10. 25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"


Mainwindow::Mainwindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::Mainwindow) {
    ui->setupUi(this);
}

Mainwindow::~Mainwindow() {
    delete ui;
}
