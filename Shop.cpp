#include "Shop.h"

Shop::Shop()
{
    ;
}

Shop::~Shop()
{
    ;
}

void Shop::setVaraibles()
{
    int x, y;

    while(true)
    {
        std::cout << "Set open and close time\n";
        std::cout << "Open: ";
        std::cin >> x;
        std::cout << "Close: ";
        std::cin >> y;

        if(x >= 0 && y >= 0 && x <= y)
            break;
        else
            std::cout << "Invalid values, try again\n";
    }

    openingPeriod = y - x;

    while(true)
    {
        std::cout << "Set cashiers number: ";
        std::cin >> x;

        if(x >= 1)
            break;
        else
            std::cout << "Invalid value, try again\n";
    }

    cashiers.resize(x);

    while(true)
    {
        std::cout << "Set migration value: ";
        std::cin >> x;

        if(x >= 2)
            break;
        else
            std::cout << "Invalid value, try again\n";
    }

    migrationValue = x;
}

void Shop::setVaraibles(int openTime, int closeTime, int cashNumber, int migration)
{
    if(openTime >= 0 && closeTime >= 0 && closeTime > openTime)
        openingPeriod = closeTime - openTime;
    else
        std::cout << "Invalid opening time values\n";

    if(cashNumber > 0)
        cashiers.resize(cashNumber);
    else
        std::cout << "Invalid cashiers number values\n";

    if(migration > 1)
        migrationValue = migration;
    else
        std::cout << "Invalid migration value\n";
}

int Shop::getCustomerNumbers(int type) const
{
    int count = 0;

    if(type == ALL)
        return customers.size();

    for(int i = 0; i < customers.size(); i++)
    {
        if(customers[i]->getType() == type)
            count++;
    }

    return count;
}

void Shop::update(int time)
{
    if(time % ONE_MINUTE == 0)
        updateChoosingTime();

    for(int i = 0; i < cashiers.size(); i++)
        cashiers[i].update();

    updateMigration();
}

void Shop::updateChoosingTime()
{
    for(int i = 0; i < customers.size(); i++)
    {
        customers[i]->decreaseChoosingTime();

        if(customers[i]->getChoosingTime() <= 0)
        {
            getShortestCashier().push(customers[i]);
            customers.erase(customers.begin() + i);
        }
    }
}

Cashier & Shop::getShortestCashier()
{
    if(cashiers.size() > 0)
    {
        unsigned shortest = cashiers[0].size();
        unsigned index = 0;

        for (int i = 1; i < cashiers.size(); i++)
        {
            if (shortest > cashiers[i].size())
            {
                shortest = cashiers[i].size();
                index = i;
            }
        }

        return cashiers[index];
    }
    else
        std::cout << "There is no any cashier\n";

}

Cashier & Shop::getLongestCashier()
{
    if(cashiers.size() > 0)
    {
        unsigned longest = cashiers[0].size();
        unsigned index = 0;

        for (int i = 1; i < cashiers.size(); i++)
        {
            if (longest < cashiers[i].size())
            {
                longest = cashiers[i].size();
                index = i;
            }
        }

        return cashiers[index];
    }
	else
        std::cout << "There is no any cashier\n";
}

void Shop::updateMigration()
{
    if (getShortestCashier().size() + migrationValue <= getLongestCashier().size())
	{
		getShortestCashier().push(getLongestCashier().getBack());
		getLongestCashier().pop();

		do {
			getShortestCashier().push(getLongestCashier().getBack());
			getLongestCashier().pop();
		} while (getShortestCashier().size() + 1 < getLongestCashier().size());
	}
}


