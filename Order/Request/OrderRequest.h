//
// Created by lee on 2024. 10. 17..
//

#ifndef BAEMIN_ORDERREQUEST_H
#define BAEMIN_ORDERREQUEST_H
#include <vector>
#include <memory>
#include <string>
#include <QJsonDocument>
#include <QJsonObject>
#include "../Order.h"

class OrderRequest {


    long orderCount;
    long foodId;
    long sellerId;
    long customerId;
    // �ֹ� �� ���ŵǴ� �κ�
    long total = 0;
    long orderId = -1;


public:
    OrderRequest(QByteArray byte);
    long getCustomerId() const {
        return customerId;
    }

    long getSellerId() const {
        return sellerId;
    }

    long getFoodId() const {
        return foodId;
    }

    long getOrderCount() const {
        return orderCount;
    }

    std::shared_ptr<Order> toOrder(long total, long orderId ){
        return std::make_shared<Order>(orderId,orderCount,foodId,sellerId,total,customerId);
    }

// ������
OrderRequest(long sellerId, long customerId, long foodId, long orderCount):sellerId(sellerId), customerId(customerId), foodId(foodId),orderCount(orderCount){

}
};


#endif //BAEMIN_ORDERREQUEST_H
