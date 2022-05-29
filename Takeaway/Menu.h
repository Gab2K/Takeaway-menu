#pragma once
#include "ItemList.h"
#include <string>
#include <cstring>
#include <iostream>  
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

class Menu : public ItemList
{
   
public:
    vector <Item*> items;
    vector <float> sortByPrice;
    string toString();
    //Constructor
    Menu(string fileName);


};

