// copyright nblevins 2023

#ifndef _TIMEINTERVAL_H_
#define _TIMEINTERVAL_H_
#include "timeofday.h"

#include<string>  // string class defined in the standard library
using std::string;  // string is in the std namespace

class TimeInterval {
  public:
  // default constructor for time interval
  // precondition: no values are passed through
  //               used for intializing
  // postcondition: will create a time interval object
  //                with values all initialized to 0
  TimeInterval();

  // constructor for time interval with user given start
  // and end times
  // preconditions: two objects are provided 1 for start time and
  //                1 for the end time, if the start time is not before
  //                the end time. Object will hold prev value and end time
  //                will be set to start time
  // postcondition: the private start and end time of day objects will
  //                hold the new values passed through
  TimeInterval(const TimeOfDay& startTime, const TimeOfDay& endTime);

  // constructor for a given start time and the value that should be added
  // to that start time as well as the units of that value (sec, min, hr)
  // will produce a new end time
  // precondition: 3 values are provided, the start time, the value to be added
  //               and the unit of that value. Length must be and integer value,
  //               start must be a time of day object and the units must be a string
  // postcondition: the private end value will be updated to hold the
  //                start time plus the length added. The start time will be updated to
  //                hold passed through value.
  TimeInterval(const TimeOfDay& startTime, int length, const string& units);

  // function to return the current private start value
  // postcondition: will return current start time of day object
  TimeOfDay GetStartTime() const { return start_; }

  // function to return current private end value
  // postcondition: will return current end time of day object
  TimeOfDay GetEndTime() const { return end_; }

  // function to set a new start time
  // precondition: the new start time is before
  //               current end time and a time of day object
  //               is provided
  // postcondition: if new start time is before current end time
  //                start object will be updated to hold the new values
  void SetStartTime(const TimeOfDay& startTime);

  // function to set a new end time
  // precondition: the new end time is after
  //               current start time and a time of day object
  //               is provided
  // postcondition: if new end time is after current start time
  //                end object will be updated to hold the new values
  void SetEndTime(const TimeOfDay& endTime);

  // function to set new end time with a given length and unit
  // precondition: an integer value is provided to be added to the current
  //               start time as well as the unit for that value.
  // postcondition: will update current end time value using the start time
  //                value and the length and its units.
  void SetEndTime(int length, const string& units);

  // will print the current start time and end time values
  // precondition: two booleans are provided, one to ddetermine
  //               if the values should be in military time and one
  //               to determine if the seconds should be displayed
  // postcondition: start and end times will be printed to the console
  //                in the users desired format.
  void Print(bool militaryTime = false, bool displaySeconds = false) const;



    private:
    TimeOfDay start_;   // start time of day
    TimeOfDay end_;     // end time of day
};
#endif    // end _TIMEINTERVAL_H_