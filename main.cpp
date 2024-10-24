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
#include <unistd.h>

using namespace std;
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    cout<<"hello\n";
    Server s;

    QJsonObject responseObj;
    responseObj["status"] = "ok";
    responseObj["message"] = "Data send";
    QJsonDocument responseDoc(responseObj);

    Client c(responseDoc.toJson());

    sleep(3);
    QByteArray byte = s.getRequest();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byte);
    QJsonObject jsonObj = jsonDoc.object();
    string status=jsonObj["status"].toString().toStdString();
    string message=jsonObj["message"].toString().toStdString();
    cout <<"receive statue : "<<status<<endl;
    cout <<"receive message : "<<message<<endl;

    return a.exec();
}