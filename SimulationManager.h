#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "CustomerType.h"
#include "Junior.h"
#include "Average.h"
#include "Senior.h"
#include "Shop.h"
#include "Factory.h"

class SimulationManager
{
    public:
        SimulationManager();
        virtual ~SimulationManager();

    private:
        CustomerType customerTypes[ALL];
        Shop shop;
        Factory factory;
        std::ofstream file;
        int analysisPeriod = 0;

        void setAnalysisPeriod();
        void setAnalysisPeriod(int t);
        void setAutomaticCustomerTypesVariables();
        void setManualCustomerTypesVariables();
        void createFileHeaders();
        void saveData(int hour, int cycle);
        void saveConvertedValue(int value, std::ofstream &stream); //save value in the time type (hours:minutes:seconds:milliseconds)

    public:
        void run();
};

#endif // SIMULATIONMANAGER_H
