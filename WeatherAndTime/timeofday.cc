// Copyright Nblevins 2023

#include <iostream>
#include "timeofday.h"
using std::cout;
using std::endl;

TimeOfDay::TimeOfDay(int hour, int minute, int second) : hour_(0), minute_(0), second_(0) {
  SetHour(hour);        // set values for hour
  SetMinute(minute);    // minute
  SetSecond(second);    // and second, default values will be 0
}
void TimeOfDay::SetHour(int hour) {
  if (hour < 24 && hour >= 0) {   // set hour if it is between
    hour_ = hour;                 // 0 and 24
  }
}
void TimeOfDay::SetMinute(int minute) {
  if (minute < 60 && minute >= 0) {    // set minute if it is between
    minute_ = minute;                  // 0 and 60
  }
}
void TimeOfDay::SetSecond(int second) {  // set second if it is between
  if (second < 60 && second >= 0) {      // 0 and 60
    second_ = second;
  }
}
void TimeOfDay::Print(bool militaryTime, bool displaySeconds) const {
  if (militaryTime == true) {         // check if mil time is true
    if (hour_ < 10) {                 // if its true and the hour is less than
    cout << "0" << hour_ << ":";      // 10 pre-append a 0
    } else {
      cout << hour_ << ":";           // if not print as is
    }
  } else {                            // if mil time is false
    if (hour_ > 12) {                 // and the hour is more than 12
      if (hour_ - 12 < 10) {          // convert to 12 hr clock by
        cout << "0" << hour_ -12      // subtracting 12, then check
             << ":";                  // if less than 10 for a pre-appended 0
      } else {
        cout << hour_ -12 << ":";
      }
    } else {                          // if the hour is not more than 12  
      if (hour_ < 10) {               // values stay the same
        cout << "0" << hour_ << ":";
      } else {
        if (hour_ >= 10) {
          cout <<  hour_ << ":";
        }
      }
    }
  }
  if (minute_ < 10) {           // if min is less than 10
    cout << "0" << minute_;     // pre-append 0 for print
  } else {
    cout << minute_;            // if not print as is
  }
  if (displaySeconds == true) {   // if dispay seconds is true
    if (second_ < 10) {           // and the seconds are less than 10
    cout << ":" << "0" << second_;    // pre-append a 0
    } else {                          // if not less than 10
      cout << ":" << second_;         // print seconds
    }
  }
  if (militaryTime == false) {    // if mil time is false
    if (hour_ < 12) {             // add corresponding am or pm
      cout << " a.m." << endl;    // and end the line
    } else {
      cout << " p.m." << endl;
    }
  } else {                       // if display seconds is false, end the line
    cout << endl;
  }
}
