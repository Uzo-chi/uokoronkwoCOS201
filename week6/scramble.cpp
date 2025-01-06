#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

string scramble(const string & text) {
	srand(time(0));
	string chars = text;
	for (int i = 0; i < chars.length(); i++) {
		int y = rand();
		int j = y % chars.length();
		cout << j << endl;
		char temp = chars[i];
		chars[i] = chars[j];
		chars[j] = temp;
	}
	return chars;
}

int main() {
	string text = "uzochi";
	string scrambled = scramble(text);
	
	cout << "Original: " << text << endl;
	cout << "Scrambled: " << scrambled << endl;
	
	return 0;
}