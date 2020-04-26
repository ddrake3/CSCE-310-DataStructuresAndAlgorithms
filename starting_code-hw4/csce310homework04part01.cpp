#include "csce310homework04part01.h"
#include <cmath>
#include <climits>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

/**
   * Author: Derek Drake
   * Date: 4/8/2020
   *
   * tallestTower is a function that, given a vector of n block weights and a vector
   * of n block carrying capacities, will return the
   * greatest number of blocks that can be stacked on top of each other.  It can be
   * assumed that a block's carrying capacity will at least be equal to its weight.
   * (The block can support its own weight.)
   *
   **/

int tallestTower( vector<int> weight , vector<int> capacity ){


  // get the inital block with the highest capacity
  // most of the time its the 1st one, but not always.
  int maxCapacity = capacity.at(0) - weight.at(0);
  for(int i = 1; i < weight.size(); i++){
    if((capacity.at(i) - weight.at(i)) > maxCapacity){
      maxCapacity = capacity.at(i) - weight.at(i);
    }
  }

  int count = 1;
  int i = 0;

  sort(weight.begin(), weight.end());

  // get the max amount for capacity
  while(maxCapacity >= 0){
    if(i < weight.size() && (maxCapacity - weight.at(i)) >= 0){
      maxCapacity = maxCapacity - weight.at(i);
      i++;
      count++;
    }
    else{
      break;
    }

  }

  return count;
}
