#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>


using namespace std;



class hash_class{
public:
	class item {
	public:
		string name;
		item* next;
		item ( string n, item* i): name(n) , next(i){}
	};
	static const int tableSize = 510000;
	item* HashTable[tableSize];

	hash_class(){
		for(int i =0; i < tableSize; i++){
			HashTable[i] = NULL;
		}
	}
int Hashfunc(string key){
	

	unsigned int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++){
		hash = (hash * 100)  + (int)key[i];
	}

	index = hash % tableSize;
	return index;


}

void addItem(string name){
	
	int index = Hashfunc(name);
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

int numberOfItemsInIndex(int index){
	int count = 0;
	if (HashTable[index] == NULL){
		return -1;

	}
	else{
		
		item* ptr = HashTable[index];
		while(ptr != NULL){
			count++;
		//cout << index << " " << ptr->name<< endl;
			ptr = ptr->next;
		}
		//cout << "count" << count << endl;
		
	}
	return count;
}

void isBinFull(){
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

void Analysis (){

	int empty = 0,in0 =0, in1=0 ,in2=0, in3=0 ,in4=0 , in5=0 , in6=0 , in7=0 , in8=0 , in9=0 , in10=0, in11=0;
 	for (int i =0 ; i < tableSize ; ++i){

		int indexValue = numberOfItemsInIndex(i);
		if ( indexValue == -1 ){
			empty++;
		}
		if ( indexValue == 0 ){
			in0++;
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
			in11++;
		}
	}
	
		
	cout << " *********************** "<<endl
		 << " Insert " << "    Count " << endl
		 << "  empty " << "    " << empty << endl
		// << "    0   " << "    " << in0 << endl
		 << "    1   " << "    " << in1 << endl
		 << "    2   " << "    " << in2 << endl
	     << "    3   " << "    " << in3 << endl
		 << "    4   " << "    " << in4 << endl
		 << "    5   " << "    " << in5 << endl
		 << "    6   " << "    " << in6 << endl
		 << "    7   " << "    " << in7 << endl
		 << "    8   " << "    " << in8 << endl
		 << "    9   " << "    " << in9 << endl
		 << "    10   " << "   " << in10 << endl
		 << " 11 or more" << "  " << in11 << endl;
	cout << " *********************** " << endl;
}


bool isFound(string name){
	int index = Hashfunc(name);
	string drink;
	bool foundName = false;

	item* ptr ; 
	for ( ptr = HashTable[index]; ptr != NULL; ptr = ptr->next){
		if (ptr->name == name ){
			foundName = true;
			return true;}

	}
	if (!foundName){
		return false;
	}
}
};


int main()
{
	hash_class obj;
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
	else{
		cout << "please check the file name. code works with only dict.txt file" << endl << endl; 
	}


	//obj.isBinFull();
	string words;
	fstream chckFile("hw8.dat", ios_base::in);
	if(chckFile.is_open()){
		int i =0;
		cout << endl;
		while ( chckFile >> words){
			//cout << words;
			cout << "  " ;
			if(obj.isFound(words)){
				cout << words <<  " \t\tYes" << endl;
			}
			else{
				cout << words <<  " \t\tNo" << endl;
			}
			++i;
		}	
		cout << endl;
	}
	else{
		cout << "please check the file name. code works with only hw6a.dat file" << endl << endl; 
	}

	cout << " tableSize is :" << obj.tableSize << endl << endl;
	cout << " Histogram to show number of values with number of bins " << endl << endl;
	obj.Analysis();
	
}
