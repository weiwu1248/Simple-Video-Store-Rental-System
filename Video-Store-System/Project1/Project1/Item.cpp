#include "Item.h"


Item::Item()
{
	title = "NotSet";
	quantity = 0;
	itemID = (-1);
}
Item::Item(string title, int quantity, int itemID, int category)
{
	this->title = title;
	this->quantity = quantity;
	this->itemID = itemID;
	this->category = category;
}
string Item::getTitle(){
	return title;
}
int Item::getQuantity(){
	return quantity;
}
int Item::getItemID(){
	return itemID;
}
int Item::getCategory(){
	return category;
}
void Item::setCategory(int category){
	this->category = category;
}
void Item::setQuantity(int quantity){
	this->quantity = quantity;
}
void Item::setTitle(string title){
	this->title = title;
}
void Item::setID(int itemID){
	this->itemID = itemID;
}
