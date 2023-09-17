// Copyright 2023
// Implement the functionality of the Temperature class
#include"temperature.h"
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;

void Temperature::Print() const {
  cout << value_ << " degrees " << units_ << endl;
}

Temperature::~Temperature() {
  // toy example - just printing output so we can see when the
  // destructor is called
  cout << "Destructor called for " << value_  << " " << units_ << endl;
}
// default constructor implementation
// member initializer list comes between the close parenthesis for the
// constructor parameters and the body of the function
// if the data member is an object of a class, the member initializer
// list allows you to call the class constructor
Temperature::Temperature(double v, string u) : value_(0), units_("Celisius") {
//  value_ = 0;
//  units_ = "Celsius";
  SetValue(v);
  SetUnits(u);  // note: this function doesn't update the units if the
                // argument u is invalid, so we need line 10 above to
                // ensure that the units holds a valid value
}

void Temperature::SetValue(double v) {
  value_ = v;
}

void Temperature::SetUnits(string u) {
  // string class has == and = overloaded to compare the contents (characters)
  // of the strings and copy the characters of the strings, respectively
  if ( u == "Fahrenheit" || u == "Celsius" || u == "Kelvin" )
    units_ = u;
}