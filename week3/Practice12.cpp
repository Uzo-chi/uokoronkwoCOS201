#include <iostream>
using namespace std;

int func(int &a, int &b) {
	int r;
	--a;
	--b;
	r=a+b;
	return r;
}

int main(){
	int num1 = 4;
	int num2 = 6;
	cout << "Num1 before calling func: " << num1 << endl;
	cout << "Num2 before calling func: " << num2 << endl;
	int z = func(num1,num2);
	cout << "The result is " << z << endl;
	cout << "Num1 after calling func: " << num1 << endl;
	cout << "Num2 after calling func: " << num2 << endl;
}