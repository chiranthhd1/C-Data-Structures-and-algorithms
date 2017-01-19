#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;


int main()
{
	
	fstream myFile("HW4a.txt", ios_base::in);
	string instruct1,instruct2;
	int a[3] = {0};
	int b,c;
	int flag = 0;
	string instruct1;
	
	if(myFile.is_open())
	{

		//while( myFile >> instruct1)
		
		while( getline(myFile,instruct,'\n'))
		{
			if (instruct == "ADD_FRONT")
			{
				cout << "Instruct1 is : " << instruct << endl;
				int flag =1;
				int cou =0;
				while(getline(myFile, instruct2,':'))
				{
					cout << instruct2 << endl;
		//			a[cou] = atoi(instruct2.c_str());
		//			cou++;
				}
			/*	for( int i=0; i<=3 ; i++)
				{

					cout << a[i] << endl;
				}*/
			}		

			if( instruct1 == "OUTPUT")
			{
			//	getline(myFile,instruct2;
				cout << instruct1 << endl;
			}
			if( instruct1 == "ADD_BACK")
			{
			//	getline(myFile,instruct2;
				cout <<"FU1"<< instruct1 << endl;
			}

		}
	}





}

