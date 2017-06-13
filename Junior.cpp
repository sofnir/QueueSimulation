#include "Junior.h"

int Junior::allCustomers = 0;
int Junior::allServiceTime = 0;

Junior::Junior() : Customer(JUNIOR)
{
    ;
}

Junior::~Junior()
{
    ;
}

void Junior::show() const
{
    std::cout << "Junior variables\n";
    showVariables();
}
