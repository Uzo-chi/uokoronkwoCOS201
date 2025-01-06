#include <iostream>
using namespace std;

struct fruits {
	float price;
	float weight;
};
fruits mango, apple, orange;

float sum=0;
float totalweight=0;
int no;

int main() {
	mango.price = 16.40;
	apple.price = 10.20;
	orange.price = 33.50;
	mango.weight = 1.3;
	apple.weight = 1.6;
	orange.weight = 1.2;
	
	cout << "How many mangoes do you want = ";
	cin >> no;
	sum = sum + no*mango.price;
	totalweight = totalweight + no*mango.weight;
	cout << "How many apples do you want = ";
	cin >> no;
	sum = sum + no*apple.price;
	totalweight = totalweight + no*apple.weight;
	cout << "How many oranges do you want = ";
	cin >> no;
	sum = sum + no*orange.price;
	totalweight = totalweight + no*orange.weight;
	cout << "The total cost is = " << sum << endl << "Total weight is = " << totalweight;
	
	return 0;
}