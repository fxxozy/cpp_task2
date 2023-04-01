#include <iostream>
#include "Customer.h"

Customer::Customer(int sequenceNumber, string name): sequenceNumber(sequenceNumber), name(name) {}

Customer::Customer(int sequenceNumber, string name, map<Product*, int> products) :
                        sequenceNumber(sequenceNumber), name(name), purchasedProducts(products) {}

int Customer::getSequenceNumber()
{
    return this->sequenceNumber;
}

void Customer::setSequenceNumber(int sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

string Customer::getName()
{
    return this->name;
}

void Customer::setName(string name)
{
    this->name = name;
}

map<Product*, int> Customer::getPurchasedProducts()
{
    return this->purchasedProducts;
}

void Customer::setPurchasedProducts(map<Product*, int> products)
{
    this->purchasedProducts = products;
}

void Customer::purchaseProduct(Product *product, int quantity,
                                OrganizationalUnit *organizationalUnit) {}

void Customer::printPurchasedProducts()
{
    for (auto product : this->purchasedProducts)
    {
        cout << product.first->toString() << " -> quantity:" << product.second << endl;
    }
}

string Customer::toString()
{
    stringstream ss;
    ss << "{SequenceNumber:" << this->sequenceNumber << ", name:" << this->name << "}";

    return ss.str();
}

Customer::~Customer()
{
    cout << "Deleting Customer" << endl;
}