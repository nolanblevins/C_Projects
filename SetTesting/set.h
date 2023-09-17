// Copyright 2023 CSCE240 (bhipp)
// nblevins 2023

// Define our Set template class
// set - unordered (the order of the values doesn't matter) collection of
//       distinct objects (since the objects can be of any type - we'll make
//       this a template class
#ifndef _SET_H_
#define _SET_H_

#include<iostream>
using std::cout;
using std::endl;

namespace Project3Problem3 {

template<class TheType>
class Set {
 public:
  // default constructor
  explicit Set(int size = 0, const TheType * values = nullptr) {
    size_ = 0;
    values_ = nullptr;
    SetValues(size, values);
  }

  // copy constructor
  Set(const Set& to_copy) {
    size_ = 0;
    values_ = nullptr;
    SetValues(to_copy.size_, to_copy.values_);
  }

  // destructor
  ~Set() {
    if ( values_ != nullptr )
      delete [] values_;
  }

  // assignment operator
  Set& operator = (const Set& to_copy) {
    SetValues(to_copy.size_, to_copy.values_);
    return *this;  // return the newly updated object the operator
                  // was called on
  }

  // SetValues function
  // pre-conditions the second argument points to a block of at least
  //                new_size TheTypes (currently not checking for
  //                duplicates)
  void SetValues(int new_size, const TheType * new_values) {
    if ( new_size < 0 )
      return;
    if ( new_size != size_ ) {
      if ( size_ != 0 )
        delete [] values_;
      if ( new_size == 0 )
        values_ = nullptr;
      else
       values_ = new TheType[new_size];
    }
    size_ = new_size;
    int position = 0;
    for ( int i = 0; i < size_; ++i ) {
      bool already_in_there = false;
      for ( int j = 0; j < position && !already_in_there; ++j )
         already_in_there = values_[j] == new_values[i];
      if ( !already_in_there )
        values_[position++] = new_values[i];
     }
     size_ = position;
  }

  // Print function to display values at the standard output device
  void Print() const {
    cout << "{";
    for ( int i = 0; i < size_; ++i )
      cout << values_[i] << (i < size_ - 1 ? ", " : "");
    cout << "}" << endl;
  }

  // Is a Subset of
  bool IsASubset(const Set& possible_subset) const {
    bool answer = true;
    int i = 0;
    while ( answer && i < possible_subset.size_ ) {
      answer = false;
      for ( int j = 0; j < size_ && !answer; ++j ) {
        answer = values_[j] == possible_subset.values_[i];
      }
      ++i;
    }
    return answer;
  }

  // is an element of
  bool IsAnElementOf(const TheType& the_value) const {
    bool found = false;
    int i = 0;
    while ( i < size_ && !found )
      found = values_[i++] == the_value;
    return found;
  }

  int GetCardinality() const { return size_; }

  // Implement the Intersection function whose prototype is given below.
  // The function should return the intersection of the two sets. Recall, the
  // intersection of two sets is the set of all elements the two sets have in
  // common.
  // For example, if set1 is the set { 1, 8, 2, 6, 3 } and
  //                 set2 is the set { 6, 4, 1 } then
  //                 set1.Intersection(set2) should return the set { 1, 6 }
  // For example, if set1 is the set { 'a', 'c' } and
  //                 set2 is the set { 'r, 'm', 'l', 't' } then
  //                 set1.Intersection(set2) should return the set {}
  // For example, if set1 is the set { 9.8, 2.7 } and
  //                 set2 is the set { 2.7, 4.16, 9.8 } then
  //                 set1.Intersection(set2) should return the set { 9.8, 2.7 }
  // function prototype: Set Intersection(const Set& right) const;

  //  function will take two sets and all values that
  //  are the same between the two will be added to a
  //  new intersected set
  Set Intersection(const Set& right) const {
    //  Create a new set to hold the intersection
    Set intersection;
    //  Iterate through values of set
    //  and assign current iteration
    //  to a variable
    for (int i = 0; i < size_; i++) {
      TheType value = values_[i];
      //  Check if the value is in the right set
      //  using IsAnElementOf function
      if (right.IsAnElementOf(value)) {
        //  increase size of updated intersection set
        TheType* temp = new TheType[intersection.size_ + 1];
        //  add all of the values of currect intersection
        //  set to the new intersection set
        for (int j = 0; j < intersection.size_; j++) {
          temp[j] = intersection.values_[j];
        }
        //  add the new sets value to the last index
        temp[intersection.size_] = value;
        //  set the intersection set to be the newValues
        intersection.SetValues(intersection.size_ + 1, temp);
        //  free memory
        delete[] temp;
    }
  }
  // Return the intersection set
  return intersection;
  }

  // The == operator should return true if the set on the left on the left
  // and the set on the right contain exactly the same elements (values) and
  // false otherwise.
  // For example, if set1 is the set {1, 2, 3} and
  //                 set2 is the set {2, 1, 3}
  //                 set1 == set2 should return true
  // For example, if set1 is the set {'a', 'b', 'x'} and
  //                 set2 is the set {'x', 'b'}
  //                 set1 == set2 should return false
  // prototype: bool operator == (const Set& right) const;

//  Equality operator overload which will check if
//  if two sets are equivalent and return true
//  if that is the case
bool operator == (const Set& right) const {
    //  If the sizes are different, they can
    //  not be equivalent so return false
    if (size_ != right.size_) {
        return false;
    }
    //  Check that all elements in the current set are in the other set
    //  since we all ready checked that the two sets are equivalent in
    //  size the we can just check for each value from one set
    for (int i = 0; i < size_; i++) {
        if ((!right.IsAnElementOf(values_[i]))) {
            return false;
        }
    }
    //  if all of those conditions previously
    //  are not false they must be equivalent
    return true;
}


 private:
  int size_;  // cardinality / cardinal number
  TheType * values_;
};  // class Set

}  // namespace Project3Problem3

#endif  // _SET_H

