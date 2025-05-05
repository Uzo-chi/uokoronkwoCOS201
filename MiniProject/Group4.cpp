#include <array>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool fileCheck(string file) {
  if (filesystem::exists(file)) {
    return true;
  } else {
    return false;
  }
}

float calculateGPA(array<int, 5> grades) {
  float sum = 0.0;
  float gpa;
  for (int grade : grades) {
    if (grade >= 70) {
      sum += static_cast<float>(10);
    } else if (grade >= 60) {
      sum += static_cast<float>(8);
    } else if (grade >= 50) {
      sum += static_cast<float>(6);
    } else if (grade >= 40) {
      sum += static_cast<float>(4);
    } else if (grade >= 30) {
      sum += static_cast<float>(2);
    } else {
      continue;
    }
  }

  gpa = (sum / 50.0) * 5;
  return gpa;
}

vector<string> getLineInfo(string line) {
  vector<string> lineInfo;
  string delim = ",";
  int pos = 0;

  while (pos != string::npos) {
    pos = line.find(delim);
    lineInfo.push_back(line.substr(0, pos));
    line.erase(0, pos + 1);
  }

  lineInfo.push_back(line);

  return lineInfo;
}

class User {
public:
  User() { setUser(); }

  vector<string> getUserInfo(string line) {
    vector<string> lineInfo;
    string delim = ",";
    int pos = 0;

    while (pos < line.length()) {
      pos = line.find(delim);
      lineInfo.push_back(line.substr(0, pos));
      line.erase(0, pos + 1);
    }

    return lineInfo;
  }

  void setUser() {
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Enter your password: ";
    getline(cin, password);
  }

  string getUserName() { return username; }

  bool validateUser() {
    vector<vector<string>> users;
    string filename = "users.txt";
    try {
      if (!fileCheck(filename)) {
        const char *fstr = filename.c_str();
        throw fstr;
      } else {
        ifstream allowedUser(filename);
        string line;
        if (allowedUser.is_open()) {
          while (getline(allowedUser, line)) {
            users.push_back(getUserInfo(line));
          }
          for (vector<string> x : users) {
            if (username == x[0]) {
              if (password == x[1])
                return true;
              else
                continue;
            }
          }
          return false;
        } else {
          cerr << "Error: Unable to open file!" << endl;
          return false;
        }
      }
    } catch (const char *file) {
      cout << "File does not exist!\nCreating file..." << endl;
      ofstream allowedUser(filename);
      if (allowedUser.is_open()) {
        allowedUser << "admin,admin123\n";
        allowedUser.close();
        return false;
      } else {
        cerr << "Error: Unable to open file!" << endl;
        return false;
      }
    }
  }

private:
  string username;
  string password;
};

class StudentRecord {
public:
  StudentRecord(string file) {
    fileName = file;
    records = {};
    if (!fileCheck(file)) {
      cerr << "Error: File does not exist!" << endl;
      return;
    } else {
      ifstream studInfo(file, ios::in);
      if (studInfo.is_open()) {

        string line;
        while (getline(studInfo, line)) {
          records.push_back(getLineInfo(line));
        }

        for (vector<string> &record : records) {
          record[7] = to_string(
              calculateGPA({stoi(record[2]), stoi(record[3]), stoi(record[4]),
                            stoi(record[5]), stoi(record[6])}));
        }
        studInfo.close();
      } else {
        cerr << "Error: Unable to open file!" << endl;
      }
    }
  }

  void viewRecords() {
    cout << "\nName, Matriculation No., COS201,"
         << " GST212, SEN201, "
         << "MTH201, ENT211, GPA\n"
         << endl;
    for (vector<string> x : records) {

      cout << x[0] << ", " << x[1] << ", " << x[2] << ", " << x[3] << ", "
           << x[4] << ", " << x[5] << ", " << x[6] << ", " << setprecision(2)
           << stof(x[7]) << "\n"
           << endl;
    }
  }

  void saveRecord(string matric) {
    for (vector<string> record : records) {
      if (matric == record[1]) {
        ofstream outFile(matric + ".txt");
        for (int n = 0; n < 7; n++) {
          if (n == 6) {
            outFile << record[n];
          } else {
            outFile << record[n] << ",";
          }
        }
        outFile.close();
        cout << "Record written to file with filename: " << matric + ".txt"
             << endl;
        return;
      } else {
        continue;
      }
    }
    cout << "No such student exists!" << endl;
    return;
  }

  void updateScores(string matric) {
    bool found = false;

    for (vector<string> &record : records) {
      if (matric != record[1])
        continue;
      else {
        found = true;
        array<string, 5> subjects = {"COS201", "GST212", "SEN201", "MTH201",
                                     "ENT211"};
        array<int, 5> newScores;
        cout << "Name: " << record[0] << "\nMatric No: " << record[1] << endl;
        for (int i = 0; i < 5; i++) {
          string userScore;
          cout << subjects[i] << ": " << record[i + 2] << endl;
          cout << "Update " << subjects[i] << " score\n"
               << "Enter score: ";
          getline(cin, userScore);

          try {
            newScores[i] = stoi(userScore);
            if (newScores[i] < 0 || newScores[i] > 100)
              throw newScores[i];
          } catch (int e) {
            cout << "Invalid value!" << endl;
            i--;
            continue;
          } catch (...) {
            cout << "Invalid value!" << endl;
            i--;
            continue;
          }
        }

        record[7] = to_string(calculateGPA(newScores));
        for (int y = 0; y < 5; y++) {
          record[y + 2] = to_string(newScores[y]);
        }
        break;
      }
    }
    if (!found) {
      cout << "No such student exists!\n" << endl;
      return;
    }

    ofstream outFile(fileName, ios::trunc);
    if (!outFile) {
      cerr << "Error: Unable to open file for writing!" << endl;
      return;
    }

    for (const vector<string> &record : records) {
      for (int a = 0; a < 7; a++) {
        outFile << record[a];
        if (a < 6)
          outFile << ",";
      }
      outFile << "\n";
    }
    outFile.close();
    cout << "\nRecord updated successfully!" << endl;
  }

  void search(string matric) {
    for (vector<string> record : records) {
      if (matric == record[1]) {
        cout << "Name: " << record[0] << "\nMatric No: " << record[1]
             << "\nCOS201: " << record[2] << "\nGST212: " << record[3]
             << "\nSEN201: " << record[4] << "\nMTH201: " << record[5]
             << "\nENT211: " << record[6] << "\nGPA: " << setprecision(2)
             << stof(record[7]) << endl;
        return;
      } else {
        continue;
      }
    }
    cout << "No such student exists!\n" << endl;
  }

private:
  string fileName;
  vector<vector<string>> records;
};

int main() {
  cout << "\t\t----------Pan-Atlantic University Result Management "
          "System----------\n"
       << endl;
  cout << "Provide your login details" << endl;

  while (true) {
    User user1;
    if (user1.validateUser()) {
      cout << "Welcome, " << user1.getUserName() << endl;
      break;
    } else {
      string choice;
      cout << "Invalid username and/or password."
           << "\nWould you like to try again? (y/n): " << endl;
      getline(cin, choice);

      if (choice == "y")
        continue;
      else if (choice == "n")
        return 0;
      else {
        cout << "\nWrong input...but we'll assume you meant to affirm! :)"
             << endl;
        continue;
      }
    }
  }

  while (true) {
    StudentRecord students("student_records.txt");
    string option = "";
    cout << "\n\t-----MAIN MENU-----\n"
         << "To SEARCH for a Student's Result --- Press F\n"
         << "To UPDATE a Student's Result --- Press U\n"
         << "To SAVE a Student's Result to a file --- Press S\n"
         << "To VIEW ALL RESULTS --- Press A\n"
         << "To EXIT the Program --- Press E\n"
         << endl;
    cout << "Enter an option: ";
    getline(cin, option);

    if (option == "f" || option == "F") {
      string matNo = "";
      cout << "\nSEARCH RECORDS\n" << "Enter Student's Matriculation Number: ";
      getline(cin, matNo);

      students.search(matNo);
      continue;
    } else if (option == "u" || option == "U") {

      string matNo = "";
      cout << "\nUPDATE RECORD\n" << "Enter Student's Matriculation Number: ";
      getline(cin, matNo);

      students.updateScores(matNo);
      continue;
    } else if (option == "s" || option == "S") {

      string matNo = "";
      cout << "\nSAVE RECORD\n" << "Enter Student's Matriculation Number: ";
      getline(cin, matNo);

      students.saveRecord(matNo);
      continue;
    } else if (option == "a" || option == "A") {
      students.viewRecords();
      continue;
    } else if (option == "e" || option == "E") {
      string confirm = "";
      cout << "Are you sure you want to quit? (y/n): ";
      getline(cin, confirm);

      if (confirm == "y" || confirm == "Y") {
        return 0;
      } else if (confirm == "n" || confirm == "N") {
        continue;
      } else {
        cout << "Wrong input! -_-" << endl;
        continue;
      }
    } else {
      cout << "\nWrong input!" << endl;
      continue;
    }
  }
}
