#include <iostream>
using namespace std;
void *a;
int num=10;
int *b;

int main() {
	a = &num;
	b = (int*)a;
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "*b = " << *b << endl;
	return 0;
}