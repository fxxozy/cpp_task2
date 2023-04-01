#pragma once
#ifndef TASK2_RETAILCUSTOMER_H
#define TASK2_RETAILCUSTOMER_H

#include <string>
#include <iostream>
#include "Customer.h"
#include "Store.h"

using namespace std;


class RetailCustomer : public Customer {

public:
    RetailCustomer(int sequenceNumber, string name);

    RetailCustomer(int sequenceNumber, string name, map<Product *, int> products);

    void purchaseProduct(Product *product, int quantity, OrganizationalUnit *organizationalUnit) override;

    ~RetailCustomer() override;
};


#endif //TASK2_RETAILCUSTOMER_H