#ifndef ITEM
#define ITEM
#include<string>
using namespace std;
class Item
{
public:
	Item();
	Item(string title, int quantity, int itemID, int category);
	string getTitle();
	int getQuantity();
	int getItemID();
	int getCategory();
	void setCategory(int category);
	void setQuantity(int quantity);
	void setTitle(string title);
	void setID(int itemID);
private:
	string title; // title of item
	int quantity; // quantity of item.
	int itemID; // ID of item
	int category; // 1 for feature, 2 for comedy, 3 for horror.

};

#endif