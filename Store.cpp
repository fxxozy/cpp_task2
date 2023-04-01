#include "Store.h"

Store::Store(int sequenceNumber, string name) : OrganizationalUnit(sequenceNumber, name) {}

Store::Store(int sequenceNumber,string name, map<Product*, int> products) : OrganizationalUnit(sequenceNumber, name, products) {}

Store::~Store() {
    for (auto product : this->products)
    {
        delete product.first;
    }
    cout << "Deleting store" << endl;
}