#include "Product.h"

Product::Product(int sequenceNumber, Product::ProductType productType, string name, int unitPrice):
                    sequenceNumber(sequenceNumber), productType(productType), name(name), unitPrice(unitPrice) {}

Product::ProductType Product::getProductType()
{
    return this->productType;
}

int Product::getSequenceNumber()
{
    return this->sequenceNumber;
}

void Product::setSequenceNumber(int sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

void Product::setProductType(Product::ProductType type)
{
    this->productType = type;
}

string Product::getName()
{
    return this->name;
}

void Product::setName(string name)
{
    this->name = name;
}

int Product::getUnitPrice()
{
    return this->unitPrice;
}

void Product::setUnitPrice(int unitPrice)
{
    this->unitPrice = unitPrice;
}

bool Product::operator==(Product &product)
{
    return productType == product.productType &&
           name == product.name &&
           unitPrice == product.unitPrice;
}

string Product::toString()
{
    stringstream ss;
    ss << "Product: {SequenceNumber: " << this->sequenceNumber << ", ProductType: " << this->productType << ", name: "
        << this->name << ", unitPrice: " << this->unitPrice << " rub}";

    return ss.str();
}

Product::~Product()
{
    cout << "Deleting product" << endl;
}