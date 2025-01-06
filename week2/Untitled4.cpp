#include <iostream>
using namespace std;

int main()
{
	int a = 20;
	int b = 14;
	int x;
	int y = 10;
	int z = 5;
	
	x = (y < z) ? y - z : z - y;
	cout << "(y < z) ? y-z : z-y :" << x << endl;
	
	cout << "\nA << 2: " << (a<<2) << endl;
	cout << "\nA >> 2: " << (a>>2) << endl;
	
	return 0;
}