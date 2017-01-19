#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class hash{
	static const int tableSize = 10;

	struct item {
		string name;
		string drink;
		item* next;
	};

	item* HashTable[tableSize];


public:
	hash();
	int Hash(string key);
	void addItem(string name, string drink);
	int numberOfItemsInIndex(int index);
	void printItems();
	void findDrink(string name);






};



#endif