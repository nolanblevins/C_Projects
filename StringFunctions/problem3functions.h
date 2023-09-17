// Copyright nblevins 2023

#ifndef PROBLEM3FUNCTIONS_H_
#define PROBLEM3FUNCTIONS_H_


// function will take an integer as a parameter
// and return the number of digits it contains.
// precondition: the number is a whole integer value
// postcondition: the number of digits the integer has
//                will be returned.
int NumDigits(int num);

// function will take a number, a number within that number
// to find and a number to replace the found number with.
// Preconditions: the second and third arguments should be positive integers,
//                and the second argument should contain at least as many digits
//                as the third argument. If the preconditions are not met, the
//                function should return false and leave the first argument
//                unchanged.
// postconditions: the function will return tue if the number has been modified
//                 and false if not. The function will aslo modify the passed through
//                 number to match the numbers that shall be found and replaced.
bool FindAndReplace(int &number, int find, int replace);

#endif /* PROBLEM3FUNCTIONS_H_ */
