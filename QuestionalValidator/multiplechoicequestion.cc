// Copyright nblevins 2023

#include "multiplechoicequestion.h"
#include "question.h"

#include <iostream>
#include <string>
using std::string;
using std::cout;

namespace csce240_program5 {

//  Default constructor for Object
//  will instantiate all of the private data members
//  as well as call the question constructor
MultipleChoiceQuestion::MultipleChoiceQuestion(string question,
                                               int numChoices,
                                               string* answerChoices,
                                               bool* correctChoices)
    : Question(question) {
  SetAnswerChoices(numChoices, answerChoices, correctChoices);
  SetNumChoices(numChoices);
}

//  Destructor for object
//  checks if either of the two private pointers
//  are null if they arent already null they will be
//  deleted and the pointers will be set to null
//  number of choices will also be set to 0
MultipleChoiceQuestion::~MultipleChoiceQuestion() {
  if (answerChoices_ != nullptr) {
    delete[] answerChoices_;
    answerChoices_ = nullptr;
  }
  if (correctChoices_ != nullptr) {
    delete[] correctChoices_;
    correctChoices_ = nullptr;
  }
  numChoices_ = 0;
}

//  Overload for assignment operator
//  checks if values are already equal
//  if not will set all values of the current object
//  to the object on the right side of the operator
//  first all values are deleted from the current
//  and then all of the values are instatiated
//  finally a pointer to the current object is returned
MultipleChoiceQuestion& MultipleChoiceQuestion::operator=(
    const MultipleChoiceQuestion& other) {
  if (this != &other) {
    Question::operator=(other);

    numChoices_ = other.numChoices_;
    delete[] answerChoices_;
    delete[] correctChoices_;
    answerChoices_ = new string[numChoices_];
    correctChoices_ = new bool[numChoices_];
    for (int i = 0; i < numChoices_; i++) {
      answerChoices_[i] = other.answerChoices_[i];
      correctChoices_[i] = other.correctChoices_[i];
    }
  }
  return *this;
}

//  Mutator to set the number of choices to param
void MultipleChoiceQuestion::SetNumChoices(int num_choices) {
  numChoices_ = num_choices;
}

//  Function to set the answer choices
//  first check if num choices has a value
//  then instatiate the size of answer choices
//  and correct choices to that value
//  then loop and assign each value of the arrays
//  to the passed through parameter. If there is no values
//  or is a null pointer, the values will be set to default values
//  if num choices is 0, two values will be automatically set to
//  a null pointer. Finally private data member num choices is set
//  to the param
void MultipleChoiceQuestion::SetAnswerChoices(int numChoices,
                                               string* answerChoices,
                                               bool* correctChoices) {
  if (numChoices != 0) {
    answerChoices_ = new string[numChoices];
    correctChoices_ = new bool[numChoices];
    for (int i = 0; i < numChoices; i++) {
      if (answerChoices != nullptr) {
        answerChoices_[i] = answerChoices[i];
      } else {
        answerChoices_[i] = "";
      }
      if (correctChoices != nullptr) {
        correctChoices_[i] = correctChoices[i];
      } else {
        correctChoices_[i] = true;
      }
    }
  } else {
    answerChoices_ = nullptr;
    correctChoices_ = nullptr;
  }
  numChoices_ = numChoices;
}

//  Copy constructor for object
//  Will take an object and create a copy
//  function takes a multiple choice object and assigns all
//  values of the current multiple choice object
//  to the ones passed in the
//  parameterized object. first the number of choices
//  is set and then that value is
//  used to create the answer and correct choices,
//  then the values of the passed through
//  object are looped through and used to assign.
MultipleChoiceQuestion::MultipleChoiceQuestion(const MultipleChoiceQuestion& other)
    : Question(other) {
  numChoices_ = other.numChoices_;
  answerChoices_ = new string[numChoices_];
  correctChoices_ = new bool[numChoices_];

  for (int i = 0; i < numChoices_; i++) {
    answerChoices_[i] = other.answerChoices_[i];
    correctChoices_[i] = other.correctChoices_[i];
  }
}


//  Print function
//  first calls questions print
//  then loops through answer choices and displays.
//  if passed through boolean is true, the correctness
//  of the answers are also printed
void MultipleChoiceQuestion::Print(bool answer) const {
  Question::Print(answer);
  cout << "Answer Choices:\n";
  for (int i = 0; i < numChoices_; i++) {
    cout << answerChoices_[i];
    if (answer == true) {
      cout << " - ";
      if (correctChoices_[i] == true) {
        cout << "correct";
      } else {
        cout << "incorrect";
      }
    }
    cout << "\n";
  }
}
//  Function will loop through all answer choices
//  evaluate whether the answer param is correct
//  then return the appropriate boolean
bool MultipleChoiceQuestion::CheckAnswer(string ans) const{
  for (int i = 0; i < numChoices_; i++) {
    if (ans == answerChoices_[i] && correctChoices_[i]) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}


}  // namespace csce240_program5
