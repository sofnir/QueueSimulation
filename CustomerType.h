#ifndef CUSTOMERTYPE_H
#define CUSTOMERTYPE_H
#include <iostream>
#include <cstdlib>

struct Interval
{
    int min;
    int max;
};

enum Types {JUNIOR, AVERAGE, SENIOR, ALL};

const int ONE_HOUR = 3600000; //as ms
const int ONE_MINUTE = 60000;
const int ONE_SECOND = 1000;

class CustomerType
{
    public:
        CustomerType();
        CustomerType(const CustomerType & customerType);
        CustomerType & operator =(const CustomerType & customerType);
        virtual ~CustomerType();

    private:
        Types type;
        Interval productsNumber = {0, 0};
        Interval choosingTime = {0, 0}; //as minutes;
        Interval packingTime = {0, 0}; //as milliseconds per product
        Interval payingTime = {0, 0}; //as seconds
        int visitsSize = 0;
        Interval *visitsNumber;
        double *arrivalPeriodTime;

        int randValue(int minValue, int maxValue) {return std::rand() % (maxValue - minValue) + minValue;}

    public:
        void setType(int t);
        void setProductsNumber();
        void setProductsNumber(int pn_min, int pn_max);
        void setChoosingTime();
        void setChoosingTime(int cht_min, int cht_max);
        void setPackingTime();
        void setPackingTime(int pt_min, int pt_max);
        void setPayingTime();
        void setPayingTime(int pt_min, int pt_max);
        void setVisitsNumber();
        void resizeVisitsNumber(int vs);
        void setVisitsNumber(int hour, int vn_min, int vn_max);

        Interval getProductsNumber() const {return productsNumber;}
        Interval getChoosingTime() const {return choosingTime;}
        Interval getPackingTime() const {return packingTime;}
        Interval getPayingTime() const {return payingTime;}
        double getArrivalPeriodTime(int index) const {return arrivalPeriodTime[index];}

        void show() const;
};

#endif // CUSTOMERTYPE_H
