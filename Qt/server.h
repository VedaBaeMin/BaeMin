//
// Created by change10 on 24. 10. 24.
//

#ifndef SERVER_H
#define SERVER_H
#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

class Server : public QTcpServer {
    Q_OBJECT
private:
    QList<QTcpSocket*> clients;
public:
    Server();
private slots:
    void onNewConnection();
    void onReadyRead();
    void onClientDisconnected();
};



#endif //SERVER_H
