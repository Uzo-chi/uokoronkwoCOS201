#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;
int main() {
	string str1, str2, temp_str1, temp_str2;
	int i, j, length1, length2, count1, count2, count3;
	count1 = 0;
	count2 = 0;
	count3 = 0;
	
	cout << "Enter first string: ";
	cin >> str1;
	cout << "Enter second string: ";
	cin >> str2;
	
	length1 = str1.length();
	char arr1[length1]; 
	
	length2 = str2.length();
	char arr2[length2];
	
	for (i=0; i<length1; i++){
		arr1[i] = str1[i];
	}
	
	for (i=0; i<length2; i++){
		arr2[i] = str2[i];
	}
	
	char rev_arr1[length1], rev_arr2[length2];
	
	for (j=0; j<length1; j++){
		rev_arr1[j] = arr1[(length1-1)-j];
	}
	
	for (j=0; j<length2; j++){
		rev_arr2[j] = arr2[(length2-1)-j];
	}
	
	for (i=0; i<length1; i++){
		if (arr1[i] == rev_arr1[i])
			count1++;
	}
	
	if (count1 == length1)
		cout << "\n\'" << str1 << "\'" << " is a palindrome" << endl;
	else
		cout << "\n\'" << str1 << "\'" << " is not a palindrome" << endl;
		
	for (i=0; i<length2; i++){
		if (arr2[i] == rev_arr2[i])
			count2++;
	}
	
	if (count2 == length2)
		cout << "\n\'" << str2 << "\'" << " is a palindrome\n" << endl;
	else
		cout << "\n\'" << str2 << "\'" << " is not a palindrome\n" << endl;
		
	temp_str1 = str1;
	temp_str2 = str2;
	
	sort(temp_str1.begin(), temp_str1.end());
	sort(temp_str2.begin(), temp_str2.end());
	
	if (length1 == length2){
		for (i=0; i<length1; i++){
			if (temp_str1[i] == temp_str2[i])
				count3++;
		}
		
		if (count3 == length1)
			cout << "\'" << str2 << "\'" << " is an anagram of \'" << str1 << "\'" << endl;
		else
			cout << "\'" << str2 << "\'" << " is not an anagram of \'" << str1 << "\'" << endl;
	} else {
		cout << "\'" << str2 << "\'" << " is not an anagram of \'" << str1 << "\'" << endl;
	}
}