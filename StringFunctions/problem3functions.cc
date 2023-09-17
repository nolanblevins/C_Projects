// Copyright nblevins 2023

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include "problem3functions.h"

using std::cin;   // used to take in standard input
using std::cout;  // used for standard output
using std::endl;  // used for end line

int NumDigits(int num) {
  int digits = 0;   // if the number
  if (num < 10 &&   // is a single digit
      num >= 0) {   // it will return 1
        return 1;
  }
  if (num < 0) {       // if the number is
    num = num * (-1); // negative convert to positive
  }                   // for calculations in for loop
  for (int i = num; i > 0; i /= 10) {   // i is equal to the number
    digits++;                           // we then check if i is zero
  }                                     // if not 0 we divide that number by
  return digits;                        // 10 until it is since we are working
}                                       // with a base 10 number system

bool FindAndReplace(int &num, int find, int replace) {
  if ((NumDigits(find) < NumDigits(replace)) ||    // Checking for invalid inputs
      (find < 0) || (replace < 0)||                // if either find or replace is negative,
       (find == replace)) {                        // the find is equal to the replace or
        return false;                              // find is greater than replace, return false
  }
  int ret = 0;      // return value
  int scaler = 1;   // scaler for adding value to return value
  int tempNum = num;  // temp value for calculations
  int lastDigit = 0;     // last digit of user inputted number
  int secondLastDigit = 0;    // second to last digit of user inputed number
  int lastTwoDigits;          // last and second to last digits combined

  if (tempNum < 0) {          // checking that the temp number is not negative
    tempNum = tempNum * (-1);   // if the temp number is negative we make it positive
  }
  if (NumDigits(find) == 1) {   // if the find value is 1 digit
  while(tempNum > 0) {                  // while temp num is not zero
    lastDigit = tempNum % (10) ;        // get the last digit of temp
    if (lastDigit == find) {            // if the last digit is the find value
      lastDigit = replace;              // we change the last digit to the replace value
    }
    ret = ret + (lastDigit * scaler);   // adding the last digit to the return value using a scaler
                                        // for the place of the last digit
    tempNum /= 10;      // remove last digit from temp
    scaler *= 10;       // increasing scaler so next value
  }                     // added to the return value is one place higher
} else if (NumDigits(find) == 2) {    // if the number of digits of the find varibale is two
  int lastDigitReplace;               // init of last digit of replace variable
  int secondLastDigitReplace;         // init of second to last digit of replace variable
  while (tempNum > 0) {          // the temp version of num
    int lastDigitFind = find % 10;    // using mod ten of find to get last digit
    int secondLastDigitFind = (find - lastDigitFind) % 100;   //  taking away last digit and using mod 100 to get second to last digit
    if (NumDigits(replace) == 2) {  // if replace is two digits
      lastDigitReplace = replace % 10;  // get last digit
      secondLastDigitReplace = (replace - lastDigitReplace) % 100;  // get second to last digit
    }
    lastDigit = tempNum % 10;     // get last digit of temp num
    secondLastDigit = (tempNum - lastDigit) % 100;  // get second to last digit of temp num
    lastTwoDigits = secondLastDigit + lastDigit;    // combine last two digits
    if ((lastDigit == lastDigitFind)&&                // if the last digit of the temp num is equal to find
        (secondLastDigit == secondLastDigitFind)) {   // and second is also equivalent
          lastDigit = lastDigitReplace;               // change last digit of temp to last digit of replace
          if (NumDigits(replace) == 2) {
          secondLastDigit = secondLastDigitReplace;   // do the same for the second to last digit if replace is two digits
          }
    }
    ret = ret + (lastDigit * scaler);   // add last digit times its place value scaler to the return
    if (NumDigits(replace == 2)) {                   // if the num digits of replace are two
    ret = ret + (secondLastDigit * (scaler * 10));   //  also add the second to last digit if replace is two digits
    }
    scaler *= 10;   // increase scaler by one place
    tempNum /= 10;  // remove last digit
  }
}
  if (num < 0) {        //  if num is negative
    ret = ret * (-1);   //  change temp to negative
  }
  num = ret;    // change value of num to ret
  return true;

}