#include <iostream>
using namespace std;

union mix_t {
	int a;
	struct {
		short hi;
		short lo;
	} s;
	char c[4];
} mix;

int main() {
	cout << "Enter value for int a \n";
	cin >> mix.a;
	cout << "The value for a is " << mix.a << endl;
	cout << "\nEnter value for short hi\n";
	cin >> mix.s.hi;
	cout << "The value for short hi " << mix.s.hi << endl;
	cout << "\nEnter value for short lo\n";
	cin >> mix.s.lo;
	cout << "The value for short lo " << mix.s.lo << endl;
	cout << "\nThe value for a is " << mix.a << endl;
	cout<<"\nThe values of c[0], c[1], c[2], c[3] are "<<mix.c[0]<<" "<<mix.c[1]<<" "<<mix.c[2]<<" "<<mix.c[3]<<endl;
	return 0;
}