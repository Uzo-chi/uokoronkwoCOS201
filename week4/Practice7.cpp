// Example on pointers
#include <iostream>
using namespace std;
int main() {
	int numbers[5];
	int *p;
	p = numbers;
	cout << p << endl;
	*p = 10;
	cout << numbers[0];
	p++;
	*p = 20;
	p = &numbers[2]; // Address of &numbers[2] was assigned to p
	*p = 30; // *p points to 30 so numbers[2] = 30
	p = numbers + 3; // Address of numbers+3 which is numbers[3] was assigned to p
	*p = 40; // *p points to 40 so numbers[3] = 40
	p = numbers; // Address of numbers which is numbers[0] was assigned to p
	*(p+4) = 50; /* p+4 is the same thing as address of numbers[4] because p=numbers so *(p+4) points to 50*/
	for (int n=0; n<5; n++) {
		cout << numbers[n] << endl;
	}
	
	return 0;
}