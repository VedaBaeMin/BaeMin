#include "client.h"
#include <QDebug>

Client::Client(QObject *parent) : QObject(parent) {
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
}

void Client::connectToServer(const QString &host, quint16 port) {
    socket->connectToHost(host, port);
}

void Client::sendJson() {
    // JSON 문서 생성
    QJsonObject jsonObj;
    jsonObj["name"] = "John Doe";
    jsonObj["age"] = 30;

    QJsonDocument jsonDoc(jsonObj);
    QByteArray jsonData = jsonDoc.toJson();

    socket->write(jsonData);  // JSON 데이터 전송
}

void Client::onReadyRead() {
    QByteArray data = socket->readAll();
    qDebug() << "Received from server:" << data;
}
