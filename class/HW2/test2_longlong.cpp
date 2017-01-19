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


int getRandD(long long n)//, int counter)
{
   //for(int i =0; i <counter; i++)
   //{
      
      //long long n= 0;
      //n = arr;
	  cout << "n is" << n << endl;
      if ( n ==2 || (n%2==0))
      {
	
			cout << n << " is not a prime " << endl;		
      }
      else
      {
	      cout << "n" << n << endl; 
	      long long nM1 = n-1;
	      long long buf = nM1;
	      long long r=0;
	      long long d=0;
	      long long x=0;
	      while( buf %2==0 ){
		  r++;
		  buf/=2;
	  }
	  d = buf;
	  for (int k=0 ; k< 10 ; k++)
	  {
			cout << "inside for loop with k value as " << k << endl;
		      long long a = rand() % ((nM1-1)-2+1) +2;
		      cout << "a" << a << endl;
		      
		      
		      //x = pow(a,d);
		      //x = x% n;
			  x = power (a,d,n);
		      cout << " Buf " << buf << endl;
		      cout << " nM1 " << nM1 << endl;
		      cout << " r " << r << endl;
		      cout << " x " << x << endl; 
			  cout << " d " << d << endl<< endl;
		      if ( x == 1 || x == nM1)
		      {

					cout << "the number " << n << " is probably prime" << endl; 

		      }
		      else
		      {
				for ( int f=1; f <=r-1;f++)
				{
					  x =  power(x , 2, n);
					  if( x == 1)
					  {
						cout << x << " the number is composite" << endl;
						return 0;
					  }

					  if ( x == -1)
					  {
						cout << "Kill me" << endl;
						cout << "Number is fucking prime" << endl;
						break;
					  }
						cout << "going to calculate for the next f:" << f <<" value and value of x is" << x << endl;
				}
		      }
		}	
      } 
    //}
}



int main()
{
   fstream myfile("HW2.dat", ios_base::in);

    long long a=0;	
    long long arr[20] = {0};
    long long counter = 0;
    while (myfile >> a)
    {
	arr[counter] = a;
	counter++;
    }
    
    for (int i = 0; i < counter ; i++)
    {
    	cout << arr[i] << endl;
		long long tmp = arr[i];
		int isComp = getRandD(tmp);
		if (isComp==0)
		{
			cout << "number is composite" << endl;
		}
		
    }


   


}

