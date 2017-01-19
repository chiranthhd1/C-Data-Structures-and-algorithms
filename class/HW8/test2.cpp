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
	static const int tableSize = 500000;
	item* HashTable[tableSize];
public:
	hash(){
		for(int i =0; i < tableSize; i++){
			HashTable[i] = NULL;

		}
	}
	int Hash(string key);
	//int Hash(const char* s);
	void addItem(string name);
	int numberOfItemsInIndex(int index);
	void printItems();
	bool isFound(string name);
	void isBinFull();
	void Analysis();

};

int hash::Hash(string key){

	unsigned int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++){
		hash = (hash * 100)  + (int)key[i];
	}

	index = hash % tableSize;
	return index;


}

void hash::addItem(string name){
	int index = Hash(name);
	if(HashTable[index] == NULL){
		HashTable[index] = new item(name,NULL);
	}
	else{
		item* ptr = HashTable[index];
		for (ptr = HashTable[index]; ptr->next != NULL; ptr = ptr->next ){
		}
		ptr->next = new item(name,NULL);
	}
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

void hash::isBinFull(){
	int empty =0;
	int full = 0;
	for (int i =0; i < tableSize ; i++){
		if(HashTable[i]==NULL){
			empty++;
		}
		else{
			full++;
		}
	}
	cout << "Empty" << empty << endl;
	cout << "full" << full << endl;

}

void hash::printItems(){
	int number;
	for(int i = 0 ; i < tableSize; i++){
		number = numberOfItemsInIndex(i);
		
		cout << "----------------------------------\n";
		cout << "index = " << i << endl;
		cout << "number of item " << number << endl;
		//cout << "Name  : " << HashTable[i]->name << endl;
		//if (number > 1){*/
			item* ptr;
			for ( ptr = HashTable[i]; ptr != NULL; ptr = ptr->next){
				cout << "*******************************\n";
			 	cout << "Name  : " << ptr->name << endl;
			}
		//}
		cout << "----------------------------------\n";

 	}
 	
}

void hash::Analysis (){

	//vector<int> a;
	int empty = 0, in1=0 ,in2=0, in3=0 ,in4=0 , in5=0 , in6=0 , in7=0 , in8=0 , in9=0 , in10=0, in11=0;

	 //,in2,in3,in4,in5,in6 = 0;
 	for (int i =0 ; i < tableSize ; ++i){

		int indexValue = numberOfItemsInIndex(i);
		if ( indexValue == 0 ){
			empty++;
		}
		if ( indexValue == 1 ){
			in1++;
		}
		if ( indexValue == 2 ){
			in2++;
		}
		if ( indexValue == 3 ){
			in3++;
		}
		if ( indexValue == 4 ){
			in4++;
		}
		if ( indexValue == 5 ){
			in5++;
		}
		if ( indexValue == 6 ){
			in6++;
		}
		if ( indexValue == 7 ){
			in7++;
		}
		if ( indexValue == 8 ){
			in8++;
		}
		if ( indexValue == 9 ){
			in9++;
		}
		if ( indexValue == 10 ){
			in10++;
		}
		if ( indexValue >= 11 ){
			cout << indexValue <<  endl;
			in11++;
		}
	}

cout << "empty,in1,in2,in3,in4,in5,in6,in7,in8,in9.in10,in11;" << empty << " " << in1 << " " << in2 << " " << in3 << " " << in4 << " " << in5 << " " << in6 << " " << in7 << " " <<  in8 << " " << in9 << " " << in10 << " " << in11 << " " << endl;




}


bool hash::isFound(string name){
	int index = Hash(name);
	string drink;
	bool foundName = false;

	item* ptr ; 
	for ( ptr = HashTable[index]; ptr != NULL; ptr = ptr->next){
		if (ptr->name == name ){
			foundName = true;
			//drink = ptr->drink;
		//	cout << "True";
			return true;

		}

	}
	if (!foundName){
		//cout << " No record found" << endl;
		return false;
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
		}
	}
	/*
	//obj.printItems();
	string name;
	int num;
	cout << "Enter a word to check if its in dictionary" << endl;
	cin >> name;
	cout << "the index number " << endl;
	cin >> num;
	obj.isFound(name);
	cout << endl;
	cout << obj.numberOfItemsInIndex(num) << endl;
	*/
	string name;
	int num;
	cout << "the index number " << endl;
	cin >> num;
	obj.isFound(name);

	obj.isBinFull();
	obj.Analysis();

	string words;
	fstream chckFile("hw8.dat", ios_base::in);
	if(chckFile.is_open()){
		int i =0;
		while ( chckFile >> words){
			cout << words << " " ;
			if(obj.isFound(words)){
				cout << "\t\tYes" << endl;
			}
			else{
				cout << "\t\tNo" << endl;
			}
			++i;
		}	
	}
	else{
		cout << "please check the file name. code works with only hw6a.dat file" << endl; 
	}
}
