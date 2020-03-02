#include <vector>
#include "csce310homework02part03.h"
#include <cmath>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/**
   * Author: Derek Drake
   * Date: 2/24/20
   *
   * Given an array ofnintegers, return the average number of comparisons that would be required to
   * successfully find an element in the array using binary search.  You may assume that the values in
   * the array will be provided in ascending order.  When more than one element can be chosen in the
   * search, choose the element with a smaller value.
   *
   **/

int binarySearch(vector<int> numbers, int toSearch){
  sort(numbers.begin(), numbers.end());

  int left = 0;
  int right = numbers.size() - 1;

  int count = 0;

  while (left <= right){
    int middle = left + (right - left)/2;

    if (numbers.at(middle) == toSearch){
        count++;
        return count;
    }
    if (numbers.at(middle) < toSearch){
        left = middle + 1;
        count++;
    }
    else{
         right = middle - 1;
         count++;
      }
  }

  return count;
}

double averageComparisons( vector<int> numbers ){
    //approach: use binary search to get the number of comparisons for
    // each number in the vector, sum all those comparisons, and finally
    // divide by the number of elements in the vector

    double toReturn = 0;
    double sum = 0;

    for(int i = 0; i < numbers.size(); i++){
      int temp = numbers.at(i);
      sum += binarySearch(numbers, temp);
    }

    int size = numbers.size();

    return sum / (double) size;
 }
