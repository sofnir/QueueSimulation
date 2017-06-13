#include "Cashier.h"

Interval Cashier::scanningTime = {0, 0};
int Cashier::longestWaitingTime = 0;

Cashier::Cashier()
{
    ;
}

Cashier::~Cashier()
{
    ;
}

void Cashier::setScanningTime()
{
    int valueMin, valueMax;

    while(true)
    {
        std::cout << "Set scanning time [~100 ms]\n";
        std::cout << "Minimum: ";
        std::cin >> valueMin;
        std::cout << "Maximum: ";
        std::cin >> valueMax;

        if(valueMin >= 0 && valueMin <= valueMax)
            break;
        else
            std::cout << "Invalid values, try again\n";
    }

    scanningTime.min = valueMin;
    scanningTime.max = valueMax;
}

void Cashier::setScanningTime(int minTime, int maxTime)
{
    if(minTime >= 0 && maxTime >= minTime && minTime % 100 == 0 && maxTime % 100 == 0)
    {
        scanningTime.min = minTime;
        scanningTime.max = maxTime;
    }
}

void Cashier::update()
{
    updateServiceTime();
    updateCustomersWaitingTime();
    updateCashierWaitingTime();
}

void Cashier::updateServiceTime()
{
    if(front != nullptr)
    {
        front->item->decreaseServiceTime();

        if(front->item->getServiceTime() <= 0)
            pop();
    }
}

void Cashier::updateCustomersWaitingTime()
{
    Node * temp = front;

    while (temp != nullptr)
    {
        temp->item->increaseWaitingTime();

        if(temp->item->getWaitingTime() > Customer::getLongestWaitingTime())
            Customer::setLongestWaitingTime(temp->item->getWaitingTime());

        temp = temp->next;
    }
}

void Cashier::updateCashierWaitingTime()
{
    if(empty())
    {
        waitingTime += 100;

        if(waitingTime > longestWaitingTime)
            longestWaitingTime = waitingTime;
    }
    else
        waitingTime = 0;
}
