#pragma once
#ifndef TASK2_WAREHOUSE_H
#define TASK2_WAREHOUSE_H

#include <string>
#include <map>
#include <iostream>
#include "OrganizationalUnit.h"

using namespace std;


class Product;

class Warehouse : public OrganizationalUnit {
public:
    Warehouse(int sequenceNumber, string name);

    Warehouse(int sequenceNumber, string name, map<Product *, int> products);

    ~Warehouse() override;
};

#endif //TASK2_WAREHOUSE_H