#include <iostream>
using namespace std;

int linearSearch(int array[], int key, int size){
	size = size - 1;
	if(size < 0){
		return -1;
	}
	else if(array[size] == key){
		return size;
	}
	else{
		return linearSearch(array,key,size);
	}
}


int main(){
	cout << "Enter the size of array: ";
	int size;
	cin >> size;
	int array[size], key, i;

	for(int j=0; j<size; j++){
		cout << "Enter element " << (j + 1) << "\n";
		cin >> array[j];
	}

	for(int a=0; a<size; a++){
		cout << "Array[" << a << "] = " << array[a] << "\n";
	}

	cout << "Enter key to search in array: ";
	cin >> key;
	int result = linearSearch(array, key, size--);
	if(result == -1){
		cout << "Key not found in array";
	}
	else{
		cout << "Key found at position " << result << "\n";
	}

	return 0;
}
