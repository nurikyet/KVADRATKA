#ifndef MEASUREMENTERROR_H_INCLUDED
#define MEASUREMENTERROR_H_INCLUDED

// TODO: Is MeasurmentError.h a good name for this file?
//       It has the right idea, but not quiet there, I mean measurment error file
//       is not a measurment error, is it? It maybe contains functions that measure
//       accordingly to an error.  


/// This function helps to compare how close a number is to zero.
int IsZero(double d);

/// This function helps to determine how close the numbers are to each other.
int IsEqual(double x1, double x1ref);

/// Epsilon is the margin of error in calculations
const double epsilon = 0.0000001;
#endif // MEASUREMENTERROR_H_INCLUDED
