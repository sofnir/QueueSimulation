#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "CustomerType.h"
#include <iostream>

class Customer
{
public:
	Customer(const Types & t);
	virtual ~Customer() = 0;

private:
    Types type;
	int productsNumber = 0;
	int choosingTime = 0; //as minutes
	int packingTime = 0; //as milliseconds per product
	int payingTime = 0; //as seconds
	int serviceTime = 0; //as milliseconds
	int waitingTime = 0; //as milliseconds
	static int longestWaitingTime;
    static int allServiceTime;
    static int allCustomers;

public:
    void setProductsNumber(int pn);
	void setChoosingTime(int cht);
	void setPackingTime(int pt);
	void setPayingTime(int pt);
	void setServiceTime(int st);
	static void setLongestWaitingTime(int time) {longestWaitingTime = time;}
	static void increaseAllServiceTime(int time) {allServiceTime += time;}
	static void increaseAllCustomers() {allCustomers++;}

	Types getType() {return type;}
	int getProductsNumber() const { return productsNumber; }
	int getChoosingTime() const { return choosingTime; }
	int getPackingTime() const { return packingTime; }
	int getPayingTime() const { return payingTime; }
	int getServiceTime() const {return serviceTime;}
	int getWaitingTime() const {return waitingTime;}
	static int getLongestWaitingTime() {return longestWaitingTime;}
	static int getAllServiceTime() {return allServiceTime;}
	static int getAllCustomers() {return allCustomers;}

	virtual void show() const = 0;
	void decreaseChoosingTime() {if(choosingTime > 0) choosingTime--;}
	void decreaseServiceTime() {if(serviceTime > 0) serviceTime -= 100;}
	void increaseWaitingTime() {waitingTime += 100;}

protected:
	void showVariables() const;
};

#endif // CUSTOMER_H
