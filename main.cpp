#include <iostream>
#include "User/Type/Customer/Customer.h"
#include "User/Type/Seller/Seller.h"
#include "User/Service/UserService.h"
#include "Food/Request/FoodRequest.h"
#include "Food/Service/FoodService.h"
#include "Order/Service/OrderService.h"
#include "User/Type/Customer/NewbieUser.h"
#include <QApplication>
#include <QWidget>
#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include "Qt/client.h"
#include "Qt/server.h"
#include "loginwindow.h"
#include "mainwindow.h"
#include "sellerwindow.h"

using namespace std;
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    /*Server s;

    FreshFood test(111,1000,"사과");
    Client c(test.makeRequest());

    QByteArray byte = s.getRequest();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byte);
    QJsonObject jsonObj = jsonDoc.object();

    int foodid=static_cast<int>(jsonObj["foodId"].toInt());
    int price=jsonObj["price"].toInt();
    string foodName=jsonObj["foodName"].toString().toStdString();

    cout <<"receive foodid : "<<foodid<<endl;
    cout <<"receive price : "<<price<<endl;
    cout <<"receive foodName : "<<foodName<<endl;*/
    Mainwindow login;
    login.show();

    return a.exec();
}