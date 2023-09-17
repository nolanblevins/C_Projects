#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include"problem3functions.h"

int main() {
  if ( NumDigits(10000) == 5 )
    cout << "Passed NumDigits(10000) test" << endl;
  else
    cout << "Failed NumDigits(10000) test" << endl;

  if ( NumDigits(-31) == 2 )
    cout << "Passed NumDigits(-3) test" << endl;
  else
    cout << "Failed NumDigits(-3) test" << endl;

  if ( NumDigits(0) == 1 )
    cout << "Passed NumDigits(0) test" << endl;
  else
    cout << "Failed NumDigits(0) test" << endl;

  return 0;
}
