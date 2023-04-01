#pragma once
#ifndef TASK2_ORGANIZATION_H
#define TASK2_ORGANIZATION_H

#include <list>
#include <iostream>
#include "Store.h"
#include "Warehouse.h"
#include "Truck.h"

using namespace std;


class Organization {
private:
    string name;
    list<OrganizationalUnit*> organizationalUnits;
    list<Provider*> providers;
    list<Truck*> trucks;

public:
    Organization(string name);

    Organization(string name, list<OrganizationalUnit*> organizationalUnits, list<Provider*> providers, list<Truck*> trucks);

    string getName();

    void setName(string name);

    list<OrganizationalUnit*> getOrganizationalUnits();

    void setOrganizationalUnits(list<OrganizationalUnit*> organizationalUnits);

    list<Provider*> getProviders();

    void setProviders(list<Provider*> providers);

    list<Truck*> getTrucks();

    void setTrucks(list<Truck*> trucks);

    void addOrganizationalUnit(OrganizationalUnit* organizationalUnit);

    void addProvider(Provider* provider);

    void addTruck(Truck* truck);

    void printListOfOrganizationalUnits();

    void printProviders();

    ~Organization();
};


#endif //TASK2_ORGANIZATION_H
