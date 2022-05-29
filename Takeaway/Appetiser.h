#pragma once
#include "Item.h"
#include "ItemList.h"
#include <string>
#include <cstring>
class Appetiser :
    public Item
{
private:
    bool shareable, twoForOne;

public:
    bool get_twoForOne();

    //Constructor
    Appetiser(std::string _name, float _price, int _calories, bool _shareable, bool _twoForOne)
    {
        name = _name;
        price = _price;
        calories = _calories;
        shareable = _shareable;
        twoForOne = _twoForOne;
    }

    std::string toString();

    

};

