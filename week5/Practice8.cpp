#include <iostream>
#include <string>
using namespace std;

struct student {
	string matno;
	string name;
};

int main() {
	student computer[5];
	
	for(int i=0; i<5; i++) {
		cout << "Enter the matriculation number of student " << i+1 << ": ";
		cin >> computer[i].matno;
		cout << "Enter the name of student " << i+1 << ": ";
		cin >> computer[i].name;
	}
	
	for(int i=0; i<5; i++) {
		cout << "\nMatriculation number of student: " << computer[i].matno << endl;
		cout << "Name of student " << i+1 << ": " << computer[i].name << endl;
	}
}