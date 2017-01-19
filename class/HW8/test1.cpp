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
	static const int tableSize = 1000000;
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
	//cout << "hash value is " << index << endl;
	//cout << "name is " << name << endl;
	
	int count = 0;
	//if(HashTable[index]->name == "empty"){
	if(HashTable[index] == NULL){
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
		//cout << "ptr->name" << ptr->name << endl;
		//cout << "ptr->nexr" << ptr->next->name << endl;
		//cout << "HashTable[index]" << HashTable[index]->name << endl;
		for (ptr = HashTable[index]; ptr->next != NULL; ptr = ptr->next ){
			//count++;
			//cout << "ptr->name inside loop is " << ptr->name << endl;
		}
		ptr->next = new item(name,NULL);
	}
	//cout << "Number of items after adding"<< count << endl;
	//cout << "index is "<< index << endl;
}

int hash::numberOfItemsInIndex(int index){
	int count = 0;
	if (HashTable[index] == NULL){
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
	//cout << " inside print 1" << endl;

	for(int i = 0 ; i < tableSize; i++){

	//cout << " inside print 2" << endl;
		number = numberOfItemsInIndex(i);

		cout << " inside print 3" << endl;
		cout << "----------------------------------\n";
		cout << "index = " << i << endl;
		cout << "number of item " << number << endl;
		//cout << "Name  : " << HashTable[i]->name << endl;
		//cout << "Drink : " << HashTable[i] -> drink << endl;
		
		if (number > 1){
			item* ptr;
			for ( ptr = HashTable[i]; ptr != NULL; ptr = ptr->next){
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
			cout << "True";

		}

	}
	if (!foundName){
		cout << " No record found" << endl;
	}
}


int main()
{
	hash obj;
	fstream myFile("dict.txt");
	string word;
	//obj.printItems();
	int count = 0;
	if(myFile.is_open()){
		while (getline(myFile, word)){
			obj.addItem(word);
			count++;
			//cout << "count is: " << count << endl;
			//obj.printItems();
		}
	}
	//obj.printItems();
	//cout << obj.numberOfItemsInIndex(9);
	string name;
	int num;
	cout << "Enter name of the person to check what he likes tp drink" << endl;
	cin >> name;
	cout << "the index number " << endl;
	cin >> num;
	obj.findDrink(name);
	cout << obj.numberOfItemsInIndex(num);
}
