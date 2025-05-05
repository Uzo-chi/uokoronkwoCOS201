#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ofstream myfile("example.txt", ios::app);
  if (myfile.is_open()) {
    myfile << "This is a line.\n";
    myfile << "Appended.\n";
    myfile.close();
  } else
    cout << "Unable to open file";
  return 0;
}
