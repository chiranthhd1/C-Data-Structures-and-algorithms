/*
 * Author - Amit Bhorania (10410232)
 * HW5A- Sort Array with Insertion and Quick Sort
 * Note - Program expects a hw5a.txt file present with executable file. 
 *        If the file is not present then it will exit the program
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

// Function to compute Time diff in ns format
uint64_t get_time_diff_ns(struct timespec *timeA, struct timespec *timeB)
{
	uint64_t sec = (timeA->tv_sec - 1 - timeB->tv_sec);
	uint64_t ns = ((timeA->tv_nsec + 1000000000ULL) - timeB->tv_nsec);

	return ((sec * 1000000000ULL) + ns);
}

// Function to Perform Insertion Sort
void insertionSort(int *x, int n) {
	int temp;
	for(int i = 1; i < n; i++) {
		if(x[i] < x[i-1]) {
			temp = x[i];
			for(int j = i-1; j >= 0; j--) {
				if(x[j] > temp) {
					x[j+1] = x[j];
					if(j == 0) {
						x[0] = temp;
					}
				}
				else {
					x[j+1] = temp;
					break;
				}
			}
		}
	}
}

void quickSort(int *x, int left, int right) {
	cout << "\n@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "\nLeft - " << left << "\nRight - " << right << endl;

	if(left >= right) {
		return;
	}

	//cout << "\nAmit" << endl;

	int pivot = (x[left] + x[right]) / 2;
	int i = left;
	int j = right;

	cout << "\nPivot - " << pivot << endl;
	//cout << " i " << i << endl;
	//	cout << " j " << j << endl;
	while(i < j) {
		//cout << "\nDipen" << endl;

		cout << " i and x[i] " << i << " " << x[i] << endl;
		cout << " j and x[j] " << j << " " << x[j] << endl;
		while(x[i] < pivot) {
			i++;
		}

		//cout << "\nRinkle" << endl;
		while(x[j] >= pivot) {
			j--;
		}

		//cout << "\nHari" << endl;
		if(i < j) {
			swap(x[i], x[j]);
		}
		//cout << "\nGhanshyam" << endl;
	}

	quickSort(x, left, i-1);
	quickSort(x, i, right);
}

int main() {
	struct timespec start1_t, end1_t;
	struct timespec start2_t, end2_t;

	// Read the input file
	ifstream data_file("hw5a.txt");
	
	// Check whether it opened successfully or not
	if(data_file.is_open() != true) {
		cout << "Error in Opening the file hw5a.txt\n";
		cout << "Program exiting....\n";
		return 0;
	}

	string s, cmd, mode;
	int n, max_value;
	int value;
	
	// Pointer to Hold the Array
	int *p, *q;

	// Random Value Generation
	std::random_device rd;
	std::mt19937 rng(rd());

	// Process each line of file
	getline(data_file, s);

	while(!data_file.eof()) {
		istringstream ss(s);

		cout << "\n==========================";

		// Extract Command, Mode and n
		ss >> cmd >> mode >> n;
		cout << "\nCommand - " << cmd;
		cout << "\nMode - " << mode;
		cout << "\nN - " << n;
		p = new int[n];
		q = new int[n];
		
		if(mode == "RANDOM") {
			ss >> max_value;
			cout << "\nMax - " << max_value;
	
			std::uniform_int_distribution<int> uni(0, max_value);

			for(int i = 0; i < n; i++) {
				p[i] = uni(rng);
				q[i] = p[i];
			}
			cout << "\nRandom Number Assignment Done";
		}
		else {
			// INPUT Mode - Get n number of int from file on next line
			getline(data_file, s);
			istringstream ss1(s);

			for(int i = 0; i < n; i++) {
				ss1 >> p[i];
				q[i] = p[i];
			}
			cout << "\nFile Number Assignment Done";
		}

		if(cmd == "PRINT") {
			cout << "\nUnsorted - " << endl;
			for(int i = 0; i < n; i++) {
				cout << "Hi" << endl;
				cout << p[i] << " ";
			}
		}

		cout << "\nPerforming Sorting" << endl;

		// Time Profiling 
		clock_gettime(CLOCK_REALTIME, &start1_t);
		insertionSort(p, n);
		clock_gettime(CLOCK_REALTIME, &end1_t);

		cout << "\nInsertion Sort Done" << endl;

		// Time Profiling 
		clock_gettime(CLOCK_REALTIME, &start2_t);
		quickSort(q, 0, n-1);
		clock_gettime(CLOCK_REALTIME, &end2_t);

		cout << "\nQuick Sort Done" << endl;

		for(int i = 0; i < n; i++) {
			if(p[i] != q[i]) {
				cout << "\n######################## ERROR ########################" << endl;
				cout << "\n######################## ERROR ########################" << endl;
				cout << "\n######################## ERROR ########################" << endl;
				break;
			}
		}

		cout << "\nPerforming Done" << endl;

		if(cmd == "PRINT") {
			cout << "\nInsertion Sorted - " << endl;
			for(int i = 0; i < n; i++) {
				cout << p[i] << " " << endl;
			}

			cout << "\nQuick Sorted - " << endl;
			for(int i = 0; i < n; i++) {
				cout << q[i] << " " << endl;
			}
		}
		else if(cmd == "BENCHMARK") {
			cout << "\nInsertion Sort Execution Time = " << get_time_diff_ns(&end1_t, &start1_t)/1000000ULL << "ms\n" << endl;
			cout << "\nQuick Sort Execution Time = " << get_time_diff_ns(&end2_t, &start2_t)/1000000ULL << "ms\n" << endl;
		}

		delete[] p;
		delete[] q;

		cout << "\nNEXT OPERATION" << endl; 

		// Next line	
		getline(data_file, s);
	}

	cout << "\n";

	return 0;
}
