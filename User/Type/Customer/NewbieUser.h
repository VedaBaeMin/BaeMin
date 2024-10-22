//
// Created by lee on 2024. 10. 21..
//

#ifndef BAEMIN_NEWBIEUSER_H
#define BAEMIN_NEWBIEUSER_H

#include "Customer.h"

class NewbieUser : public Customer {

    int discountCount = 0;

public:
    void updateUserInfo() override;

    float getTotalDiscountRate() const override;
};

#endif //BAEMIN_NEWBIEUSER_H
