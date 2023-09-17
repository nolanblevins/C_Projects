// copyright nblevins 2023

#ifndef _LENGTH_H_
#define _LENGTH_H_

#include<iostream>
#include<string>  // string class defined in the standard library
using std::string;  // string is in the std namespace
using std::ostream;   // ostream for std::ostream

// Length class
class Length {
    public:
      // default constructor for length, used when creating a length
      // object
      // precondition: a double value for the length value is provided
      //               and a string value is provided for the units of
      //               the length
      // postcondition: will create a length object with the passed though
      //                double value for the length and the passed through
      //                string value for the lengths units. If no value for
      //                the value is provided will be set to 0, if no value is
      //                provided for the units it will be set to the default value
      //                of "inches".
      Length(double value = 0, const string &units = "inches");

      // set units function, will take in a string and set units_ to that value
      // precondition: a string is provided for the unit value
      // postcondition: will set the current units_ value to the passed through unit
      //                value as long as it is a valid value for the unit variable
      //                valid units are "centimeters" and "inches"
      void SetUnits(const string& units);

      // set value function, will take a double in as a parameter
      // and set value_ to that value
      // precondition: a double is provided for the "value" value
      // postcondition: will set the current "value_" value to the passed through "value"
      //                value as long as it is a valid value for the value variable
      //                valid units are greater than 0
      void SetValue(double value);

      // get value will return the current value_ variable
      double GetValue() const { return value_; }

      // get units will return the current units_ variable
      string GetUnits() const { return units_;}

      // Convert function will take in a string of units and
      // update the current units to that value, as well as
      // update the current "value_" value to match those units
      // precondition: a string value for the new units are provided
      // postcondition: function will update the current unit value to hold
      //                the new units as well as modify the value_ value to hold
      //                the correct conversion of the units
      void Convert(const string &units);

      // function overloads the "+" operator for length objects
      // precondition: a length object is provided and the operator is called
      //               on a length object
      // postcondition: the + operator will now take the length object to the left of
      //                and use its units to create a new object that has that unit value
      //                then convert the passed through object to hold the same unit value.
      //                then add the two values together and return the new length object of
      //                the two summed length objects.
      Length operator+(const Length& sec) const;

      // function overloads the == operator to compare to length objects to see if
      // there value_ variables are equal
      // precondition: the function is called on a length object and the passed through
      //               object is also a length object.
      // postcondition: function will take length object to the right of the == operator
      //                and convert the units to be the same as the length object to the left.
      //                Then the function will compare the value_ variables of both objects and
      //                return true if they are equal.
      bool operator==(const Length& sec) const;

      // function overloads the < operator to compare to length objects to see if
      // the value_ of the first object is less than the second object
      // precondition: the function is called on a length object and the passed through
      //               object is also a length object.
      // postcondition: function will take length object to the right of the < operator
      //                and convert the units to be the same as the length object to the left.
      //                Then the function will compare the value_ variables of both objects and
      //                return true if the called upon object is less than the passed through object.
      bool operator<(const Length& sec) const;

      // function overloads the standard output operator to automatically
      // output using the length object with the format "value units"
      // precondition: a length object is provided for the output
      //               and a reference to the output stream is provided
      // postcondition: the function will return the output
      //                stream object  with the length value and units inserted
      //                so it can be used with other output operations
      friend std::ostream& operator<<(std::ostream& os, const Length& length);
    private:

      double value_;
      string units_;
};

#endif  //  _LENGTH_H
