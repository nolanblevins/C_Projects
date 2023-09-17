// Copyright nblevins 2023

#ifndef _MULTIPLE_CHOICE_QUESTION_H_
#define _MULTIPLE_CHOICE_QUESTION_H_
#include"question.h"
#include <iostream>
#include <string>

using std::string;

namespace csce240_program5 {
// MultipleChoiceQuestion should be a child of the Question class
class MultipleChoiceQuestion : public Question {
    public:
    //  default constructor for multiple choice question object
    //  preconditions:  a string, int, pointer to string, and pointer to bool
    //                  are provided
    //  postconditions: a multiple choice question object is created with given
    //                  values if any are missing defaults will be used
    explicit MultipleChoiceQuestion(string = "?", int = 0, string * = nullptr,
                                    bool * = nullptr);

    //  Mutator for number of choices integer data member
    //  precondition: integer value is provided
    //  postcondition:  numchoices_ private data member
    //                  will be set to param value
    void SetNumChoices(int numChoices);

    //  Accessor for private data member number of choices
    //  preconditions:  the value of num choices has a value
    //  postconditions: the value of numchoices private
    //                  data member is returned
    int GetNumChoices() const { return numChoices_; }

    //  A copy constructor for a multiple choice question
    //  that will change the current multiple choice questions value
    //  to the passed through value
    //  Preconditions:  a multiple choice object is provided
    //  postconditions: all values of the multiple choice object
    //                  will be updated to hold passed through values
    //                  essentially copying the values
    MultipleChoiceQuestion(const MultipleChoiceQuestion& other);

    //  Operator overload for assignment operator
    //  preconditions: there is a multiple choice question object on the
    //                 left and right side of operator
    //  postconditions: multiple choice object on left side of operator will
    //                  have its values changed to hold values of right side
    //                  multiple choice object.
    MultipleChoiceQuestion& operator=(const MultipleChoiceQuestion& other);

    //  Destructor for Multiple choice question,
    //  is used to free memory
    //  preconditions: the multiple choice object has been instantiated and
    //                 contains values.
    //  postconditions: the private data members for the current object will
    //                  have all of their values removed or deleted to free
    //                  memory
    virtual ~MultipleChoiceQuestion();

    //  Function to set the answer choices
    //  Preconditions:  a integer for the number of choices, a pointer to
    //                  an array of answers, and a pointer to the correct answer
    //                  array are provided
    //  postconditions: the values for the three private data members are instatiated
    //                  if no values ae provided a set of default values are used
    void SetAnswerChoices(int, string *, bool *);

    //  Function to print answer choices and correctness if bool is true
    //  preconditions:  A boolean value is provided to determine if
    //                  the correct answers should be displayed, and values
    //                  of current object are instatiated
    //  postconditions: the question is printed as well as potential
    //                  answers, if the user passes true through function
    //                  it shall also print whether the answe is correct or
    //                  inccorect
    virtual void Print(bool answer) const;

    //  Function CheckAnswer checks if read answer is correct ot not
    //  param will be the users entered string
    //  precondition: user provides a string answer
    //  postcondition: answer is checked and reported for correctness
    virtual bool CheckAnswer(string answer) const;

    private:
    int numChoices_;  // number of answer choices
    string* answerChoices_;   // the answer choices themselves
    bool* correctChoices_;    // correctness of choices
};
};  // namespace csce240_program5
#endif  // _MULTIPLE_CHOICE_QUESTION_H_