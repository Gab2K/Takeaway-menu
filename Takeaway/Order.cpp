#include "Order.h"
string name;
void Order::add(Item* choice)
{
	cout << to_string(orderItems.size()+1)+ ") " + choice->getName()+" added to order!\n";
	orderItems.push_back(choice);
}

void Order::remove(int index)
{
	//If number is no bigger than order vector and number is not 0
	if (orderItems.size() >= index && index!= 0)
	{
		cout << orderItems[index - 1]->getName() + " removed from order!\n";
		orderItems.erase(orderItems.begin() + index - 1);
		
	}
	else
	{
		cout << to_string(index) + " is not in list type checkout to get number\n";
	}
	
	
}

void Order::calculateTotal()
{
	total = 0;
	savings = 0;
	num_Of_twoForOne = 0;
	vector <float> twoForOne; //Stores number of twoForOne items
	//Loops through vector of order items
	for (int i = 0; i < orderItems.size(); i++)
	{
		//Adds the total price
		total += orderItems[i]->getPrice();
		//Get number of two for one items
		if (static_cast<Appetiser*>(orderItems[i])->get_twoForOne() == 1)
		{
			//Add price of 2-4-1 items to the vector
			twoForOne.push_back(orderItems[i]->getPrice());
		}
		
	}
	//Sorts twoForOne items by lowest price first
	sort(twoForOne.begin(), twoForOne.end()); 
	num_Of_twoForOne = twoForOne.size();

	//If number of two for one's is at least 2
		if (num_Of_twoForOne >= 2)
		{
			//Loop through the amount of items eligeble for two for one and adds the price to savings
			for (int i = 0; i < num_Of_twoForOne/2; i++)
			{
				savings += twoForOne[i];
			}
			
		}
		total -= savings;
}
string Order::toString()
{
	calculateTotal(); // Call function to update price before printing
	string line;
	//Print checkout
	line+= "===== Checkout =====\n";
	for (int i = 0; i < orderItems.size(); i++)
	{
		line+= "(" + to_string(i + 1) + ") ";
		line+= orderItems[i]->toString() + "\n";
	}

	//Total price and confirmation
	line += "--------\n";
	//If there are at least 2 items are eligible for (2-4-1) discount
	if (num_Of_twoForOne >= 2)
	{
		line += "2-4-1 discount applied! Savings:";
		line += char(156);
		line += to_string(savings).substr(0, to_string(savings).find(".") + 3);
		line += "\n";
	}

	line += "Total: ";
	line += char(156);
	line+= to_string(total).substr(0, to_string(total).find(".")+3) + "\n\n";
	
	return line;
}

void Order::printReceipt()
{
	//Create a new file and read to it
	ofstream outfile("receipt.txt");
	outfile << toString();
	outfile.close();
	cout << "Receipt added to receipt.txt file\n";
}