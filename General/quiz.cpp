#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

void scrambleOptions(string *opt)
{
	for (int i = 0; i < 4; i++)
	{
		int y = rand() % 4;
		string temp = opt[i];
		opt[i] = opt[y];
		opt[y] = temp;
	}
}

bool isInsideArray(string opt[], int n, string k, int *index)
{
	for (int i = 0; i < n; i++)
	{
		if (opt[i] == k)
		{
			*index = i;
			return true;
		}
	}
	return false;
}

void loadQuestions(const string *qn, const string *ans, int *num, string userAns[], string userOpt[])
{

	int randIndex;
	int userIndex;
	string letters[4] = {"a", "b", "c", "d"};
	string options[4];
	char choice;
	cout << "\n"
		 << *num + 1 << ".) " << qn[*num] << "" << endl;

	options[0] = ans[*num];

	for (int j = 1; j < 4; j++)
	{
	randomOptions:
		randIndex = rand() % 16;
		if (!isInsideArray(options, 4, ans[randIndex], &userIndex))
		{
			options[j] = ans[randIndex];
		}
		else
		{
			goto randomOptions;
		}
	}
	cout << endl;

	scrambleOptions(options);

	for (int i = 0; i < 4; i++)
	{
		cout << letters[i] << ".) " << options[i] << "     ";
	}
	cout << "\nYour choice: ";
	cin >> choice;

	choice = tolower(choice);

	if (isInsideArray(letters, 4, string(1, choice), &userIndex))
	{
		userOpt[*num] = choice;
		userAns[*num] = options[userIndex];
		cout << "You chose: " << userAns[*num] << " (" << userOpt[*num] << ")\n"
			 << endl;
	}
	else if (choice == 's')
	{
		*num += 1;
		return;
	}
	else if (choice == 'r')
	{
		*num -= 1;
		return;
	}
	*num += 1;
}

int main()
{
	srand(time(0));
	int qnNum = 0;
	string start;
	int questionSize;
	char retry;
	string questions[7] = {
		"What language is used for this code?", "Who is the author of the code?", "What is the color of the sky?", "Which of the following a way to define a datatype in C++?",
		"Who is the course coordinator of Software Engineering?", "Who was my MTH 102 teacher?", "Which of the following is a course I am offering this semester?"};
	string answers[16] = {"C++", "Uzochi", "Blue", "char", "Ms. Augusta", "Mr. Aroloye", "GST 212", "MTH 101", "GST 112", "CSC 252", "Dr. Pius", "Dr. Darlington", "number", "red",
						  "purple", "character"};
	string userAnswers[7];
	string userOptions[7];
	questionSize = sizeof(questions) / sizeof(questions[0]);

	cout << "-----------------------WORD SCRAMBLE-----------------------\n"
		 << endl;
	cout << "*Rules*\n - Getting a question correct gives you 1 point."
		 << "\n - Enter 's' to skip a question.\n"
		 << " - Enter 'r' to view skipped questions and enter the appropriate number to return to the question."
		 << "\n - Answer at least 4 questions."
		 << "\n - Enter 'q' to quit (only after answering at least 4 questions)" << endl;

userChoice:
	cout << "\nEnter 1 to start and 2 to exit: " << endl;
	cin >> start;

	if (start != "1" && start != "2")
	{
		cout << "\nWrong input! Try again?(y/n): ";
		cin >> retry;
		if (retry == 'y')
		{
			goto userChoice;
		}
		else if (retry == 'n')
		{
			cout << "Ending Code...";
			return 0;
		}
		else
		{
			cout << "Error! Ending Code...";
			return 0;
		}
	}
	else if (start == "1")
	{
		while (qnNum < questionSize)
		{
			loadQuestions(questions, answers, &qnNum, userAnswers, userOptions);
		}
	}
	cout << userAnswers[3] << " "
		 << userOptions[3] << endl;
}