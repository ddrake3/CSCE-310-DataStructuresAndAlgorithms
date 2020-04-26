#include <vector>
#include <cmath>
#include <iostream>
#include "csce310homework04part03.h"

using namespace std;

/**
   * Author: Derek Drake
   * Date: 4/8/20
   *
   * A race is about to be run.  Two (2) evenly matched runners take their marks.  However,
   * the course is not flat.  There are n distinct segments to the course, each slightly uphill
   * or downhill.  There are even variations between the two (2) lanes.  Each runner must complete
   * first segment in their assigned lane, but they are free to change lanes (as many times as they want)
   * afterwards.  However changing lanes comes with a small penatly (different for each transition area between segments).
   * There is no penatly for staying in the same lane from segment i to Segment i + 1.  The first runner to arrive at the
   * course is given a choice of starting lane.  That runner would like to choose the lane that minimizes their time to complete
   * the race.
   *
   * footRace is a function that, given two (2) vectors of n values each (seconds required to complete each of n segments
   * of a track with two lanes), and two (2) vectors of n - 1values each (secons required to change from Lane 1 to Lane 2,
   * or Lane2 to Lane 1, after completing segment s), will return the shortest time required to complete the race.
   **/

int footRace( vector<int> segments01 , vector<int> segments02 , vector<int> transitions01to02 , vector<int> transitions02to01 ){

  return 0;
}
