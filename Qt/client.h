#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>

class Client : public QObject {
    Q_OBJECT

public:
    Client(QObject *parent = nullptr);
    void connectToServer(const QString &host, quint16 port);
    void sendJson();

private slots:
    void onReadyRead();

private:
    QTcpSocket *socket;
};

#endif // CLIENT_H
