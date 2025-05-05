#include <iostream>
#include <exception>
#include <new>
using namespace std;
int main() {
	try {
		int *myarray = new int[1000000000000];
	}
	catch (bad_alloc &exception) {
		cerr << "bad_alloc detected: " << exception.what();
	}
	return 0;
}