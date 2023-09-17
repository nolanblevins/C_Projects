// Copyright 2023 bhipp
// definition of the Question base class
#ifndef _QUESTION_H_
#define _QUESTION_H_

#include<string>
using std::string;
#include<iostream>

namespace csce240_program5 {

class Question {
 public:
  explicit Question(string q = "?") { question_ = q; }
  void SetQuestion(string q) {
    if ( q.length() > 0 )
      question_ = q;
  }
  string GetQuestion() const { return question_; }
  //  Virtual function to be used and overridden
  //  by child classes such as TrueFalseQuestion

  virtual void Print(bool print) const {
    std::cout << "Question: " << question_ << std::endl;
  }

  //  Virtual destructor to be used by
  //  child classes
  virtual ~Question() {};

  //  function to check if an answer is correct
  //  or incorrect depending on passed througn param
  //  not implemeneted in this class bc it is a pure
  //  virtual function to be implemented by child classes
  virtual bool CheckAnswer(string answer) const = 0;


 private:
  string question_;
};

}  // namespace csce240_program5

#endif  // _QUESTION_H_
