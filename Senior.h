#ifndef SENIOR_H
#define SENIOR_H
#include "Customer.h"

class Senior : public Customer
{
    public:
        Senior();
        virtual ~Senior();

        virtual void show() const override;
        static void increaseAllCustomers() {allCustomers++;}
        static void increaseAllServiceTime(int time) {allServiceTime += time;}
        static int getAllCustomers() {return allCustomers;}
        static int getAllServiceTime() {return allServiceTime;}

    private:
        static int allCustomers;
        static int allServiceTime;
};

#endif // SENIOR_H
