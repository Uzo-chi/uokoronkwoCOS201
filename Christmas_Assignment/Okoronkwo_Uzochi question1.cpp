#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <random>
#include <ctime>
#include <algorithm>
#include <array>

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

void scrambleOptions(array<string, 4> &opt)
{
	for (int i = 0; i < 4; i++)
	{
		int y = rand() % 4;
		string temp = opt[i];
		opt[i] = opt[y];
		opt[y] = temp;
	}
}

class StudentQuiz {
	
	public:
		StudentQuiz(string username, string password)
		{
			setUserName(username);
			setPassword(password);
		}
		
		void setUserName(string username)
		{
			email = username;
		}
		
		void setPassword(string passcode)
		{
			password = passcode;
		}
		
		void startTest()
		{
			string userChoice;
			int next;
			
			for (itr = questions.begin(); itr != questions.end(); itr++) {
				scrambleOptions(itr->second);
			}
			
			itr = questions.begin();
			while (itr != questions.end()) {
				cout << "\n" << number << ".) " << itr->first << endl;
				for (int i = 0; i<4; i++) {
					cout << options[i] << ". " << itr->second[i] << "     ";
				}
				cout << endl;
				if (userOptions.find(number) != userOptions.end()) {
					cout << "You chose: " << userOptions[number][0] << " ("
						<< userOptions[number][1] << ")" << endl;
				}
				
				userLoop:
					cout << "\nYour choice: ";
					getline(cin, userChoice);
					stripWhiteSpace(userChoice, userChoice.length());
					
					transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);
					
				if (userChoice == "a") {
					userOptions[number] = {itr->second[0],userChoice};
				}
				else if (userChoice == "b") {
					userOptions[number] = {itr->second[1],userChoice};
				}
				else if (userChoice == "c") {
					userOptions[number] = {itr->second[2],userChoice};
				}
				else if (userChoice == "d") {
					userOptions[number] = {itr->second[3],userChoice};
				}
				else if (userChoice == "n") {
					if (++itr != questions.end()){
						--itr;
						nextQuestion();
						continue;
					}
					else {
						cout << "You cannot skip to any question!" << endl;
						itr--;
						goto userLoop;
					}
				}
				else if (userChoice == "p") {
					if (itr == questions.begin()) {
						cout << "You cannot return to any previous question!" << endl;
						goto userLoop;
					}
					else {
						if (previousQuestion() == 2){
							break;
						}
						else {
							continue;
						}
					}
				}
				else if (userChoice == "s") {
					submitQuiz();
					break;
				}
				else {
					cout << "Wrong character entered!" << endl;
					goto userLoop;
				}
				if (++itr == questions.end()) {
					cout << "\nComplete!" << endl;
					string userInput;
					loop:
						cout << "Your Input ('s' to submit, 'p' to go back): ";
						getline(cin, userInput);
						stripWhiteSpace(userInput, userInput.length());
						if (userInput == "s" || userInput == "S") {
							submitQuiz();
							break;
						}
						else if (userInput == "n" || userInput == "N") {
							cout << "You cannot skip to any question!" << endl;
							goto loop;
						}
						else if (userInput == "p" || userInput == "P") {
							
							next = previousQuestion();
							if (next == 1) {
								continue;
							}
							else {
								goto loop;
							}
						}
						else {
							cout << "Wrong character entered!" << endl;
							goto loop;
						}
				}
				else {
					--itr;
				}
				number++;
				itr++;
			}
		}
		
		void submitQuiz()
		{
			string choice;
			
			for (ptr = userOptions.begin(); ptr != userOptions.end(); ptr++) {
				if (ptr->second[0] == correct_ans[(ptr->first)-1]) {
					score++;
				}
				else {
					continue;
				}
			}
			
			cout << "\nScore: " << score << "/15" << endl;
			
			submitLoop:
				cout << "\nWould you like to view your script (y/n): ";
				getline(cin, choice);
				
				stripWhiteSpace(choice, choice.length());
				transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
				
				if (choice == "y") {
					itr = questions.begin();
					cout << "\n" << endl;
					for (int i = 0; i < 15; i++) {
						cout << "\n" << i+1 << ".)" << itr->first << endl;
						for (int j = 0; j < 4; j++) {
							cout << options[j] << ". " << itr->second[j] << "     ";
						}
						if (userOptions.find(i+1) != userOptions.end()) {
							cout << "\nYou chose: " << userOptions[i+1][0] << " ("
								<< userOptions[i+1][1] << ")";
							if (userOptions[i+1][0] == correct_ans[i]) {
								cout << "       Correct: " << correct_ans[i] << " ("
									<< userOptions[i+1][1] << ")\n" << endl;
							}
							else {
								cout << "       Wrong: " << correct_ans[i];
								for (int k=0; k<4; k++) {
									if (itr->second[k] == correct_ans[i]) {
										cout << " (" << options[k] << ")" << endl;
									}
									else {
										continue;
									}
								}
							}
						}
						else {
							cout << "\nYou chose: N/A";
							cout << "       Wrong: " << correct_ans[i];
							for (int k=0; k<4; k++) {
								if (itr->second[k] == correct_ans[i]) {
									cout << " (" << options[k] << ")" << endl;
								}
								else {
									continue;
								}
							}
						}
						itr++;
					}
				}
				else if (choice == "n") {
					return;
				}
				else {
					cout << "Wrong character entered!" << endl;
					goto submitLoop;
				}
		}
		
		void nextQuestion()
		{
			++itr;
			++number;
			return;
		}
		
		int previousQuestion(bool previous=true)
		{
			if (previous == true) {
				--itr;
				if (++itr != questions.end()) {
					--number;
				}
				--itr;
			}
			string userChoice;
			
			cout << "\n" << number << ".) " << itr->first << endl;
			for (int i = 0; i<4; i++) {
				cout << options[i] << ". " << itr->second[i] << "     ";
			}
			cout << endl;
			if (userOptions.find(number) != userOptions.end()) {
				cout << "You chose: " << userOptions[number][0] << " ("
					<< userOptions[number][1] << ")" << endl;
			}
			
			input:
				cout << "\nYour choice: ";
				getline(cin, userChoice);
				
				stripWhiteSpace(userChoice, userChoice.length());
				transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);
		
			if (userChoice == "a") {
				userOptions[number] = {itr->second[0],userChoice};
				itr++;
				number++;
				return 0;
			}
			else if (userChoice == "b") {
				userOptions[number] = {itr->second[1],userChoice};
				itr++;
				number++;
				return 0;
			}
			else if (userChoice == "c") {
				userOptions[number] = {itr->second[2],userChoice};
				itr++;
				number++;
				return 0;
			}
			else if (userChoice == "d") {
				userOptions[number] = {itr->second[3],userChoice};
				itr++;
				number++;
				return 0;
			}
			else if (userChoice == "n") {
				if (++itr != questions.end()){
					++number;
					return 1;
				}
				else {
					itr--;
					cout << "You cannot skip to any question!" << endl;
					return 0;
				}
			}
			else if (userChoice == "p") {
				if (itr == questions.begin()) {
					cout << "You cannot return to any previous question!" << endl;
					goto input;
					return 0;
				}
				else {
					itr--;
					number--;
					return 1;
				}
			}
			else if (userChoice == "s") {
				submitQuiz();
				return 2;
			}
			else {
				cout << "Wrong character entered!" << endl;
				goto input;
			}
			return 0;
		}
	
		
	private:
		int number = 1;
		int score = 0;
		string email;
		string password;
		map<int, array<string,2>> userOptions;
		map<int, array<string,2>>::iterator ptr;
		map<string, string>::iterator str;
		map<string, array<string, 4>> questions = {			// ChatGPT was used to generate a set of 15 questions and options
			{"In which continent is the country of Egypt located?",{"Asia","Africa","Europe","South America"}},
			{"In which year did World War II end?",{"1939","1945","1950","1963"}},
			{"What is the boiling point of water at sea level?",{"90C","100C","110C","212F"}},
			{"What is the capital city of France?",{"London","Berlin","Paris","Madrid"}},
			{"What is the formula for calculating the area of a circle?",{"A = I*w", "A = pi*r^2", "A = 2*pi*r", "A = 2*r^2"}},
			{"What is the longest river in the world?",{"Amazon River","Nile River","Mississippi River","Yangtze River"}},
			{"What is the process by which plants make their own food?",{"Respiration","Germination","Photosynthesis","Pollination"}},
			{"Which mathematical operation is represented by the symbol '/'?",{"Addition","Multiplication","Division","Subtraction"}},
			{"Which of the following authors wrote the play 'Romeo and Juliet'?",{"William Shakespeare","Charles Dickens","Jane Austen","Mark Twain"}},
			{"Which of the following is a primary color of light?",{"Green","Purple","Yellow","Brown"}},
			{"Which of the following is a type of cloud?",{"Stratus","Granite","Limestone","Sand"}},
			{"Which of the following is the largest planet in our solar system?",{"Earth","Mars","Jupiter","Venus"}},
			{"Which of these elements is a noble gas?",{"Oxygen","Nitrogen","Helium","Hydrogen"}},
			{"Who is the father of modern physics?",{"Isaac Newton","Albert Einstein","Nikola Tesla","Galileo Galilei"}},
			{"Who was the first president of the United States?",{"Abraham Lincoln","George Washington","Thomas Jefferson","Franklin D. Roosevelt"}}
		};
		map<string, array<string, 4>>::iterator itr;
		string options[4] = {"a","b","c","d"};
		string correct_ans[15] = {"Africa","1945","100C","Paris","A = pi*r^2",
			"Amazon River","Photosynthesis","Division","William Shakespeare",
			"Green","Stratus","Jupiter","Helium","Albert Einstein",
			"George Washington"};
};

int main() {
	srand(time(0));
	
	bool valid = false;
	string start;
	string school_mail;
	string school_password;
	map<string, string> students = {			// ChatGPT was used to generate random emails in the PAU student email format and also passwords
		{"adebola.akinyele@pau.edu.ng","Akinyele2024!"}, {"chidi.okafor@pau.edu.ng","Okafor#93"},
		{"funmi.balogun@pau.edu.ng","Funmi@123"}, {"oluwaseun.adebayo@pau.edu.ng","Ade$Bayo21"},
		{"uchechi.nwosu@pau.edu.ng","Nwosu!456"}, {"kunle.fasanya@pau.edu.ng","Fasanya98$"},
		{"amaka.nwachukwu@pau.edu.ng","Amaka@77"}, {"tolu.akinola@pau.edu.ng","Tolu2023"},
		{"nkechi.nwankwo@pau.edu.ng","Nkechi@100"}, {"segun.oshinowo@pau.edu.ng","Segun#567"},
		{"ayo.oladipo@pau.edu.ng","Oladipo$90"}, {"kemi.adeola@pau.edu.ng","Kemi#123"},
		{"emeka.igwe@pau.edu.ng","Emeka@2023"}, {"bolanle.ajayi@pau.edu.ng","Bola$Ajayi"},
		{"chioma.okoro@pau.edu.ng","Okoro!Chi"}, {"femi.alabi@pau.edu.ng","Alabi@567"},
		{"ngozi.obi@pau.edu.ng","Ngozi@#78"}, {"bisi.adeniran@pau.edu.ng","Bisi!789"},
		{"tope.folarin@pau.edu.ng","Folarin@2024"}, {"zainab.abdullahi@pau.edu.ng","Zainab$85"},
		{"musa.danjuma@pau.edu.ng","Musa@Dan21"}, {"maryam.sadiq@pau.edu.ng","Maryam#2023"},
		{"abimbola.joseph@pau.edu.ng","Abimbola!34"}, {"titilayo.oshin@pau.edu.ng","Titilayo@56"},
		{"habib.aliyu@pau.edu.ng","Habib@23$"}, {"adunni.faleye@pau.edu.ng","Faleye2024"},
		{"kelechi.eze@pau.edu.ng","Eze#1234"}, {"odunayo.adekunle@pau.edu.ng","Odun@78"},
		{"ifeanyi.chukwu@pau.edu.ng","Chukwu@567"}, {"yetunde.olawale@pau.edu.ng","Yetunde2023!"},
		{"gbenga.akintola@pau.edu.ng","Gbenga@678"}, {"onyeka.madu@pau.edu.ng","Madu@432"},
		{"yewande.soyinka@pau.edu.ng","Yewande#567"}, {"abdul.umar@pau.edu.ng","Abdul2024!"},
		{"fatimah.bello@pau.edu.ng","Bello@Fat"}, {"sunday.ogunsanya@pau.edu.ng","Sunday#23$"},
		{"bukola.ogundele@pau.edu.ng","Bukola@789"}, {"ahmed.lawal@pau.edu.ng","Ahmed2023"},
		{"blessing.ikechukwu@pau.edu.ng","Blessing@21"}, {"damilola.adeoti@pau.edu.ng","Damilola#99"}
	};
	map<string, string>::iterator stud_itr;
	
	testBegin:
	    cout << "\nEnter 's' to start and 'e' to exit: " << endl;
	    getline(cin, start);
	    
	    start = stripWhiteSpace(start, start.length());
	
	    if (start == "e" || start == "E")
	    {
	        return 0;
	    }
	    else if (start == "s" || start == "S")
	    {
	    	cout << "\n-----------------------Student Authentication-----------------------" << endl;
	    	cout << "Identify Yourself!" << endl;
	    	
	    	userAuthentication:
		    	cout << "\nYour school email: ";
		    	getline(cin, school_mail);
		    	cout << "Your password: ";
		    	getline(cin, school_password);
		    	
		    	for (stud_itr = students.begin(); stud_itr != students.end(); stud_itr++) {
		    		if (school_mail != stud_itr->first) {
		    			continue;
					}
					else if (school_mail == stud_itr->first) {
						if (school_password != stud_itr->second) {
							cout << "Wrong login details!" << endl;
							goto userAuthentication;
						}
						else {
							valid = true;
							break;
						}
					}
				}
				
				if (valid != true) {
					cout << "Wrong login details!" << endl;
					goto userAuthentication;
				}
				else {
					StudentQuiz studentQuiz1(school_mail,school_password);
					cout << "Logging you in..." << endl;
					cout << "\nTEST INSTRUCTIONS" << endl;
					cout << "You are to input only characters from your keyboard"
						<< " while keeping the following in mind:\n"
						<< " - Enter 'a', 'b' , 'c' or 'd' to select an option\n" 
						<< " - Enter 'n' to skip a question\n"
						<< " - Enter 'p' to return to the previous question\n" 
						<< " - Enter 's' when you are done to submit your test\n"
						<< "\nGood Luck and you may begin" << endl;
					
					studentQuiz1.startTest();
				}
		}
		else
    	{
	        cout << "Wrong character entered!" << endl;
	        goto testBegin;
    	}
}