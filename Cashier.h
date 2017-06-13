#ifndef CASHIER_H
#define CASHIER_H
#include "Queue.h"
#include "Customer.h"

class Cashier : public Queue <Customer *>
{
    public:
        Cashier();
        virtual ~Cashier();

    private:
        static Interval scanningTime; //as milliseconds
        int waitingTime = 0;
        static int longestWaitingTime;

        void updateServiceTime();
        void updateCustomersWaitingTime();
        void updateCashierWaitingTime(); //as milliseconds

    public:
        static void setScanningTime();
        static void setScanningTime(int minTime, int maxTime);
        static Interval getScanningTime() {return scanningTime;}
        static int getLongestWaitingTime() {return longestWaitingTime;}

        void update();
};

#endif // CASHIER_H
