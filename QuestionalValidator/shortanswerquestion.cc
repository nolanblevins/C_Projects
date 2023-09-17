// Copyright nblevins 2023

#include <iostream>
#include <string>
#include "shortanswerquestion.h"
#include "question.h"

using std::string;
using std::cout;
using std::endl;

namespace csce240_program5 {

//  Constructor for short answer question
//  parameters are the question and answer as strings
//  the question will be used to instatiate question
ShortAnswerQuestion::ShortAnswerQuestion(string question, string answer)
    : Question(question) {
  SetAnswer(answer);  // call set answer
}

//  sets priv data member answer value to parameter
void ShortAnswerQuestion::SetAnswer(string answer) {
  answer_ = answer;
}

//  calls questions print function then sets
//  a string to the answer, then checks if bool
//  is true to print correct answers and prints
//  accordingly
void ShortAnswerQuestion::Print(bool answer) const {
  Question::Print(answer);
  string ans = GetAnswer();
  if (answer) {
    cout << "Correct Answer: " << ans << endl;
  }
}
//  Destructor for short answer question
//  nothing to destruct because no dynamically
//  allocated memory
ShortAnswerQuestion::~ShortAnswerQuestion() {}

//  pure virtual function that checks a user answer for
//  correctness, function will take a string as a param
//  and compare to local private data member, if they are equal
//  function will return true else will return false
bool ShortAnswerQuestion::CheckAnswer(string ans) const{
  if (ans == answer_) {
    return true;
  } else {
    return false;
  }
}

};  // namespace csce240_program5
