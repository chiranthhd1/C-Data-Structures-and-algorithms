#include <iostream>
#include <cstdlib>
#include <string>
#include "hash.h"

using namespace std;


int main()
{
	hash obj;
	obj.addItem("chiranth", "pepsi");
	obj.addItem("chiranth", "pepsi");
	obj.addItem("chiranth", "pepsi");
	obj.addItem("chiranth", "majige");
	obj.addItem("chiranth", "pepsi");
	obj.addItem("chiranth", "pepsi");
	obj.addItem("punith", "coke");
	obj.addItem("sumith", "dew");
	obj.addItem("alex", "fanta");
	obj.addItem("joey", "snapple");
	obj.addItem("phoebe", "gatorade");
	obj.addItem("rachel", "brisk");
	obj.addItem("monica", "sunkist");
	obj.addItem("ross", "sprite");
	obj.addItem("gunther", "7up");

	obj.printItems();
	//cout << obj.numberOfItemsInIndex(9);
	string name;
	cout << "Enter name of the person to check what he likes tp drink" << endl;
	cin >> name;
	obj.findDrink(name);
}
