#include <iostream>
using namespace std;
union array {
	short num[10];
	char a[10];
} letters;
int main() {
	for(int i=0; i<10; i++) {
		letters.num[i] = i+65;
	}
	for(int j=0; j<10; j++) {
		cout << "number: " << letters.num[j] << "    letter: " << letters.a[j] << endl;
	}
	
	return 0;
}