#include <iostream>
using namespace std;

int main() {
	int matrix1[3][3];
	int matrix2[3][3];
	
	for (int i=0; i<=2; i++){
		for (int j=0; j<=2; j++){	
			cout << "Input matrix1[" << i << "][" << j << "] matrix2[" << i << "][" << j << "]: ";
			cin >> matrix1[i][j] >> matrix2[i][j];
		}
	}
	
	for (int i=0; i<=2; i++){
		for (int j=0; j<=2; j++){	
			cout << matrix1[i][j]+matrix2[i][j] << "\t";
		}
		cout << "\n";
	}
}