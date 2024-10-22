#include "server.h"
#include <QDebug>

Server::Server(QObject *parent) : QTcpServer(parent) {
    connect(this, &QTcpServer::newConnection, this, &Server::onNewConnection);
    listen(QHostAddress::Any, 12345);
}

void Server::onNewConnection() {
    clientSocket = nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    qDebug() << "Client connected:" << clientSocket->peerAddress().toString();
}

void Server::onReadyRead() {
    QByteArray data = clientSocket->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);

    if (!jsonDoc.isNull()) {
        qDebug() << "Received JSON:" << jsonDoc.toJson();
        // JSON 처리...
    } else {
        qDebug() << "Invalid JSON data.";
    }
}
