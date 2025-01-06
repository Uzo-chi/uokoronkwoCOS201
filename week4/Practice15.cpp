#include <iostream>
#include <new>
using namespace std;
int *array;
int i, size;
int main() {
	cout << "Enter the size of the array: ";
	cin >> size;
	array = new int [size]; // Declaring the array
	
	for (i=0; i<size; i++) {
		array[i] = i*i;
	}
	
	for (int j=0; j<size; j++){
		cout << "array[" << j << "] = " << array[j] << endl;
	}
	
	delete []array; // delete the array
	
	return 0;
}