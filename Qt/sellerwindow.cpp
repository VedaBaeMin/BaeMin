//
// Created by change10 on 24. 10. 25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_sellerwindow.h" resolved

#include "sellerwindow.h"
#include "ui_sellerwindow.h"


Sellerwindow::Sellerwindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::Sellerwindow) {
    ui->setupUi(this);
}

Sellerwindow::~Sellerwindow() {
    delete ui;
}
