/**
  *Author:Derek Drake
  *Date: 1/27/20
  *CSCE-310
  *
  * This program contains the function implementation for csce310homework01part01
  *
  */


#include "csce310homework01part01.h"
#include "boost/lexical_cast.hpp"
#include <string>

using namespace std;

unsigned long long int productOfDigits( unsigned long long int digits ){

  //convert digits into a string
  string digitString = boost::lexical_cast<string>(digits);

  // now that we have converted the int
  // take each character of the string,
  // convert it back into an int, then
  // multiply it to our the toReturn variable

  unsigned long long int toReturn = 1;
  for(string::size_type i = 0; i < digitString.size(); i++){
    int temp = digitString[i] - 48;
    toReturn *= temp;
  }

  return toReturn;
}
