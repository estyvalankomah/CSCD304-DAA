#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <ctime>
#include <fstream>
using namespace std;

void genRandInput(int arr[],int n){
	int i;
	srand(time(NULL));
	for(i = 0; i < n; i++){
		arr[i] = rand() % 100;
	}
}

void merge(int arr[], int low, int mid, int high){
	int num1, num2, i, j, k;
	num1 = mid - low + 1;
	num2 = high - mid;

	int left[num1], right[num2];

	for(i = 0; i < num1; i++){
		left[i] = arr[low + i];
	}

	for(j = 0; j < num2; j++){
		right[j] = arr[mid + j + 1];
	}

	i = 0, j = 0 ;

	for(k = low; i < num1 && j < num2; k++){
		if(left[i] < right[j]){
 			arr[k] = left[i++];
		}
		else{
			arr[k] = right[j++];
		}
	}

	while(i < num1){
		arr[k++] = left[i++];
	}

	while(j < num2){
		arr[k++] == right[j++];
	}
}

void mergeSort(int arr[], int low, int high){
	int mid;
	if(low < high){
		mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		
		merge(arr, low, mid, high);
	}
}

int main(){
	ofstream fp;
	struct timeval tv;
	double dStart, dEnd;
	int n;

	fp.open("mergePlot.dat");

	for(int i = 0; i < 6; i++){
		cout << "\nEnter number of elements to be sorted\n";
		cin >> n;

		int arr[n];
		genRandInput(arr,n);
		gettimeofday(&tv, NULL);
		dStart = tv.tv_sec + (tv.tv_usec / 1000000.0);
		mergeSort(arr, 0, n - 1);
		gettimeofday(&tv, NULL);
		dEnd = tv.tv_sec + (tv.tv_usec / 1000000.0);

		fp << n << "\t";
		fp << (dEnd - dStart) << "\n";

		cout << "\nSorted elements : ";

		for(int j = 0; j < n; j++){
			cout << arr[j] << " ";
		}
	}

	fp.close();
	
	cout << "\nData file generated and stored in file <mergePlot.dat>";
	
	
	cout << "\n";

	return 0;

}
