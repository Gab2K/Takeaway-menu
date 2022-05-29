#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include "Item.h"
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"

using namespace std;
class ItemList
{

public:
	virtual string toString() = 0;
protected:
	vector <Item*> items;
	
};

