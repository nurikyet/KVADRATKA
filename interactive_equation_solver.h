#ifndef SOLVESQUARE_H_INCLUDED
#define SOLVESQUARE_H_INCLUDED


/**
* @brief         Quadratic Equation with Nonzero Leading Coefficient
* @param[in] a   The leading coefficient (at x^2 ) in the quadratic equation
* @param[in] b   Coefficient at x in the quadratic equation
* @param[in] c   Free term in quadratic equation
* @param[out] x1 The first root of the quadratic equation
* @param[out] x2 The second root of the quadratic equation
*/
///
int SolveSquare (double a, double b, double c, double* x1, double* x2);

/**
* @brief         Linear Equation
* @param[in] b   Linear Equation Coefficient (at x)
* @param[in] c   Free term in a linear equation
* @param[out] x  Linear Equation Root
*/
int SolveLinear(double a, double b, double c, double* x1);

/// Possible options for the number of roots
enum roots
{
    INF_ROOTS = -1,
    ZERO_ROOT = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
};

#endif // SOLVESQUARE_H_INCLUDED
