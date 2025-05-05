#include <iostream>
using namespace std;

float num, ans, denom;

float divide(float numerator, float denominator) {
	float answer;
	if (denominator == 0)
		throw denominator;
	else if(denominator > numerator)
		throw "Denominator is greater than numerator";
	else {
		answer = numerator/denominator;
	}
	return answer;
}

int main() {
	cout << "Handling Exception" << endl;
	cout << "Enter Numerator" << endl;
	cin >> num;
	cout << "Enter Denominator" << endl;
	cin >> denom;
	try {
		ans = divide(num, denom);
		cout << "Output: " << ans;
	} catch (float e) {
		cout << "The denominator is Zero";
	} catch (const char *St) {
		cout << "Denominator is greater than numerator";
	}
	
	return 0;
}