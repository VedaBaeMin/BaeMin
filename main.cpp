#include <iostream>
#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QLabel hello("Hello " ,0);
    hello.show();
    return app.exec();
}
