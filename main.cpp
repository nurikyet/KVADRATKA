#include<stdio.h>
#include<math.h>
#include<assert.h>

#include "TXLib.h"
#include "interactive_equation_solver.h"
#include "PrintSolution.h"
#include "Tests.h"
#include "TestsFromFile.h"
#include "FunnyColour.h"

int main()
  {

  Greetings();

  int choice = 0;

  scanf("%d", &choice);

  if (choice == 0)
    {
    int nOKK = Testing();
    printf("%d\n", nOKK);
    }

  printf(COLOUR_YELLOW(("Enter odds a, b, c\n"));

  double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

  if (scanf("%lg%lg%lg", &a, &b, &c) != 3)
    {
    printf(COLOUR_RED("Incorrect input\n"));
    }

  else
    {
    int nRoots = SolveSquare(a, b, c, &x1, &x2);
    PrintSolution(nRoots, x1, x2);
    }
  }




