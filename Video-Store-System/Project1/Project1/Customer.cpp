#include "Customer.h"


Customer::Customer()
{
	this->name = "NotSet";
	this->phone = 0;
	this->videosRented = 0;
	this->ID = (-1);
	this->videosRentedMax = 10;
	this->videosRentedID = new int[videosRentedMax];
	
}
string Customer::getName()
{
	return name;
}
unsigned long long  Customer::getPhone()
{
	return phone;
}
int Customer::getVideosRented()
{
	return videosRented;
}
int* Customer::getVideosRentedID(){
	return videosRentedID;
}
int Customer::getID()
{
	return ID;
}
void Customer::setID(int ID){
	this->ID = ID;
}
void Customer::setName(string name)
{
	this->name = name;
}
void Customer::setPhone(unsigned long long  phone)
{
	this->phone = phone;
}
void Customer::setVideosRented(int videosRented){
	this->videosRented = videosRented;
}
void Customer::setVideosRentedID(int* videosRentedID){
	this->videosRentedID = videosRentedID;
}
bool Customer::addVideo(int itemID){
	//adds video to list, if video is already in list then don't add.
	//if list is full then resize.
	for (int i = 0; i < videosRented; i++){
		if (videosRentedID[i] == itemID){
			return false;
		}
	}

	if (videosRented >= videosRentedMax){
		videosRentedMax += 10;
		int* temp = videosRentedID;
		videosRentedID = new int[videosRentedMax];
		for (int i = 0; i < videosRented; i++){
			videosRentedID[i] = temp[i];
		}
	}
	else{
		videosRentedID[videosRented] = itemID;
	}
	videosRented = videosRented + 1;
	return true;
}
bool Customer::removeVideo(int itemID)
{
	//removes itemID from list
	//will also push forwards the data in list to remove empty space.
	for (int i = 0; i < videosRented; i++){
		if (videosRentedID[i] == itemID){
			
			if (i == videosRented){
				videosRentedID[videosRented] = (-1);
			}
			else{
				for (int j = i; j < videosRented; j++){
					videosRentedID[j] = videosRentedID[j + 1];
					videosRentedID[videosRented] = (-1);
				}
			}
			videosRented--;
			return true;
		}
	}
	//returns false if item was not rented by customer.
	return false;
}

Customer::~Customer()
{
	delete videosRentedID;
}
