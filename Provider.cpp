#include <iostream>
#include <sstream>
#include "Provider.h"


Provider::Provider(int sequenceNumber, string name, string address) : sequenceNumber(sequenceNumber), name(name), phoneNumber(address) {}

int Provider::getSequenceNumber()
{
    return this->sequenceNumber;
}

void Provider::setSequenceNumber(int sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

string Provider::getName()
{
    return this->name;
}

void Provider::setName(string name)
{
    this->name = name;
}

string Provider::getPhoneNumber()
{
    return this->phoneNumber;
}

void Provider::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Provider::bringProductsToWarehouse(OrganizationalUnit *warehouse, Product* product, int quantity)
{
    map<Product*, int> products = warehouse->getProducts();
    if (products.contains(product))
    {
        products.at(product) += quantity;
    }
    else
    {
        products.insert(make_pair(product, quantity));
    }
    warehouse->setProducts(products);
}

void Provider::bringBatchOfProductsToWarehouse(OrganizationalUnit* warehouse, map<Product*, int> newProducts)
{
    map<Product*, int> products = warehouse->getProducts();
    for (auto product_item: newProducts)
    {
        if (products.contains(product_item.first)) {
            products.at(product_item.first) += newProducts.at(product_item.first);
        }
        else
        {
            products.insert(make_pair(product_item.first, product_item.second));
        }
    }
    warehouse->setProducts(products);
}

string Provider::toString()
{
    stringstream ss;
    ss << "Provider: {SequenceNumber: " << this->getSequenceNumber() << ", name: " << this->getName() << ", phoneNumber: "
       << this->getPhoneNumber() << "}";

    return ss.str();
}

Provider::~Provider()
{
    cout << "Deleting provider" << endl;

}