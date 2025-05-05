#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class StudentRecords {
   public:
		void searchrecord(const string& MatricNo) {
			string line;
			bool found = false;
			ifstream myfile("StudentRecord.txt");
			if (myfile.is_open()) {
				while (getline(myfile, line)) {
					if (line.find(MatricNo) != string::npos) {
						stringstream ss(line);
						string StudentName, MatricNo, COS201, GST212, SEN201, MTH201, ENT211, GPA;
						
						getline(ss, StudentName, ',');
						getline(ss, MatricNo, ',');
						getline(ss, COS201, ',');
						getline(ss, GST212, ',');
						getline(ss, SEN201, ',');
						getline(ss, MTH201, ',');
						getline(ss, ENT211, ',');
						getline(ss, GPA, ',');
						
						cout<<"Record Searched: "<<endl;
						cout<<"Student Name: "<< StudentName <<endl;
						cout<<"Matric Number: "<< MatricNo <<endl;
						cout<<"COS201: "<< COS201 <<endl;
						cout<<"GST212: "<< GST212 <<endl;
						cout<<"SEN201: "<< SEN201 <<endl;
						cout<<"MTH201: "<< MTH201 <<endl;
						cout<<"ENT211: "<< ENT211 <<endl;
						cout<<"GPA: "<< GPA <<endl;
						
						found = true;
						break;
					}
				}
				if (!found) {
					cout<<"The record searched "<<MatricNo<<" is not found.";
				}
				
				myfile.close();
			}
			else {
				cout<<"Unable to open file";
			}
		}
};

int main() {
	ofstream myfile;
	myfile.open ("StudentRecord.txt");
	
	if (myfile.is_open()) {
	   myfile <<"Student-Name,Matric-No,COS201,GST212,SEN201,MTH201,ENT211,GPA\n";
	   
	   myfile << "Alice Johnson,MAT12345,78,85,92,88,79,4.3\n";
       myfile << "Bob Smith,MAT67890,82,79,85,91,84,4.5\n";
       myfile << "Carol White,MAT54321,90,88,80,87,93,4.8\n";
       myfile.close();
    }
    else {
    	cout<<"Unable to open file";
    	return 0;
	}
	
	StudentRecords srch;
	string MatricNo;
	
	cout<<"Enter Matric Number of Student: ";
	cin >> MatricNo;
	srch.searchrecord(MatricNo);
	
	string leave;   //This was added so the record can show, and then you can exit when you run the exe.
	cout<<"Enter E to exit the record searcher: ";
	cin >> leave;
	
	for (char& c : leave) {
        c = toupper(c);
    }
	if (leave == "E") {
		cout<<"Exiting.....";
	}
	else {
		cout<<"Invalid input..."<<endl;
	}
}