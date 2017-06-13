#ifndef JUNIOR_H
#define JUNIOR_H
#include "Customer.h"

class Junior : public Customer
{
    public:
        Junior();
        virtual ~Junior();

        virtual void show() const override;
        static void increaseAllCustomers() {allCustomers++;}
        static void increaseAllServiceTime(int time) {allServiceTime += time;}
        static int getAllCustomers() {return allCustomers;}
        static int getAllServiceTime() {return allServiceTime;}

    private:
        static int allCustomers;
        static int allServiceTime;
};

#endif // JUNIOR_H
