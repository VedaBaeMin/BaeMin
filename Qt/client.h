//
// Created by change10 on 24. 10. 24.
//

#ifndef CLIENT_H
#define CLIENT_H
#include <QCoreApplication>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

class Client : public QObject {
    Q_OBJECT
private:
    QTcpSocket *socket;
    QByteArray json;
public:
    Client(QByteArray json);
private slots:
    void onConnected();
};


#endif //CLIENT_H
