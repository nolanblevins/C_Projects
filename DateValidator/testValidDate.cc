// Copyright 2023 bhipp
// runs sample tests for ValidDate function
#include<iostream>
using std::cout;
using std::endl;
#include "program2functions.h"

//4/31/1900

int main() {
  if ( ValidDate(1, 1, 2023) )
    cout << "Passed 1/1/2023 test" << endl;
  else
    cout << "Failed 1/1/2023 test" << endl;

  if ( ValidDate(2, 29, 2000) )
    cout << "Passed 2/29/2000 test" << endl;
  else
    cout << "Failed 2/29/2000 test" << endl;

  if ( !ValidDate(2, 29, 2001) )
    cout << "Passed 2/29/2001 test" << endl;
  else
    cout << "Failed 2/29/2001 test" << endl;

  if ( !ValidDate(4, 31, 1900)  )
    cout << "Passed 4/31/1900 test" << endl;
  else
    cout << "Failed 4/31/1900 test" << endl;

  if ( !ValidDate(13, 1, 2023) )
    cout << "Passed 13/1/2023 test" << endl;
  else
    cout << "Failed 13/1/2023 test" << endl;

  if ( !ValidDate(12, 0, 2023)  )
    cout << "Passed 12/0/2023 test" << endl;
  else
    cout << "Failed 12/0/2023 test" << endl;

  if ( !ValidDate(8, 6, -17)  )
    cout << "Passed 12/0/-17 test" << endl;
  else
    cout << "Failed 12/0/-17 test" << endl;

  return 0;
}
