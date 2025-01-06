#include <iostream>
using namespace std;

int main(){
	int upper, lower;
	int result = 0;
	cout << "Input upper limit: ";
	cin >> upper;
	cout << "Input lower limit: ";
	cin >> lower;
	
	if (upper > lower){
		for (int i=lower; i<upper; i++){
			if (i % 2 != 0) {
				cout << i << "\t";
				result += i;
			} else {
				continue;
			}
		}
		cout << "\nThe sum of all odd numbers between " << lower << " and " << upper << " is " << result;
	} else if (upper == lower) {
		cout << "The upper and lower limits are equal!" << endl;
	} else {
		cout << "The upper limit is less than the lower limit!" << endl;
	}
}