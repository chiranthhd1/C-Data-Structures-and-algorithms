// Run for c++ 9.8

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>


using namespace std;


class hash{
	class item {
	public:
		string name;
		item* next;
		item ( string n, item* i): name(n) , next(i){}
	};
	static const int tableSize = 2;
	//item* head;
	item* HashTable[tableSize];
public:
	hash(){
		//head = NULL;
		for(int i =0; i < tableSize; i++){
			//HashTable[i] = new item("empty", NULL);
			HashTable[i] = NULL;

		}
	}
	int Hash(string key);
	void addItem(string name);
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
	//cout << "hash value is " << hash << endl;

	index = hash % tableSize;
	//cout << "hash value is " << index << endl;
	return index;


}

void hash::addItem(string name){
	int index = Hash(name);
	cout << "hash value is " << index << endl;
	cout << "name is " << name << endl;
	
	int count = 0;
	if(HashTable[index]->name == "empty"){
		//HashTable[index]->name = name;
		//HashTable[index]->drink = drink;
		//HashTable[index]->next = NULL;
		HashTable[index] = new item(name,NULL);
	}
	else if (HashTable[index]->next == NULL ){

		HashTable[index]->next = new item(name,NULL);


	}
	else{
		item* ptr = HashTable[index];
		cout << "ptr->name" << ptr->name << endl;
		cout << "ptr->nexr" << ptr->next << endl;
		cout << "HashTable[index]" << HashTable[index]->name << endl;
		for (ptr = HashTable[index]; ptr->next != NULL; ptr = ptr->next ){
			count++;
			cout << "ptr->name" << ptr->name << endl;
		}
		ptr = new item(name,NULL);
	}
	cout << "Number of items while adding"<< count << endl;
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
		//cout << "Drink : " << HashTable[i] -> drink << endl;
		
		if (number > 1){
			item* ptr;
			for ( ptr = HashTable[i]->next; ptr != NULL; ptr = ptr->next){
				cout << "*******************************\n";
			 	cout << "Name  : " << ptr->name << endl;
			 	// /cout << "Drink : " << ptr->drink << endl;
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
			//drink = ptr->drink;
			cout << name << endl;

		}

	}
	if (!foundName){
		cout << " No record found" << endl;
	}
}


int main()
{
	hash obj;
	fstream myFile("dict1.txt");
	string word;
	//obj.printItems();

	if(myFile.is_open()){
		while (getline(myFile, word)){
			obj.addItem(word);
			//obj.printItems();
		}









	}


	/*
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
    */
	obj.printItems();
	//cout << obj.numberOfItemsInIndex(9);
	string name;
	int num;
	cout << "Enter name of the person to check what he likes tp drink" << endl;
	//cin >> name;
	cin >> num;
	//obj.findDrink(name);
	cout << obj.numberOfItemsInIndex(num);
}
