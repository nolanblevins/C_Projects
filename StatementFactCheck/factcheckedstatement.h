// Copyright Nblevins 2023

#ifndef _FACTCHECKEDSTATEMENT_H_
#define _FACTCHECKEDSTATEMENT_H_

#include "sentence.h"
#include <string>
#include <iostream>

namespace Project3Problem2 {

class FactCheckedStatement : public Sentence {
 public:
  // Constructor for object with a statement as a string
  // and a truth value as a double
  // Preconditions: a valid or no value is provided
  //                for both the truth and statement
  // Postcondition: the object is created
  FactCheckedStatement(string statement = "This is an unverified statement",
                       double truth = 0.0);

  // Overloaded assignment operator
  // Preconditions: a string is provided to be checked for
  //                assignment and will be checked for validity
  // Postconditions: will return a pointer to assigned object
  FactCheckedStatement& operator=(const string& str);

  // Accessor for truth private data member
  // Postconditions: will return the value of private truth data member
  double GetTruth() const { return truth_; }

  // Mutator for truth private data member
  // Preconditions: a double value is provided to function
  // Postconditions: will ensure that value is between
  //                 0.0 and 1.0 which will be between 0 and 100 %
  void SetTruth(double truth);

  // Overloaded output stream operator
  // Preconditions: a fact checked statement object
  //                is provided to the output stream
  // Postconditions: will output the statement followed
  //                 by its truth percentage using
  //                 the called upon object
  friend std::ostream& operator<<(std::ostream& os, const FactCheckedStatement& fcs);

 private:
  // Private data member representing how true a statement is
  double truth_;
};

}  // namespace Project3Problem2

#endif  // _FACTCHECKEDSTATEMENT_H_
