#include <iostream>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;

int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
 
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


int getRandD(uint64_t n)//, int counter)
{
	cout << "n is " << n << endl;
	uint64_t nM1 = n-1;
	uint64_t buf = nM1;
	uint64_t r=0;
	uint64_t d=0;
	uint64_t x=0;
    if ( n ==2 || (n%2==0)){
		//cout << n << " is not a prime " << endl;	
		return 1;
    }
    else{	      
	    while( buf %2==0 ){
			r++;
			buf/=2;
		}
		
		d = buf;
		for (int k=0 ; k< 10 ; k++){
			//cout << "inside for loop with k value as " << k << endl;
			uint64_t a = rand() % ((nM1-1)-2+1) +2;
			//cout << "a" << a << endl;
			x = power (a,d,n);
			//cout << "n" << n << endl; 
			//cout << " nM1 " << nM1 << endl;
			//cout << " r " << r << endl;
			//cout << " x " << x << endl; 
			//cout << " d " << d << endl<< endl;
			if ( x == 1 || x == nM1){
				cout << "the number " << n << " is probably prime" << endl; 

			}
			else{
				for ( int f=1; f <=r-1;f++){
					x =  power(x , 2, n);
					if( x == 1){
						//cout << x << " the number is composite" << endl;
						return 0;
					}
					if ( x == -1){
					//	cout << "Kill me" << endl;
						cout << "Number is fucking prime" << endl;
						break;
					}
					//cout << "going to calculate for the next f:" << f <<" value and value of x is" << x << endl;
				}
			}
		}
		return 0;
	}
}



int main()
{
    fstream myfile("HW2.dat", ios_base::in);

    uint64_t a=0;	
    uint64_t arr[20] = {0};
    uint64_t counter = 0;
    while (myfile >> a)
    {
		arr[counter] = a;
		counter++;
    }
    
    for (int i = 0; i < counter ; i++)
    {
    	//cout << arr[i] << endl;
		uint64_t tmp = arr[i];
		int isComp = getRandD(tmp);
		if (isComp==0)
		{
			cout << "number is composite" << endl;
		}
		else
		{
			cout << "Number is prime " << endl;
		}
		
    }


   


}

