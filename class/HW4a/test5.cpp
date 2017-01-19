#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

// I don't recommend using the std namespace in production code.
// For ease of reading here.
using namespace std;

// You could also take an existing vector as a parameter.
vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
  
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
  
  return internal;
}

int main(int argc, char **argv) {
  //string myCSV = "Front_add 1:2:10";
	fstream myFile("HW4a.txt", ios_base::in);
	string instruct1,inst2;
	int a[3] = {0};
	int b,c;
	int flag = 0;
	int count =0;
	//if(myFile.is_open())
	//{
		//while( getline(myFile,instruct,'\n'))
		while (myFile.is_open())
		{
			myFile>>instruct1;
			cout << "Instruct 1 is " << instruct1<< endl;
			if (instruct1 != "OUTPUT")
			{
				myFile>>inst2;
			//cout << inst2 << count << endl;
			cout <<"instruct 1" <<instruct1<< "inst2" << inst2 << endl;
			
			vector<string> sep = split(inst2, ':');
   
			for(int i = 0; i < sep.size(); ++i)
			cout << sep[i] << endl;
			count++;
			}
			cout << " next one bitch" << endl;
		}
	//}
	
}