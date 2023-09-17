// Copyright nblevins 2023

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cctype>
#include "program3functions.h"
using std::cin;   // used to take in standard input
using std::cout;  // used for standard output
using std::endl;

int maxFrequency(int charFrequency[]) {   // takes the char frequency array as
  int maxFreq = 0;                        // a parameter and returns the value
  for (int i = 0; i < 26; i++) {          // of the index with the highest value
    if (charFrequency[i] > maxFreq) {
      maxFreq = charFrequency[i];
    }
  }
  return maxFreq;
}
int minFrequency(int charFrequency[]) {       // takes the char frequency array as
  int minFreq = maxFrequency(charFrequency);  // a parameter and returns the value
  for (int i = 0; i < 26; i++) {              // of the index with the lowest value
    if (charFrequency[i] < minFreq) {
      minFreq = charFrequency[i];
    }
  }
  return minFreq;
}
int numMinFrequencies(int charFrequency[]) {    // takes char frequency array as
  const int ALPHABET_SIZE = 26;                 // a parameter and loops through
  int minFreq = minFrequency(charFrequency);    // the array comparing every index
  int minFreqCount = 0;                         // to the min frequency value, if the
  for (int i = 0; i < ALPHABET_SIZE; i++) {     // two values are equivalent, it will increment
    if (charFrequency[i] == minFreq) {          // a counter and return the counters value
      minFreqCount++;
    }
  }
  return minFreqCount;
}
int numMaxFrequencies(int charFrequency[]) {    // takes char frequency array as
  const int ALPHABET_SIZE = 26;                 // a parameter and loows through
  int maxFreq = maxFrequency(charFrequency);    // the array comparing every index
  int maxFreqCount = 0;                         // to the max frequency value, if the
  for (int i = 0; i < ALPHABET_SIZE; i++) {     // two values are equivalent, it will increment
    if (charFrequency[i] == maxFreq) {          // a counter and return the counters
      maxFreqCount++;
    }
  }
  return maxFreqCount;
}
void printMaxFrequencies(int charFrequency[]) {         // takes char frequency array
  int maxFreq = maxFrequency(charFrequency);            // as a parameter and uses the
  int maxFreqCount = numMaxFrequencies(charFrequency);  // max freq function to find the max ammount
  int maxFreqPrintCount = 0;                            // of times a single letter occured, and the max
  cout << "Highest frequency character";                // freq count function to find the letters with
  if (maxFreqCount > 1) {                               // max occurence, then prints a statement
    cout << "s";                                        // accounting for plurality
  }
  cout << " (appeared " << maxFreq                      // also takes plurality into account for the number
       << " time";                                      // of occurences.
  if (maxFreq > 1 || maxFreq < 1) {
    cout << "s";
  }
  cout << " in the file): ";
  for (int i = 0; i < 26; i++) {                         // loops through every index of the char freq array
    if (charFrequency[i] == maxFreq) {                   // and checks if the index has the max frequency
      maxFreqPrintCount++;                               // if it does the counter is incremented
      cout << static_cast<char>('a' + i);                // and the char is printed using the characters numerical
      if (maxFreqPrintCount < maxFreqCount - 1) {        // ASCII value from the array
        cout << ", ";
      }
      if ((maxFreqPrintCount == maxFreqCount - 1)&&     // then depending on plurality and number of letters
           maxFreqCount > 1 &&                          // left to print it prints different conjuctions such as
           maxFreqCount == 2) {                         // ", and " or ", " or " and "
            cout << " and ";
           } else if ((maxFreqPrintCount ==
           maxFreqCount - 1)&&
           maxFreqCount > 1 &&
           maxFreqCount != 2) {
            cout << ", and ";
           }
      }
    }
    cout << endl;
}
void printMinFrequencies(int charFrequency[]) {           // takes char frequency array
  int minFreq = minFrequency(charFrequency);              // as a parameter and uses the
  int minFreqCount = numMinFrequencies(charFrequency);    // min freq function to find the min ammount
  int minFreqPrintCount = 0;                              // of times a single letter occured, and the min
  cout << "Lowest frequency character";                   // freq count function to find the letters with
  if (minFreqCount > 1) {                                 // min occurence, then prints a statement
    cout << "s";                                          // accounting for plurality
  }
  cout << " (appeared " << minFreq                        // also takes plurality into account for the number
       << " time";                                        // of occurences.
  if (minFreq > 1 || minFreq < 1) {
    cout << "s";
  }
  cout << " in the file): ";                               // loops through every index of the char freq array
  for (int i = 0; i < 26; i++) {                           // and checks if the index has the min frequency
    if (charFrequency[i] == minFreq) {                     // if it does the counter is incremented
      minFreqPrintCount++;                                 // and the char is printed using the characters numerical
      cout << static_cast<char>('a' + i);                  // ASCII value from the array
      if (minFreqPrintCount < minFreqCount - 1) {
        cout << ", ";
      }
      if ((minFreqPrintCount == minFreqCount - 1)&&       // then depending on plurality and number of letters
           minFreqCount > 1 &&                            // left to print it prints different conjuctions such as
           minFreqCount == 2) {                           // ", and " or ", " or " and "
            cout << " and ";
           } else if ((minFreqPrintCount ==
           minFreqCount - 1)&&
           minFreqCount > 1 &&
           minFreqCount != 2) {
            cout << ", and ";
           }
      }
    }
    cout << endl << "\n";
}
void printBarChart(int charFrequency[]) {           // function will take the char frequency
  const int ALPHABET_SIZE = 26;                     // array as a parameter and find its max frequency
  int maxFreq = maxFrequency(charFrequency);        // then set a temp variable equivalent to the max
  int temp = maxFreq;                               // frequency value.
    while (temp > 0) {
      if (temp <= 9 && maxFreq > 9) {                // checking if num is two digits for spacing
        cout << " ";
      }
      cout << temp << " ";                          // printing y axis value
      for (int i = 0; i < ALPHABET_SIZE; i++) {     // the char frequency array is then iterated through
        if (charFrequency[i] >= temp) {             // if the value in the array is larger than or equal to the
          if (i == ALPHABET_SIZE - 1) {             // current temp a "*" is printed for the bar. if the value is
            cout << "*";                            // the last on the x axis no space proceeds the "*"
          } else {
            cout << "* ";
          }
        } else {
          if (i == ALPHABET_SIZE - 1) {             // if the value in the array does not have that level or
            cout << " ";                            // greater of occurence no star is printed and instead a two
          } else {                                  // spaces are printed, unless it is the last value and in that case
            cout << "  ";                           // a single space is printed
          }
        }
      }
      cout << "\n";
      temp -= 1;                                    // decrementing the temp
    }
    if (maxFreq > 9) {                               // if the numbers on y axis are double digit
      cout << "   ";                                 // three spaces are added to the x axis, if they are
    } else {                                         // single digit just two spaces are added
      cout << "  ";
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {        // then the entire alphabet is incremented through
      if (i == ALPHABET_SIZE - 1) {                  // printing 'a' first, which has a numerical ASCII
        cout << static_cast<char>(i + 'a');          // value of 97 and then adding the incremented i value
      } else {                                       // to increase the letter by 1 each time to 'b'
      cout << static_cast<char>(i + 'a') << " ";     // then 'c' and so on. Printing a space between each letter.
      }
    }
    cout << endl;
}
void printFrequencyTable(int charFrequency[]) {            // function will print the table of frequency in
  const int ALPHABET_SIZE = 26;                            // decending order, by taking the char frequency array
  int maxFreq = maxFrequency(charFrequency);               // as a parameter. First a temporary variable is made
  int temp = maxFreq;                                      // and set equivalent to the max frequency value. Then using a
    while (temp >= 0) {                                    // loop the array is iterated through checking if each letter has the
    for (int i = 0; i < ALPHABET_SIZE; i++) {              // max frequency of occurence. If a letter does that letter is printed using
        if (charFrequency[i] == temp) {                    // its numerical ascii value by adding the iterator to the char 'a' which is 97.
            cout << static_cast<char>(i + 'a') << ": "     // the frequency is then printed after the letter, and the temp value used for checking
            << charFrequency[i] << endl;                   // frequency is decremented.
        }
      }
      temp -= 1;
    }
    cout << "\n";
}



