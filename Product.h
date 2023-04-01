#pragma once
#ifndef TASK2_PRODUCT_H
#define TASK2_PRODUCT_H

#include <sstream>
#include <string>
#include "Provider.h"
#include <iostream>

using namespace std;


class Provider;

class Product {
public:
    enum ProductType {
        Clothes, Food, Medicines, Furniture
    };

private:
    int sequenceNumber;
    ProductType productType;
    string name;
    int unitPrice;

public:
    Product(int sequenceNumber, ProductType productType, string name, int unitPrice);

    int getSequenceNumber();

    void setSequenceNumber(int sequenceNumber);

    ProductType getProductType();

    void setProductType(ProductType type);

    string getName();

    void setName(string name);

    int getUnitPrice();

    void setUnitPrice(int unitPrice);

    virtual string toString();

    bool operator==(Product &product);

    ~Product();
};


#endif //TASK2_PRODUCT_H