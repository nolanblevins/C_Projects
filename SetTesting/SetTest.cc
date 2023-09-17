#include "set.h"
#include <cassert>
#include<iostream>
 using namespace Project3Problem3;
 using std::cout;
int main() {
  Set<int> s1;
  s1.Print();
  int some_ints[6] = {1, 7, 22, 84, 100, 107};
  s1.SetValues(6, some_ints);
  s1.Print();

  Set<int> s2;
  s2.Print();
  int some_ints2[8] = { 1, 3, 6, 9, 84, 19, 25, 31 };
  s2.SetValues(8, some_ints2);
  s2.Print();
  
  if (s1 == s2) {
    cout << "sets are equivalent\n";
  } else {
    cout << "sets 1 and 2 are not equivalent\n";
  }
  Set<int> s3 = s1.Intersection(s2);
  s1.Print();
  s2.Print();
  cout << "\nintersection of sets\n";
  s3.Print();


  Set<int> s4;
  s4 = s1;
  s4.SetValues(6, some_ints);
  s4.Print();
  s1.Print();
  return 0;
}
