#include <iostream>

using namespace std;

void passPointer(int *p) {
	cout << "In the function" << endl;
	cout << "*p = " << *p << endl;
	cout << "p = " << p << endl;
}

int main() {
	int num = 9;
	passPointer(&num);
	return 0;
}