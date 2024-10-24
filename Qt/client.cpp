//
// Created by change10 on 24. 10. 24.
//

#include "client.h"
using namespace std;

Client::Client(QByteArray json) {
    this->json=json;
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, &Client::onConnected);
    socket->connectToHost("127.0.0.1", 1234);
}

void Client::onConnected() {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(json);
        socket->flush(); // 메시지를 즉시 전송
    } else {
        cout<< "Socket is not connected!"<<endl;
    }
    socket->disconnectFromHost();
}

#include "client.moc"