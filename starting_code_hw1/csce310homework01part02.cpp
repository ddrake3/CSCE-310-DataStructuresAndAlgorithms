/**
  *Author:Derek Drake
  *Date: 1/27/20
  *CSCE-310
  *
  * This program contains the function implementation for csce310h0mework01part02.h
  *
  */

#include "csce310homework01part02.h"
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void printPermutations( string word){

  int length = word.length();
  int factorial = 1;
  for(int i = 1; i <= length; i++){
    factorial *= i;
  }


    // separate case if permutations == 1
    if(factorial == 1){
      cout << word << endl;
    }
    // separate case if permuatations == 2
    else if(factorial == 2){
      cout << word << endl;
      swap(word[0], word[1]);
      cout << word << endl;
    }
  return;
}
