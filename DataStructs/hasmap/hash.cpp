#include <iostream>
#include <cstdlib>
#include <string>
#include "hash.h"

using namespace std;


hash::hash(){
	for(int i =0; i < tableSize; i++){
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}


}

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
		item* n = new item;
		for (ptr = HashTable[index]; ptr->next != NULL; ptr = ptr->next ){

		}

		n->name = name;
		n->drink = drink;
		n->next =NULL;

		ptr->next = n;

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