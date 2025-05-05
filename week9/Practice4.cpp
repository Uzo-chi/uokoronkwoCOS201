#include <iostream>
using namespace std;
float num, ans, denom;

int main() {
	cout << "Handling Exceptions" << endl;
	cout << "Enter Numerator" << endl;
	cin >> num;
	cout << "Enter Denominator" << endl;
	cin >> denom;
	try {
		if (denom == 0)
			throw denom;
		ans = num/denom;
		cout << "Output: " << ans;
	} catch (float e) {
		cout << "The denominator is zero";
	}
	
	return 0;
}