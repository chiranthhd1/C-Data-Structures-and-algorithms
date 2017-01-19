#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;

void getValueOfK(int arr[], int counter)
{	
    for (int i = 0; i < counter ; i++)
    {
        int n = arr[i];
	int nM1 = n-1;
	cout << "n-1 is " << nM1 << endl;
	double m=0;
	//vector<int> k;
	int k[100] ={0};
	int counter1 = 0;
	for ( int j=1; j<10 ; j++)
	{
		m = nM1/pow(2,j);
		cout << "2 power to " << j << " is " << pow(2,j) << endl;
		if (floor(m) == m)
		{
    			cout << m << " Is whole" << endl;
			k[counter1] = m;
			
		counter1++;
		}
		else
		{
    			cout <<m<< "is not whole" << endl;
		}
		
	}
	for (int f =0 ; f < counter1 ; f++)
	{
		cout << " K array" <<endl;
		cout << k[f] << " " << f<<endl;

	}
	cout << "maximum value is " << *min_element(k,k+counter1);
	cout << "next value " <<endl<< endl<< endl;
    
//*/    
/*	for ( int j=1; m<2 ; j++)
//	{
	int j=0
	while(floor(m) == m)
	{
		m = nM1/pow(2,j);
    		cout << "It's whole";
	}	cout << m << endl;
		
	/ *	else
		{
    			cout << "Not whole";
			cout << m << endl;
		}*i /
	}
    
*/    

























    }
 

}

int main()
{
    fstream myfile("HW2.dat", ios_base::in);

    int a;
    int arr[6] = {0};
    int counter = 0;
    while (myfile >> a)
    {
	arr[counter] = a;
	counter++;
    }
    
    for (int i = 0; i < counter ; i++)
    {
    	cout << arr[i] << endl;
    }
    
    getValueOfK(arr, counter);

}
