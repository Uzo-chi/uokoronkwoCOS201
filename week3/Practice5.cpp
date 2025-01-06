#include <iostream>
using namespace std;
int score=-50;

int main() {
	if (score>=0 && score<=100){
		if(score>=70)
			cout << "Grade A" << endl;
		else if(score>=60)
			cout << "Grade B" << endl;
		else if(score>=50)
			cout << "Grade C" << endl;
		else if(score>=40)
			cout << "Grade D" << endl;
		else
			cout << "Grade F" << endl;
	}
	else {
		cout << "Score invalid!" << endl;
	}	
	return 0;
}