#include <iostream>

#include "Customer.h"
#include "Seller.h"
#include "UserService.h"
int main() {

    Customer * c = new Customer(1,"hello","112", "test",10123);
//    Seller * s = new Seller(2,"seller", "test", "hello3", 10231);

// ��û�� ������
    UserService userService;
    userService.createUser(c);



    std::cout << "Hello, World!" << std::endl;
    return 0;




}
