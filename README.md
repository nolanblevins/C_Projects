# C++ Projects Showcase

Welcome to my C++ Projects Showcase! This repository is a collection of C++ projects that demonstrate my programming skills and abilities.

## Project List

1. **ArraySort**
   - Description: The `ArraySort` module is a C++ header file that contains a versatile template function named `Median`. This function calculates the median value of an array of elements, making it useful for a wide range of data analysis tasks.
   - Difficulty: Moderate
   - Folder: `/ArraySort`

2. **CircleMath**
   - Description: The "CircleMath" module provides a set of utility functions for performing calculations related to circles and points in a two-dimensional plane. These functions are designed to assist with common geometric tasks:
     - `double Distance(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0)` calculates the distance between two points `(x1, y1)` and `(x2, y2)` using the Euclidean distance formula.
     - `int OnCircle(double xCenter, double yCenter, double radius, double xPoint, double yPoint)` determines the relationship between a point `(xPoint, yPoint)` and a circle with center `(xCenter, yCenter)` and radius `radius`. It returns `-1` if the point is inside the circle, `0` if the point is on the circle, and `1` if the point is outside the circle.
     - `bool OnLine(double x1, double y1, double x2, double y2, double x3, double y3)` checks if three points `(x1, y1)`, `(x2, y2)`, and `(x3, y3)` are collinear (lie on the same straight line). It returns `true` if the points are collinear and `false` otherwise.
   - Difficulty: Moderate
   - Folder: `/CircleMath`

3. **DateValidator**
   - Description: The "DateValidator" module includes a collection of functions for date validation and manipulation. It offers the following features:
     - `bool LeapYear(int year)`: Checks if a given year is a leap year.
     - `int LastDayOfMonth(int month)`: Returns the last day of a given month.
     - `int LastDayOfMonth(int month, int year)`: Returns the last day of a given month, accounting for leap years.
     - `bool ValidDate(int month, int day, int year)`: Validates a date, ensuring it falls within the expected range.
     - `void NextDate(int & month, int & day, int & year)`: Calculates the next date from a given date.
     - `void PreviousDate(int & month, int & day, int & year)`: Calculates the previous date from a given date.
   - Difficulty: Moderate
   - Folder: `/DateValidator`

4. **FrequencyOfChars**
   - Description: The "FrequencyOfChars" module is a C++ program for analyzing the frequency of characters in text files. It provides the following functions:
     - `int maxFrequency(int charFrequency[])`: Finds the maximum frequency of characters.
     - `int minFrequency(int charFrequency[])`: Finds the minimum frequency of characters.
     - `int numMinFrequencies(int charFrequency[])`: Counts the number of characters with the minimum frequency.
     - `int numMaxFrequencies(int charFrequency[])`: Counts the number of characters with the maximum frequency.
     - `void printMaxFrequencies(int charFrequency[])`: Prints characters with the maximum frequency.
     - `void printMinFrequencies(int charFrequency[])`: Prints characters with the minimum frequency.
     - `void printBarChart(int charFrequency[])`: Prints a bar chart representing character frequencies.
     - `void printFrequencyTable(int charFrequency[])`: Prints a frequency table in descending order.
   - Difficulty: Moderate
   - Folder: `/FrequencyOfChars`

5. **LengthUnitConversion**
   - Description: The "LengthUnitConversion" module provides a versatile C++ class named `Length` for performing unit conversions between inches and centimeters. This class allows you to:
     - Initialize a `Length` object with a value and units (default is 0 inches).
     - Set the units to either inches or centimeters.
     - Convert between inches and centimeters.
     - Perform addition, equality checks, and comparisons between `Length` objects.
   - Difficulty: Moderate
   - Folder: `/LengthUnitConversion`

6. **NumericalAndCharacterCounter**
   - Description: The "NumericalAndCharacterCounter" module is a C++ program that analyzes user input and counts the number of alphabetical and numerical characters entered. It also detects invalid characters and terminates when specific punctuation marks are encountered.
   - Difficulty: Easy
   - Folder: `/NumericalAndCharacterCounter`

7. **OperationalAndRelationalChecker**
   - Description: The "OperationalAndRelationalChecker" module is a C++ program that quizzes users on their knowledge of arithmetic and relational operators. It presents arithmetic and relational expressions and evaluates whether they are correct. Users can play multiple rounds and receive a score based on their performance.
   - Difficulty: Moderate
   - Folder: `/OperationalAndRelationalChecker`

8. **PointerProblem**
   - Description: The "PointerProblem" module demonstrates the use of pointers in C++ and includes two implemented functions:
     - `void Merge(SortedDynamicArray * const array1, const SortedDynamicArray * const array2)`: Merges two sorted dynamic arrays while removing duplicates.
     - `void Print(const SortedDynamicArray * nums)`: Prints the elements of a sorted dynamic array.
   - Note: The `Merge` function was implemented by nblevins, and the `Print` function was implemented by bhipp.
   - Difficulty: Moderate
   - Folder: `/PointerProblem`

9. **QuestionalValidator**
   - Description: [Briefly describe the QuestionalValidator project.]
   - Difficulty: Moderate
   - Folder: `/QuestionalValidator`
