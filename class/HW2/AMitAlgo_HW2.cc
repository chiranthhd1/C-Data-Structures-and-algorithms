/*/
 * Author - Amit Bhorania (10410232)
 * HW2- Miller-Rabin Primality Test
 */

#include <iostream>
#include <stdlib.h>
#include <cstdint>
#include <cmath>
#include <time.h>
#include <random>
#define MAX_LIMIT 1000000000ULL

using namespace std;

// Function to compute Time diff in ns format
uint64_t get_time_diff_ns(struct timespec *timeA, struct timespec *timeB)
{
	uint64_t sec = (timeA->tv_sec - 1 - timeB->tv_sec);
	uint64_t ns = ((timeA->tv_nsec + 1000000000ULL) - timeB->tv_nsec);
	
	return ((sec * 1000000000ULL) + ns);
}

// Function to Compute Power Mod (x^n mod m)
uint64_t powermod(uint64_t x, uint64_t n, uint64_t m) {
	uint64_t prod = 1;

	while(n > 0) {
		if(n % 2 != 0) {
			prod = (prod * x) % m;
		}
		x = (x * x) % m;
		n = n / 2;
	}
	return prod;
}

// Function to Find Primes between two numbers using Seive of Eratosthenes Method
bool miller_rabin(uint64_t n, uint64_t k) {
	uint64_t d;
	uint64_t r;
	uint64_t value = n-1;	
	uint64_t a;
	uint64_t x;
	int flag = 0;

	// Random Value Generation
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<uint64_t> uni(2, n-2);
	
	cout << "\nChecking Primality of Number = " << n << "\n";
	// Find out the d and r value such that n-1 = (2^r)*d
	uint64_t i;
	i = 0;
	while(value % 2 == 0) {
		value = value / 2;
		i++;
	}
	d = value;
	r = i;
	cout << "\nRepresenting " << n-1 << " = 2^" << r << " * " << d;
	cout << "\nd = " << d;
	cout << "\nr = " << r << "\n\n";

	for(i = 0; i < k; i++) {
		// Pick a from 2 to n-2
		a = uni(rng);

		cout << "\n\tTaking " << a << " as witness...";
		// Perform Powermod operation a^d mod n
		x = powermod(a,d,n);

		// If result is 1 or n-1 => Continue to check prime with other base a
		if(x == 1 || x == n-1) {
			cout << "Probably Prime";
			continue;
		}

		flag = 0;
		// Check the prime r-1 times by squaring x and checking powermod output
		for(uint64_t j = 0; j < r-1; j++) {
			x = powermod(x,2,n);
			if(x == 1) {
				cout << "NOT Prime";
				// Composite number
				return false;
			}

			if(x == n-1) {
				flag = 1;
				cout << "Probably Prime";
				// Continue to check prime with other base a
				break;
			}
		}
		if(flag == 0) {
			cout << "NOT Prime";
			// Composite number
			return false;
		}
	}

	// Probably Prime
	return true;
}

int main() {
	uint64_t n;
	uint64_t k;
	bool result;
	struct timespec start_t, end_t;

	cout << "HW2-Miller Rabin\n";
	cout << "================\n";

	cout << "Please Enter the Number to test for Miller Rabin Primality Test...\n";
	cout << "Number = ";
	cin >> n;

	cout << "Please Enter the Number of repeatation...\n";
	cin >> k;

	// Error Checking
	if (n%2 == 0 && n > 2) {
		cout << "You entered Even Number which is not Prime....No need to test using Miller Rabin Algo\n";
		exit(0);
	} 


	if (n <= 3) {
		cout << "ERROR - Please enter odd number greater than 3\n";
		exit(EXIT_FAILURE);
	}

	if (k < 1) {
		cout << "ERROR - Please enter repeatation number greater than 0";
		exit(EXIT_FAILURE);
	}

	// Time Profiling 
	clock_gettime(CLOCK_REALTIME, &start_t);

	// Find out Prime Numbers for given range
	result = miller_rabin(n, k);
	
	clock_gettime(CLOCK_REALTIME, &end_t);

	if(result == true) {
		cout << "\n\n\nGiven Number " << n << " is Probably Prime\n";
	}
	else {
		cout << "\n\n\nGiven Number " << n << " is NOT Prime\n";
	}

	cout << "\n\nAlgorithm Execution Time = " << get_time_diff_ns(&end_t, &start_t)/1000000ULL << "ms\n";
}

