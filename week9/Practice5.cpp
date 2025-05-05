#include <iostream>
using namespace std;
float num, ans, denom;

int main() {
  cout << "Handling Exceptions" << endl;
  cout << "Enter Numerator" << endl;
  cin >> num;
  cout << "Enter Denominator" << endl;
  cin >> denom;
  try {
    if (denom == 0)
      throw denom;
    else if (denom > num)
      throw "Denominator is greater than numerator";
    else {
      ans = num / denom;
      cout << "Output: " << ans;
    }
  } catch (float e) {
    cout << "The denominator is Zero";
  } catch (const char *St) {
    cout << "Denominator is greater than numerator";
  }

  return 0;
}
