#include "Menu.h"

Menu::Menu(string fileName)
{
	//Opens a file 
	ifstream fileContent;
	fileContent.open(fileName);
	if (!fileContent.is_open())
	{
		cout << "Menu failed to load";
	}

	
	string line, type, name, price, calories, volume, abv, shareable, twoForOne;

	//Reads through a file
	while (getline(fileContent, line))
	{
		stringstream ss(line);
		getline(ss, type, ',');
		getline(ss, name, ',');
		getline(ss, price, ',');
		getline(ss, calories, ',');
		getline(ss, shareable, ',');
		getline(ss, twoForOne, ',');
		getline(ss, volume, ',');
		getline(ss, abv);
		
		
		//Conversion
		bool twoForOneBool, shareableBool;
		istringstream(twoForOne) >> twoForOneBool;
		istringstream(shareable) >> shareableBool;

		//Turning bools to true and fals
		if (type == "a")
		{
			if (shareable == "y")
			{
				shareableBool = true;
			}
			else
			{
				shareableBool = false;
			}
			if (twoForOne == "y")
			{
				twoForOneBool = true;
			}
			else
			{
				twoForOneBool = false;
			}
			//Appetiser class instance
			Appetiser* appetiser = new Appetiser{name, stof(price), stoi(calories), shareableBool, twoForOneBool};
			items.push_back(appetiser);
		}
		if (type == "b")
		{
			//Beverage class instance
			Beverage* beverage = new Beverage{name, stof(price), stoi(calories), stoi(volume), stof(abv)};
			items.push_back(beverage);

		}
		if (type == "m")
		{
			//MainCourse class instance
			MainCourse* mainDish = new MainCourse{name, stof(price), stoi(calories)};
			items.push_back(mainDish);
		}
		
	}
	fileContent.close();
}


	
std::string Menu::toString()
{
	string line, type;
	for (int i = 0; i < items.size(); i++)
	{
		//Checks for item type
		if (typeid(*items[i]).name()[6] == 'A' && type != "a")
		{
				type = "a";
				line += "----------------Appetisers----------------\n";
				
		}
		
		else if (typeid(*items[i]).name()[6] == 'M' && type != "m")
		{
				type = "m";
				line += "----------------Main dishes----------------\n";
				
		}
		else if (typeid(*items[i]).name()[6] == 'B' && type != "b")
		{

				type = "b";
				line += "----------------Beverages----------------\n";
				
		}
		//Print menu items
		line += "(" + to_string(i + 1) + ") ";
		line += items[i]->toString();
		line += "\n";
		
	}
	return line;
}
