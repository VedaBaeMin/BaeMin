//
// Created by lee on 2024. 10. 21..
//

#ifndef BAEMIN_NORMALUSER_H
#define BAEMIN_NORMALUSER_H

#include "Customer.h"

class NormalUser : public Customer {

public:
    void updateUserInfo() override;

    float getTotalDiscountRate() const override;

};


#endif //BAEMIN_NORMALUSER_H
