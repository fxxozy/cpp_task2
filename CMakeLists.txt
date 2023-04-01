cmake_minimum_required(VERSION 3.24)
project(task2)

set(CMAKE_CXX_STANDARD 20)

add_executable(task2 main.cpp Customer.cpp Customer.h Product.cpp Product.h Provider.cpp Provider.h RetailCustomer.cpp RetailCustomer.h WholesaleCustomer.cpp WholesaleCustomer.h Store.cpp Store.h Warehouse.cpp Warehouse.h Organization.cpp Organization.h Organization.h OrganizationalUnit.cpp OrganizationalUnit.h Truck.cpp Truck.h)
