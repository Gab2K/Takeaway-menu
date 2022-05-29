#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
class Item
{
protected:
	int calories;
	std::string name;
	float price;
public:
	virtual std::string toString() = 0;
	int getCalories();
	std::string getName();
	float getPrice();
	
};
