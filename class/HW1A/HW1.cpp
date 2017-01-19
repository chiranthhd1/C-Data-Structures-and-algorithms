#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int erathSievePrime(int a , int b)
{
	bool *isPrimeTrue =  new bool [b+1];
	memset(isPrimeTrue, true, sizeof(bool)*(b+1));

	if (a==1)
	{
		a++;
	}
	for (int i = a; i <=sqrt(b) ; i++)
	{
	
		if ((i%2==0) && i!=2)
			isPrimeTrue[i]=false;
	}
	int count1= 0;
	for (int p=2; p<= sqrt(b); p++)
	{
		if (isPrimeTrue[p])
		{
			for (int i=p*p ; i<=b;i+=p)
				isPrimeTrue[i] = false;
			count1++;
		}

	}
	
	int count = 0;
	for (int i=a; i<=b;i++)
	{
		if(isPrimeTrue[i])
		{
			count++;
		}
	}
	

	cout << "total number of primes are count1: " << count1 << endl;
	delete [] isPrimeTrue;
	return count;
}

int main()
{
	unsigned long long int a = 0LL;
	unsigned long long int b = 0LL;
	
//	uint64_t a=0 ;
//	uint64_t b=0 ;

	cout << "Enter first number" << endl;
	cin >> a;
	if (a < 2 )
	{
		cout << "Please enter numbers greater than 1" << endl;
	}
	cout << "Enter second number " << endl;
	cin >> b;
	if (b < 2 )
	{
		cout << "Please enter numbers greater than 1" << endl;
	}
	cout << "Total number of primes between "<<a<<" and "<<b<<" are  "<< erathSievePrime(a,b) << endl;

}
	
