#include <iostream>
using namespace std;
int main()
{
	int var = 10;
	int *ptr;
	int val;
		ptr = &var; // take the address of var
		val = *ptr; // take the value available at ptr
		
	cout << "Value of var: " << var << endl;
	cout << "Value of ptr: " << ptr << endl;
	cout << "Value of val: " << val << endl;
	
	return 0;
}