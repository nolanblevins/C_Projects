// Copyright nblevins 2023

#ifndef _SHORT_ANSWER_QUESTION_H_
#define _SHORT_ANSWER_QUESTION_H_
#include"question.h"
#include <iostream>
#include <string>
using std::string;

namespace csce240_program5 {
class ShortAnswerQuestion : public Question {
    public:
      //  constructor for short answer question, will make a short answer
      //  question object when called
      //  precondition: a string question and string answer are provided
      //  postcondition: a short answer question object will be created,
      //                 using given values, if none are provided defaults
      //                 will be used.
      explicit ShortAnswerQuestion(string question = "?", string answer = "");

      // Mutator for private data member "answer_".
      // Precondition: Function is provided with a string value.
      // Postcondition: Function will set "answer_" to param of "answer".
      void SetAnswer(string answer);

      // Accessor for private data member "answer_".
      // Precondition: Answer has a current value.
      // Postcondition: Private data member "answer_" will be returned.
      string GetAnswer() const { return answer_; }

      // Function to print the short answer question and answer.
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

      //  Function will destruct short answer question object
      //  no dynamically allocated memory so nothing to destruct
      virtual ~ShortAnswerQuestion();
    private:

      string answer_;
};
};    // namespace csce240_program5
#endif    // SHORT_ANSWER_QUESTION