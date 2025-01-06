#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct biodata {
	string name;
	int dob;
};

struct csc211 {
	biodata data;
	int score;
};

csc211 student1;

int main() {
	cout << "Enter student's name: ";
	cin >> student1.data.name;
	cout << "Enter student's age: ";
	cin >> student1.data.dob;
	cout << "Enter sudent's csc211 score: ";
	cin >> student1.score;
	cout << "\nThe students name is: " << student1.data.name << endl;
	cout << "The students age is: " << student1.data.dob << endl;
	cout << "The students score in csc211 is: " << student1.score << endl;
	
	return 0;
}