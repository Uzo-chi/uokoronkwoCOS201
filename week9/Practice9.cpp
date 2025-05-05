#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> myvector(10);
	try {
		myvector.at(20) = 100;
	} catch (const out_of_range &err) {
		cerr << "Out of Range Error: " << err.what() << endl;
		cerr << "Type: " << typeid(err).name() << endl;
	}
	
	return 0;
}