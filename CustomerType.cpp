#include "CustomerType.h"

CustomerType::CustomerType()
{
    ;
}

CustomerType::~CustomerType()
{
    delete[] visitsNumber;
    delete[] arrivalPeriodTime;
}

CustomerType::CustomerType(const CustomerType & customerType)
{
	productsNumber = customerType.productsNumber;
	choosingTime = customerType.choosingTime;
	packingTime = customerType.packingTime;
	payingTime = customerType.payingTime;
	visitsSize = customerType.visitsSize;

	visitsNumber = new Interval [visitsSize];
	arrivalPeriodTime = new double [visitsSize];

	for (int i = 0; i < visitsSize; i++)
    {
        visitsNumber[i] = customerType.visitsNumber[i];
        arrivalPeriodTime[i] = customerType.arrivalPeriodTime[i];
    }

}

CustomerType & CustomerType::operator=(const CustomerType & customerType)
{
	if (this == & customerType)
		return * this;

	productsNumber = customerType.productsNumber;
	choosingTime = customerType.choosingTime;
	packingTime = customerType.packingTime;
	payingTime = customerType.payingTime;
	visitsSize = customerType.visitsSize;

	delete[] visitsNumber;
	delete[] arrivalPeriodTime;
	visitsNumber = new Interval [visitsSize];
	arrivalPeriodTime = new double [visitsSize];

	for (int i = 0; i < visitsSize; i++)
    {
        visitsNumber[i] = customerType.visitsNumber[i];
        arrivalPeriodTime[i] = customerType.arrivalPeriodTime[i];
    }

	return *this;
}

void CustomerType::setType(int t)
{
    if(t >= JUNIOR && t <= SENIOR)
        type = (Types)t;
}

void CustomerType::setProductsNumber()
{
    int valueMin, valueMax;

    while(true)
    {
        std::cout << "Set products number\n";
        std::cout << "Minimum: ";
        std::cin >> valueMin;
        std::cout << "Maximum: ";
        std::cin >> valueMax;

        if(valueMin >= 0 && valueMin <= valueMax)
            break;
        else
            std::cout << "Invalid values, try again\n";
    }

    productsNumber.min = valueMin;
    productsNumber.max = valueMax;
}

void CustomerType::setProductsNumber(int pn_min, int pn_max)
{
    if(pn_min >= 0 && pn_max >= pn_min)
        productsNumber = {pn_min, pn_max};
    else
        std::cout << "Invalid products number value\n";
}

void CustomerType::setChoosingTime()
{
    int valueMin, valueMax;

    while(true)
    {
        std::cout << "Set choosing time [m]\n";
        std::cout << "Minimum: ";
        std::cin >> valueMin;
        std::cout << "Maximum: ";
        std::cin >> valueMax;

        if(valueMin >= 0 && valueMin <= valueMax)
            break;
        else
            std::cout << "Invalid values, try again\n";
    }

    choosingTime.min = valueMin;
    choosingTime.max = valueMax;
}

void CustomerType::setChoosingTime(int cht_min, int cht_max)
{
    if(cht_min >= 0 && cht_max >= cht_min)
        choosingTime = {cht_min, cht_max};
    else
        std::cout << "Invalid choosing time values\n";
}

void CustomerType::setPackingTime()
{
    int valueMin, valueMax;

    while(true)
    {
        std::cout << "Set packing time [~100 ms]\n";
        std::cout << "Minimum: ";
        std::cin >> valueMin;
        std::cout << "Maximum: ";
        std::cin >> valueMax;

        if(valueMin >= 0 && valueMin <= valueMax && valueMin % 100 == 0 && valueMax % 100 == 0)
            break;
        else
            std::cout << "Invalid values, try again\n";
    }

    packingTime.min = valueMin;
    packingTime.max = valueMax;
}

void CustomerType::setPackingTime(int pt_min, int pt_max)
{
    if(pt_min >= 0 && pt_max >= pt_min && pt_min % 100 == 0 && pt_max % 100 == 0)
        packingTime = {pt_min, pt_max};
    else
        std::cout << "Invalid packing time values\n";
}

void CustomerType::setPayingTime()
{
    int valueMin, valueMax;

    while(true)
    {
        std::cout << "Set paying time [s]\n";
        std::cout << "Minimum: ";
        std::cin >> valueMin;
        std::cout << "Maximum: ";
        std::cin >> valueMax;

        if(valueMin >= 0 && valueMin <= valueMax)
            break;
        else
            std::cout << "Invalid values, try again\n";
    }

    payingTime.min = valueMin;
    payingTime.max = valueMax;
}

void CustomerType::setPayingTime(int pt_min, int pt_max)
{
    if(pt_min >= 0 && pt_max >= pt_min)
        payingTime = {pt_min, pt_max};
    else
        std::cout << "Invalid paying time values\n";
}

void CustomerType::setVisitsNumber()
{
	int valueMin, valueMax;

	std::cout << "Set visits number\n";

	for (int i = 0; i < visitsSize; i++)
	{
        while(true)
        {
            std::cout << "In the " << i + 1 << " hour\n";
            std::cout << "Minimum: ";
            std::cin >> valueMin;
            std::cout << "Maximum: ";
            std::cin >> valueMax;

            if(valueMin >= 0 && valueMin <= valueMax)
                break;
            else
                std::cout << "Invalid values, try again\n";
        }


        visitsNumber[i].min = valueMin;
        visitsNumber[i].max = valueMax;
        arrivalPeriodTime[i] = ONE_HOUR / randValue(valueMin, valueMax);
	}
}

void CustomerType::resizeVisitsNumber(int vs)
{
    if(vs >= 0)
    {
        visitsSize = vs;
        visitsNumber = new Interval [visitsSize];
        arrivalPeriodTime = new double [visitsSize];

        for (int i = 0; i < visitsSize; i++)
        {
            visitsNumber[i].min = 0;
            visitsNumber[i].max = 0;
            arrivalPeriodTime[i] = 0;
        }
    }
    else
        std::cout << "Invalid visits number values\n";
}

void CustomerType::setVisitsNumber(int hour, int vn_min, int vn_max)
{
    if(vn_min >= 0 && vn_max >= vn_min && hour >= 0 && hour <= visitsSize)
    {
        visitsNumber[hour].min = vn_min;
        visitsNumber[hour].max = vn_max;
        arrivalPeriodTime[hour] = ONE_HOUR / randValue(vn_min, vn_max);

    }
    else
        std::cout << "Invalid visits number values\n";
}

void CustomerType::show() const
{
    switch(type)
    {
    case JUNIOR:
        std::cout << "JUNIOR\n";
        break;
    case AVERAGE:
        std::cout << "AVERAGE\n";
        break;
    case SENIOR:
        std::cout << "SENIOR\n";
        break;
    default:
        std::cout << "NONE TYPE\n";
        break;
    }

    std::cout << "Products number: " << productsNumber.min << "-" << productsNumber.max
		<< " / Choosing time: " << choosingTime.min << "-" << choosingTime.max << " [m]"
		<< " / Packing time: " << packingTime.min << "-" << packingTime.max << " [ms/item]"
		<< " / Paying time: " << payingTime.min << "-" << payingTime.max  << " [s]" << std::endl;

	std::cout << "Visits";

	if (visitsSize == 0)
		std::cout << ": NONE\n";
	else
    {
        std::cout << std::endl;

        for (int i = 0; i < visitsSize; i++)
            std::cout << i + 1 << ": " << visitsNumber[i].min << "-" << visitsNumber[i].max << std::endl;
    }

    std::cout << std::endl;
}
