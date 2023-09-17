// Copyright 2023 Nblevins

#ifndef _PROBLEM1_H_
#define _PROBLEM1_H_

namespace Project3Problem1 {
// defining the template and defining the class
template<class T>
T Median(const T* array, const int size) {
  // Var to store median
  T median;
  // Pointer to sortedArray of object type T with size if user input
  T* sortedArray = new T[size];
  // fill sorted array with user arrays values using for loop
  for (int i = 0; i < size; i++) {
    sortedArray[i] = array[i];
  }
  // Bubble sort to get sorted array which compares values of array
  // with next index and swaps if out of order
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      // second element less than the first element
      if (sortedArray[j] > sortedArray[j+1]) {
        // swap values
        T temp = sortedArray[j];
        sortedArray[j] = sortedArray[j+1];
        sortedArray[j+1] = temp;
      }
    }
  }
  // if the size of the array is evenly divisible by 2, there are
  // two middle elements so we add the two middle elements together
  // and divide by two for the median value
  if (size % 2 == 0) {
    median = (sortedArray[size/2-1] + sortedArray[size/2]) / 2;
  // if the size of the array is not evenly divisible by 2 that
  // means there is a single element as the median value, so we
  // just return the middle value
  } else {
    median = sortedArray[size/2];
  }
  // free memory and return median value
  delete[] sortedArray;
  return median;
}
}   // namespace Project3Problem1

#endif  //  _PROBLEM1_H_
