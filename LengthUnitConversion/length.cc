//  copyright nblevins 2023

#include "length.h"   // header file
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::ostream;   // osteam for std::ostream

Length::Length(double value, const string &units) : value_(0), units_("inches") {
  // default constructor, sets value and units
  // will default to 0 and inches if no values are provided
  SetValue(value);    // set value_
  SetUnits(units);    // set units_
}
void Length::SetUnits(const string& units) {
  if (units == "inches" ||        // if the units provided are
      units == "centimeters") {   // valid set units_ to units
        units_ = units;
        } else {                  // else default inches
          units_ = "inches";
        }
}
void Length::SetValue(double value) {
  if (value > 0) {      // if value is greater than 0
    value_ = value;     // set value_ to value
  }                     // else no change
}
void Length::Convert(const string &units) {
  if (units == "inches" ||        // check id units to convert
      units == "centimeters") {   // to are valid
        if (units == "inches"&&       // if they are and the passed through
           units_ == "centimeters") {  // is inches and current is centimeters
            value_ /= 2.54;            // divide value by 2.54 to get new value
            units_ = "inches";         // change units to inches
           } else if (units == "centimeters"&&    // if the new unit is centimeters
                      units_ == "inches") {       // and current is inches
                        value_ *= 2.54;           // multiply by 2.54 and
                        units_ = "centimeters";   // change units to centimeters
                      }
      }
}
Length Length::operator+(const Length& sec) const {
  Length ret;                             // create return length
  if (units_ == sec.GetUnits()) {         // if the two units are equal
    ret.SetUnits(units_);                 // set return units to units_
    ret.SetValue(value_ + sec.GetValue());  // add values together and set return
    return ret;                             // return return value

  } else {                                  // if two units are not equal
    ret = sec;                              // set ret to the passed through length
    ret.Convert(units_);                    // convert second to units of current
    ret.SetValue(ret.GetValue() + value_);  // set value to ret plus current
    return ret;                             // return return value
  }
}
bool Length::operator==(const Length& sec) const {
  Length l;                             // create temp length object
  if (units_ == sec.GetUnits() &&       // if units and value
       value_ == sec.GetValue()) {      // of both objects are equal return true
        return true;
       } else {                         // if not equal
        l = sec;                        // set temp length to sec length
        l.Convert(units_);              // convert units of length to current units
        if (l.GetValue() == value_) {   // of values are equal return true
          return true;
        }
       }                                // else return false
       return false;
}
bool Length::operator<(const Length& sec) const {
  Length l;                           // create temp length object
  if (units_ == sec.GetUnits() &&     // if units are equal
       value_ < sec.GetValue()) {     // and current value is less than passed
        return true;                  // return true
       } else {                       // if units are not equal
        l = sec;                      // set length object to second object
        l.Convert(units_);            // convert units of second to units of current
        if (value_ < l.GetValue()) {    // if current is less than temp
          return true;                  // return true
        }
       }
       return false;          // else return false
}

ostream& operator<<(ostream& outputStream, const Length& length) {
    outputStream << length.value_ << " " << length.units_;      // inserts length value and units in
                                                                // output stream object
    return outputStream;        // returns output stream object
}

