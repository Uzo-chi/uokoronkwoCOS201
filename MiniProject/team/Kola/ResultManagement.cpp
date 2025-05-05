#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Login
{
    string username;
    string password;
};

struct Course
{
    string courseName;
    string courseCode;
    string courseCredit;
};

struct Student
{
    string matric;
    string surname;
    string firstName;
    vector<int> scores;
};

// Function to display menu
void displayMenu()
{
    cout << "\n\t MAIN MENU" << endl;
    cout << "F - SEARCH for a Student's Result\n";
    cout << "U - UPDATE a Student's Result\n";
    cout << "P - SAVE a Student's Result to File\n";
    cout << "V - VIEW All Results\n";
    cout << "E - EXIT the Program\n";
    cout << "Enter your choice: ";
}

vector<string> splitString(const string &input)
{
    vector<string> words;
    string word = "";

    for (char ch : input)
    {
        if (ch == ' ')
        {
            if (!word.empty())
            {
                words.push_back(word);
                word = "";
            }
        }
        else
        {
            word += ch;
        }
    }

    if (!word.empty())
    {
        words.push_back(word);
    }

    return words;
}

void writeFile()
{
    string response;
    cout << "Enter Student's Matric Number: ";
    cin >> response;

    ifstream file("students.txt");
    if (!file)
    {
        cout << "Error: students.txt not found!" << endl;
        return;
    }

    ofstream file2(response + ".txt"); // Open the output file once
    if (!file2)
    {
        cout << "Error creating " << response << ".txt" << endl;
        return;
    }

    string line;
    int lineCount = 0;
    bool found = false;

    while (getline(file, line))
    {
        lineCount++;

        if (lineCount == 1)
        {
            file2 << line << endl; // Write the first line (header)
        }
        else
        {
            vector<string> words = splitString(line); // Split line into words
            if (!words.empty() && words[0] == response)
            { // Check if matric number matches
                cout << "Found!" << endl;
                file2 << line << endl;
                found = true;
            }
        }
    }

    file.close();
    file2.close();

    if (found)
    {
        cout << "Student's result has been saved to " << response << ".txt" << endl;
    }
    else
    {
        cout << "Student with matric number " << response << " not found!" << endl;
    }
}
int main()
{
    writeFile();

    // vector<Student> students = loadStudents("students.txt");
    // char choice;

    // do
    // {
    //     displayMenu();
    //     cin >> choice;
    //     choice = tolower(choice); // Allow both uppercase and lowercase input

    //     switch (choice)
    //     {
    //     case 'f':
    //         searchStudentResult(students);
    //         break;
    //     case 'p':
    //         saveStudentResultOption(students);
    //         break;
    //     case 'e':
    //         cout << "Exiting program..." << endl;
    //         break;
    //     default:
    //         cout << "Invalid option! Try again." << endl;
    //     }

    // } while (choice != 'e');

    return 0;
}