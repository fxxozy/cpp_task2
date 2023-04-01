#include <iostream>
#include "Product.h"
#include "Warehouse.h"
#include "Store.h"
#include "RetailCustomer.h"
#include "WholesaleCustomer.h"
#include "Organization.h"


using namespace std;

void printInfoAboutOrganization(Organization* organization)
{
    cout << "Organization: " << organization->getName() << "\n\n";
    for (auto provider: organization->getProviders())
    {
        cout << provider->toString() << endl;
    }
    cout << endl;
    for (auto unit: organization->getOrganizationalUnits())
    {
        if (dynamic_cast<Store *>(unit))
        {
            cout << "Store: " << unit->getName() << endl;
        }
        else
        {
            cout << "Warehouse: " << unit->getName() << endl;
        }
        unit->printProducts();
        cout << endl;
    }
}

void printInfoAboutCustomers(list<Customer*>* customers)
{
    for (auto &customer: *customers)
    {
        if (dynamic_cast<RetailCustomer*>(customer))
        {
            cout << "Retail customer:" << customer->toString() << endl;
        }
        else
        {
            cout << "Wholesale customer:" << customer->toString() << endl;
        }
        customer->printPurchasedProducts();
        cout << endl;
    }
}

void printExistingProducts(list<Product*>* products)
{
    for (auto product: *products)
    {
        cout << product->toString() << endl;
    }
}

void createProduct(list<Product*>* products)
{
    int sequenceNumber;
    cout << "Input the product's sequence number:";
    cin >> sequenceNumber;
    int numberOfType;
    Product::ProductType type;
    cout << "0 - Clothes;\n1 - Food;\n2 - Medicines;\n3 - Furniture\n"
            "Select the desired product type by number from the list:";
    cin >> numberOfType;
    switch (numberOfType)
    {
        case 0:
            type = Product::Clothes;
            break;
        case 1:
            type = Product::Food;
            break;
        case 2:
            type = Product::Medicines;
            break;
        case 3:
            type = Product::Furniture;
            break;
        default:
            cerr << "You have chosen an incorrect number!" << endl;
    }
    string name;
    cout << "Input a product name:";
    cin >> name;
    int unitPrice;
    cout << "Input an unit price:";
    cin >> unitPrice;
    Product* product = new Product(sequenceNumber, type, name, unitPrice);
    products->push_back(product);
}

void createCustomer(list<Customer*>* customers)
{
    int sequenceNumber;
    cout << "Input the customer's sequence number:";
    cin >> sequenceNumber;
    Customer* customer;
    cout << "Input the customer's name:";
    string name;
    cin >> name;
    cout << "Select the type of customer (0 - Retail Customer, 1 - Wholesale customer): ";
    int numberOfType;
    cin >> numberOfType;
    switch (numberOfType)
    {
        case 0:
            customer = new RetailCustomer(sequenceNumber, name);
            break;
        case 1:
            customer = new WholesaleCustomer(sequenceNumber, name);
            break;
        default:
            cerr << "You have chosen an incorrect number!" << endl;
    }
    customers->push_back(customer);
}

void createOrganizationalUnit(Organization* organization)
{
    int sequenceNumber;
    cout << "Input the building's sequence number :";
    cin >> sequenceNumber;
    string name;
    cout << "Input the building's name:";
    cin >> name;
    int numberOfType;
    OrganizationalUnit* organizationalUnit;
    cout << "Select the type of building (0 - Store, 1 - Warehouse): ";
    cin >> numberOfType;
    switch (numberOfType) {
        case 0:
            organizationalUnit = new Store(sequenceNumber, name);
            break;
        case 1:
            organizationalUnit = new Warehouse(sequenceNumber, name);
            break;
        default:
            cerr << "You have chosen an incorrect number!" << endl;
    }
    organization->addOrganizationalUnit(organizationalUnit);
}

void bringGoodsToWarehouse(Organization* organization, list<Product*>* products)
{
    cout << "Providers:" << endl;
    organization->printProviders();
    int sequenceNumberOfProvider;
    cout << "Select the provider's sequence number:";
    cin >> sequenceNumberOfProvider;
    Provider* provider;
    list<Provider *> providers = organization->getProviders();
    for (auto provider_item: providers)
    {
        if (provider_item->getSequenceNumber() == sequenceNumberOfProvider)
        {
            provider = provider_item;
        }
    }
    cout << endl;

    cout << "Products that can be delivered to warehouse: \n";
    for (auto product: *products)
    {
        cout << product->toString() << endl;
    }
    int sequenceNumberOfProduct;
    cout << "Select the product's sequence number:";
    cin >> sequenceNumberOfProduct;
    Product* product;
    for (auto product_item: *products)
    {
        if (product_item->getSequenceNumber() == sequenceNumberOfProduct)
        {
            product = product_item;
        }
    }
    cout << endl;

    organization->printListOfOrganizationalUnits();
    int sequenceNumberOfWarehouse;
    cout << "Select the warehouse's number by sequence number:";
    cin >> sequenceNumberOfWarehouse;
    Warehouse *warehouse;
    for (auto unit: organization->getOrganizationalUnits())
    {
        if (unit->getSequenceNumber() == sequenceNumberOfWarehouse)
        {
            warehouse = dynamic_cast<Warehouse*>(unit);
        }
    }

    int quantity;
    cout << "Input quantity of product you want buy:";
    cin >> quantity;
    provider->bringProductsToWarehouse(warehouse, product, quantity);
}

void buyProductInOrganizationalUnit(Organization* organization, list<Customer*>* customers)
{
    cout << "Customers:" << endl;
    printInfoAboutCustomers(customers);
    int sequenceNumberOfCustomer;
    cout << "Select the customer's sequence number who will make the purchase:";
    cin >> sequenceNumberOfCustomer;
    Customer* customer;
    for (auto customer_item: *customers)
    {
        if (customer_item->getSequenceNumber() == sequenceNumberOfCustomer)
        {
            customer = customer_item;
        }
    }
    cout << endl;

    organization->printListOfOrganizationalUnits();
    int sequenceNumberOfOrganizationalUnit;
    cout << "Select building's sequence number in which the customer will make a purchase:";
    cin >> sequenceNumberOfOrganizationalUnit;
    OrganizationalUnit* organizationalUnit;
    for (auto unit: organization->getOrganizationalUnits())
    {
        if (unit->getSequenceNumber() == sequenceNumberOfOrganizationalUnit)
        {
            organizationalUnit = unit;
        }
    }
    cout << endl;

    cout << "Products that are in stock:";
    organizationalUnit->printProducts();
    int sequenceNumberOfProduct;
    cout << "Select the product's sequence number which will be purchased by the customer:";
    cin >> sequenceNumberOfProduct;
    Product* product;
    for (auto product_item: organizationalUnit->getProducts())
    {
        if (product_item.first->getSequenceNumber() == sequenceNumberOfOrganizationalUnit)
        {
            product = product_item.first;
        }
    }
    cout << endl;

    int quantity;
    cout << "Input quantity of product which will be purchased by the customer:";
    cin >> quantity;
    customer->purchaseProduct(product, quantity, organizationalUnit);
}

void deliverProductInStore(Organization* organization)
{
    organization->printListOfOrganizationalUnits();
    int sequenceNumberOfWarehouse;
    cout << "Select the warehouse's sequence number from which the delivery will be made:";
    cin >> sequenceNumberOfWarehouse;
    OrganizationalUnit* warehouse;
    for (auto unit: organization->getOrganizationalUnits())
    {
        if (unit->getSequenceNumber() == sequenceNumberOfWarehouse)
        {
            warehouse = unit;
        }
    }
    warehouse->printProducts();
    cout << endl;

    int sequenceNumberOfStore;
    cout << "Select the store's sequence number in which the delivery will be made:";
    cin >> sequenceNumberOfStore;
    OrganizationalUnit* store;
    for (auto unit: organization->getOrganizationalUnits())
    {
        if (unit->getSequenceNumber() == sequenceNumberOfStore)
        {
            store = unit;
        }
    }
    store->printProducts();
    cout << endl;

    int sequenceNumberOfTruck;
    for (auto truck_item: organization->getTrucks())
    {
        cout << "Truck: " << truck_item->toString();
    }
    cout << "Select the truck's sequence number that will make the delivery:";
    cin >> sequenceNumberOfTruck;
    Truck* truck;
    for (auto truck_item: organization->getTrucks())
    {
        if (truck_item->getSequenceNumber() == sequenceNumberOfTruck)
        {
            truck = truck_item;
        }
    }
    cout << endl;

    warehouse->printProducts();
    int sequenceNumberOfProduct;
    int quantity;
    map<Product*, int> products;
    while (true)
    {
        cout << "Select the product's sequence number which you want to deliver in the store"
                "(0 - finish the selection of products):";
        cin >> sequenceNumberOfProduct;
        if (sequenceNumberOfProduct == 0)
        {
            break;
        }
        Product* product;
        for (auto product_item: warehouse->getProducts())
        {
            if (product_item.first->getSequenceNumber() == sequenceNumberOfProduct)
            {
                product = product_item.first;
            }
        }
        cout << endl;
        cout << "Select quantity of the product which will be delivered:";
        cin >> quantity;
        products.insert(make_pair(product, quantity));
    }
    truck->deliverProductsToStore(warehouse, store, products);
}


void printMenu() {
    cout << "Select an action:" << endl;
    cout << "1. View information about the organization" << endl;
    cout << "2. View customers" << endl;
    cout << "3. View existing products" << endl;
    cout << "4. Create a product" << endl;
    cout << "5. Create a customer" << endl;
    cout << "6. Create a store/warehouse" << endl;
    cout << "7. Make the delivery of products to the warehouse" << endl;
    cout << "8. Buy product in the store/warehouse" << endl;
    cout << "9. Deliver products to the store" << endl;
    cout << "10. Exit" << endl;
}

void deleteCustomers(list<Customer*>* customers)
{
    for (auto customer: *customers)
    {
        delete customer;
    }
    delete customers;
}

void deleteProducts(list<Product*>* products)
{
    for (auto product: *products)
    {
        delete product;
    }
    delete products;
}

int main()
{
    Organization* organization = new Organization("Spectrum");

    Provider* provider1 = new Provider(1, "Maria", "89083459671");
    Provider* provider2 = new Provider(2, "Max", "89517583405");

    Product* product1 = new Product(1, (Product::Medicines), "Nurafen", 350);
    Product* product2 = new Product(2, (Product::Furniture), "Safe Onyx", 35000);
    Product* product3 = new Product(3, (Product::Clothes), "Tommy Hoodie", 10000);

    OrganizationalUnit* store = new Store(1, "Store1");
    OrganizationalUnit* store2 = new Store(2, "Store2");
    OrganizationalUnit* warehouse = new Warehouse(5, "Warehouse1");
    OrganizationalUnit* warehouse2 = new Warehouse(6, "Warehouse2");

    Truck* truck1 = new Truck(1, "Mercedes", "Sprinter");
    Truck* truck2 = new Truck(2, "Opel", "Zafira");

    Customer* retailCustomer = new RetailCustomer(1, "Alex");
    Customer* wholesaleCustomer = new WholesaleCustomer(2, "Andrey");

    list<Customer*>* customers = new list<Customer*>;
    customers->push_back(retailCustomer);
    customers->push_back(wholesaleCustomer);

    list<Product*>* products = new list<Product*>;
    products->push_back(product1);
    products->push_back(product2);
    products->push_back(product3);

    organization->addOrganizationalUnit(store);
    organization->addOrganizationalUnit(store2);
    organization->addOrganizationalUnit(warehouse);
    organization->addOrganizationalUnit(warehouse2);
    organization->addProvider(provider1);
    organization->addProvider(provider2);
    organization->addTruck(truck1);
    organization->addTruck(truck2);

    store->addProduct(product1, 15);
    store->addProduct(product2, 6);
    store2->addProduct(product3, 30);
    warehouse->addProduct(product1, 12);
    warehouse->addProduct(product2, 10);
    warehouse2->addProduct(product3, 8);

    retailCustomer->purchaseProduct(product1, 3, store);
    retailCustomer->purchaseProduct(product1, 8, store);
    retailCustomer->purchaseProduct(product2, 4, store);

    wholesaleCustomer->purchaseProduct(product2, 5, warehouse);

    bool end = false;
    int actionNumber;
    while (!end) {
        cout << "\n";
        printMenu();
        cout << "\n";
        cout << "Input a number:";
        cin >> actionNumber;
        switch (actionNumber) {
            case 1:
                printInfoAboutOrganization(organization);
                break;
            case 2:
                printInfoAboutCustomers(customers);
                break;
            case 3:
                printExistingProducts(products);
                break;
            case 4:
                createProduct(products);
                break;
            case 5:
                createCustomer(customers);
                break;
            case 6:
                createOrganizationalUnit(organization);
                break;
            case 7:
                bringGoodsToWarehouse(organization, products);
                break;
            case 8:
                buyProductInOrganizationalUnit(organization, customers);
                break;
            case 9:
                deliverProductInStore(organization);
                break;
            case 10:
                end = true;
                break;
            default:
                cerr << "You have chosen the incorrect number!" << endl;
        }
    }

    delete organization;
    deleteCustomers(customers);
    return 0;
}
