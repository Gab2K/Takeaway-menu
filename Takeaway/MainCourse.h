#pragma once
#include "Item.h"
#include "ItemList.h"
class MainCourse :
    public Item
{
public:
    std::string toString();

    //Constructor
    MainCourse(std::string _name, float _price, int _calories)
    {
        name = _name;
        price = _price;
        calories = _calories;
    }
};

