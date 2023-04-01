#include "Store.h"

Store::Store(int sequenceNumber, string name) : OrganizationalUnit(sequenceNumber, name) {}

Store::Store(int sequenceNumber,string name, map<Product*, int> products) :
                OrganizationalUnit(sequenceNumber, name, products) {}


/*string Store::toString() {
    stringstream ss;
    ss << "Product: {ProductType: " << this->getName() << ", products: {"
       << this->getProducts() << "}";

    return ss.str();
}*/

Store::~Store() {
    for (auto product : this->products)
    {
        delete product.first;
    }
    cout << "Deleting store" << endl;
}