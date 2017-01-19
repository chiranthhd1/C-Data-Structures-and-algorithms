#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <ctime>

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

vector<uint64_t> splitInt(string str, char delimiter) {
  	vector<uint64_t> internal;
  	stringstream ss(str);
  	string tok;
  
  	while(getline(ss, tok, delimiter)) {
    		uint64_t tmp=0;
    		tmp = atoi(tok.c_str());
    		internal.push_back(tmp);
  	}
  	return internal;
}

void insertSort(int *arr,int len){
	int j,temp;
	for (int i = 1; i<=len-1;i++){
		temp = arr[i];
		j = i-1;
		while(temp < arr[j] && j>=0){
				arr[j+1] = arr[j];
				j--;
		}	
		arr[j+1] = temp;
		
	}
	
	
}

void partitionArray(int *a, int beg, int end, int *pivotLoc){
	int left = beg;
	int right = end;
	*pivotLoc = left;
	int tmp;

	while(1){

		while(a[*pivotLoc] <= a[right] && *pivotLoc != right){	
			right--;
		}

		if(*pivotLoc == right){
			break;
		}else if(a[*pivotLoc] > a[right]){
			tmp = a[right];
			a[right] = a[*pivotLoc];
			a[*pivotLoc] = tmp;
			*pivotLoc = right;}

	
		while(a[*pivotLoc] >= a[left] && *pivotLoc != left){
			left++;
		}

		if(*pivotLoc == left){
			break;
		}else if(a[*pivotLoc] < a[left]){
			tmp = a[left];
			a[left] = a[*pivotLoc];
			a[*pivotLoc] = tmp;
			*pivotLoc = left;
		}
	}
}


void quickSort(int *a, int beg, int end){
	int pivotLoc;
	if(beg < end){
		partitionArray(a, beg, end, &pivotLoc);	
		quickSort(a, beg, pivotLoc - 1);
		quickSort(a, pivotLoc + 1, end);
	}
}
int main(){

	
	fstream myFile("hw5a.txt");
	int flag = 0;
	int inputPrintLen = 0;
	srand(time(NULL));

	cout << "*************************************************" << endl;
	cout << "Insertion Sort " << endl;
	cout << "*************************************************" << endl;

	if(myFile.is_open()){
		string instruct;
		while( getline(myFile,instruct,'\n')){	
			if(instruct == ""){
				continue;
			}
			if (flag == 1){
				int arr[inputPrintLen] = {0};
				vector<uint64_t> v(inputPrintLen);
				v = splitInt(instruct, ' ');
				for (uint64_t i = 0; i < inputPrintLen ; i++){
					cout << v[i] <<" ";
					arr[i] = v[i];
				}
				cout << endl;
				insertSort(arr,inputPrintLen);
				for (int i=0; i < inputPrintLen; i++)
				{
					cout << arr[i] << " " ;
				}
				cout << endl;
				inputPrintLen = 0;
				flag = 0;

				

				
			}
		
			vector<string> sep;
			sep.reserve(100);
			sep = split(instruct, ' ');
			if (sep[0] == "10"){
				continue;
				cout << "fm" << endl;
			}
			
			if (sep[0] == "PRINT" && sep[1]=="RANDOM"){
				int in1 = 0;
				int in2 = 0; 
				in1 = atoi(sep[2].c_str());
				in2 = atoi(sep[3].c_str());;
				int arr[in1] = {0};
				for(int i = 0; i < in1 ; i++){
					int ran = rand()%(in2-1)+1;
					cout << ran << " ";
					arr[i] = ran;
				}
				cout << endl;
				insertSort(arr,in1);
				for (int i=0; i < in1; i++)
				{
					cout << arr[i] << " " ;
				}
				cout << endl;
 			}

 			if(sep[0] == "BENCHMARK" && sep[1] == "RANDOM" ){
 				int in1 = 0;
				int in2 = 0; 
				in1 = atoi(sep[2].c_str());
				in2 = atoi(sep[3].c_str());
				int arr[in1] = {0};
				for(int i = 0; i < in1 ; i++){
					int ran = rand()%(in2-1)+1;
					arr[i] = ran;
				}
				int startTime = clock();
				insertSort(arr,in1);
				int stopTime = clock();
				cout << "Time elapsed is : " << (stopTime-startTime)/double(CLOCKS_PER_SEC)*1000 << endl;
				
 			}
 			if (sep[0]=="PRINT" && sep[1] == "INPUT"){
 				inputPrintLen = atoi(sep[2].c_str());
 				flag = 1;
 				continue;

 			}


 		}
	}
	else{

		cout << "please check the file name. code works with only hw5a.txt file" << endl; 
	}		

cout << "*************************************************" << endl;
cout << "Quick Sort " << endl;
cout << "*************************************************" << endl;

fstream myFile2("hw5a.txt");


if(myFile2.is_open()){
	string instruct;
		while( getline(myFile2,instruct,'\n')){	
			if(instruct == ""){
				continue;
			}
			if (flag == 1){
				int arr[inputPrintLen] = {0};
				vector<uint64_t> v(inputPrintLen);
				v = splitInt(instruct, ' ');
				for (uint64_t i = 0; i < inputPrintLen ; i++){
					cout << v[i] <<" ";
					arr[i] = v[i];
				}
				cout << endl;
				quickSort(arr, 0, inputPrintLen-1);
				//insertSort(arr,inputPrintLen);
				for (int i=0; i < inputPrintLen; i++)
				{
					cout << arr[i] << " " ;
				}
				cout << endl;
				inputPrintLen = 0;
				flag = 0;

				

				
			}
		
			vector<string> sep;
			sep.reserve(100);
			sep = split(instruct, ' ');
			if (sep[0] == "10"){
				continue;
				cout << "fm" << endl;
			}
			
			if (sep[0] == "PRINT" && sep[1]=="RANDOM"){
				int in1 = 0;
				int in2 = 0; 
				in1 = atoi(sep[2].c_str());
				in2 = atoi(sep[3].c_str());;
				int arr[in1] = {0};
				for(int i = 0; i < in1 ; i++){
					int ran = rand()%(in2-1)+1;
					cout << ran << " ";
					arr[i] = ran;
				}
				cout << endl;
				//insertSort(arr,in1);
				quickSort(arr, 0, in1-1);
				
				for (int i=0; i < in1; i++)
				{
					cout << arr[i] << " " ;
				}
				cout << endl;
 			}

 			if(sep[0] == "BENCHMARK" && sep[1] == "RANDOM" ){
 				int in1 = 0;
				int in2 = 0; 
				in1 = atoi(sep[2].c_str());
				in2 = atoi(sep[3].c_str());
				int arr[in1] = {0};
				for(int i = 0; i < in1 ; i++){
					int ran = rand()%(in2-1)+1;
					arr[i] = ran;
				}
				int startTime = clock();
				//insertSort(arr,in1);
				quickSort(arr, 0, in1-1);
				
				int stopTime = clock();
				cout << "Time elapsed is : " << (stopTime-startTime)/double(CLOCKS_PER_SEC)*1000 << endl;
				
 			}
 			if (sep[0]=="PRINT" && sep[1] == "INPUT"){
 				inputPrintLen = atoi(sep[2].c_str());
 				flag = 1;
 				continue;

 			}


 		}
	}
	else{

		cout << "please check the file name. code works with only hw5a.txt file" << endl; 
	}		
	cout << "*************************************************" << endl;	
	
	
	
}