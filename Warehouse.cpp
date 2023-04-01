#include "Warehouse.h"

Warehouse::Warehouse(int sequenceNumber, string name) : OrganizationalUnit(sequenceNumber, name) {}

Warehouse::Warehouse(int sequenceNumber, string name, map<Product *, int> products) :
                        OrganizationalUnit(sequenceNumber, name, products) {}

Warehouse::~Warehouse()
{
    for (auto& product : this->products)
        delete product.first;
    cout << "Deleting warehouse" << endl;
}