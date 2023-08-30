#include <stdio.h>
#include<math.h> // TODO: style

const double epsilon = 0.0000001;

int IsZero(double d)
  {
  return (fabs(d - 0)< epsilon); // TODO: Pretty sure isZero can be expressed through isEqual
  } // TODO:           ^ inconsistent spacing

int IsEqual(double x1, double x1ref)
  {
  return fabs(x1-x1ref) > epsilon;
  }
