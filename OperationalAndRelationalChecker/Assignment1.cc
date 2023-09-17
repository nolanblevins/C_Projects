// Copyright 1/23/2023 nblevins

#include <iostream>
#include <string>
#include <iomanip>
using std::cin; // used to take in standard input
using std::cout; // used for standard output
using std::endl; // used for end line

int main() {
	cout << std::setiosflags(std::ios::fixed | std::ios::showpoint) << std::setprecision(2); // used to show user score with 
																																													 // two values after decimal place
	bool externalRunning = true; // The external while loop condition
	int firstNum, secondNum, thirdNum; // The integer based variables used for the arithmetic relational problems
	double userScore = 0; // The number of relational problems the user entered correctly and have the correct answer
	double userTotal = 0; // The total number of entered arithmetic problems
	char arithmeticOperator, // The arithmetic operator used for the problems such as "+,-,/,% and *"
	relationalOperator, // The relational operators used for the problems such as "< and >"
	playAgain; // The character used to determine if the user wants to continue 
						 // such as "c" for continue and "q" for quit
	bool internalRunning; // The internal while loop condition
	while (externalRunning) {
		internalRunning = true;
		while (internalRunning) {
			cin >> firstNum >> arithmeticOperator >> secondNum >> relationalOperator >> thirdNum; // Takes in user input and sets
																								  																					// the variables equal to their
																								  																					// matching values

			if (arithmeticOperator != '/' && arithmeticOperator != '+' && arithmeticOperator != '-' && // Checks if arithmetic operator
					arithmeticOperator != '*' && arithmeticOperator != '%') {   													// matches an acceptable input
						cout << "Unrecognized armithmetic operator " << arithmeticOperator << "\n"; // outputs unrecognized operator
						internalRunning = false;																										// and quits internal loop
						break;
			}
			if (relationalOperator != '<' && relationalOperator != '>') { // checks if the relational operator matches acceptable input
				cout << "Unrecognized relational operator " << relationalOperator << "\n"; // outputs unrecognized relational operator
				internalRunning = false;																									 // and quits internal loop
				break;
			}
			if (arithmeticOperator == '/' && relationalOperator == '>' && firstNum / secondNum > thirdNum) { // checks if division with greater than
					cout << firstNum << " " << arithmeticOperator << " " << 																		 // and that the expression is true
					secondNum << " " << relationalOperator << " " << thirdNum << " - Correct\n";								 // then incriments score, total and quits loop
					userTotal += 1;
					userScore += 1;
					internalRunning = false;
			} else if (arithmeticOperator == '/' && relationalOperator == '<' && firstNum / secondNum < thirdNum) { // checks if division with less than
					cout << firstNum << " " << arithmeticOperator << " " << 																						// and that the expression is true
					secondNum << " " << relationalOperator << " " << thirdNum << " - Correct\n";												// then incriments score, total and quits loop
					userTotal += 1;
					userScore += 1;
					internalRunning = false;
			} else if (arithmeticOperator == '+' && relationalOperator == '<' && firstNum + secondNum < thirdNum) { // checks if addition with less than
					cout << firstNum << " " << arithmeticOperator << " " << 																						// and that the expression is true
					secondNum << " " << relationalOperator << " " << thirdNum << " - Correct\n";												// then incriments score, total and quits loop
					userTotal += 1;
					userScore += 1;
					internalRunning = false;
			} else if (arithmeticOperator == '+' && relationalOperator == '>' && firstNum + secondNum > thirdNum) { // checks if addition with greater than
					cout << firstNum << " " << arithmeticOperator << " " << 																						// and that the expression is true
					secondNum << " " << relationalOperator << " " << thirdNum << " - Correct\n";												// then incriments score, total and quits loop
					userTotal += 1;
					userScore += 1;
					internalRunning = false;
			} else if (arithmeticOperator == '-' && relationalOperator == '<' && firstNum - secondNum < thirdNum) { // checks if subraction with less than
					cout << firstNum << " " << arithmeticOperator << " " << 																						// and that the expression is true
					secondNum << " " << relationalOperator << " " << thirdNum << " - Correct\n";												// then incriments score, total and quits loop
					userTotal += 1;
					userScore += 1;
					internalRunning = false;
			} else if (arithmeticOperator == '-' && relationalOperator == '>' && firstNum - secondNum > thirdNum) { // checks if subtraction with greater then
					cout << firstNum << " " << arithmeticOperator << " " << 																						// and that the expression is true
					secondNum << " " << relationalOperator << " " << thirdNum << " - Correct\n";												// then incriments score, total and quits loop
					userTotal += 1;
					userScore += 1;
					internalRunning = false;
			} else if (arithmeticOperator == '*' && relationalOperator == '<' && firstNum * secondNum < thirdNum) { // check is multiplication with less than
					cout << firstNum << " " << arithmeticOperator << " " << 																						// and that the expression is true
					secondNum << " " << relationalOperator << " " << thirdNum << " - Correct\n";												// then incriments score, total and quits loop
					userTotal += 1;
					userScore += 1;
					internalRunning = false;
			} else if (arithmeticOperator == '*' && relationalOperator == '>' && firstNum * secondNum > thirdNum) { // checks if multiplication with greater than
					cout << firstNum << " " << arithmeticOperator << " " << 																						// and that the expression is true
					secondNum << " " << relationalOperator << " " << thirdNum << " - Correct\n";												// then incriments score, total and quits loop
					userTotal += 1;
					userScore += 1;
					internalRunning = false;
			} else if (arithmeticOperator == '%' && relationalOperator == '<' && firstNum % secondNum < thirdNum) { // checks if mod with less than
					cout << firstNum << " " << arithmeticOperator << " " << 																						// and that the expression is true
					secondNum << " " << relationalOperator << " " << thirdNum << " - Correct\n";												// then incriments score, total and quits loop
					userTotal += 1;
					userScore += 1;
					internalRunning = false;
			} else if (arithmeticOperator == '%' && relationalOperator == '>' && firstNum % secondNum > thirdNum) { // checks if mod with greater than
					cout << firstNum << " " << arithmeticOperator << " " << 																						// and that the expression is true
					secondNum << " " << relationalOperator << " " << thirdNum << " - Correct\n";												// then incriments score, total and quits loop
					userTotal += 1;
					userScore += 1;
					internalRunning = false;
			} else {
					cout << firstNum << " " << arithmeticOperator << " " <<															// If all other if statements are false						
					secondNum << " " << relationalOperator << " " << thirdNum << " - Incorrect\n";			// the expression must be false
					userTotal += 1;																																			// so will display that expression is incorrect
					internalRunning = false;																														// incriment user total and quit loop
			}
			}
			cin >> playAgain;								// read in whether the user wants to play again user standard input
			if(playAgain == 'c') {					// if the user enters c it will continue
				internalRunning = false;			// and if the user enters q it will quit
			} else if (playAgain == 'q') {  // default will quit program if anything other than c is or q is entered
				externalRunning = false;
			} else {
				externalRunning = false;
			}
		}
		cout << "\n" << userScore/userTotal << "\n"; // displays user score withe two decimal places

		return 0;
	}
