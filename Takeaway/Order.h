#pragma once
#include "ItemList.h"
#include "Appetiser.h"
#include <fstream>
#include <sstream>
#include <algorithm>

class Order :
    public ItemList
{
private:
    float savings, total;
    int num_Of_twoForOne;
public:
    string toString();
    void add(Item* choice);
    void remove(int index);
    void calculateTotal();
    void printReceipt();
    vector<Item*>orderItems;
    

};

