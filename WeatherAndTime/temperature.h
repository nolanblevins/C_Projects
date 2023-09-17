// Copyright 2023 bhipp
// Define the Temperature class
#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

#include<string>  // string class defined in the standard library
using std::string;  // string is in the std namespace

class Temperature {
 public:
  // constructor
  Temperature(double v = 0, string u = "Celsius");
  // destructor - no return type, name = ~classname()
  ~Temperature();

  // mutator function
  void SetValue(double v);
  void SetUnits(string m);
  // accessor functions
  double GetValue() const { return value_; }
  string GetUnits() const { return units_; }

  void Print() const;
 private:
   value_;
  string units_;  // Fahrenheit, Celsius, Kelvin
};

#endif  // end _TEMPERATURE_H_