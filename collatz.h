#ifndef COLLATZ_H
#define COLLATZ_H

#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdint>
#include "counting_iterator.h"
#include "transformreduce.h"

// Do not add any extra #includes challenge

	
int innerFunc(uint64_t n, int count){

    if (n == 1) {
	  return count;
	}
    
    else if (n % 2 == 0) { 
      uint64_t r = n / 2;
	  int countUp = count + 1;
	  
	  if (r == 1) return countUp;
	
	  else
      innerFunc(r, countUp);
	  
    }
    
    else {
      uint64_t r = (3 * n + 1);
      int countUp = count + 1;	  
	  if (r == 1) return countUp;
	  else
      innerFunc(r, countUp);
	  
    }	
}

uint64_t collatz(uint64_t n) {
    innerFunc(n, 1);
}


//Complete the collatz-bound function below. It should
//     calculate how many steps are needed for each number 
//     from 1 up to a bound and then calculate the maximum number of
//     steps and the corresponding number that needs that many 
//     steps. Again, expect bounds in the range of 1
//     up to 1 Million. The first component of the pair is
//     the maximum number of steps and the second is the 
//     corresponding number.


std::pair<uint64_t, uint64_t> collatz_max(uint64_t bound) {
  
	//perform collatz on each thing for each number from 1 up to bound
	//then calculate the maximum result of this and the corresponding number to it, return as pair.
	//The first component of the pair is the maximum number of steps and the second is the corresponding number
	
	std::vector<int> vectorToBound(bound) ; 
	std::iota (std::begin(vectorToBound), std::end(vectorToBound), 1); 

	std::vector<int> listOfCollatz(vectorToBound.size());
	
	transform(
		vectorToBound.begin(), vectorToBound.end(),
		listOfCollatz.begin(),
		[](const uint64_t n) {
			return collatz(n);
		});
		
	//listOfCollatz should now be a vector containing all collatzes.
	//-we need to find the maximum one, and its iterator
	
	//first element is the length of the longest collatz sequence found,
	uint64_t maxLength = *std::max_element(listOfCollatz.begin(),listOfCollatz.end());	
	//and the second element is the number that had that collatz sequence.
	
	uint64_t pos = std::find(listOfCollatz.begin(), listOfCollatz.end(), maxLength) - listOfCollatz.begin();
	uint64_t numberForMax = pos + 1;
	
	return {maxLength, numberForMax};

}

// Do not edit anything below this line

#endif