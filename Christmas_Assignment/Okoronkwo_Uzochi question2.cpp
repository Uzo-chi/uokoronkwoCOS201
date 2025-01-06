#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

string stripWhiteSpace(string & userInput, int userInputLength)
{
	string newUserInput = "";
	
	for (int i=0; i<userInputLength; i++) {
		if (userInput[i] == ' ') {
			continue;
		} else {
			newUserInput += userInput[i];
		}
	}

	return newUserInput;
}

string scramble(const string &text)
{
    srand(time(0));
    string chars = text;
    for (int i = 0; i < chars.length(); i++)
    {
        int j = rand() % chars.length();
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }
    return chars;
}

int main()
{
    string start;
    string words[] = {"buffalo", "gorilla", "apple", "watermelon", "university", "undergraduate", "coconut", "lily", "helicopter", "home"};
    string hints[] = {"a big animal in the bovine family", "primate", "a common fruit", "a fruit with lots of liquid", "higher education", "higher education student", "a fruit with a hard shell", "a flower", "an aircraft", "where you return to at the end of the day"};
    int score = 0;
    int gcl_uses = 5;

    int words_size = sizeof(words) / sizeof(words[0]);

    cout << "----------Spelling Game-----------" << endl;

gameBegin:
    cout << "\nEnter 's' to start and 'e' to exit: " << endl;
    getline(cin, start);
    
    start = stripWhiteSpace(start, start.length());

    if (start == "e" || start == "E")
    {
        return 0;
    }
    else if (start == "s" || start == "S")
    {
        string guess;
        cout << "\nWelcome to the spelling game!\nYou are to guess the correct word while keeping the following rules in mind:" << endl;
        cout << " - Enter 'g' to reveal a correct position for a letter\n - Enter 'n' to skip to the next word (you will not gain any points)\n - Enter 'h' to receive a clue for the word\n"
             << endl;

        for (int i = 0; i < words_size; i++)
        {
            int search = 0;
            if (i + 1 == words_size)
            {
                cout << "\n"
                     << i + 1 << ".) Scrambled Word (This is the last word): " << scramble(words[i]) << endl;
            }
            else
            {
                cout << "\n"
                     << i + 1 << ".) Scrambled Word: " << scramble(words[i]) << endl;
            }

        userChoice:
        	cout << "Get correct letter uses: " << gcl_uses << endl;
            cout << "Your guess: ";
            getline(cin, guess);
            guess = stripWhiteSpace(guess, guess.length());
            
            transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

            if (guess == words[i])
            {
                cout << "\nCorrect! You spelt the word correctly." << endl;
                score += 1;
                gcl_uses += 1;
                cout << "Score: " << score << "/" << i + 1 << endl;;
            }
            else
            {
                if (guess.length() == 1)
                {
                    if (guess == "n" || guess == "N")
                    {
                        cout << "\nThe correct word was " << words[i] << endl;
                        cout << "Score: " << score << "/" << i + 1;
                        continue;
                    }
                    else if (guess == "h" || guess == "H")
                    {
                        cout << "Hint: " << hints[i] << endl;
                        goto userChoice;
                    }
                    else if (guess == "g" || guess == "G")
                    {
                        if (gcl_uses != 0)
                        {
							if (search < words[i].length()) {
								cout << "\nLetter " << search + 1 << ": " << words[i][search] << endl;
                            	search += 1;
                            	gcl_uses -= 1;
                            	goto userChoice;
							}
							else {
								cout << "\nThe word has been fully revealed. Please type it out or skip to continue." << endl;
								goto userChoice;
							}
                        }
                        else
                        {
                            cout << "\nYou cannot get anymore correct letters!" << endl;
                            goto userChoice;
                        }
                    }
                    else
                    {
                        cout << "Wrong character enter! Enter a valid character." << endl;
                        goto userChoice;
                    }
                }
                else
                {
                    cout << "\nIncorrect Spelling" << endl;
                    goto userChoice;
                }
            }
        }
    }
    else
    {
        cout << "Wrong character entered!" << endl;
        goto gameBegin;
    }
}