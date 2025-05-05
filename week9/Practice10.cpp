#include <iostream>
#include <exception>
using namespace std;

int AddPositiveIntegers(int a, int b) {
	if (a < 0 || b < 0)
		throw invalid_argument("Add Positive Integers arguments must be positive");
	return (a + b);
}

int main() {
	try {
		cout << AddPositiveIntegers(-1, 2);
	}
	catch (invalid_argument& e) {
		cerr << e.what() << endl;
		return -1;
	}
	
	return 0;
}