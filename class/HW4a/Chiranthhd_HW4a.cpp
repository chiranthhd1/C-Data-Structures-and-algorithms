#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class GrowArray { // C++: Vector<int>    Java: ArrayList
private:
	uint64_t* data;
	uint64_t used;
	int capacity;
public:
	GrowArray() {
		data = nullptr;
		capacity = 0;
		used = 0;

	}
	//preallocate storage for more speed (how much? 100%)
	GrowArray(int initialCapacity) {
		data = new uint64_t[initialCapacity];
		capacity = initialCapacity;
		used = 0;
	}
	~GrowArray() {
		delete [] data;
	}
	bool addEnd(uint64_t v) {
		uint64_t* temp = data;
		if ( used < capacity){
			data = new uint64_t[used+1];
			for (uint64_t i=0; i < used; i++)
				data[i] = temp[i];
			data[used] = v;
			used++;
		}
		else{
			return 1;
		}
		delete [] temp;
	}

	bool addStart(uint64_t v) {
		uint64_t* temp = data;
		if ( used < capacity){
			data = new uint64_t[used+1];
			for (uint64_t i=0; i < used; i++)
				data[i+1] = temp[i];
			data[0] = v;
			used++;
		}
		else{
			return 1;
		}
		delete [] temp;

	}

	bool removeEnd(uint64_t v) {
		uint64_t* temp = data;
		if ( used < capacity){
			data = new uint64_t[used-v];
			for (uint64_t i=0; i < used-v; i++)
				data[i] = temp[i];
			used-=v;
		}
		delete [] temp;
	}

	bool removeStart(uint64_t v) {
		uint64_t* temp = data;
		if ( used < capacity){
			data = new uint64_t[used-v];
			for (uint64_t i=0; i < used; i++)
				data[i] = temp[i+v];
			used-=v;
		}
		delete [] temp;

	}

	void output(){
		for (uint64_t i=0; i <used; i++)
			cout << data[i] << " ";

	}

	int getCapacity()
	{
		return capacity;
	}

	int getSize()
	{
		return used;
	}
};


vector<string> split(string str, char delimiter) {
  	vector<string> internal;
  	stringstream ss(str);
  	string tok;
  
  	while(getline(ss, tok, delimiter)) {
    		internal.push_back(tok);
  	}
  	return internal;
}

vector<uint64_t> splitInt(string str, char delimiter) {
  	vector<uint64_t> internal;
  	stringstream ss(str);
  	string tok;
  
  	while(getline(ss, tok, delimiter)) {
    		uint64_t tmp=0;
    		tmp = atoi(tok.c_str());
    		internal.push_back(tmp);
  	}
  	return internal;
}

 

int main() {
	fstream myFile("HW4a.txt", ios_base::in);
	int capacity;
	cout << "Please enter the capacity of the array you wish to create" << endl;
	cout << "This array can accomadate only untill the capacity is full others will be disregarded" << endl;
	cin >> capacity;
	GrowArray a(capacity);
	//cout << " \nAn array has been created with below capacity and size used: " << endl;
	//cout << "Capacity of the array is: " << a.getCapacity() << endl;
	//cout << "Size used is \t: " << a.getSize() << endl;
	//cout << "This array can accomadate only untill the capacity is full others will be disregarded" << endl;
	string instruct;
	
	if(myFile.is_open()){
		while( getline(myFile,instruct,'\n')){	
			if(instruct == ""){
				continue;
			}
			
			vector<string> sep;
			sep.reserve(100);
			sep = split(instruct, ' ');
			
			if (sep[0] == "ADD_FRONT"){
				//cout << "Inside add front " << endl;
				bool sizeOutOfBound = 0;
				vector<uint64_t> sep1 = splitInt(sep[1], ':');
				for (uint64_t j = sep1[0]; j <= sep1[2] ; j+=sep1[1]){	
					sizeOutOfBound = a.addStart(j);
				}
			}
			
			if (sep[0] == "ADD_BACK"){
				//cout << "Inside add back " << endl;
				bool sizeOutOfBound = 0;
				vector<uint64_t> sep1 = splitInt(sep[1], ':');
				for (uint64_t j = sep1[0]; j <= sep1[2] ; j+=sep1[1]){
					sizeOutOfBound = a.addEnd(j) ;
				}
			}
			
			if (sep[0] == "REMOVE_FRONT"){
				//cout << "Inside remove front " << endl;
				vector<uint64_t> sep3 = splitInt(sep[1],' ');
				a.removeStart(sep3[0]);
			}
			
			if (sep[0] == "REMOVE_BACK"){
				//cout << "Inside remove back " << endl;
				vector<uint64_t> sep4 = splitInt(sep[1], ' ');
				a.removeEnd(sep4[0]);
			}

			if (sep[0] == "OUTPUT"){
				cout << endl;
				a.output();
				cout << endl;
			}
			
		}
	}
	//cout << " \nAfter the operation" << endl;
	//cout << "Capacity of the array is: " << a.getCapacity() << endl;
	//cout << "Size Used is \t: " << a.getSize() << endl;
	
}

