#ifndef TRADE_H
#define TRADE_H

#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdint>

// Do not add any extra #includes challenge

	// needs to be a template function

int bestProfit(std::iterator itrBeginIn, std::iterator itrEndIn){	
	
	int const itrBegin = itrBeginIn;
	int const itrEnd = itrEndIn;
	
	std::vector<int> listOfLists(itrEnd) ; // vector with bound number of ints.
	//std::iota (std::begin(listOfLists), std::end(listOfLists), itrBegin);
	
	std::vector<int> innerList(itrEnd) ; // vector with bound number of ints.
	//std::iota (std::begin(innerList), std::end(innerList), itrBegin);
	
	transform(itrBegin, itrEnd-2,
			listOfLists.begin(),
			[itrBegin, itrEnd, innerList](const int firstItem) {
				
					transform(itrBegin + 1, itrEnd-1,
						innerList.begin(),
						[firstItem, innerList](const int secondItem) {
							return (secondItem - firstItem);
						});	
				
			});
			
	// and then listOfLists should contain lists of profits?		
			
	return itrBeginIn;

}


// Don't write any code below this line

#endif