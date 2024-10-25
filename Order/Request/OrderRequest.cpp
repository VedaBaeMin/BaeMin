//
// Created by lee on 2024. 10. 17..
//

#include "OrderRequest.h"

//std::shared_ptr<Order> OrderRequest::toOrder(long orderId) {
//    return std::make_shared<Order>(orderId,sellerId,customerId,PENDING);
//}
//
//
OrderRequest::OrderRequest(QByteArray byte) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byte);
    QJsonObject jsonObj = jsonDoc.object();
    this->orderCount=jsonObj["orderCount"].toInt();
    this->foodId=jsonObj["foodId"].toInt();
    this->sellerId=jsonObj["sellerId"].toInt();
    this->customerId=jsonObj["customerId"].toInt();
}