#include <iostream>

#include "User/Type/Customer/Customer.h"
#include "User/Type/Seller/Seller.h"
#include "User/Service/UserService.h"
#include "Food/Request/FoodRequest.h"
#include "Food/Service/FoodService.h"
#include "Order/Service/OrderService.h"

int main() {

    FoodRequest request(1000,"helloFood",FROZEN);
    FoodService foodService;

    foodService.createFood(request);
    const  shared_ptr<const Food> &ptr = foodService.readFood(1);
    if(ptr != nullptr) std::cout <<  ptr->getFoodName() << std::endl;
    cout << ptr->getFoodPrice() << endl;
    UserService userService;
    OrderService orderService(foodService,userService);

    OrderRequest orderRequest(1,2,1,2);
    orderService.createOrder(orderRequest);

    const shared_ptr<Order> &orderptr = orderService.readOrder(1);
    cout << orderptr->gerOrderId() << endl;
    cout << orderptr->getId() << endl;

//    foodService.updateFood(ptr);

//    const shared_ptr<Food> &ptr2 = foodService.readFood(1);
//    if(ptr != nullptr) std::cout <<  ptr2->getFoodName() << std::endl;
    return 0;




}
