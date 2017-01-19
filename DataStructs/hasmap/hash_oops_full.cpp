// Run for c++ 9.8

#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;


class hash{
	class item {
	public:
		string name;
		string drink;
		item* next;
		item ( string n, string d, item* i): name(n), drink(d) , next(i){}
	};
	static const int tableSize = 5;
	item* HashTable[tableSize];
public:
	hash(){
	for(int i =0; i < tableSize; i++){
		HashTable[i] = new item("empty","empty",NULL);
	}
	}
	int Hash(string key);
	void addItem(string name, string drink);
	int numberOfItemsInIndex(int index);
	void printItems();
	void findDrink(string name);

};

int hash::Hash(string key){

	int hash = 0;
	int index;

	for (int i =0; i < key.length(); i++){
		hash = hash + (int)key[i];
	}

	index = hash % tableSize;
	return index;


}

void hash::addItem(string name, string drink){
	int index = Hash(name);

	if(HashTable[index]->name == "empty"){
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
		//HashTable[index]->next 
	}
	else{
		item* ptr;
		for (ptr = HashTable[index]; ptr->next != NULL; ptr = ptr->next ){

		}
		ptr = new item(name,drink,NULL);
	}
}

int hash::numberOfItemsInIndex(int index){
	int count = 0;
	if (HashTable[index]->name == "empty"){
		return count;
	}
	else{
		count++;
		item* ptr = HashTable[index];
		while(ptr->next != NULL){
			count++;
			ptr = ptr->next;
		}
	}

	return count;


}

void hash::printItems(){
	int number;

	for(int i = 0 ; i < tableSize; i++){
		number = numberOfItemsInIndex(i);
		cout << "----------------------------------\n";
		cout << "index = " << i << endl;
		cout << "number of item " << number << endl << endl;
		cout << "Name  : " << HashTable[i] -> name << endl;
		cout << "Drink : " << HashTable[i] -> drink << endl;
		
		if (number > 1){
			item* ptr;
			for ( ptr = HashTable[i]->next; ptr != NULL; ptr = ptr->next){
				cout << "*******************************\n";
			 	cout << "Name  : " << ptr->name << endl;
			 	cout << "Drink : " << ptr->drink << endl;
			}
		}
		cout << "----------------------------------\n";

 	}
 	
}

void hash::findDrink(string name){
	int index = Hash(name);
	string drink;
	bool foundName = false;

	item* ptr ; 
	for ( ptr = HashTable[index]; ptr != NULL; ptr = ptr->next){
		if (ptr->name == name ){
			foundName = true;
			drink = ptr->drink;
			cout << drink << endl;

		}

	}
	if (!foundName){
		cout << " No recoed found" << endl;
	}
}


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
