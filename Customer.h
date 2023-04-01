#pragma once
#ifndef TASK2_CUSTOMER_H
#define TASK2_CUSTOMER_H

#include <string>
#include <map>
#include "Product.h"
#include "OrganizationalUnit.h"

using namespace std;


class Customer {
protected:
    int sequenceNumber;
    string name;
    map<Product*, int> purchasedProducts;

public:

    Customer(int sequenceNumber, string name);

    Customer(int sequenceNumber, string name, map<Product*, int> products);

    int getSequenceNumber();

    void setSequenceNumber(int sequenceNumber);

    string getName();

    void setName(string name);

    map<Product*, int> getPurchasedProducts();

    void setPurchasedProducts(map<Product*, int> products);

    virtual void purchaseProduct(Product* product, int quantity, OrganizationalUnit* organizationalUnit);

    void printPurchasedProducts();

    string toString();

    virtual ~Customer();
};


#endif //TASK2_CUSTOMER_H