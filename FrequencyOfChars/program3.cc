// Copyright nblevins 2023

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cctype>
#include"program3functions.h"

using std::cin;   // used to take in standard input
using std::cout;  // used for standard output
using std::endl;  // used for end line
using std::ifstream;
using std::ofstream;

int main(int argc, char * argv[]) {
  char letter;                   // the letter being added to the array
  int charFrequency[26] = {0};   // char array of size 26 for 26 letter in alphabet
  ifstream inputFile(argv[1]);   // input file as first argument
    if (inputFile.is_open()) {   // checking that the input file is open
      do {
        while (inputFile.get(letter)) {              // getting each letter from the file
          charFrequency[tolower(letter) - 'a']++;    // then subtracting the letter 'a' using its numerical
        }                                            // ascii value to get the index in which should be incremented
      } while (inputFile.good());                    // b for example should be (98 - 97) and then increment the first index
    }
    printMaxFrequencies(charFrequency);  // prints the max frequency chars
                                         // and the ammount of times they appeared

    printMinFrequencies(charFrequency);  // prints the min frequency chars
                                         // and the ammount of times they appeared

    printFrequencyTable(charFrequency);  // prints a chart with the chars
                                         // in descending order from highest
                                         // frequency of occurence to lowest
                                         // frequency of occurence

    printBarChart(charFrequency);       // prints a bar chart with the
                                        // frequency of occurence on the
                                        // y-axis and the letter on the
                                        // x-axis with '*' representing
                                        // the bars
    return 0;
}