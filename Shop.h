#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include <vector>
#include "Customer.h"
#include <Cashier.h>

class Shop
{
    public:
        Shop();
        virtual ~Shop();

    private:
        int openingPeriod = 0;
        int migrationValue = 2;
        std::vector <Customer *> customers;
        std::vector <Cashier> cashiers;

        void updateChoosingTime();
        void updateMigration();

        Cashier & getShortestCashier();
        Cashier & getLongestCashier();

    public:
        void push(Customer * item) {customers.push_back(item);}
        void update(int time);

        void setVaraibles();
        void setVaraibles(int openTime, int closeTime, int cashNumber, int migration);
        int getOpeningPeriod() const {return openingPeriod;}
        int getCustomerNumbers(int type) const;
        int getCashiersNumber() const {return cashiers.size();}
        int getCashierSize(int index) {return cashiers[index].size();}

        void show() const;
};

#endif // SHOP_H
