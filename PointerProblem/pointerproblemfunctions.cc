// Copyright 2023 nblevins
// Merge function implemented by nblevins
// Print function implemented by bhipp
#include"pointerproblemfunctions.h"
#include<iostream>
using std::cout;
using std::endl;
#include<iomanip>
using std::setw;

// do not modify the implementation of the Print function
void Print(const SortedDynamicArray * nums) {
  for ( int i = 0; i < nums->size; ++i )
    cout << setw(4) << nums->values[i];
  cout << endl;
}
void Merge(SortedDynamicArray * const array1, const SortedDynamicArray * const array2) {
  int totSize = array1->size + array2->size;    // total size of two arrays
  int *mergedArray = new int[totSize];    // create array with total size
                                          // and assign a pointer to the first
                                          // element
  int i;    // i is the index for the first array
  int j;    // j is the index for the second array
  int k;    // k is the index for the merged array
  for (i = 0, j = 0, k = 0; i < array1->size && j < array2->size; k++) {
    if (array1->values[i] < array2->values[j]) {    // if the value of index i in array 1
                                                    // is less than the value of index j
                                                    // in array 2
      mergedArray[k] = array1->values[i];           // set index k of the merged array
                                                    // to array 1 index i's value
      i++;                                          // increment i
    } else if (array2->values[j] < array1->values[i]) {   // if value of index j in array 2
                                                          // is less than value of index i in
                                                          // array 1
      mergedArray[k] = array2->values[j];                 // set index k of the merged array
                                                          // to array 2 index j's value
      j++;                                                // increment j
    } else {                                // if the value of the indicies of the two arrays
                                            // is the same
      mergedArray[k] = array1->values[i];   // set index k of the merged array to index i of
                                            // array 1 (could be array 2 index j) they are the same
      i++;    // increment i
      j++;    // increment j
      }
  }
  while (i < array1->size) {              // if there are leftover values in array 1
    mergedArray[k] = array1->values[i];   // add them to the merged array
    i++;      // increment i
    k++;      // increment k
  }
  while (j < array2->size) {              // if there are leftover values in array 2
    mergedArray[k] = array2->values[j];   // add them to the merged array
    j++;      // increment j
    k++;      // increment k
  }

  int finSize = 1;  // final array size
                    // starting at 1 because check if equal to zero
                    // and first element could be zero so we just include
                    // the first element automatically
  for (int i = 1; i < totSize; i++) {
    if (mergedArray[i] != 0) {  // if the value of the i in merged array is not zero (null)
      finSize++;               // increase the final arrays size
    }
  }
  delete[] array1->values;    // remove values of array 1
  array1->size = finSize;     // set size of array 1 to the final size
  for (int i = 0; i < array1->size; i++) {
    array1->values[i] = mergedArray[i];  // set values of array 1 to the merged array
  }

  // i tried to update the pointer to have it point
  // to the values in the merged array rather than have
  // the values of array1 updated, but im getting some type of
  // overflow issue, when i run the code in my macOS terminal
  // im getting correct values when updating the pointer
  // the code that updates the pointer is below, but only works
  // inside of my mac terminal and not linux. Im not sure what exactly is causing
  // this issue because i freed all unused dynamically allocated memory.
  // Im assuming its some type of issue relating to overflow or
  // pointing to un-allocated memory.
  // array1->values = mergedArray; //(only works on macOS)

  delete[] mergedArray;       // free dynamically allocated memory
}

