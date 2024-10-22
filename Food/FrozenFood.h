//
// Created by lee on 2024. 10. 22..
//

#ifndef BAEMIN_FROZENFOOD_H
#define BAEMIN_FROZENFOOD_H

#include "Food.h"

class FrozenFood :public Food {
public:
    FrozenFood(long foodId, long price, const string &foodName);

    const long getFoodPrice() const override;
};


#endif //BAEMIN_FROZENFOOD_H
