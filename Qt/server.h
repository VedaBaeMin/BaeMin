#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>

class Server : public QTcpServer {
    Q_OBJECT

public:
    Server(QObject *parent = nullptr);

private slots:
    void onNewConnection();
    void onReadyRead();

private:
    QTcpSocket *clientSocket;
};

#endif // SERVER_H
