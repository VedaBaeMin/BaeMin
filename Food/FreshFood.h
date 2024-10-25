//
// Created by lee on 2024. 10. 22..
//

#ifndef BAEMIN_FRESHFOOD_H
#define BAEMIN_FRESHFOOD_H

#include "Food.h"

class FreshFood : public Food {
public:
    FreshFood(long foodId, long price, const string &foodName);

   const long getFoodDiscountPercent() const override;

};


#endif //BAEMIN_FRESHFOOD_H
