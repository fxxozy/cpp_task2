#include <iostream>
#include "RetailCustomer.h"

RetailCustomer::RetailCustomer(int sequenceNumber, string name) : Customer(sequenceNumber, name) {}

RetailCustomer::RetailCustomer(int sequenceNumber, string name, map<Product*, int> products) :
                    Customer(sequenceNumber, name, products) {}

void RetailCustomer::purchaseProduct(Product* product, int quantity, OrganizationalUnit* organizationalUnit)
{
    map<Product*, int> currentPurchases = purchasedProducts;
    if (dynamic_cast<Store*>(organizationalUnit))
    {
        map<Product*, int> products = organizationalUnit->getProducts();
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
                cout << "There is no such quantity of goods in the store!" << endl;
            }
        }
        else
        {
            cout << "There is no such good in the store!" << endl;
        }
    }
    else
    {
        cout << "A retail customer can't buy goods in warehouse!" << endl;
    }
}

RetailCustomer::~RetailCustomer()
{
    cout << "Deleting RetailCustomer \n";
}