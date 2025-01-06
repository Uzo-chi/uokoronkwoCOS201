#include <iostream>
using namespace std;

using C = char;
using NUMBERS = int;
using field = char [50];

int main() {
	
	C x='a';
	NUMBERS y = 10;
	NUMBERS z = 5;
	field characters="Hello World";
	
	NUMBERS c=y+z;
	
	cout << "NUMBERS c=y+z, So c = " << c << endl;
	cout << "field characters = " << characters << endl;
	cout << "C x='a', So x = " << x << endl;
	return 0;
}