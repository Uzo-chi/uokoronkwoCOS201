#include <iostream>
using namespace std;
int main() {
	int n=10;
	
	loop:
		cout << n << ",";
		n--;
		if (n>0) goto loop;
		cout << "End of loop!\n";
		return 0;
}