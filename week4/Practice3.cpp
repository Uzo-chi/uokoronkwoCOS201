#include <iostream>
#include <string.h>
#include <string> // for string class

using namespace std;
int main() {
	string str = "Pan Atlantic University";
	string str2 = "Pan-Atlantic University";
	cout << "str.compare(str2): " << str.compare(str2) << endl;
	cout << "str.length(): " << str.length() << endl;
	cout << "str.size(): " << str.size() << endl;
	// Swap string
	str.swap(str2);
	cout << "str.swap(str2): " << str << endl;
	// Create substring
	int position = 0;
	int number = 5;
	cout << "str.substr(position, number): " << str.substr(position, number) << endl;
}