#include <iostream>
using namespace std;

class csc201 {
	public:
		int score;
		string name;
		char grade;
	public:
		void prerequisite() {
			cout << "Student must pass CSC101\n";
		}
		void verdict() {
			cout << "To pass the course the student must have a minimum score of 40";
		}
};

int main() {
	csc201 student1;
	student1.score = 20;
	student1.grade = 'F';
	student1.name = "Bello Moses Eromsele";
	cout << "Student1's Name = " << student1.name << ", grade = " << student1.grade << ", and score = " << student1.score << endl;
	student1.prerequisite();
	student1.verdict();
}