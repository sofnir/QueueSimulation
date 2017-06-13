#include "Average.h"

int Average::allCustomers = 0;
int Average::allServiceTime = 0;

Average::Average() : Customer(AVERAGE)
{
    ;
}

Average::~Average()
{
    ;
}

void Average::show() const
{
    std::cout << "Average variables\n";
    showVariables();
}
