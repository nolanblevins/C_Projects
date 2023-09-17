// Copyright 2023 CSCE240 bhipp
// compare output generated by student's stream insertion operator to the
// expected output
#include<fstream>
using std::ifstream;
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;
#include<cstring>
#include<cmath>

int main() {
  // correctoutput.txt holds the expected output generated by testoutput.cc
  ifstream correctfile("correctoutput.txt");

  // studentoutput.txt holds the output generated by testoutput.cc using
  // the student's stream insertion operator
  ifstream studentfile("studentoutput.txt");

  bool match = true;
  string correctline, studentline;
  int totallines = 0, linescorrect = 0;

  cout << "Your output:" << endl;
  getline(correctfile, correctline);
  getline(studentfile, studentline);
  while ( correctfile.good() ) {
    cout << "correct line " << totallines + 1 << ": " << correctline << endl;
    if ( studentfile.good() ) {
      match = correctline == studentline;
      cout << "student line " << totallines + 1 << ": " << studentline << endl;
      if ( !match )
        cout << "mismatch" << endl;
      else
        ++linescorrect;
      getline(studentfile, studentline);
      cout << endl;
    }
    ++totallines;
    getline(correctfile, correctline);
  }

  cout << linescorrect << " of " << totallines << " lines match." << endl;

  return 0;
}