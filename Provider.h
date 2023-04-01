#pragma once
#ifndef TASK2_PROVIDER_H
#define TASK2_PROVIDER_H

#include <string>
#include <map>
#include "Product.h"
#include "OrganizationalUnit.h"

using namespace std;


class Product;

class OrganizationalUnit;

class Provider {
private:
    int sequenceNumber;
    string name;
    string phoneNumber;

public:
    Provider(int sequenceNumber, string name, string address);

    string getName();

    void setName(string name);

    int getSequenceNumber();

    void setSequenceNumber(int sequenceNumber);

    string getPhoneNumber();

    void setPhoneNumber(string phoneNumber);

    void bringProductsToWarehouse(OrganizationalUnit *warehouse, Product *product, int quantity);

    void bringBatchOfProductsToWarehouse(OrganizationalUnit *warehouse, map<Product *, int> newProducts);

    string toString();

    ~Provider();

};


#endif //TASK2_PROVIDER_H