// copyright nblevins 2023

#ifndef _TIMEOFDAY_H_
#define _TIMEOFDAY_H_

#include<string>  // string class defined in the standard library
using std::string;  // string is in the std namespace

class TimeOfDay {
    public:
    // constructor for time of day class
    // precondition: hour, minute and second of time
    //               are all provided in int form
    // postcondition: time of day object will be created
    //                using given values as long as they are valid
    //                if invalid will be set to 0
    TimeOfDay(int hour = 0, int minute = 0, int second = 0);

    // function to set hour for time of day
    // precondition: integer of hour is provided
    // postcondition: hour will be updated to hold
    //                new hour value, if invalid value
    //                will be left unchanged
    void SetHour(int hour);

    // function to set min for time of day
    // precondition: integer of min is provided
    // postcondition: min will be updated to hold
    //                new min value, if invalid value
    //                will be left unchanged
    void SetMinute(int minute);

    // function to set sec for time of day
    // precondition: integer of sec is provided
    // postcondition: sec will be updated to hold
    //                new sec value, if invalid value
    //                will be left unchanged
    void SetSecond(int second);

    // returns current hour value
    int GetHour() const { return hour_; }

    // returns current minute value
    int GetMinute() const { return minute_; }

    // returns current second value
    int GetSecond() const { return second_; }

    // function to print the current time of day value
    // precondition: two booleans are provided, one to determine
    //               if the values should be in military time and one
    //               to determine if the seconds should be displayed
    // postcondition: current time of day will be printed, will display
    //                the time with users desired formatting
    void Print(bool militaryTime = false, bool displaySeconds = false) const;

    private:
    int hour_;  // hour for time of day object
    int minute_;  // minute for time of day object
    int second_;  // second for time of day object
};
#endif   // end _TIMEOFDAY_H_