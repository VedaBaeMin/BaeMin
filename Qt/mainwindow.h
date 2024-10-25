//
// Created by change10 on 24. 10. 25.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Mainwindow; }
QT_END_NAMESPACE

class Mainwindow : public QWidget {
Q_OBJECT

public:
    explicit Mainwindow(QWidget *parent = nullptr);
    ~Mainwindow() override;

private:
    Ui::Mainwindow *ui;
};


#endif //MAINWINDOW_H
