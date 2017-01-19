#include <iostream>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <random>

using namespace std;

uint64_t power(uint64_t x, uint64_t y, uint64_t p)
{
    uint64_t res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}


int millerRabin(uint64_t n, uint64_t k_v)//, int counter)
{
	//cout << "n is " << n << endl;
	uint64_t nM1 = n-1;
	uint64_t buf = nM1;
	uint64_t r=0;
	uint64_t d=0;
	uint64_t x=0;
	int flag=0;
    if ( n ==2 || (n%2==0)){
		//cout << n << " is not a prime " << endl;	
		return 0;
    }
    else{	      
	    while( buf %2==0 ){
			buf/=2;
			r++;
		}
		
		d = buf;
		for (uint64_t k=0 ; k< k_v ; k++){
			//cout << "inside for loop with k value as " << k << endl;
			
			std::default_random_engine generator;
			std::uniform_int_distribution<uint64_t> distribution(2,nM1-1);
			uint64_t a = distribution(generator); 
			
			//cout << "a" << a << endl;
			x = power (a,d,n);
			//cout << " n " << n << endl; 
			//cout << " nM1 " << nM1 << endl;
			//cout << " r " << r << endl;
			//cout << " x " << x << endl; 
			//cout << " d " << d << endl<< endl;
			if ( x == 1 || x == nM1){
				//cout << "the number " << n << " is probably prime" << endl;
				continue;

			}
			flag=0;
			for ( uint64_t f=0; f <=r-1;f++){
				x =  power(x , 2, n);
				if( x == 1){
					//cout << x << " the number is composite" << endl;
					return 0;
				}
				if ( x == nM1){
					//cout << "Kill me" << endl;
					//cout << "Number is fucking prime" << endl;
					flag = 1;
					break;
				}
				//cout << "going to calculate for the next f " << f <<" value and value of x is" << x << endl;
			}
			if(flag == 0) {
				//cout << "Flag value is " << flag << " and exiting" << endl;
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
    uint64_t arr[20] = {0};
    uint64_t counter = 0;
	uint64_t k_v=0;
    while (myfile >> a)
    {
		arr[counter] = a;
		counter++;
    }
    
    for (int i = 0; i < counter ; i++)
    {
    	//cout << arr[i] << endl;
		uint64_t tmp = arr[i];
		//cout << "Please enter the value of k " << endl;
		//cin >> k_v;
		int isComp = millerRabin(tmp,10);
		if (isComp==0)
		{
			cout << arr[i] << " is composite" << endl << endl;
		}
		else
		{
			cout << arr[i] << " is  probably prime " << endl<< endl;
		}
		
    }
/*
	int isComp = millerRabin(961748947,10);
		if (isComp==0)
		{
			cout << "number is composite" << endl << endl;
		}
		else
		{
			cout << "Number is prime " << endl<< endl;
		}
   
*/

}

