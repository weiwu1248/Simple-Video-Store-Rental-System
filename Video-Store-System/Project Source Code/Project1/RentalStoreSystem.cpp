#include "RentalStoreSystem.h"


RentalStoreSystem::RentalStoreSystem()
{
	itemsMax = 10;
	customersMax = 10;
	itemCount = 0;
	customerCount = 0;
	items = new Item[itemsMax];
	customers = new Customer[customersMax];

}
void RentalStoreSystem::run(){
	if (!readFile()){//Inputs data from file.
		cout << "\nError occurred when trying to read from file.\n";
		cout << "Please check if file exist or if its already open.\n";
		cout << "Program will auto create file if it does not exist.\n\n";
	}
	bool run = true; //keeps the program running.
	int inputIntTemp = 0;
	//main program loop
	cout << "Welcome. This is a rental store system.\n";
	while (run){
		//loop for input of options.
		while (true){
			cout << "\nPick a option:\n";
			cout << "(0) Quit\n";
			cout << "(1) Rent Item\n";
			cout << "(2) Return Item\n";
			cout << "(3) Add New Customer\n";
			cout << "(4) Add New Item\n";
			cout << "(5) Display Customers\n";
			cout << "(6) Display Items\n";
			cin >> inputIntTemp;
			//check if input is within option range.
			if (inputIntTemp >= 0 && inputIntTemp <= 6 && !cin.fail()){
				break;
			}
			else{
				//will continue to ask for input until it is correct.
				//clears cin incase it failed.
				
				cout << "Error with input, please retry.\n";
			}
		}
		//option 0
		if (inputIntTemp == 0){
			//exits program.
			cout << "\nProgram ended.\n";
			run = false;
		}
		//option 1
		if (inputIntTemp == 1){
			//temp data holders.
			unsigned long long  phoneTemp = 0;
			int itemTemp = 0;
			int idTemp = 0;
			cout << "You selected: Rent Item\n";
			do{
				//clear cin if it fails
				if (cin.fail()){
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Error in input try again.\n";
				}
				cout << "Input customer phone number: ";
				cin >> phoneTemp;
				//will continue to ask for input untill successful
			} while (cin.fail());

			do{
				//clear cin if it fails
				if (cin.fail()){
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Error in input try again.\n";
				}
				cout << "Input the item ID to rent out: ";
				cin >> itemTemp;
				//will continue to ask for input untill successful
			} while (cin.fail());

			idTemp = searchCustomerPhone(phoneTemp); // gets the customer ID by searching with phone number.
			if (idTemp < 0){
				//check if customer was found or not.
				cout << "Customer Not Found\n";
			}
			else{
				if (rentItem(idTemp, itemTemp)){
					//attemps to rent out item.
					cout << "Item has been successfully rented\n";
				}
				else{
					cout << "Error. Please check if item exist and if its in stock.\n";
				}
			}	
		}
		//option 2
		if (inputIntTemp == 2){
			//temp data holders.
			unsigned long long  phoneTemp = 0;
			int itemTemp = 0;
			int idTemp = 0;
			cout << "You selected: Return Item\n";
			do{
				//clear cin if it fails
				if (cin.fail()){
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Error in input try again.\n";
				}
				cout << "Input customer phone number: ";
				cin >> phoneTemp;
				//will continue to ask for input untill successful
			} while (cin.fail());

			do{
				//clear cin if it fails
				if (cin.fail()){
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Error in input try again.\n";
				}
				cout << "Input the item ID to return: ";
				cin >> itemTemp;
				//will continue to ask for input untill successful
			} while (cin.fail());

			idTemp = searchCustomerPhone(phoneTemp);// gets the customer ID by searching with phone number.
			if (idTemp < 0){
				//check if customer was found or not.
				cout << "Customer Not Found\n";
			}
			else{
				if (returnItem(idTemp, itemTemp)){
					//attemps to return item.
					cout << "Item has been successfully returned\n";
				}
				else{
					cout << "Error. Please check if item ID is correct.\n";
				}
			}
		}
		//option 3
		if (inputIntTemp == 3){
			//temp data holders.
			unsigned long long  phoneTemp = 0;
			string nameTemp = "NotSet";
			cout << "You selected: Add New Customer\n";
			do{
				//clear cin if it fails
				if (cin.fail()){
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Error in input try again.\n";
				}
				cout << "Input customer name: ";
				cin >> nameTemp;
				//will continue to ask for input untill successful
			} while (cin.fail());

			do{
				//clear cin if it fails
				if (cin.fail()){
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Error in input try again.\n";
				}
				cout << "input customer phone: ";
				cin >> phoneTemp;
				//will continue to ask for input untill successful
			} while (cin.fail());

			if (addCustomer(customerCount, nameTemp, phoneTemp)){
				//attemps to add the customer to system.
				cout << "Customer has been added to system.\n";
			}
			else{
				cout << "Error. Please check wether a customer already exist with the same phone number.\n";
			}
		}
		//option 4
		if (inputIntTemp == 4){
			//temp data holders.
			string titleTemp = "NotSet";
			int quantityTemp = 0;
			int categoryTemp = 1;
			cout << "You selected: Add New Item\n";

			do{
				//clear cin if it fails
				if (cin.fail()){
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Error in input try again.\n";
				}
				cout << "Input title: ";
				cin >> titleTemp;
				//will continue to ask for input untill successful
			} while (cin.fail());
			do{
				//clear cin if it fails
				if (cin.fail()){
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Error in input try again.\n";
				}
				cout << "Input quantity: ";
				cin >> quantityTemp;
				//will continue to ask for input untill successful
			} while (cin.fail());

			do{
				//clear cin if it fails
				if (cin.fail()){
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Error in input try again.\n";
				}
				cout << "Input category(1 for feature, 2 for comedy, 3 for horror): ";
				cin >> categoryTemp;
				//will continue to ask for input untill successful
			} while (cin.fail());


			if (addItem(itemCount, titleTemp, quantityTemp, categoryTemp)){
				//attemps to add the title to system.
				cout << "Item has been added to system.\n";
			}
			else{
				cout << "Error. Check if values inputed are correct or wether item title already exist.\n";
			}

		}
		//option 5
		if (inputIntTemp == 5){
			//prints out customers.
			displayCustomers();
		}
		if (inputIntTemp == 6){
			//prints out items.
			displayItems();
		}
		
		if (!writeFile()){//Saves data to file.
			//outputs error message if writeFile() fails.
			cout << "\nError occurred when trying to write to file.\n";
			cout << "Please check if file exist or if its already open.\n\n";
		}
	}

	
}
bool RentalStoreSystem::readFile()
{
	ifstream customerFile;
	ifstream itemFile;
	customerFile.open("customers.txt");
	itemFile.open("items.txt");
	
	//Check if files are open
	if (!customerFile.is_open() || !itemFile.is_open()){
		return false;
	}


	//temp data golders
	string marker = "";
	string titleHolder = "";
	string nameHolder = "";
	unsigned long long  phoneHolder = 0;
	int idHolder = 0;
	int quantityHolder = 0;
	int videoCountHolder = 0;
	int videoIDHolder = 0;
	int categoryHolder = 1;
	//loop for item data input
	while (itemFile >> marker){
		if (marker == "ItemID:"){
			itemFile >> idHolder;
		}
		itemFile >> marker;
		if (marker == "Title:"){
			itemFile >> titleHolder;
		}
		itemFile >> marker;
		if (marker == "Quantity:"){
			itemFile >> quantityHolder;
		}
		itemFile >> marker;
		if (marker == "Category:"){
			char tempChar;
			itemFile >> tempChar;
			if (tempChar == 'f'){
				categoryHolder = 1;
			}
			if (tempChar == 'c'){
				categoryHolder = 2;
			}
			if (tempChar == 'h'){
				categoryHolder = 3;
			}
		}
		addItem(idHolder,titleHolder,quantityHolder,categoryHolder);//adds the item to memory
	}
	//loop for customer data input
	while (customerFile >> marker){
		if (marker == "CustomerID:"){
			customerFile >> idHolder;
		}
		customerFile >> marker;
		if (marker == "CustomerName:"){
			customerFile >> nameHolder;
		}
		customerFile >> marker;
		if (marker == "CustomerPhone:"){
			customerFile >> phoneHolder;
		}

		addCustomer(idHolder,nameHolder,phoneHolder); // adds customer to memory

		//adds the videos rented by the customer
		customerFile >> marker;
		if (marker == "VideoCount:"){
			customerFile >> videoCountHolder;
		//	customers[customerCount-1].setVideosRented(videoCountHolder);
		}
		customerFile >> marker;
		if (marker == "VideosRented:"){
			for (int i = 0; i < videoCountHolder; i++){
				customerFile >> videoIDHolder;
				customers[customerCount-1].addVideo(videoIDHolder);
			}
		}
	}
	customerFile.close();
	itemFile.close();
	return true;
}
bool RentalStoreSystem::writeFile()
{
	ofstream customerFile;
	ofstream itemFile;
	customerFile.open("customers.txt");
	itemFile.open("items.txt");

	//check if file is open
	if (!customerFile.is_open() || !itemFile.is_open()){
		return false;
	}

	//outputs all item data to file.
	for (int i = 0; i < itemCount; i++){
		itemFile << "ItemID:" << endl;
	    itemFile << items[i].getItemID() << endl;
		itemFile << "Title:" << endl;
		itemFile << items[i].getTitle() << endl;
		itemFile << "Quantity:" << endl;
		itemFile << items[i].getQuantity() << endl;
		itemFile << "Category:" << endl;
		if (items[i].getCategory() == 1){
			itemFile << "f" << endl;
		}
		else if (items[i].getCategory() == 2){
			itemFile << "c" << endl;
		}
		else if (items[i].getCategory() == 3){
			itemFile << "h" << endl;
		}
		
	}
	//outputs all customer data to file.
	for (int i = 0; i < customerCount; i++){
		customerFile << "CustomerID:" << endl;
		customerFile << customers[i].getID() << endl;
		customerFile << "CustomerName:" << endl;
		customerFile << customers[i].getName() << endl;
		customerFile << "CustomerPhone:" << endl;
		customerFile << customers[i].getPhone() << endl;
		customerFile << "VideoCount:" << endl;
		customerFile << customers[i].getVideosRented() << endl;
		customerFile << "VideosRented:" << endl;
		//for loop to output the videos rented by customer.
		for (int j = 0; j < customers[i].getVideosRented(); j++){
			customerFile << customers[i].getVideosRentedID()[j] << endl;
		}
	}


	customerFile.close();
	itemFile.close();
	return true;
}
int RentalStoreSystem::searchCustomerPhone(unsigned long long  phone)
{
	//search customer by phone, returns customer ID.
	for (int i = 0; i < customerCount;i++){
		if (customers[i].getPhone() == phone){
			return customers[i].getID();
		}
	}
	return (-1);
	//returning -1 means not found.
}
bool RentalStoreSystem::rentItem(int customerID, int itemID)
{
	if (!itemIDExist(itemID)){
		//if item ID does not exist.
		return false;
	}

	//checks quantity of item, must be above 0
	if (items[itemID].getQuantity() > 0){
		//adds the itemID to the customer
		//will fail if customer has already rented item.
		if (customers[customerID].addVideo(itemID)){
			//decrease quantity of the item.
			items[itemID].setQuantity(items[itemID].getQuantity() - 1);
			return true;
			//returns true is successful
		}
	}
	return false;
}
bool RentalStoreSystem::returnItem(int customerID, int itemID)
{

	if (!itemIDExist(itemID)){
		//if item ID does not exist.
		return false;
	}

	if (customers[customerID].removeVideo(itemID)){
		items[itemID].setQuantity(items[itemID].getQuantity() + 1);
		return true;
	}
	return false;
	
}
bool RentalStoreSystem::addCustomer(int ID, string name, unsigned long long  phone)
{
	if (!(searchCustomerPhone(phone) == (-1))){
		return false;
	}
	if (customerCount >= customersMax){
		Customer* tempCustomers = new Customer[customersMax + 10];
		for (int i = 0; i < customerCount; i++){
			tempCustomers[i].setID(customers[i].getID());
			tempCustomers[i].setName(customers[i].getName());
			tempCustomers[i].setPhone(customers[i].getPhone());
			tempCustomers[i].setVideosRented(customers[i].getVideosRented());
			int* temp = new int[customers[i].getVideosRented()];
			for (int j = 0; j < customers[i].getVideosRented(); i++){
				temp[j] = customers[i].getVideosRentedID()[i];
			}
			tempCustomers[i].setVideosRentedID(temp);
		}
		delete[] customers;
		customers = tempCustomers;
	}
	else{
		customers[customerCount].setID(ID);
		customers[customerCount].setName(name);
		customers[customerCount].setPhone(phone);
		customerCount = customerCount + 1;
	}
	return true;
}
bool RentalStoreSystem::addItem(int itemID, string title, int quantity, int category)
{
	if (quantity < 0){
		return false;
	}
	if (!(category >= 1 && category <= 3)){
		return false;
	}
	for (int i = 0; i < itemCount; i++){
		//Check if item title already exist.
		if (items[i].getTitle() == title){
			return false;
		}
	}
	if (itemCount >= itemsMax){
		itemsMax += 10;
		Item* tempItems = items;
		items = new Item[itemsMax];
		for (int i = 0; i < itemCount; i ++){
			items[i].setID(tempItems[i].getItemID());
			items[i].setTitle(tempItems[i].getTitle());
			items[i].setQuantity(tempItems[i].getQuantity());
			items[i].setCategory(tempItems[i].getCategory());
				
		}	
	}
	else{
		items[itemCount].setTitle(title);
		items[itemCount].setQuantity(quantity);
		items[itemCount].setCategory(category);
		items[itemCount].setID(itemID);
		itemCount = itemCount + 1;
	}
	return true;
}
bool RentalStoreSystem::itemIDExist(int itemID){
	for (int i = 0; i < itemCount; i++){
		//Check if item ID exist.
		if (items[i].getItemID() == itemID){
			return true;
		}
	}
	
		//if item ID does not exist.
		return false;
}
void RentalStoreSystem::displayCustomers(){
	for (int i = 0; i < customerCount; i++){
		cout << endl;
		cout << "Customer ID: ";
		cout << customers[i].getID() << endl;
		cout << "Customer Name: ";
		cout << customers[i].getName() << endl;
		cout << "Customer Phone Number: ";
		cout << customers[i].getPhone() << endl;
		cout << "Number of items rented: ";
		cout << customers[i].getVideosRented() << endl;
		cout << "List of the IDs of rented items: " << endl;
		for (int j = 0; j < customers[i].getVideosRented(); j++){
			cout << customers[i].getVideosRentedID()[j] << endl;
		}
	}
}
void RentalStoreSystem::displayItems(){
	for (int i = 0; i < itemCount; i++){
		cout << endl;
		cout << "Item ID: ";
		cout << items[i].getItemID() << endl;
		cout << "Item Title: ";
		cout << items[i].getTitle() << endl;
		cout << "Item Quantity: ";
		cout << items[i].getQuantity() << endl;
		cout << "Item Category: ";
		if (items[i].getCategory() == 1){
			cout << "feature" << endl;
		}
		else if (items[i].getCategory() == 2){
			cout << "comedy" << endl;
		}
		else if (items[i].getCategory() == 3){
			cout << "horror" << endl;
		}
		
	}
}
RentalStoreSystem::~RentalStoreSystem()
{
	delete[] items;
	delete[] customers;
}
