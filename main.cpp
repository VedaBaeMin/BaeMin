#include <iostream>

#include "User/Type/Customer/Customer.h"
#include "User/Type/Seller/Seller.h"
#include "User/Service/UserService.h"
#include "Food/Request/FoodRequest.h"
#include "Food/Service/FoodService.h"
int main() {

    FoodRequest request(1000,"helloFood",FROZEN);
    FoodService foodService;
    foodService.createFood(request);
    const  shared_ptr<const Food> &ptr = foodService.readFood(1);
    if(ptr != nullptr) std::cout <<  ptr->getFoodName() << std::endl;
    else cout<< "hello" << endl;
    cout << ptr->getFoodPrice() << endl;


//    foodService.updateFood(ptr);

//    const shared_ptr<Food> &ptr2 = foodService.readFood(1);
//    if(ptr != nullptr) std::cout <<  ptr2->getFoodName() << std::endl;
    return 0;




}
