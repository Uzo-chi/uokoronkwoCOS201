#include <iostream>
using namespace std;

int score[4][5] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
int result = 0;

int main() {
	for (int n=0; n < 4; n++){
		for (int i=0; i < 5; i++){
			result += score[n][i];
			cout << result << endl;
		}
	}
	cout << result;
	return 0;
}