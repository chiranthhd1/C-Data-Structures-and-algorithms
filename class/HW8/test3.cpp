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
	static const int tableSize = 30000;
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
		//cout << "Adding head" << name << endl;
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
		return 0;

	}
	else{
		count++;
		item* ptr = HashTable[index];
		while(ptr->next != NULL){
			count++;
			//cout << index << " " << ptr->name<< endl;
			ptr = ptr->next;
		}
		
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

/*
void printItems(){
	int number;
	int empty =0;
	int full = 0;
	for(int i = 0 ; i < tableSize; i++){
		number = numberOfItemsInIndex(i);

		
		//cout << "----------------------------------\n";
		//cout << "index = " << i << endl;
		//cout << "number of item " << number << endl;
		//cout << "Name  : " << HashTable[i]->name << endl;
		if (number > 1){
			item* ptr;
			for ( ptr = HashTable[i]; ptr != NULL; ptr = ptr->next){
				cout <<" print" <<  ptr->name << endl;
				//cout << "*******************************\n";
			 	//cout << "Name  : " << ptr->name << endl;
			 	full++;
			}
		}
		else{
			empty++;
		}
		//cout << "----------------------------------\n";

 	}
 	cout << "Empty" << empty << endl;
	cout << "full" << full << endl;
 	
}
*/

void Analysis (){

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
			//cout << indexValue <<  endl;
			in11++;
		}
	}

/*cout << " with 0 values in a bin " << empty << endl <<
	" with 1 values in a bin " << in1 << endl <<
	" with 2 values in a bin " << in2 << endl <<
	" with 3 values in a bin " << in3 << endl <<
	" with 4 values in a bin " << in4 << endl <<
	" with 5 values in a bin " << in5 << endl <<
	" with 6 values in a bin " << in6 << endl <<
	" with 7 values in a bin " << in7 << endl <<
	" with 8 values in a bin " << in8 << endl <<
	" with 9 values in a bin " << in9 << endl <<
	" with 10 values in a bin " << in10 << endl <<
	" with 11 values in a bin " << in11 << endl; */
	
cout << " Insert " << "    Count " << endl
	 << "    0   " << "    " << empty << endl
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
	 << "11 or more" << "  " << in11 << endl << endl;
	 

	    




}


bool isFound(string name){
	int index = Hashfunc(name);
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
	//string name;
	//int num;
	//cout << "the index number " << endl;
	//cin >> num;
	//obj.isFound(name);

	//obj.isBinFull();
	//obj.printItems();
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
