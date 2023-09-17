// Copyright nblevins 2023

#ifndef PROGRAM3FUNCTIONS_H
#define PROGRAM3FUNCTIONS_H

// function will take an integer array as a parameter and
// return thevalue of the index with the largest value.
// which is the frequency value of the highest occuring char.
// precondition: an array of integers is provided
//               where its size is 26 for the 26 chars
//               in the alphabet.
// postcondition: an integer will be returned representing
//                the largest value stored in the array.
//                which is the maximum frequency of a single char.
int maxFrequency(int charFrequency[]);

// function will take an integer array as a parameter and
// return the value of the index with the smallest value.
// which is the frequency value of the lowest occuring char.
// precondition: an array of integers is provided
//               where its size is 26 for the 26 chars
//               in the alphabet.
// postcondition: an integer will be returned representing
//                the smallest value stored in the array.
//                Which is the minimum frequency of a single char.
int minFrequency(int charFrequency[]);

// function will priint a bar chart representation
// of the chracter frequencies using astrisks to represent
// the bars and the frequency as the y-axis and the
// characters as the x-axis.
// precondition: the function will be provided an
//               array of integers where the 0th
//               index represents the letter 'a'
//               and the last index represents the letter
//               'z'. The function will also expect an array of
//               size 26.
// postcondition: the function will display a bar chart representation
//                of characters where '*' represents the bars. The x-axis
//                is the characters and the y-axis is the frequencies.
void printBarChart(int charFrequency[]);

// Function will print out the frequency of letter
// in a descending order.
// precondition: an array containing chracter frequencies is provided
//               where the 0th index represents the letter a and
//               last represents the letter z.
//               The array must also be 26 in size.
// postcondition: the function will display a table in decending
//                order where the first letter displayed is the
//                letter with the highest frequency of occurence
//                and the last is the one with the lowest.
void printFrequencyTable(int charFrequency[]);

// Function will return the number of characters
// that have the minimum level of frequency.
// precondition: an array containing chracter frequencies is provided
//               where the 0th index represents the letter a and
//               last represents the letter z.
//               The array must also be 26 in size.
// postcondition: the function will return an int value
//                that represents the number of characters
//                that have the minimum level of frequency.
int numMinFrequencies(int charFrequency[]);

// Function will return the number of characters
// that have the maximum level of frequency.
// precondition: an array containing chracter frequencies is provided
//               where the 0th index represents the letter a and
//               last represents the letter z.
//               The array must also be 26 in size.
// postcondition: the function will return an int value
//                that represents the number of characters
//                that have the maximum level of frequency.
int numMaxFrequencies(int charFrequency[]);

// function will display which characters appeared
// the most often and how often they occured.
// precondition: an array containing chracter frequencies is provided
//               where the 0th index represents the letter a and
//               last represents the letter z.
//               The array must also be 26 in size.
// postcondition: the function will print out a statement containing
//                the characters that had the maximum level
//                of frequency, how often they occured, as well
//                as use correct conjuctions depending on plurality.
void printMaxFrequencies(int charFrequency[]);

// function will display which characters appeared
// the least often and how often they occured.
// precondition: an array containing chracter frequencies is provided
//               where the 0th index represents the letter a and
//               last represents the letter z.
//               The array must also be 26 in size.
// postcondition: the function will print out a statement containing
//                the characters that had the minimum level
//                of frequency, how often they occured, as well
//                as use correct conjuctions depending on plurality.
void printMinFrequencies(int charFrequency[]);

#endif  // PROGRAM3FUNCTIONS_H