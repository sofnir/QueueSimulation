#ifndef FACTORY_H
#define FACTORY_H
#include "CustomerType.h"
#include "Junior.h"
#include "Average.h"
#include "Senior.h"
#include "Cashier.h"

class Factory
{
    public:
        Factory(CustomerType * types);
        virtual ~Factory();

    private:
        CustomerType * customerTypes;

        void setVariables(Customer *& customer, int type);
        int randValue(int minValue, int maxValue) {return std::rand() % (maxValue - minValue) + minValue;}
    public:
        bool isNewCustomer(int type, int currentHour);
        Customer * createCustomer(int type);
};

#endif // FACTORY_H
