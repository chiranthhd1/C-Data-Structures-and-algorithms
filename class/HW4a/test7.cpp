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

class 

int main() {
	fstream myFile("HW4a.txt", ios_base::in);

	string instruct;
	if(myFile.is_open())
	{
		while( getline(myFile,instruct,'\n'))
		{	
			if(instruct == "")
			{
				continue;
			}
			cout << "inside the while loop with instruct as " << instruct << endl;
			
			vector<string> sep;
			sep.reserve(100);
			sep = split(instruct, ' ');
			if (sep[0] == "ADD_FRONT")
			{
				vector<int> sep1 = splitInt(sep[1], ':');
				cout << "size is" << sep1.size();
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
				//continue;
			}
			//readFromFile(myFile);
			if (sep[0] == "ADD_BACK")
			{
				vector<int> sep1 = splitInt(sep[1], ':');
				cout << "size is" << sep1.size();
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
				//cout << "sep[1]" << sep[1] << endl;
				//vector<string> sep5 = split(sep[1], ':');
				continue;
			}
			
		}
	}
	
	
}

