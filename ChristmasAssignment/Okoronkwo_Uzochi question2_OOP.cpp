#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

class WordGame {
	private:
	  vector<string> words;
	  vector<string> hints;
	  int score;
	  int gclUses;
	
	  string stripWhiteSpace(const string &input) {
	    string result;
	    for (char c : input) {
	      if (!isspace(c)) {
	        result += c;
	      }
	    }
	    return result;
	  }
	
	  string scramble(const string &text) {
	    string chars = text;
	    srand(time(0));
	    for (size_t i = 0; i < chars.length(); i++) {
	      int j = rand() % chars.length();
	      swap(chars[i], chars[j]);
	    }
	    return chars;
	  }
	
	  void displayRules() {
	    cout << "\nWelcome to the spelling game!\n"
	         << "You are to guess the correct word while keeping the following "
	            "rules in mind:\n"
	         << " - Enter 'g' to reveal a correct position for a letter\n"
	         << " - Enter 'n' to skip to the next word (you will not gain any "
	            "points)\n"
	         << " - Enter 'h' to receive a clue for the word\n"
	         << endl;
	  }
	
	  void playWord(const string &word, const string &hint) {
	    string scrambledWord = scramble(word);
	    string guess;
	    int search = 0;
	
	    cout << "\nScrambled Word: " << scrambledWord << endl;
	
	    while (true) {
	      cout << "Get correct letter uses: " << gclUses << endl;
	      cout << "Your guess: ";
	      getline(cin, guess);
	      guess = stripWhiteSpace(guess);
	      transform(guess.begin(), guess.end(), guess.begin(), ::tolower);
	
	      if (guess == word) {
	        cout << "\nCorrect! You spelt the word correctly." << endl;
	        score++;
	        gclUses++;
	        break;
	      } else if (guess == "n") {
	        cout << "\nThe correct word was " << word << endl;
	        break;
	      } else if (guess == "h") {
	        cout << "Hint: " << hint << endl;
	      } else if (guess == "g") {
	        if (gclUses > 0) {
	          if (search < word.length()) {
	            cout << "\nLetter " << (search + 1) << ": " << word[search] << endl;
	            search++;
	            gclUses--;
	          } else {
	            cout << "\nThe word has been fully revealed. Please type it out or "
	                    "skip to continue."
	                 << endl;
	          }
	        } else {
	          cout << "\nYou cannot get any more correct letters!" << endl;
	        }
	      } else {
	        cout << "\nIncorrect spelling or invalid input." << endl;
	      }
	    }
	
	    cout << "Score: " << score << endl;
	  }

	public:
	  WordGame()
	      : words{"buffalo",       "gorilla", "apple", "watermelon", "university",
	              "undergraduate", "coconut", "lily",  "helicopter", "home"},
	        hints{"a big animal in the bovine family",
	              "primate",
	              "a common fruit",
	              "a fruit with lots of liquid",
	              "higher education",
	              "higher education student",
	              "a fruit with a hard shell",
	              "a flower",
	              "an aircraft",
	              "where you return to at the end of the day"},
	        score(0), gclUses(5) {}
	
	  void startGame() {
	    string start;
	
	    cout << "----------Spelling Game-----------" << endl;
	
	    while (true) {
	      cout << "\nEnter 's' to start and 'e' to exit: " << endl;
	      getline(cin, start);
	      start = stripWhiteSpace(start);
	
	      if (start == "e") {
	        cout << "Thanks for playing! Your final score is: " << score << endl;
	        break;
	      } else if (start == "s") {
	        displayRules();
	
	        for (size_t i = 0; i < words.size(); i++) {
	          playWord(words[i], hints[i]);
	        }
	
	        cout << "\nGame Over! Your final score is: " << score << endl;
	        break;
	      } else {
	        cout << "Invalid input. Please enter 's' to start or 'e' to exit."
	             << endl;
	      }
	    }
	  }
};

int main() {
  WordGame game;
  game.startGame();
  return 0;
}
