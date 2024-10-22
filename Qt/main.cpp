#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>
#include "server.h"
#include "client.h"

int main() {
    // JSON 객체 생성
    QJsonObject jsonObj;
    jsonObj["name"] = "John Doe";
    jsonObj["age"] = 30;

    // JSON 배열 생성
    QJsonArray hobbies;
    hobbies.append("Reading");
    hobbies.append("Traveling");
    jsonObj["hobbies"] = hobbies;

    // JSON 문서 생성
    QJsonDocument jsonDoc(jsonObj);
    QByteArray jsonData = jsonDoc.toJson();

    // qbytearray를 tcp를 이용하여 전송

    QJsonDocument jsonDoc2 = QJsonDocument::fromJson(jsonData);

    QJsonObject jsonObj2 = jsonDoc2.object();

    // 데이터 접근
    QString name = jsonObj2["name"].toString();
    int age = jsonObj2["age"].toInt();
    QJsonArray hobbies2 = jsonObj2["hobbies"].toArray();

    qDebug() << "Name :" << name;
    qDebug() << "Age :" << age;

    for (const QJsonValue &hobby : hobbies) {
        qDebug() << "Hobby:" << hobby.toString();
    }

    // 출력
    //qDebug() << jsonData;

    return 0;
}
