#pragma once
#ifndef TASK2_TRUCK_H
#define TASK2_TRUCK_H

#include <string>
#include "OrganizationalUnit.h"
#include "RetailCustomer.h"

using namespace std;


class Truck {
private:
    int sequenceNumber;
    string make;
    string model;

public:
    Truck(int sequenceNumber, string make, string model);

    int getSequenceNumber();

    void setSequenceNumber(int sequenceNumber);

    string getMake();

    void setMake(string make);

    string getModel();

    string setModel(string model);

    void deliverProductsToStore(OrganizationalUnit *warehouse, OrganizationalUnit *store, map<Product *, int> products);

    string toString();

    ~Truck();

};


#endif //TASK2_TRUCK_H