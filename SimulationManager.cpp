#include "SimulationManager.h"

SimulationManager::SimulationManager() : factory(customerTypes), file("data.csv")
{
//    shop.setVaraibles(8, 10, 2, 2);
//    Cashier::setScanningTime(3400, 4500); //as milliseconds
//    setAnalysisPeriod(5);
//    setAutomaticCustomerTypesVariables();

    shop.setVaraibles();
    Cashier::setScanningTime();
    setAnalysisPeriod();
    std::cout << std::endl;
    setManualCustomerTypesVariables();

    createFileHeaders();
}

SimulationManager::~SimulationManager()
{
    ;
}

void SimulationManager::run()
{
    std::cout << "Please waiting...\n";

    for(int hour = 0; hour < shop.getOpeningPeriod(); hour++)
    {
        for(int time = 0; time <= ONE_HOUR; time += 100) //cycle = 100 ms
        {
            if(time % analysisPeriod == 0)
                saveData(hour, time);

            for(int i = 0; i < ALL; i++)
            {
                if(factory.isNewCustomer(i, hour))
                   shop.push(factory.createCustomer(i));
            }

            shop.update(time);
        }
    }
}

void SimulationManager::setAnalysisPeriod()
{
    int t;
    std::cout << "Set analysis period: ";

    while(true)
    {
        std::cin >> t;

        if(t >= 0)
            break;
        else
            std::cout << "Invalid value, try again\n";
    }

    analysisPeriod = t * ONE_MINUTE;
}

void SimulationManager::setAnalysisPeriod(int t)
{
    if(t >= 1)
        analysisPeriod = t * ONE_MINUTE;
    else
        std::cout << "Invalid value\n";
}

void SimulationManager::setManualCustomerTypesVariables()
{
    std::cout << "Set customers type variables\n\n";
    for(int i = 0; i < ALL; i++)
    {
        if(i == JUNIOR)
            std::cout << "Junior type\n";
        else if(i == AVERAGE)
            std::cout << "Average type\n";
        else if(i == SENIOR)
            std::cout << "Senior type\n";

        customerTypes[i].setType(i);
        customerTypes[i].setProductsNumber();
        customerTypes[i].setChoosingTime(); //as minutes
        customerTypes[i].setPackingTime(); //as milliseconds per product
        customerTypes[i].setPayingTime(); //as seconds
        customerTypes[i].resizeVisitsNumber(shop.getOpeningPeriod());
        customerTypes[i].setVisitsNumber();
        std::cout << std::endl;
        customerTypes[i].show();
    }
}

void SimulationManager::setAutomaticCustomerTypesVariables()
{
    customerTypes[JUNIOR].setType(JUNIOR);
    customerTypes[JUNIOR].setProductsNumber(5 , 20);
    customerTypes[JUNIOR].setChoosingTime(5, 10); //as minutes
    customerTypes[JUNIOR].setPackingTime(4000, 5000); //as milliseconds per product
    customerTypes[JUNIOR].setPayingTime(30, 60); //as seconds
    customerTypes[JUNIOR].resizeVisitsNumber(shop.getOpeningPeriod());
    customerTypes[JUNIOR].setVisitsNumber(0, 15, 20);
    customerTypes[JUNIOR].setVisitsNumber(1, 16, 22);

    customerTypes[AVERAGE].setType(AVERAGE);
    customerTypes[AVERAGE].setProductsNumber(20, 50);
    customerTypes[AVERAGE].setChoosingTime(15, 25);
    customerTypes[AVERAGE].setPackingTime(3500, 7500);
    customerTypes[AVERAGE].setPayingTime(40, 70);
    customerTypes[AVERAGE].resizeVisitsNumber(shop.getOpeningPeriod());
    customerTypes[AVERAGE].setVisitsNumber(0, 20, 30);
    customerTypes[AVERAGE].setVisitsNumber(1, 18, 28);

    customerTypes[SENIOR].setType(SENIOR);
    customerTypes[SENIOR].setProductsNumber(10 , 40);
    customerTypes[SENIOR].setChoosingTime(10, 30);
    customerTypes[SENIOR].setPackingTime(4500, 18000);
    customerTypes[SENIOR].setPayingTime(50, 90);
    customerTypes[SENIOR].resizeVisitsNumber(shop.getOpeningPeriod());
    customerTypes[SENIOR].setVisitsNumber(0, 15, 20);
    customerTypes[SENIOR].setVisitsNumber(1, 12, 18);

    for(int i = 0; i < ALL; i++)
        customerTypes[i].show();
}

void SimulationManager::createFileHeaders()
{
	file << "Cycle,Customers in the shop,1 type,2 type,3 type,";

	for (int i = 0; i < shop.getCashiersNumber(); i++)
		file << i + 1 << " cashier,";

	file << "Customer longest waiting time, Cashier longest waitimg time,Average service time,";

	for (int i = 0; i < ALL; i++)
		file << i + 1 << " type,";

	file << std::endl;
}

void SimulationManager::saveData(int hour, int cycle)
{
    saveConvertedValue(cycle + hour * ONE_HOUR, file);
	file << shop.getCustomerNumbers(ALL) << ",";

	for (int i = 0; i < ALL; i++)
		file << shop.getCustomerNumbers(i) << ",";

	for (int i = 0; i < shop.getCashiersNumber(); i++)
		file << shop.getCashierSize(i) << ",";

	saveConvertedValue(Customer::getLongestWaitingTime(), file);
	saveConvertedValue(Cashier::getLongestWaitingTime(), file);

    if(Customer::getAllCustomers() > 0)
        saveConvertedValue(Customer::getAllServiceTime() / (double)Customer::getAllCustomers(), file);
    else
        saveConvertedValue(0, file);

    if(Junior::getAllCustomers() > 0)
        saveConvertedValue(Junior::getAllServiceTime() / (double)Junior::getAllCustomers(), file);
    else
        saveConvertedValue(0, file);

    if(Average::getAllCustomers() > 0)
        saveConvertedValue(Average::getAllServiceTime() / (double)Average::getAllCustomers(), file);
    else
        saveConvertedValue(0, file);

    if(Senior::getAllCustomers() > 0)
        saveConvertedValue(Senior::getAllServiceTime() / (double)Senior::getAllCustomers(), file);
    else
        saveConvertedValue(0, file);

	file << std::endl;
}

void SimulationManager::saveConvertedValue(int value, std::ofstream & stream)
{
    int hour = value / ONE_HOUR;
    value -= hour * ONE_HOUR;
    int minute = value / ONE_MINUTE;
    value -= minute * ONE_MINUTE;
    int second = value / ONE_SECOND;
    int millisecond = value - second * ONE_SECOND;

	if (hour < 10)
		stream << "0";

	stream << hour << ":";

	if (minute < 10)
		stream << "0";

	stream << minute << ":";

	if (second < 10)
		stream << "0";

	stream << second << ":" << millisecond << ",";
}
