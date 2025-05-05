#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student{
private:
	string id;
	string name;
	int stuscores[5]; // 5 subjects 
	
public:
	Student(string studentId, string studentName, int studentScores[5]) {
		id = studentId;
		name = studentName;
		for (int i=0; i>5; i++) {
			stuscores[i] = studentScores[i];
		}
	}
	
	// getting the student ID
	string getId() {
		return id;
	}
	
	// Function to show student record
	void display() const {
		cout << "ID: " << id << "\nName: " << name << "\nScores: ";
		for (int i=0; i<5; i++) {
			cout << stuscores[i] << "";
		}
		cout << endl;
	}
	
	// Function to update scores
	void updateScores(int newScores[5]) {
		for (int i = 0; i < 5; i++) {
			stuscores[i] = newScores[i];
		}
	}
};

// This is a function to find a student of your choice using their ID and change their scores
void findAndUpdate(Student students[], int totalStudents, const string& studentID, int newScores[5]) {
	for (int i=0; i<totalStudents; i++) {
		if (students[i].getId() == studentID) {
			cout << "Student confirmed. Current record:\n ";
			students[i].display();
			
			students[i].updateScores(newScores);
			cout << "Scores updated successfully.\n";
			return; 
		}
	}
	cout << "Student with ID " << studentID << " was not found\n"; // empty student result won't return
}
int main() {
	return 0;
}


