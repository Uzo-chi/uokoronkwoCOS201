#include <iostream>
using namespace std;

enum week {
	Sunday=12, Monday=1, Tuesday=5, Wednesday, Thursday, Friday, Saturday
};

int main() {
	week today;
	today = Wednesday;
	cout << "Day " << today+1;
	return 0;
}