#include "Truck.h"

Truck::Truck(int sequenceNumber, string make, string model) :
                sequenceNumber(sequenceNumber), make(make), model(model) {}

int Truck::getSequenceNumber()
{
    return this->sequenceNumber;
}

void Truck::setSequenceNumber(int sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

string Truck::getMake()
{
    return this->make;
}

void Truck::setMake(string make)
{
    this->make = make;
}

string Truck::getModel()
{
    return this->model;
}

string Truck::setModel(string model)
{
    this->model = model;
}

void Truck::deliverProductsToStore(OrganizationalUnit* warehouse, OrganizationalUnit* store, map<Product*, int> products)
{
    if (dynamic_cast<Store*>(store))
    {
        map<Product*, int> productsInWarehouse = warehouse->getProducts();
        map<Product*, int> productsInStore = store->getProducts();
        for (auto product: products)
        {
            if (productsInWarehouse.contains(product.first) && productsInWarehouse.at(product.first) >= product.second)
            {
                store->addProduct(product.first, product.second);
                warehouse->removeProduct(product.first, product.second);
            }
            else
            {
                cout << "There aren't enough products in warehouse for delivery!" << endl;
            }
        }
    }
    else
    {
        cout << "The products are delivered only to store!" << endl;
    }
}

string Truck::toString()
{
    stringstream ss;
    ss << "{SequenceNumber:" << this->sequenceNumber << ", make:" << this->make <<
              ", model:"  <<  this->model << "}" << endl;
    return ss.str();
}

Truck::~Truck()
{
    cout << "Deleting Truck" << endl;
}