#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class GrowArray { // C++: Vector<int>    Java: ArrayList
private:
	int* data;
	int used;
	int capacity;
public:
	GrowArray() {
		data = nullptr;
		capacity = 0;
		used = 0;

	}

	//preallocate storage for more speed (how much? 100%)
	GrowArray(int initialCapacity) {
		data = new int[initialCapacity];
		capacity = initialCapacity;
		used = 0;


	}

	~GrowArray() {
		delete [] data;

	}

	void addStart(int v) {
		int* temp = data;
		data = new int[used+1];
		for (int i=0; i < used; i++)
			data[i] = temp[i];
		data[used] = v;
		used++;
	}

	void addEnd(int v) {
		int* temp = data;
		data = new int[used+1];
		for (int i=0; i < used; i++)
			data[i+1] = temp[i];
		data[0] = v;
		used++;

	}
	void removeEnd(int v) {
		int* temp = data;
		data = new int[used-v];
		for (int i=0; i < used-v; i++)
		 	data[i] = temp[i];
		 used-=v;

	}

	void removeStart(int v) {
		int* temp = data;
		data = new int[used-v];
		for (int i=0; i < used; i++)
		 	data[i] = temp[i+v];
		 used-=v;
	}
	void output(){
		for (int i=0; i <used; i++)
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

vector<int> splitInt(string str, char delimiter) {
  vector<int> internal;
  stringstream ss(str);
  string tok;
  
  while(getline(ss, tok, delimiter)) {
    int tmp=0;
    tmp = atoi(tok.c_str());
    internal.push_back(tmp);
  }
  
  return internal;
}

 

int main() {
	fstream myFile("HW4a.txt", ios_base::in);
	int capacity;
	cout << "Please enter the capacity of the array you wish to create" << endl;
	cin >> capacity;
	GrowArray a(capacity);
	cout << "capacity of the array is: " << a.getCapacity() << endl;
	cout << "size of the array is: " << a.getSize() << endl;


	string instruct;
	if(myFile.is_open())
	{
		while( getline(myFile,instruct,'\n'))
		{	
			if(instruct == "")
			{
				continue;
			}
			//cout << "inside the while loop with instruct as " << instruct << endl;
			
			vector<string> sep;
			sep.reserve(100);
			sep = split(instruct, ' ');
			if (sep[0] == "ADD_FRONT")
			{
				vector<int> sep1 = splitInt(sep[1], ':');
			//	cout << "size is" << sep1.size();
			/*	for(int i = 0; i <
				3; i++)
				{
					//sep1[i] =  atoi(sep1[i].c_str());
					cout << sep1[i] << endl;
				}
				
				for (int j = sep1[0]; j < sep1[2] ; j+=sep1[1])
				{
					cout << j << " " ;
				}
				*/
				for (int j = sep1[0]; j < sep1[2] ; j+=sep1[1])
				{
					a.addStart(j) ;
				}
				//cout << endl;
				//continue;
			}
			//readFromFile(myFile);
			if (sep[0] == "ADD_BACK")
			{
				vector<int> sep1 = splitInt(sep[1], ':');
				
				/*cout << "size is" << sep1.size();
				for(int i = 0; i <
				3; i++)
				{
					//sep1[i] =  atoi(sep1[i].c_str());
					cout << sep1[i] << endl;
				}
				
				for (int j = sep1[0]; j < sep1[2] ; j+=sep1[1])
				{
					cout << j << " " ;
				}
				cout << endl;
				*/
				for (int j = sep1[0]; j < sep1[2] ; j+=sep1[1])
				{
					a.addEnd(j) ;
				}
			}
			if (sep[0] == "REMOVE_FRONT")
			{
				//cout << "sep[1]" << sep[1] << endl;
				vector<int> sep3 = splitInt(sep[1],' ');
				a.removeStart(sep3[0]);
	
			}
			
			if (sep[0] == "REMOVE_BACK")
			{
				//cout << "sep[1]" << sep[1] << endl;
				vector<int> sep4 = splitInt(sep[1], ' ');
				a.removeEnd(sep4[0]);

			}
			if (sep[0] == "OUTPUT")
			{
				cout << endl;
				//cout << "sep[1]" << sep[1] << endl;
				//vector<string> sep5 = split(sep[1], ':');
				a.output();
				//continue;
			}
			
		}
	}
	cout << "capacity of the array is: " << a.getCapacity() << endl;
	cout << "size of the array is: " << a.getSize() << endl;
	a.output();
	
}

