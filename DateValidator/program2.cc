// Copyright nblevins 2023

#include <iostream>
#include <string>
#include <iomanip>
#include"program2functions.h"   // functions for calculating difference in days
using std::cin;   // used to take in standard input
using std::cout;  // used for standard output
using std::endl;  // used for end line

int main() {
  int firstMonth, secMonth;   // first and second user inputted months
  int firstDay, secDay;       // first and second user inputted days
  int firstYear, secYear;     // first and second user inputted years
  char firstMonthDayDelim, secMonthDayDelim;    // user inputted delimmiter "/" for date
  char firstDayYearDelim, secDayYearDelim;      // user inputted delimmiter "/" for date
  int dayCount = 0;     // integer used to count difference in dates
  int tempMonth, tempDay, tempYear;   // temporary values used to make date calculations

  cin >> firstMonth >> firstMonthDayDelim >>      // user inputted date
  firstDay >> firstDayYearDelim >> firstYear >>
  secMonth >> secMonthDayDelim >> secDay >>
  secDayYearDelim >> secYear;

  tempMonth = firstMonth;   // temporary month for calculations
  tempDay = firstDay;       // temporary day for calculations
  tempYear = firstYear;     // temporary year for calculations

  if (!ValidDate(firstMonth, firstDay, firstYear)) {          // first checking if user dates are valid
    cout << firstMonth << firstMonthDayDelim <<               // if not, output that the invalid date is in
            firstDay << firstDayYearDelim << firstYear <<     // invalid and end.
            " is not a valid date" << endl;
  }
  if (!ValidDate(secMonth, secDay, secYear)) {
    cout << secMonth << secMonthDayDelim <<
            secDay << secDayYearDelim << secYear <<
            " is not a valid date" << endl;
  }
  if (ValidDate(firstMonth, firstDay, firstYear)&&    //  ensuring that the date is valid
      ValidDate(secMonth, secDay, secYear)) {
        if ((firstYear < secYear)||            // checking if the date first date comes
             ((firstYear == secYear)&&         // before the second date
              (firstMonth < secMonth))||
              ((firstYear == secYear)&&
              (firstMonth == secMonth)&&
              (firstDay < secDay))) {
                while ((tempYear < secYear)||       // as long as the first date is
                      ((tempYear == secYear)&&      // less than the second date
                      (tempMonth < secMonth))||     // continue the while loop
                      ((tempYear == secYear)&&
                      (tempMonth == secMonth)&&
                      (tempDay < secDay))) {
                        NextDate(tempMonth, tempDay, tempYear);   // change temporary date to the next day
                        dayCount++;                               // and update day counter
              }
              cout << firstMonth << firstMonthDayDelim <<     // outputting the first date
                  firstDay << firstDayYearDelim <<            // how many days before the second
                  firstYear << " is " << dayCount <<          // date it is and then the second date
                  " days before " << secMonth <<
                  secMonthDayDelim << secDay <<
                  secDayYearDelim << secYear << endl;
              }
        if ((firstYear > secYear)||         // checking if first date comes
             ((firstYear == secYear)&&      // after the second date
              (firstMonth > secMonth))||
              ((firstYear == secYear)&&
              (firstMonth == secMonth)&&
              (firstDay > secDay))) {
                while ((tempYear > secYear)||     // as long as the first day is
                      ((tempYear == secYear)&&    // greater than the second day
                      (tempMonth > secMonth))||   // continue the while loop
                      ((tempYear == secYear)&&
                      (tempMonth == secMonth)&&
                      (tempDay > secDay))) {
                        PreviousDate(tempMonth, tempDay, tempYear);   // change temporary date the the previous day
                        dayCount++;                                   // and update the day counter
              }
              cout << firstMonth << firstMonthDayDelim <<   // outputting the first date
                  firstDay << firstDayYearDelim <<          // how many days after the second
                  firstYear << " is " << dayCount <<        // date it is and then the second date
                  " days after " << secMonth <<
                  secMonthDayDelim << secDay <<
                  secDayYearDelim << secYear << endl;
              }
        if (((firstYear == secYear)&&                         // checking to see if date are equivalent
              (firstMonth == secMonth)&&                      // if they are output the first day the number
              (firstDay == secDay))) {                        // of days it is before the second and then
                cout << firstMonth << firstMonthDayDelim <<   // output the second day.
                  firstDay << firstDayYearDelim <<
                  firstYear << " is " << dayCount <<
                  " days before " << secMonth <<
                  secMonthDayDelim << secDay <<
                  secDayYearDelim << secYear << endl;
      }
}
}