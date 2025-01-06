#include <iostream>

using namespace std;

int * add(int a, int b){
	static int c[0];
	c[0] = a+b;
	
	return c;
}

int main() {
	int *p=NULL, num1=2, num2=6;
	p = add(num1, num2);
	cout << "*p = " << *p << endl;
	cout << "p = " << p << endl;
	
	return 0;
}