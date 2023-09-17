// Copyright nblevins 2023

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using std::cin;   // used to take in standard input
using std::cout;  // used for standard output
using std::endl;  // used for end line


double Distance(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0) {
  double distance = 0;                        // function uses formula
  distance = sqrt(((x2 - x1) * (x2 - x1))+    // for finding the distance
                  ((y2 - y1) * (y2 - y1)));   // between two cordinates
                  return distance;
}

int OnCircle(double xCenter, double yCenter, double radius, double xPoint, double yPoint) {
  double distance = 0;
  distance = sqrt(((xPoint - xCenter) * (xPoint - xCenter))+    // Using formula to find the distance
                  ((yPoint - yCenter) * (yPoint - yCenter)));   // from the center of the circle to the point
  if (distance < radius) {          // if the distance is less than the radius
    return -1;                      // the point is inside and will return -1.
  } else if (distance == radius) {  // if the distance is equal to the radius
    return 0;                       // it is on the circle and will return 0
  } else {                          // if the distance is greater than the radius
    return 1;                       // it is outside the circle and will return 1
  }
}

bool OnLine(double x1, double y1, double x2, double y2, double x3, double y3) {
  double crossProduct = 0;
  crossProduct = (((x2 - x1) * (y3 - y1))-    // using the cross product formula
                  ((y2 - y1) * (x3 - x1)));   // to determine if all points fall
  if (crossProduct == 0) {                    // on the same line, if they do the
    return true;                              // formula will equal zero and return
  } else {                                    // true.
    return false;
  }
}

