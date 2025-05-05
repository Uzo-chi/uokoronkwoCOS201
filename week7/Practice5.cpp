#include <iostream>
using namespace std;

class course {
public:
  string coursecode;
};

class csc201 : public course {
public:
  char grade;
  int score;
  string name;
};

int main() {
  csc201 student1;
  student1.score = 20;
  student1.grade = 'F';
  student1.coursecode = "CSC201";
  student1.name = "Bello Moses Eromsele";
  cout << "Student's Name = " << student1.name << ", grade = ";
  cout << student1.grade << ", and score = " << student1.score << endl;
  cout << "Student1 coursecode inherited from course " << student1.coursecode;
}
