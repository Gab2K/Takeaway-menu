#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		cout << "Enter help for list of commands" << endl;
		cout << "Please enter: ";
		getline(cin, userCommand);

		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {
			system("cls");
			cout << menu.toString();
		}
		else if (command.compare("add") == 0)
		{
			//Loops through how many entries there are
				for (int i = 1; i < parameters.size(); i++)
				{
					try
					{
						//If user input is between 1 and menu size
						if (stoi(parameters[i]) >= 1 && stoi(parameters[i]) <= menu.items.size())
						{
							//Add choice to order
							Item* choice = menu.items[stoi(parameters[i]) - 1];
							//Checks for an empty space
							if (parameters.size() != 1)
							{
								order.add(choice);
							}
							
						}
						else
						{
							cout << parameters[i] << " is out of range\n";
						}
					}
					catch (const std::invalid_argument& ia)
					{
						cout << parameters[i] << " is a wrong input\n";
					}
					


				}

			
		}
		
		else if (command.compare("remove") == 0)
		{
			
			for (int i = 1; i < parameters.size(); i++)
			{
				try
				{
					order.remove(stoi(parameters[i]));
				}
				catch (const std::invalid_argument& ia)
				{
					cout << parameters[i] + " is not a number!\n";
				}

				
			}
			
		}
		else if (command.compare("checkout") == 0)
		{
			//If it's not empty
			if (order.orderItems.size() != 0)
			{
				string input;
				system("cls");
				cout << order.toString();

				cout << "\nDo you want to place your order?\n"
					"Type 'y' to confirm, or 'n' to go back and modify it\n";

				while (input != "y" && input != "n")
				{

					cout << "Please enter: ";
					getline(cin, input);
					if (input == "y")
					{
						order.printReceipt();
					}
					else if (input == "n")
					{
						cout << "You can modify your order\n";
					}
					else
					{
						cout << "Please enter y or n\n";
					}

				}
				if (input == "y")
				{
					userCommand = "exit";
				}
			}
			else
			{
				cout << "Your checkout is empty" << endl;
			}
			
			



		}
		else if (command.compare("help") == 0)
		{
			system("cls");
			cout << 
				"-----Help menu-----\n"
				"menu - display the menu\n"
				"add [number] - adds the item to the order\n"
				"remove [number] - removes the item from the order\n"
				"checkout - display the added items, price and discout savings\n"
				"help - displays help menu with available options\n"
				"exit - terminates the program\n";
		}

		parameters.clear();

	}

	cout << "Press any key to quit...";
	getchar();

}