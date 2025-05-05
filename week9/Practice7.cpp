#include <iostream>
using namespace std;

void func(int test) throw(int, char, double) {
	if (test == 0) throw test;
	if (test == 1) throw 'a';
	if (test == 2) throw 123.23;
}

int main() {
	try {
		func(1);
	} catch(int i) {
		cout << "Caught int\n";
	} catch(char c) {
		cout << "Caught char\n";
	} catch(double d) {
		cout << "Caught double\n";
	}
	return 0;
}