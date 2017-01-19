#include <stdio.h>
#define SIZE 6


void partitionArray(int *a, int beg, int end, int *pivotLoc);
void quickSort(int *a, int beg, int end);

int main(){
	int a[SIZE] = {5,2,6,1,3,4};
	int i;

	quickSort(a, 0, SIZE-1);
	for(i = 0; i < SIZE; i++){
		printf("%d\t", a[i]);
	}
	return 0;
}

void quickSort(int *a, int beg, int end){
	int pivotLoc;
	if(beg < end){
		partitionArray(a, beg, end, &pivotLoc);	
		quickSort(a, beg, pivotLoc - 1);
		quickSort(a, pivotLoc + 1, end);
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
