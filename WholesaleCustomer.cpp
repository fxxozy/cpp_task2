#include <iostream>
#include "WholesaleCustomer.h"

WholesaleCustomer::WholesaleCustomer(int sequenceNumber, string name) : Customer(sequenceNumber, name) {}

WholesaleCustomer::WholesaleCustomer(int sequenceNumber, string name, map<Product*, int> products) :
                    Customer(sequenceNumber, name, products) {}

void WholesaleCustomer::purchaseProduct(Product* product, int quantity, OrganizationalUnit* organizationalUnit)
{
    map<Product*, int> currentPurchases = purchasedProducts;
    if (dynamic_cast<Warehouse*>(organizationalUnit))
    {
        map<Product *, int> products = organizationalUnit->getProducts();
        if (products.contains(product))
        {
            for (auto &product_item: products)
            {
                if (product_item.first == product && quantity <= products.at(product))
                {
                    if (purchasedProducts.contains(product))
                    {
                        purchasedProducts.at(product_item.first) += quantity;
                    }
                    else
                    {
                        purchasedProducts.insert(make_pair(product, quantity));
                    }
                    organizationalUnit->removeProduct(product, quantity);
                    break;
                }
            }
            if (currentPurchases == purchasedProducts)
            {
                cout << "There is no such product in the warehouse!" << endl;
            }
        }
        else
        {
            cout << "There is no such good in the warehouse!" << endl;
        }
    }
    else
    {
        cout << "A wholesale customer can't buy goods in store!" << endl;
    }
}

WholesaleCustomer::~WholesaleCustomer()
{
    cout << "Deleting WholesaleCustomer \n";
}