#pragma once
#include "Item.h"
#include "ItemList.h"
class Beverage :
    public Item
{
private:
    float abv;
    int volume;

public:
    std::string toString();

    //Constructor
    Beverage(std::string _name, float _price, int _calories, int _volume, float _abv)
    {
        name = _name;
        price = _price;
        calories = _calories;
        volume = _volume;
        abv = _abv;
    }

};

