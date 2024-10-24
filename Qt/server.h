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
#include <QMutex>
#include <QWaitCondition>

class Server : public QTcpServer {
    Q_OBJECT
private:
    QList<QTcpSocket*> clients;
    QByteArray request;
    bool r_flag=false;
    QMutex mutex; // 데이터 보호를 위한 뮤텍스
    QWaitCondition condition; // 대기 조건
public:
    Server();
    QByteArray getRequest();
private slots:
    void onNewConnection();
    void onReadyRead();
    void onClientDisconnected();
};



#endif //SERVER_H
