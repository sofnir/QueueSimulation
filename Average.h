#ifndef AVERAGE_H
#define AVERAGE_H
#include "Customer.h"

class Average : public Customer
{
    public:
        Average();
        virtual ~Average();

        virtual void show() const override;
        static void increaseAllCustomers() {allCustomers++;}
        static void increaseAllServiceTime(int time) {allServiceTime += time;}
        static int getAllCustomers() {return allCustomers;}
        static int getAllServiceTime() {return allServiceTime;}

    private:
        static int allCustomers;
        static int allServiceTime;
};

#endif // AVERAGE_H
