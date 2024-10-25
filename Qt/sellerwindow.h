//
// Created by change10 on 24. 10. 25.
//

#ifndef SELLERWINDOW_H
#define SELLERWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Sellerwindow; }
QT_END_NAMESPACE

class Sellerwindow : public QWidget {
Q_OBJECT

public:
    explicit Sellerwindow(QWidget *parent = nullptr);
    ~Sellerwindow() override;

private:
    Ui::Sellerwindow *ui;
};


#endif //SELLERWINDOW_H
