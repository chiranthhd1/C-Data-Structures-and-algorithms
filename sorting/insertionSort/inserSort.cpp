#include <iostream>

using namespace std;

void Sort(int *arr,int len){
	int j,temp;
	for (int i = 1; i<=len-1;i++){
		temp = arr[i];
		j = i-1;
		cout << "Temp before while is :" << temp << endl; 
		cout << "a[j] before while is :" << arr[j] << endl; 
		while(temp < arr[j] && j>=0){
				cout << "inside the while" << endl;
				arr[j+1] = arr[j];
				j--;
		}	
		arr[j+1] = temp;
		
	}
	
	
}

int main(){
	
	int len=6;
	/*
	cout<< "enter length of the array" << endl;
	cin >> len;
	
	int arr[len];
	cout << "Enter the values to the array" << endl;
	for (int i=0; i < len; i++)
	{
		cout << i << "th value is : ";
		cin >> arr[i];
		cout << endl;
	}
	*/
int arr[] = {44,1,66,3,99,5};
	
	Sort(arr,len);
	cout << "sorted array is: " << endl;
	for (int i=0; i < len; i++)
	{
		cout << arr[i] << " " ;
		
	}
	
	
}