#include<stdio.h >

#include"TXLib.h"
#include"interactive_equation_solver.h"
#include"MeasurementError.h"
#include "TestsFromFile.h"

const int NUMBEROFTESTS = 7;
const int MAX_LEN = 140;

struct TestData
  {
  double a; double b; double c; double x1ref; double x2ref;
  int nRootsref;
  char name[MAX_LEN];
  };

int TestOne(double a, double b, double c, double x1ref, double x2ref, int nRootsref)
  {
  double x1 = 0, x2 = 0;
  int nRoots = SolveSquare(a, b, c, &x1, &x2);
  if ( IsEqual(x1, x1ref) or IsEqual(x2, x2ref) or nRoots != nRootsref)
    {
    printf("FAILED: x1 = %lg, x2 = %lg, nRoots = %d, expected: x1ref = %lg, x2ref = %lg, nRootsref = %d\n", x1, x2, nRoots, x1ref, x2ref, nRootsref);   /// Test error output
    return 0;
    }
  else
    {
    printf("Test OK\n");
    return 1;
    }
  }

int Testing()
  {

  FILE *datafile = fopen("datafile.txt", "r");

  int nOk = 0;

  for (int i; i<NUMBEROFTESTS; i++)
    {
    TestData data1 = {0, 0, 0, 0, 0, 0};

    fscanf(datafile, "%lg%lg%lg%lg%lg%d", &data1.a, &data1.b, &data1.c, &data1.x1ref, &data1.x2ref, &data1.nRootsref);

    nOk += TestOne(data1.a, data1.b, data1.c, data1.x1ref, data1.x2ref, data1.nRootsref);

    fgets(data1.name, MAX_LEN, datafile);

    printf("%lg%lg%lg%lg%lg%d%s", data1.a, data1.b, data1.c, data1.x1ref, data1.x2ref, data1.nRootsref, data1.name);

    }

  fclose(datafile);

  return nOk;
  }
