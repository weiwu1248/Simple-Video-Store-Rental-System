#ifndef CUSTOMER
#define CUSTOMER
#include<string>
using namespace std;
class Customer
{
public:
	Customer();
	string getName();
	unsigned long long  getPhone();
	int getVideosRented();
	int* getVideosRentedID();
	int getID();
	void setID(int ID);
	void setName(string name);
	void setPhone(unsigned long long  phone);
	void setVideosRented(int videosRented);
	void setVideosRentedID(int* videosRentedID);
	bool addVideo(int itemID);
	bool removeVideo(int itemID);
	~Customer();
private:
	string name;
	//unsigned long long to store large numbers like a phone number.
	unsigned long long phone; 
	int videosRented; //Number of videos customer has rented
	int ID; //ID of customer
	int* videosRentedID; //pointer to array of ints
	int videosRentedMax; //max size of array
};

#endif