#include <fstream>
#include <iostream>
using namespace std;

int main() {
  // Create the file
  ofstream myfile;
  // Open the file
  myfile.open("example.txt");
  // Write to the file
  myfile << "Writing this to a file.\n";
  // Close the file
  myfile.close();
  return 0;
}
