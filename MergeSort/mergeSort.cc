#include <iostream>
using namespace std;

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
	int n;

	cout << "Enter array size : " ;
	cin >> n;

	int arr[n];
	
	for(int i = 0; i < n; i++){
		cout << "\nEnter element " << (i + 1) << ": ";
		cin >> arr[i];
	}

	mergeSort(arr, 0, n - 1);

	cout << "\nSorted elements : ";

	for(int j = 0; j < n; j++){
		cout << arr[j] << " ";
	}
	
	cout << "\n";

	return 0;

}
