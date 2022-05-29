#include "Beverage.h"

string Beverage::toString()
{
	std::string abvText;
	if (abv == 0)
	{
		abvText = "";
	}
	else
	{
		abvText = ", " + to_string(abv).substr(0, to_string(abv).find(".") + 2) + "% abv";
	}
	return (name + ": " + char(156) + to_string(price).substr(0, 4) + ", " + to_string(calories) + " cal (" + to_string(volume) + "ml" + abvText + ")");
}