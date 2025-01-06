#include <iostream>
using namespace std;
main()
{
	
	int a, b;
	a = (b = 4, b + 7);
	cout << "a=(b=4, b+7):" << a << endl;
	
	return 0;
}