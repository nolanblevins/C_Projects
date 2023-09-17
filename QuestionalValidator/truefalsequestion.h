// Copyright nblevins 2023

#ifndef _TRUE_FALSE_QUESTION_H_
#define _TRUE_FALSE_QUESTION_H_

#include "question.h"
#include <iostream>
#include <string>

namespace csce240_program5 {

class TrueFalseQuestion : public Question {
  public:
    // Constructor for True False Question.
    // Precondition: A string is provided for the question and a boolean
    //               value is provided for the answer.
    // Postcondition: Function will create a true false question with a
    //                boolean answer. If nothing is provided for one of
    //                the parameters, a default value will be used.
    explicit TrueFalseQuestion(string Question = "?", bool Answer = true);

    // Mutator for private data member "answer_".
    // Precondition: Function is provided with a boolean value.
    // Postcondition: Function will set "answer_" to param of "answer".
    void SetAnswer(bool answer);

    // Accessor for private data member "answer_".
    // Precondition: Answer has a current value.
    // Postcondition: Private data member "answer_" will be returned.
    bool GetAnswer() const { return answer_; }

    // Function to print the true false question and answer.
    // Parameter will determine if the answer should be printed.
    // Precondition: Boolean is provided to determine what shall be displayed.
    // Postcondition: The function will print the question and then use bool
    //                param to determine if answer should be printed as well.
    virtual void Print(bool answer) const;

    //  Function CheckAnswer checks if read answer is correct ot not
    //  param will be the users entered string
    //  precondition: user provides a string answer
    //  postcondition: answer is checked and reported for correctness
    virtual bool CheckAnswer(string answer) const;

    //  Destructor for true false question
    //  will essentially do nothing due to the
    //  absence of any dynamically allocated
    //  memory
    virtual ~TrueFalseQuestion();

  private:

    bool answer_;  // Private "answer_" data member to hold answer.
};
}  // namespace csce240_program5

#endif  // TRUE_FALSE_QUESTION_H
