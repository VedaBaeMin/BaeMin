//
// Created by change10 on 24. 10. 24.
//

#include "server.h"
using namespace std;

Server::Server() {
    connect(this, &QTcpServer::newConnection, this, &Server::onNewConnection);
    listen(QHostAddress::Any, 1234);
}

void Server::onNewConnection() {
    QTcpSocket *clientSocket = nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &Server::onClientDisconnected);
    clients.append(clientSocket);
    cout << "A new client connected!"<<endl;
}

void Server::onReadyRead() {
    QTcpSocket *senderSocket = qobject_cast<QTcpSocket*>(sender());
    QByteArray data = senderSocket->readAll();

    // JSON 파싱
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject json = doc.object();
    string status = json["status"].toString().toStdString();
    string message = json["message"].toString().toStdString();
    cout<<"status : "<<status<<endl;
    cout<<"message : "<<message<<endl;
}

void Server::onClientDisconnected() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    clients.removeAll(clientSocket);
    clientSocket->deleteLater();
    cout << "A client disconnected!"<<endl;
}

#include "server.moc"