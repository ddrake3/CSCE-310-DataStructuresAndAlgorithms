#include "csce310homework02part01.h"
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>

using namespace std;

/**
   * Author: Derek Drake
   * Date: 2/24/20
   *
   * overlappingIntervalsis an adaptation of Exercise 6.1.8 on page 207. overlappingIntervals
   * is  a  function  that  should  take  two  (2)  vectors  of n double  values  each  as  input  and  return  the
   * maximum  number  of  open  intervals  that  overlap  at  a  single  point.   The  first  vector  defines  the
   * starting point of each interval and the second vector defines the ending point of each interval.  It
   * may be assumed that the first vector will be in ascending order.
   *
   **/

int overlappingIntervals( vector<double> start , vector<double> end ){

    // approach: get an interval then iterate through all other possible
    // intervals checking if they overlap with the current stored interval
    sort(end.begin(), end.end());

    double stored[3];
    double current[3];
    int count = 0;

    stored[0] = start.at(0);
    stored[1] = end.at(0);

    for(int i = 1; i < start.size(); i++){


      current[0] = start.at(i);
      current[1] = end.at(i);

        if(stored[0] < current[0] && stored[1] < current[1]){
          count++;
        }
        if(stored[0] > current[0] && stored[1] < current[1]){
          count++;
        }
        if(stored[0] < current[0] && stored[1] > current[1]){
          count++;
        }
        if(stored[0] > current[0] && stored[1] > current[1]){
          count++;
        }
      
    }
    return count;
  }
