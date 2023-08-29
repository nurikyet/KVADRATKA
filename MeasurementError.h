#ifndef MEASUREMENTERROR_H_INCLUDED
#define MEASUREMENTERROR_H_INCLUDED

/// This function helps to compare how close a number is to zero.
int IsZero(double d);

/// This function helps to determine how close the numbers are to each other.
int IsEqual(double x1, double x1ref);

/// Epsilon is the margin of error in calculations
const double epsilon = 0.0000001;
#endif // MEASUREMENTERROR_H_INCLUDED
