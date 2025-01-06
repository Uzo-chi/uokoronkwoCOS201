#include <iostream>
using namespace std;
int score [] = {6,3,4,2,4};
int n, result = 0;

int main () {
	for (n=0; n < 5; n++) {
		result += score[n];
	}
	cout << result << endl;
	cout << score[8];
	return 0;
}