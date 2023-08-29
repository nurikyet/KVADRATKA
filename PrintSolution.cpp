#include<stdio.h>
#include<assert.h>

#include "PrintSolution.h"
#include "interactive_equation_solver.h"
#include "FunnyColour.h"

int PrintSolution(int nRoots, double x1, double x2)
  {
  switch (nRoots)
    {
      case ZERO_ROOT:  printf("No roots\n");
                       break;
      case ONE_ROOT:   printf("x = %lg\n", x1);
                       break;
      case TWO_ROOTS:  printf("x1 = %lg, x2 = %lg\n", x1, x2);
                       break;
      case INF_ROOTS:  printf(COLOUR_MAGENTA("Infinite number of roots\n"));
                       break;
      default: printf("main():ERROR: nRoots = %d\n", nRoots);
               assert(false); return 1;


    }

  return 0;

  }


int Greetings()
  {

  printf(COLOUR_RED("Quadratic equation version - 15555\n" "Type equation a*x**2+b*x+c = 0\n"));

  printf(COLOUR_GREEN("Do you want to test the program?\n"));

  printf(COLOUR_BLUE("If you want, enter 0, otherwise enter another character\n"));

  return 0;

  }
