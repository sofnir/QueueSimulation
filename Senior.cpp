#include "Senior.h"

int Senior::allCustomers = 0;
int Senior::allServiceTime = 0;

Senior::Senior() : Customer(SENIOR)
{
    ;
}

Senior::~Senior()
{
    ;
}

void Senior::show() const
{
    std::cout << "Senior variables\n";
    showVariables();
}
