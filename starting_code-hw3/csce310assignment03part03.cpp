#include <vector>
#include <math.h>
#include "csce310assignment03part03.h"

using namespace std;

/**
   * Author: Derek Drake
   * Date: 3/15/20
   *
   * hornersRule (15 Points Extra Credit, or Honors Contract)
   * hornersRule is a function that should take a vector of integers (coefficients of a polynomial) and
   * another integer as input and return the value of polynomial, evaluated at that particular integer.
   *
   **/

int hornerRule( vector<int> xs , int ys ){
  // strategy: continuously get and remove the last element in the vector
  // we know that the last value doesn't have an exponent, after we just
  // iterate a variable as the exponent and take our given number to that
  // power

  int sum = xs.back();
  xs.pop_back();

  int exponent = 1;
  while(!xs.empty()){
    sum += (xs.back() * pow(ys, exponent));
    xs.pop_back();
    exponent++;
  }
  return sum;
}
