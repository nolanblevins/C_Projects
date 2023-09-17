// Copyright Nblevins 2023

#include <iostream>
#include "timeofday.h"
#include "timeinterval.h"
using std::cout;
using std::endl;
using std::string;  // string is in the std namespace


TimeInterval::TimeInterval() {
  start_.SetHour(0);      // default constructor
  start_.SetMinute(0);    // all times set to 0
  start_.SetSecond(0);
  end_.SetHour(0);
  end_.SetMinute(0);
  end_.SetSecond(0);
}
TimeInterval::TimeInterval(const TimeOfDay& startTime, const TimeOfDay& endTime) {
  int totalStartTime = 0;
  totalStartTime = startTime.GetHour() * 3600 +   // get total times for
                   startTime.GetMinute() * 60 +   // start and end by multiplying
                   startTime.GetSecond();         // hours by 3600 for time in sec
  int totalEndTime = 0;                           // and mins by 60 then adding
  totalEndTime = endTime.GetHour() * 3600 +       // seconds.
                 endTime.GetMinute() * 60 +
                 endTime.GetSecond();
    if (totalStartTime > totalEndTime) {          // compare total start time in sec
      SetStartTime(startTime);                    // to total end time in seconds
      SetEndTime(startTime);                      // if the start time is more than
    } else {                                      // end, end becomes start time
      SetStartTime(startTime);                    // else set end to passed through end time
      SetEndTime(endTime);
    }
  }
TimeInterval::TimeInterval(const TimeOfDay& startTime, int length, const string& units) {
    SetStartTime(startTime);    // set start with param
    SetEndTime(length, units);  // set end with length and units of added length
  }
void TimeInterval::SetStartTime(const TimeOfDay& startTime) {
  int totalStartTime = 0;
  totalStartTime += startTime.GetHour() * 3600;     // get total start time in seconds
  totalStartTime += startTime.GetMinute() * 60;     // by multiplying hours by 3600, mins
  totalStartTime += startTime.GetSecond();          // by 60 and adding them with seconds,
  int totalEndTime = 0;                             // then do the same for end time. If the total
  totalEndTime += end_.GetHour() * 3600;            // start time in seconds is less than the total end
  totalEndTime += end_.GetMinute() * 60;            // or the end is zero set the new start time.
  totalEndTime += end_.GetSecond();
  if (totalStartTime < totalEndTime || totalEndTime == 0) {
    start_.SetSecond(startTime.GetSecond());
    start_.SetMinute(startTime.GetMinute());
    start_.SetHour(startTime.GetHour());
  }
}
void TimeInterval::SetEndTime(const TimeOfDay& endTime) {
  int totalStartTime = 0;
  totalStartTime = (start_.GetHour() * 3600) +      // get total start time in seconds
                   (start_.GetMinute()) * 60 +      // by multiplying hours by 3600, mins by 60
                   (start_.GetSecond());            // and adding with seconds. Then do the same for end time
  int totalEndTime = 0;                             // if total end time in seconds is less than total start time
  totalEndTime = (endTime.GetHour()) * (3600 +      // in seconds set the new end time topassed through end time
                  endTime.GetMinute()) * 60 +
                 (endTime.GetSecond());

  if (totalEndTime > totalStartTime) {
    end_.SetHour(endTime.GetHour());
    end_.SetMinute(endTime.GetMinute());
    end_.SetSecond(endTime.GetSecond());
  }
}
void TimeInterval::SetEndTime(int length, const string& units) {
  int totalEndTime = start_.GetSecond() +           // first get total end time
                     (start_.GetMinute() * 60) +    // by using current start time converted
                     (start_.GetHour() * 3600);     // to seconds
  TimeOfDay newEnd = start_;
  int lengthInSeconds = 0;  // total length in sec
  int endMins;              // new end time mins
  int endHours;             // new end time hrs
  int endSeconds;           // new end time seconds
    if (units == "seconds" && length > 0) {         // check for units, if the units are seconds
      lengthInSeconds = length;                     // and the length is greater than 0, set
    } else if (units == "minutes" && length > 0) {  // length in seconds to the length value
      lengthInSeconds = length * 60;                // if mins mult by 60
    } else if (units == "hours" && length > 0) {
      lengthInSeconds = length * 3600;              // if hrs mult by 3600
    } else {
      lengthInSeconds = 0;
    }
    if (lengthInSeconds > 0) {
      totalEndTime += lengthInSeconds;      // add length in seconds to end time in seconds
      endHours = totalEndTime / 3600;       // get new end times hrs by dividing by 3600
      totalEndTime -= endHours * 3600;      // take that number away from the end time
      endMins = totalEndTime / 60;          // get mins by diving by 60
      endSeconds = totalEndTime % 60;       // get seconds from remainder of mins div
      newEnd.SetHour(endHours);       // set new end values
      newEnd.SetMinute(endMins);
      newEnd.SetSecond(endSeconds);
    } else {
      newEnd = end_;    // if the length in seconds is not greater than 0, keep end value
    }
    if (newEnd.GetHour() < 24) {
      end_ = newEnd;    // if the end value is less than 24 or
    }                   // in the same day, set end to new end
  }

void TimeInterval::Print(bool militaryTime, bool displaySeconds) const {
  cout << "Start time: ";
  start_.Print(militaryTime, displaySeconds);   // use func from time of day to print
  cout << "End time: ";
  end_.Print(militaryTime, displaySeconds);     // use func from time of day to print
}