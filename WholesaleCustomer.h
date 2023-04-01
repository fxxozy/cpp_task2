#pragma once
#ifndef TASK2_WHOLESALECUSTOMER_H
#define TASK2_WHOLESALECUSTOMER_H

#include <iostream>
#include <string>
#include "Customer.h"
#include "Warehouse.h"


using namespace std;

class WholesaleCustomer: public Customer {

public:
    WholesaleCustomer(int sequenceNumber, string name);

    WholesaleCustomer(int sequenceNumber, string name, map<Product*, int> products);

    void purchaseProduct(Product* product, int quantity, OrganizationalUnit* organizationalUnit) override;

    ~WholesaleCustomer() override;
};


#endif //TASK2_WHOLESALECUSTOMER_H