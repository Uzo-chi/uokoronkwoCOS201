#include <iostream>
using namespace std;

class csc201 {
private:
  char grade;
  int score;

public:
  string name;

public:
  csc201() {
    cout << "Student must pass CSC101\n";
    cout << "To pass the course the student must have a minimum score of 40\n";
  }

  void setScore(int s) { score = s; }

  int getScore() { return score; }

  void setGrade(char g) { grade = g; }

  int getGrade() { return grade; }
};

int main() {
  csc201 student1;
  student1.setScore(20);
  student1.setGrade('F');
  student1.name = "Bello Moses Eromsele";
  cout << "Student's Name = " << student1.name
       << ", grade = " << student1.getGrade()
       << ", and score = " << student1.getScore() << endl;
}
