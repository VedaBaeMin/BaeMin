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
    #include <QDebug>


    UserService userService;
    FoodService foodService;
    OrderService orderService(foodService,userService);



     QString handleJson(QJsonObject &jsonObject) {
        // JSON에서 요소 추출
        //// 여기서 확인 가능
        QString type  = jsonObject["type"].toString();
        qDebug() << "type:" << type;

        if(type == "foodRequest"){
            QString foodName =jsonObject["foodName"].toString();
            qDebug() << foodName;

            FoodRequest request(1000,"food1",FROZEN);
            foodService.createFood(request);

            // 여기에 만든 객체들로 실행하게


        }
        else if(type == "orderRequest"){

            OrderRequest request(1,1,1,10);
            orderService.createOrder(request);


        }
        else if(type == "joinRequest"){
            UserRegisterRequest request("lee","123");
            userService.join(request);
        }



        return "success";

        ////
    }

    class MyClass {
    public:
        MyClass(const QString &name, int age) : name(name), age(age) {}
        QString getName() const { return name; }
        int getAge() const { return age; }

    private:
        QString name;
        int age;

    };



    class HttpServer : public QTcpServer {
    Q_OBJECT

    public:
        HttpServer(QObject *parent = nullptr) : QTcpServer(parent) {
            connect(this, &QTcpServer::newConnection, this, &HttpServer::handleNewConnection);
        }

    private slots:
        void handleNewConnection() {
            QTcpSocket *socket = nextPendingConnection();
            connect(socket, &QTcpSocket::readyRead, this, &HttpServer::readRequest);
        }

        void readRequest() {
            QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
            QByteArray requestData = socket->readAll();

            // HTTP 요청을 처리
            QString requestString(requestData);
            qDebug() << "Received Request:\n" << requestString;

            // HTTP 요청에서 "\r\n\r\n"을 찾아 헤더와 본문을 분리
            int headerEndIndex = requestData.indexOf("\r\n\r\n");

            if (headerEndIndex == -1) {
                // 본문이 없는 잘못된 요청 처리
                QString httpResponse = "HTTP/1.1 400 Bad Request\r\n"
                                       "Content-Type: text/plain\r\n"
                                       "Content-Length: 0\r\n"
                                       "\r\n";
                socket->write(httpResponse.toUtf8());
                socket->disconnectFromHost();
                return;
            }

            // 본문 부분을 추출 (JSON 데이터)
            QByteArray jsonData = requestData.mid(headerEndIndex + 4); // \r\n\r\n 뒤에 있는 데이터를 가져옴
            QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

            if (!jsonDoc.isObject()) {
                // 유효하지 않은 JSON 데이터 처리
                QString httpResponse = "HTTP/1.1 400 Bad Request\r\n"
                                       "Content-Type: text/plain\r\n"
                                       "Content-Length: 0\r\n"
                                       "\r\n";
                socket->write(httpResponse.toUtf8());
                socket->disconnectFromHost();
                return;
            }



            QJsonObject jsonObject = jsonDoc.object();
            const QString &response = handleJson(jsonObject);

            // 응답 보내기
           
            QString httpResponse = "HTTP/1.1 200 OK\r\n"
                                   "Content-Type: text/plain\r\n"
                                   "Content-Length: %1\r\n"
                                   "\r\n"
                                   "%2";
            socket->write(httpResponse.arg(response.length()).arg(response).toUtf8());

            socket->disconnectFromHost();
        }


    };



    int main(int argc, char *argv[]) {
        QCoreApplication a(argc, argv);


        HttpServer server;
        if (!server.listen(QHostAddress::Any, 8080)) {
            qFatal("Unable to start the server: %s", qPrintable(server.errorString()));
        }
        qDebug() << "Server started on port" << server.serverPort();

        return a.exec();
    }

    #include "main.moc"
