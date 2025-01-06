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
		char temp = chars[i];
		chars[i] = chars[j];
		chars[j] = temp;
	}
	return chars;
}

int main() {
	string guess;
	string words[5] = {"uzochi", "apples", "banana", "cocomelon", "undergraduate"};
	
	cout << "Scrambled Word Guessing Game!\n" << endl;
	for (int i=0; i<5; i++) {
		string mixedWord = scramble(words[i]);
		
		block1:
			cout << "Guess what word this is: " << mixedWord << endl;
			getline(cin, guess);
			
			if (guess == words[i]) {
				cout << "Correct!" << endl;
				continue;
			}
			else {
				goto block1;
			}
	}
}