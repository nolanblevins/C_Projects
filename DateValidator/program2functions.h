// Copyright nblevins 2023

#ifndef _PROGRAM2FUNCTIONS_H_
#define _PROGRAM2FUNCTIONS_H_

// LeapYear should take an integer argument for the year. If the argument
// is a positive integer that is a leap year, the function should return
// true, otherwise it should return false.
// For example, LeapYear(2023) should return false. LeapYear(2024) should
// return true.

// Function to determine if the given year is a leap year
// precondition: We expect argument to be a non-negative int
// postcondition: function returns true if given value is
//                a leap year and false if value is not a
//                leap year. if the value is a not a positive
//                int it will also return false.
bool LeapYear(int year);


// LastDayOfMonth function should take an integer for the month, and an integer
// for the year as its three arguments.
// The year parameter should have a default argument of 0.
// The function should return the largest valid day for the given month (an
// integer).
// For example LastDayOfMonth(1) should return 31.
// LastDayOfMonth(4) should return 30.
// If the month is invalid, the function should return 0.
// For example, LastDayOfMonth(13) should return 0.
// If the month sent to the function is 2 (February), the function must be
// sent a positive integer argument for the year in order to return the last
// date of the month. If the year argument is not a positive integer the
// function should return 0.
// For example, LastDayOfMonth(2) should return 0.
// LastDayOfMonth(2, 2023) should return 28.
// LastDayOfMonth(2, 2024) should return 29.


// Function to determine the last day of the month and return the int value
// precondition: we expect a postive integer between 1 and 12 and that if
//               the month is equal to february the year will also be included
// postcondition: function returns the integer value of all months 1 - 12
//                if the input is invalid it shall return 0 and if the input is
//                2 and is a leap year it will return 29, if the input is 2 and is
//                not a leap year it will return 28.
int LastDayOfMonth(int month);
int LastDayOfMonth(int month, int year);


// ValidDate function should take an integer for the month, an integer for
// the day, and an integer for the year as three arguments. The function should
// return true if the values make a valid date, and false otherwise.
// For example ValidDate(1, 5, 2023) should return true.
// ValidDate(7, 50, 2023) should return false.
// If the year is not a positive integer, then the function should return false

// Function to determine if a given date is valid
// precondition: all integer values are positive and given in
//               month/day/year formatting
// postcondition: function will return false if a date is invalid
//                or contains a negative integer and true if the
//                date is a valid date.
bool ValidDate(int month, int day, int year);


// NextDate function should take an integer variable for the month, an
// integer variable for the day, and an integer variable for the year as
// its three arguments.
// If the values of the arguments are not the values for a valid date, then
// the function should exit without making any changes to the arguments.
// If the values of the arguments are a valid date, then the function should
// update the three arguments to hold the next calendar date. For example, if
// the function is sent variables containing 1, 31, and 2023, the function
// update those variables so that they hold 2, 1, and 2023 when the function
// completes.

// Function will change values of passed through parameters to the next day
// precondition: date is a valid date and contains no negative values.
// postcondition: function will change passed through parameters to next calender date.
//                if values are invalid they will remain unchanged
void NextDate(int & month, int & day, int & year);


// PreviousDate function should take an integer variable for the month, an
// integer variable for the day, and an integer variable for the year as
// its three arguments.
// If the values of the arguments are not the values for a valid date, then
// the function should exit without making any changes to the arguments.
// If the values of the arguments are a valid date, then the function should
// update the three arguments to hold the previous calendar date. For example,
// if the function is sent variables containing 1, 1, and 2023, the function
// should update those variables so that they hold 12, 31, and 2022 when the
// function completes.

// Function will change passed through parameters to previous day.
// precondition: date is a valid date and contains no negative values.
// postcondition: function will change passed through parameters to
//                the previous calender date. if the values are invalid
//                they will remain unchanged.
void PreviousDate(int & month, int & day, int & year);

#endif