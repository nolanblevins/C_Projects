// Copyright nblevins 2023

#include <iostream>
#include <string>
#include "truefalsequestion.h"
#include "question.h"

using std::string;
using std::cout;
using std::endl;

namespace csce240_program5 {

  //  constuctor for true false question
  //  question is the question and answer is a true of false value
  TrueFalseQuestion::TrueFalseQuestion(string question, bool answer)
      : Question(question) {
    SetAnswer(answer);  // function to set the answer
  }

  //  Mutator for private answer data member
  void TrueFalseQuestion::SetAnswer(bool answer) {
    answer_ = answer;
  }

  //  Function to print
  //  Will first call questions print function
  //  then set a return string to true if the
  //  answer is true, else will be false
  //  prints correct answe with correct answer
  //  if param is true
  void TrueFalseQuestion::Print(bool answer) const {
    Question::Print(answer);  // print question
    string ans;
    if (GetAnswer() == true) {
      ans = "true";   // set ans str to true if true
    } else {
      ans = "false";   // else set ans to false
    }
    if (answer == true) {   // if the param is true: print corrrect ans
      cout << "Correct Answer: " << ans << endl;
    }
  }

  //  Destructor for true false question
  //  no dynamically allocated memory to destruct
  //  so function will essentially do nothing
  TrueFalseQuestion::~TrueFalseQuestion() {}


  //  Function to check if user answer matches
  //  stored private value for answer
  //  will check if ans string is equal to stored
  //  boolean value
  bool TrueFalseQuestion::CheckAnswer(string ans) const {
    if ((ans == "true" && answer_ == true)||
      (ans == "false" && answer_ == false)) {
        return true;
      } else {
        return false;
      }
  }
};  // namespace csce240_program5
