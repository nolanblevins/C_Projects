// Copyright Nblevins 2023

#include"program2functions.h"

bool LeapYear(int year) {                    // function will return true if
  if (year % 100 == 0 && year % 400) {       // given year is a leap year and
    return false;                            // otherwise will return false.
  } else if ((year % 4 == 0 && year > 0)) {
    return true;
  } else {
    return false;
  }
}
int LastDayOfMonth(int month) {                   // function will return the
  if (month == 1 || month == 3 || month == 5 ||   // last day of the month for all months
      month == 7 || month == 8 || month == 10 ||  // except for february
      month == 12) {
        return 31;
      } else if (month == 4 || month == 6 ||
                 month == 11 || month == 9) {
                  return 30;
      } else {
        return 0;
      }
}
int LastDayOfMonth(int month, int year) {     // function will return the last
  if ((month == 2)&&                          // day of the month for february
      (LeapYear(year))) {                     // specifically if it is a leap year
        return 29;                            // will return 29, and 28 if not
      } else if ((month == 2)&&
                 (!LeapYear(year))) {
                  return 28;
      } else {
        return 0;
      }
}
bool ValidDate(int month, int day, int year) {    // function will return whether a
  if (month <= 0 || day <= 0 || year < 0) {       // given date is valid or not. if
    return false;                                 // the given date contains negative values
  } else if ((month == 2) &&                      // or values outside of the given months accepted days
            ((LeapYear(year)) &&                  // it will return false. if the values are valid function will
            (day <= 29))) {                       // return true.
    return true;
  } else if ((month == 2) &&
            (year % 4 != 0) &&
            (day <= 28)) {
    return true;
  } else if ((month == 1 || month == 3 ||
              month == 5 || month == 7 ||
              month == 8 || month == 10 ||
              month == 12) && (day <= 31) &&
              (year > 0)) {
                return true;
      } else if ((month == 4 || month == 6 ||
                 month == 11 || month == 9) &&
                 (day <= 30) &&
                 (year > 0)) {
                  return true;
                 } else {
                  return false;
                 }
}
void NextDate(int & month, int & day, int & year) {         // function will take in a given date
  if (ValidDate(month, day, year)) {                        // and update the given values to the next
    if (day != LastDayOfMonth(month) && month != 2) {       // calender day. if the values are invalid,
      day++;                                               // the function will leave given values unchanged.
      } else if ((day == LastDayOfMonth(month))&&
                (month == 12)) {
                  month = 1;
                  day = 1;
                  year += 1;
      } else if ((month == 2) &&
                (day == LastDayOfMonth(month, year))) {
                  month += 1;
                  day = 1;
      } else if ((month == 2)&&
                 (day != LastDayOfMonth(month, year))) {
                  day += 1;
      } else if ((month != 2)&&
                (month != 12)&&
                (day == LastDayOfMonth(month))) {
                  month += 1;
                  day = 1;
      }
  }
}
void PreviousDate(int & month, int & day, int & year) {       // function will take in a given date
  if (ValidDate(month, day, year)) {                          // and update the values to the previous
    if ((month == 1)&&                                        // calender date. if the values are invalid
        (day == 1)) {                                         // the function will leave given values unchanged.
          month = 12;
          day = LastDayOfMonth(month);
          year -= 1;
        } else if ((month == 3)&&
                   (LeapYear(year))&&
                   (day == 1)) {
                    day = 29;
                    month -= 1;
        } else if ((month != 3)&&
                   (month != 1)&&
                   (day == 1)) {
                    month -= 1;
                    day = LastDayOfMonth(month);
        } else if ((month == 3)&&
                   (!LeapYear(year))&&
                    (day == 1)) {
                      day = 28;
                      month -= 1;
        } else {
          day -= 1;
        }
  }
}

