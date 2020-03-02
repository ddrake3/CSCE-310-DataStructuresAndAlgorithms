#include <vector>
#include "csce310homework02part02.h"
#include <cmath>
#include <iostream>

using namespace std;

/**
   * Author: Derek Drake
   * Date: 2/24/20
   *
   * sumToNis an adaptation of Exercise 6.1.7 on page 206.sumToNwill take two arguments:  a vector
   * of double values and another double value.  The function will returntrueif two unique values in
   * the array sum to the quantitiy of the second input value.  It may be assumed that the vector will
   * be in ascending order.
   *
   **/

bool sumToN( vector<double> numbers , double sum ){

  // approch: add every single combination of numbers
  // and check if that adds up to the given sum

  double stored = 0;
  double current = 0;
  double tempSum = 0;
  bool flag = false;

  for(int i = 0; i < numbers.size(); i++){
    stored = numbers.at(i);
    for(int j = 0; j < numbers.size(); j++){

      current = numbers.at(j);

      tempSum = stored + current;

        if(tempSum == sum){
          flag = true;
        }

        tempSum = 0;
    }
  }

  return flag;
}
