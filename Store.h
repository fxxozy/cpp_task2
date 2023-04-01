#pragma once
#ifndef TASK2_STORE_H
#define TASK2_STORE_H

#include <string>
#include <iostream>
#include <map>
#include "OrganizationalUnit.h"

using namespace std;


class Store : public OrganizationalUnit {
public:
    Store(int sequenceNumber, string name);

    Store(int sequenceNumber, string name, map<Product *, int> products);

    // string toString();

    ~Store() override;
};


#endif //TASK2_STORE_H