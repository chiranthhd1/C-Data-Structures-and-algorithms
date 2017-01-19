#include <iostream>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <random>

using namespace std;

uint64_t power(uint64_t x, uint64_t y, uint64_t p)
{
    uint64_t res = 1;
 
    x = x % p;
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;  
    }
    return res;
}


int millerRabin(uint64_t n, uint64_t k_v)
{
	
	uint64_t nM1 = n-1;
	uint64_t buf = nM1;
	uint64_t r=0;
	uint64_t d=0;
	uint64_t x=0;
	int isPrime=0;
    if ( n ==2 || (n%2==0)){
		return 0;
    }
    else{	      
	    while( buf %2==0 ){
			buf/=2;
			r++;
		}
		
		d = buf;
		for (uint64_t k=0; k< k_v; k++){
	
			std::default_random_engine generator;
			std::uniform_int_distribution<uint64_t> distribution(2,nM1-1);
			uint64_t a = distribution(generator); 
		
			x = power (a,d,n);
			if ( x == 1 || x == nM1){
				continue;
			}

			isPrime=0;
			for ( uint64_t f=0; f <=r-1;f++){
				x =  power(x , 2, n);
				if( x == 1){
					return 0;
				}
				if ( x == nM1){
					isPrime = 1;
					break;
				}
			}
			if(isPrime == 0) {
				return 0;
			}
			
		}
		
		return 1;
	}
}



int main()
{
    fstream myfile("HW2.dat", ios_base::in);

    uint64_t a=0;	
    uint64_t arr[50] = {0};
    uint64_t counter = 0;
	uint64_t k_v=0;
	if(myfile.is_open())
	{
		while (myfile >> a)
		{
			arr[counter] = a;
			counter++;
		}
		cout << "Please enter the value of k" << endl;
		cin >> k_v;
		for (int i = 0; i < counter ; i++)
		{
			
			uint64_t tmp = arr[i];
			if (tmp > 3)
			{
				int isComp = millerRabin(tmp,k_v);
				
				if (isComp==0)
				{
					cout << arr[i] << " \t    false " << endl ;
				}
				else
				{
					cout << arr[i] << " \t    true " << endl;
				}
			}
			else{
				cout << tmp << " is less than 3 and Miller rabin holds good only for values gretaer than 3 " << endl;
				
			}
		}
	}
	else{
		cout << "Error: Unable to open the file" << endl;
		cout << " Looking for file HW2.dat " << endl;
	}

}

