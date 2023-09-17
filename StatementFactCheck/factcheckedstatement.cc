// Copyright Nblevins 2023

#include "factcheckedstatement.h"
#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::cout;

namespace Project3Problem2 {
  //  Constructor for FactCheckedStatement, will check if the statement is valid
  //  before assignment, and check if truth is valid using set truth function
  FactCheckedStatement::FactCheckedStatement(string statement, double truth)
      : Sentence("") {
    //  check for valid statement
    if ((statement[0] >= 'A' && statement[0] <= 'Z') &&
        (statement[statement.length() - 1] == '.')) {
      Sentence::operator=(statement);
    } else {
      //  assign default
      Sentence::operator=("This is an unverified statement.");
    }
    SetTruth(truth);
  }
  //  overloaded assignment operator, that checks if
  //  statement begins with capital letter and ends in period
  FactCheckedStatement& FactCheckedStatement::operator=(const string& right) {
    if ((right[0] >= 'A' && right[0] <= 'Z') &&
        (right[right.length() - 1] == '.')) {
      string::operator=(right);
      truth_ = 0.0;
    }
    return *this;
  }
  //  Mutator for setting truth, will checl that
  //  the value is between 0.0 and 1.0, or 0 - 100%
  void FactCheckedStatement::SetTruth(double truth) {
    if (truth >= 0.0 && truth <= 1.0) {
      truth_ = truth;
    } else {
      truth_ = 0.0;
    }
  }
  //  Overloaded output stream for FactCheckedStatement Object
  //  will print in format "statement" "(num% true)"
  ostream& operator<<(ostream& os, const FactCheckedStatement& fcs) {
    os << static_cast<const Sentence&>(fcs) << " (" << fcs.GetTruth() * 100
       << "% true)";
    return os;
  }

}  // namespace Project3Problem2
