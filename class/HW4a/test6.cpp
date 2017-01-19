#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;


vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str);
  string tok;
  
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
  
  return internal;
}

vector<string> readFromFile( fstream& myFile){
	string instruct;
	if(myFile.is_open())
	{
		while( getline(myFile,instruct,'\n'))
		{
			vector<string> sep;
			sep.reserve(100);
			sep = split(instruct, ' ');
			cout << "sep[0]" << sep[0] << endl;
			cout << "sep[1]" << sep[1] << endl;
			if (sep[0] == "ADD_FRONT")
			{
				vector<string> sep1 = split(sep[1], ':');
				cout << "size is" << sep1.size();
				for(int i = 0; i <
				3; i++)
					cout << sep1[i] << endl;
			}
			if (sep[0] == "ADD_BACK")
			{
				vector<string> sep2 = split(sep[1], ':');
				cout << "size is" << sep2.size();
				for(int i = 0; i < sep2.size(); ++i)
					cout << sep2[i] << endl;
			}
			if (sep[0] == "REMOVE_FRONT")
			{
				cout << "sep[1]" << sep[1] << endl;
				vector<string> sep3 = split(sep[1],' ');
	
			}
			
			if (sep[0] == "REMOVE_BACK")
			{
				cout << "sep[1]" << sep[1] << endl;
				vector<string> sep4 = split(sep[1], ' ');

			}
			if (sep[0] == "OUTPUT")
			{
				cout << "sep[1]" << sep[1] << endl;
				vector<string> sep5 = split(sep[1], ':');

			}
			
		}
	}	
	
}

int main() {
	fstream myFile("HW4a.txt", ios_base::in);
	readFromFile(myFile);
	
}
