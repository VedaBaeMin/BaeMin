//
// Created by lee on 2024. 10. 17..
//

#include "Food.h"

#include <qbytearray.h>

Food::Food(long foodId, long price, string foodName): foodId(foodId), price(price), foodName(foodName){
}

QByteArray Food::makeRequest() {
    QJsonObject jsonObj;
    jsonObj["foodId"] = static_cast<qint64>(foodId);
    jsonObj["price"] = static_cast<qint64>(price);
    jsonObj["foodName"] = QString::fromStdString(foodName);
    QJsonDocument jsonDoc(jsonObj);
    return jsonDoc.toJson();
}

long Food::getId() {
     return foodId;
}

long Food::getPrice() const {
    return price;
}

const string &Food::getFoodName() const {
    return foodName;
}

void Food::setPrice(long price) {
    Food::price = price;
}

void Food::setFoodName(const string &foodName) {
    Food::foodName = foodName;
}
