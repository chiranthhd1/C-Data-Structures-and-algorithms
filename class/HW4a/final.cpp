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

	bool addEnd(int v) {
		cout << "size is:" << used << endl;
		if ( used < capacity)
		{
			cout << "Out of bound" << endl;
			//continue;
			//return 0;
		//cout << ""
		int* temp = data;
		data = new int[used+1];
		for (int i=0; i < used; i++)
			data[i] = temp[i];
		data[used] = v;
		used++;
		}
		else
		{
			cout << " inside else of addend" << endl;
			return 1;
		}
	}

	bool addStart(int v) {
		cout << "size is:" << used << endl;
		if ( used < capacity)
        {
            cout << "Out of bound" << endl;
                        //continue;
                       // return 0;
                

		int* temp = data;
		data = new int[used+1];
		for (int i=0; i < used; i++)
			data[i+1] = temp[i];
		data[0] = v;
		used++;
		}
		else
		{
			cout << " inside else of addstart" << endl;
			return 1;
		}

	}
	bool removeEnd(int v) {
		cout << "size is:" << used << endl;
		 if ( used < capacity)
                {
                      cout << "Out of bound" << endl;
                        //continue;
                      //  return 0;
                

		int* temp = data;
		data = new int[used-v];
		for (int i=0; i < used-v; i++)
		 	data[i] = temp[i];
		 used-=v;
		}
		else
		{
			cout << " inside else of addstart" << endl;
			return 1;
		}

	}

	bool removeStart(int v) {
		cout << "size is:" << used << endl;
		 if ( used < capacity)
                {
                      cout << "Out of bound" << endl;
                        //continue;
                        //return 0;
                

		int* temp = data;
		data = new int[used-v];
		for (int i=0; i < used; i++)
		 	data[i] = temp[i+v];
		 used-=v;
		}
		else
		{
			cout << " inside else of addstart" << endl;
			return 1;
		}
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
	cout << " \n An array has been created with below capacity and size used: " << endl;
	cout << "Capacity of the array is: " << a.getCapacity() << endl;
	cout << "Size used is \t: " << a.getSize() << endl;


	string instruct;
	if(myFile.is_open())
	{
		while( getline(myFile,instruct,'\n'))
		{	
			if(instruct == "")
			{
				continue;
			}
			
			vector<string> sep;
			sep.reserve(100);
			sep = split(instruct, ' ');
			if (sep[0] == "ADD_FRONT")
			{
				vector<int> sep1 = splitInt(sep[1], ':');
				
					for (int j = sep1[0]; j <= sep1[2] ; j+=sep1[1])
					{	
			//			if((a.getSize())<a.getCapacity())
			//			{
							a.addStart(j);
			//			}
					}	
			}
			if (sep[0] == "ADD_BACK")
			{
				vector<int> sep1 = splitInt(sep[1], ':');
				
					for (int j = sep1[0]; j <= sep1[2] ; j+=sep1[1])
					{
			//			if((a.getSize())<a.getCapacity())
			//			{
							a.addEnd(j) ;
			//			}
					}
			}
			if (sep[0] == "REMOVE_FRONT")
			{
				vector<int> sep3 = splitInt(sep[1],' ');
			//	if((a.getSize()-1)<a.getCapacity())
			//	{
					a.removeStart(sep3[0]);
			//	}
			}
			
			if (sep[0] == "REMOVE_BACK")
			{
				vector<int> sep4 = splitInt(sep[1], ' ');
				//if((a.getSize()-1)<a.getCapacity())
				//{
					a.removeEnd(sep4[0]);
			//	}
			}
			if (sep[0] == "OUTPUT")
			{
				cout << endl;
				a.output();
				cout << endl;
			}
			
		}
	}
	cout << "After the operation" << endl;
	cout << "Capacity of the array is: " << a.getCapacity() << endl;
	cout << "Size Used is \t: " << a.getSize() << endl;
	
}

