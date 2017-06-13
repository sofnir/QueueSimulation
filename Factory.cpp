#include "Factory.h"

Factory::Factory(CustomerType * types) : customerTypes(types)
{
    ;
}

Factory::~Factory()
{
    ;
}
bool Factory::isNewCustomer(int type, int currentHour)
{
    if(customerTypes[type].getArrivalPeriodTime(currentHour) > 0)
        return (std::rand() * (customerTypes[type].getArrivalPeriodTime(currentHour) / 100) / RAND_MAX < 1);
    else
        return false;
}

Customer * Factory::createCustomer(int type)
{
    switch(type)
    {
    case JUNIOR:
        {
            Customer * customer = new Junior;
            setVariables(customer, JUNIOR);
            return customer;
            break;
        }
    case AVERAGE:
        {
            Customer * customer = new Average;
            setVariables(customer, AVERAGE);
            return customer;
            break;
        }
    case SENIOR:
        {
            Customer * customer = new Senior;
            setVariables(customer, SENIOR);
            return customer;
            break;
        }
        break;
    }
}

void Factory::setVariables(Customer *& customer, int type)
{
    int choosingTime = randValue(customerTypes[type].getChoosingTime().min, customerTypes[type].getChoosingTime().max);
    customer->setChoosingTime(choosingTime);

    int productsNumber = randValue(customerTypes[type].getProductsNumber().min, customerTypes[type].getProductsNumber().max);
    customer->setProductsNumber(productsNumber);

    int payingTime = randValue(customerTypes[type].getPayingTime().min, customerTypes[type].getPayingTime().max);
    customer->setPayingTime(payingTime);

    int serviceTime;

    for (int i = 0; i < productsNumber; i++)
    {
        serviceTime += randValue(Cashier::getScanningTime().min, Cashier::getScanningTime().max) +
            randValue(customerTypes[type].getPackingTime().min, customerTypes[type].getPackingTime().max);
    }

    serviceTime = payingTime * ONE_SECOND;
    customer->setServiceTime(serviceTime);

    Customer::increaseAllCustomers();
    Customer::increaseAllServiceTime(serviceTime);

    if(type == JUNIOR)
    {
        Junior::increaseAllCustomers();
        Junior::increaseAllServiceTime(serviceTime);
    }
    else if(type == AVERAGE)
    {
        Average::increaseAllCustomers();
        Average::increaseAllServiceTime(serviceTime);
    }
    else if(type == SENIOR)
    {
        Senior::increaseAllCustomers();
        Senior::increaseAllServiceTime(serviceTime);
    }
}
