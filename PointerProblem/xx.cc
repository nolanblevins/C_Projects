// Copyright 2023 bhipp
// pointers and dynamic memory allocation
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int main() {
  // read in major grades for each class we're taking this semester
  int num_classes;
  int * grades_in_class;
  double * * the_grades;
  do {
    cout << "How many classes are you taking? ";
    cin >> num_classes;
  } while ( num_classes <= 0 );
  the_grades = new double * [num_classes];  // the addresses of the grades
  grades_in_class = new int[num_classes];   // the num of grades for each
                                            // class
  // check that the allocation was successful
  if ( the_grades == nullptr || grades_in_class == nullptr ) {
    cout << "Trouble!!!" << endl;
    return 0;
  }
  for ( int i = 0; i < num_classes; ++i ) {
    do {
      cout << "How many major grades are there in class " << i + 1 << "? ";
      cin >> grades_in_class[i];
    } while ( grades_in_class[i] <= 0 );
    the_grades[i] = new double[ grades_in_class[i] ];
    if ( the_grades[i] == nullptr ) {
      cout << "Couldn't reserve " << grades_in_class[i] << " spots" << endl;
      return 0;
    }
    cout << "Enter the " << grades_in_class[i] << " grade values: ";
    for ( int j = 0; j < grades_in_class[i]; ++j )
      cin >> the_grades[i][j];
  }
  for ( int the_class = 0; the_class < num_classes; ++the_class ) {
    cout << "Grades for class " << the_class << ": ";
    for ( int grade = 0; grade < grades_in_class[the_class]; ++grade )
      cout << the_grades[the_class][grade] << " ";
    cout << endl;
  }

  // housecleaning to free up all of the dynamically allocated memory
  for ( int i = 0; i < num_classes; ++i )
    delete [] the_grades[i];
  delete [] the_grades;
  delete [] grades_in_class;

  return 0;
}

/*
int main() {
  int size;
  char * ptr;
  do {
    cout << "How many characters do you need? ";
    cin >> size;
  } while ( size <= 0 );
  ptr = new char[size + 1];  // dynamically allocates a block of size 
                             // characters the address is held in ptr
  if ( ptr == nullptr ) {
    cout << "Couldn't allocated the requested memory.";
    return 0;
  }
  cout << "Enter your " << size << " characters ";
  for ( int i = 0; i < size; ++i )
    cin >> ptr[i];  // reads one character at a time
  ptr[size] = '\0'; // puts a null character on the end of the array
  cout << ptr << endl;
  
  // whenever we're finished with the dynamically allocated memory, we free
  // it up with delete
  delete [] ptr;  // frees up the dynamically allocated memory ptr points to
                  // Not the variable ptr (which still exists)

  cout << "ptr still exists! ";
  return 0;
}
*/
/*
#include<fstream>
using std::ifstream;
*/
/* char *[]  OR  char * *  */
// first argument is the number of elements of args
// args holds the name of the executable and the additional
// cstrings following that executable
/*int main ( int numargs, char * args []  ) {
  cout << "numargs = " << numargs << endl;
  for ( int i = 0; i < numargs; ++i )
    cout << args[i] << endl;
  ifstream inobject(args[1]);
  char next;
  inobject >> next;
  while ( inobject.good() ) {
    cout << next << endl;
    inobject >> next;
  }
  inobject.close();
  return 0;
}
*/

/*
int main () {
  const int kRows = 4;
  // const int kCols = 12;
  // note: this reserves 48 spots, but not all of them are needed
  // we'll modify this to use pointers on Tuesday!
  // const char words[kRows][kCols] = { "you", "me", "another", 
  // "yet another" };
  const char * words[kRows] = { "you", "me", "another", "yet another" };
  for ( int i = 0; i < kRows; ++i ) {
    cout << words[i] << endl;
  }
  return 0;
}
*/