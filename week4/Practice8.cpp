// C++ program to demonstrate pointer to pointer
#include <iostream>
using namespace std;

int main() {
	int var = 789;
	int *ptr2; // pointer for var
	int **ptr1; // double pointer for ptr2
	ptr2 = &var; // storing address of var in ptr2
	ptr1 = &ptr2; // storing address of ptr2 in ptr1
	cout << "Value of var = " << var << endl;
	cout << "Content value of single pointer ptr2 = " << *ptr2 << endl;
	cout << "Address value of single pointer ptr2 = " << ptr2 << endl;
	cout << "Content value of double pointer ptr1 = " << **ptr1 << endl;
	cout << "Address value of double pointer ptr1 = " << ptr1 << endl;
	
	return 0;
}