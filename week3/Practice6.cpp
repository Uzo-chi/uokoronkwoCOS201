#include <iostream>
using namespace std;
int a=40;
int b=30;
int main() {
	
	if (a == 40) {
		
		if (b < 12)
			cout << "A is equal to 40 and b is less than 12" << endl;
		else
			cout << "A is equal to 40 and B is greater than 12" << endl;
	}
	
	else {
		
		cout << "A is not equal to 40" << endl;
	}
	
	return 0;
}