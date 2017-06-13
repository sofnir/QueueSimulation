#include "Customer.h"

int Customer::longestWaitingTime = 0;
int Customer::allServiceTime = 0;
int Customer::allCustomers = 0;

Customer::Customer(const Types & t) : type(t)
{
    ;
}

Customer::~Customer()
{
    ;
}

void Customer::setProductsNumber(int pn)
{
    if(pn >= 0)
        productsNumber = pn;
    else
        std::cout << "Invalid products number value\n";
}

void Customer::setChoosingTime(int cht)
{
    if(cht >= 0)
        choosingTime = cht;
    else
        std::cout << "Invalid choosing time value\n";
}

void Customer::setPackingTime(int pt)
{
    if(pt >= 0)
        packingTime = pt;
    else
        std::cout << "Invalid packing time value\n";
}

void Customer::setPayingTime(int pt)
{
    if(pt >= 0)
        payingTime = pt;
    else
        std::cout << "Invalid paying time value\n";
}

void Customer::setServiceTime(int st)
{
    if(st >= 0)
        serviceTime = st;
    else
        std::cout << "Invalid service time value\n";
}

void Customer::showVariables() const
{
    std::cout << "Products number: " << productsNumber << " / Choosing time: " << choosingTime << " [m]"
        << " / Packing time: " << packingTime << " [ms/item]" << " / Paying time: " << payingTime << " [s]\n";
}

