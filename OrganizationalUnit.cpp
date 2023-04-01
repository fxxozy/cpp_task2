#include <iostream>
#include "OrganizationalUnit.h"

OrganizationalUnit::OrganizationalUnit(int sequenceNumber, string name): sequenceNumber(sequenceNumber), name(name) {}

OrganizationalUnit::OrganizationalUnit(int sequenceNumber, string name, map<Product*, int> products):
                    sequenceNumber(sequenceNumber), name(name), products(products) {}

string OrganizationalUnit::getName()
{
    return this->name;
}

void OrganizationalUnit::setName(string name)
{
    this->name = name;
}

int OrganizationalUnit::getSequenceNumber()
{
    return this->sequenceNumber;
}

void OrganizationalUnit::setSequenceNumber(int sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

map<Product*, int> OrganizationalUnit::getProducts()
{
    return this->products;
}

void OrganizationalUnit::setProducts(map<Product*, int> products)
{
    this->products = products;
}

void OrganizationalUnit::addProduct(Product* product, int quantity)
{
    if (products.contains(product))
    {
        products.at(product) += quantity;
    }
    else
    {
        products.insert(make_pair(product, quantity));
    }
}

void OrganizationalUnit::removeProduct(Product* product, int quantity)
{
    for (auto pair : this->products)
    {
        if (pair.first->operator==(*product))
        {
            if (pair.second > quantity)
            {
                this->products[product] -= quantity;
            }
            else if (pair.second == quantity)
            {
                cout << "The last product of this type has just been purchased!" << endl;
                this->products.erase(product);
            }
        }
        else
        {
            continue;
        }
        return;
    }
}

void OrganizationalUnit::printProducts()
{
    for (auto product : this->products)
    {
        cout << product.first->toString() << " -> quantity:" << product.second << endl;
    }
}

string OrganizationalUnit::toString()
{
    stringstream ss;
    ss << "OrganizationalUnit: {SequenceNumber:" << this->sequenceNumber << ", name:" << this->name << "}";

    return ss.str();
}

OrganizationalUnit::~OrganizationalUnit()
{
    cout << "Deleting OrganizationalUnit" << endl;
}




