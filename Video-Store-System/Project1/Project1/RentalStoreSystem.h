#ifndef RENTALSTORESYSTEM_H
#define RENTALSTORESYSTEM_H
#include"Customer.h"
#include"Item.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class RentalStoreSystem
{
public:
	RentalStoreSystem();
	void run();
	bool readFile();
	bool writeFile();
	int searchCustomerPhone(unsigned long long  phone);
	bool rentItem(int customerID, int itemID);
	bool returnItem(int customerID, int itemID);
	bool addCustomer(int ID, string name, unsigned long long  phone);
	bool addItem(int itemID, string title, int quantity, int category);
	bool itemIDExist(int itemID);
	void displayCustomers();
	void displayItems();
	~RentalStoreSystem();
private:
	Item* items; //Pointer to array of items
	Customer* customers; //Pointer to array of customers
	int itemsMax; //Max size of item array
	int customersMax; //Max size of customer array
	int itemCount; //number of items
	int customerCount; //number of customers
};

#endif