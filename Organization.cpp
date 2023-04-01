#include <iostream>
#include "Organization.h"

Organization::Organization(string name): name(name) {}

Organization::Organization(string name, list<OrganizationalUnit*> organizationalUnits, list<Provider*> providers, list<Truck*> trucks):
                            name(name), organizationalUnits(organizationalUnits), providers(providers), trucks(trucks){}

string Organization::getName()
{
    return this->name;
}

void Organization::setName(string name)
{
    this->name = name;
}

list<OrganizationalUnit*> Organization::getOrganizationalUnits()
{
    return this->organizationalUnits;
}

void Organization::setOrganizationalUnits(list<OrganizationalUnit*> organizationalUnits)
{
    this->organizationalUnits = organizationalUnits;
}

list<Provider*> Organization::getProviders()
{
    return this->providers;
}

void Organization::setProviders(list<Provider*> provider)
{
    this->providers = provider;
}

list<Truck*> Organization::getTrucks()
{
    return this->trucks;
}

void Organization::setTrucks(list<Truck*> trucks)
{
    this->trucks = trucks;
}

void Organization::addOrganizationalUnit(OrganizationalUnit *organizationalUnit)
{
    this->organizationalUnits.push_back(organizationalUnit);
}

void Organization::addProvider(Provider* provider)
{
    providers.push_back(provider);
}

void Organization::addTruck(Truck* truck)
{
    trucks.push_back(truck);
}

void Organization::printListOfOrganizationalUnits()
{
    for (auto unit: this->organizationalUnits)
    {
        if (dynamic_cast<Store*>(unit))
        {
            cout << "Store:" << unit->toString() << endl;
        }
        else {
            cout << "Warehouse: " << unit->toString() << endl;
        }
    }
    cout << endl;
}

void Organization::printProviders()
{
    for (auto provider: this->providers)
    {
        cout << provider->toString() << endl;
    }
}



Organization::~Organization()
{
    for (auto unit: this->organizationalUnits)
    {
        delete unit;
    }
    for (auto provider: this->providers)
    {
        delete provider;
    }
    for (auto truck: trucks)
    {
        delete truck;
    }
    cout << "Deleting organization" << endl;
}








