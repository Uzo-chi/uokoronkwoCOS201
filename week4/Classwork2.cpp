#include <iostream>
using namespace std;

int main() {
	int n;
	
	cout << "Enter value for n: ";
	cin >> n;
	
	for (int i=1; i<13; i++){
		for (int j=1; j<=n; j++){
			cout << i << " * " << j << " = " << i*j << "\t";
		}
		cout << "\n";
	}
}