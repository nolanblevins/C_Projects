// Copyright nblevins 2023

#ifndef PROBLEM2FUNCTIONS_H_
#define PROBLEM2FUNCTIONS_H_


// Fuction will take 4 double arguments for two seperate coordinates
// and will return the distance between those points.
// precondition: at least two values are entered or distance will be 0
// postcondition: function will return the distance betwen two points
//                using formula
double Distance(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0);


// Function will take 5 doubles, the first two being the x and y coordinates
// of the center of the circle, the next will be the radius of the circle and
// the last two will be the point.
// precondition: the function will be given 5 double values.
//               the radius must be a positive value.
// postcondition: the function will return negative 1 if the point
//                is inside the circle, 0 if on the circle and 1 if
//                outside the circle.
int OnCircle(double xCenter, double yCenter, double radius, double xPoint, double yPoint);


// Function will take 6 double corresponding to 3 pairs of coordinates 
// and determine if all of these coordinates fall on the same linear function.
// precondition: all inputs are doubles.
// postcondition: function will return true if the three pairs fall on the
//                same line and false if they do not.
bool OnLine(double x1, double y1, double x2, double y2, double x3, double y3);


#endif /* PROBLEM2FUNCTIONS_H_ */
