#pragma once
#ifndef TASK2_ORGANIZATIONALUNIT_H
#define TASK2_ORGANIZATIONALUNIT_H

#include <string>
#include "Product.h"

using namespace std;


class Product;

class OrganizationalUnit {
protected:
    int sequenceNumber;
    string name;
    map<Product *, int> products;

public:
    OrganizationalUnit(int sequenceNumber, string name);

    OrganizationalUnit(int sequenceNumber, string name, map<Product *, int> products);

    string getName();

    void setName(string name);

    int getSequenceNumber();

    void setSequenceNumber(int sequenceNumber);

    map<Product *, int> getProducts();

    void setProducts(map<Product *, int> products);

    void addProduct(Product *product, int quantity);

    void removeProduct(Product *product, int quantity);

    string toString();

    void printProducts();

    virtual ~OrganizationalUnit();
};


#endif //TASK2_ORGANIZATIONALUNIT_H