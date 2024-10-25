//
// Created by change10 on 24. 10. 25.
//

#ifndef SELLERWINDOW_H
#define SELLERWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class sellerwindow; }
QT_END_NAMESPACE

class sellerwindow : public QWidget {
Q_OBJECT

public:
    explicit sellerwindow(QWidget *parent = nullptr);
    ~sellerwindow() override;

private:
    Ui::sellerwindow *ui;
};


#endif //SELLERWINDOW_H
