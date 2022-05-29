#include "Appetiser.h"

bool Appetiser::get_twoForOne()
{
	return twoForOne;
}
std::string Appetiser::toString()
{
	std::string shareableText;
	std::string twoForOneText;
	if (shareable == true)
	{
		shareableText = "shareable";
	}
	else
	{
		shareableText = "";
	}
	if (twoForOne == true)
	{
		twoForOneText = "2-4-1";
	}
	else
	{
		twoForOneText = "";
	}
	return (name + ": "+char(156)+to_string(price).substr(0, 4) +", "+to_string(calories)+" cal ("+ shareableText + twoForOneText + ")");
}

