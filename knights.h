#ifndef KNIGHTS_H
#define KNIGHTS_H

#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cstdint>

// Do not add any extra #includes challenge

using std::pair;
using std::make_pair;
using std::vector;

using std::find;
  
typedef pair<int,int> Pair;
typedef vector<pair<int,int> > Path;

/** Helper function: adds two pairs of ints */
pair<int,int> operator+(const pair<int,int> & a, const pair<int,int> & b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

Path moves(Pair pair) { 
	
	std::vector<Pair > original = { Pair(pair.first + 1, pair.second - 2),
									Pair(pair.first + 2, pair.second - 1),
									Pair(pair.first + 2, pair.second + 1),
									Pair(pair.first + 1, pair.second + 2),
									Pair(pair.first - 1, pair.second + 2),
									Pair(pair.first - 2, pair.second + 1),
									Pair(pair.first - 2, pair.second - 1),
									Pair(pair.first - 1, pair.second - 2)};		
	
	return original;

}

Path legal_moves(int dim, Path pathSoFar, pair<int,int> pos) {
	
	vector<Pair > movesAvail = moves(pos);
	
	vector<Pair > legalPath;
	
	copy_if(movesAvail.begin(), movesAvail.end(),
	back_inserter(legalPath),
	[dim, pathSoFar](const Pair x) {	
		if (x.first < dim && x.second < dim && x.first >= 0 && x.second >= 0) {
			if (find(pathSoFar.begin(), pathSoFar.end(), x) == pathSoFar.end()) return true; 
			else return false;		
		}
		else return false;	
	});
	
	return legalPath;

}

pair<Path,bool> first_tour(int dim, Path pathSoFar) {
	
	if (dim == 4) {
		
		Path emptyPath = {};
		return {emptyPath,false};
		
	}
	
	else if (pathSoFar.size() == dim*dim) return {pathSoFar,true};
	
	else {

		Path legalMoves = legal_moves(dim, pathSoFar, pathSoFar.back());
		Path emptyPath = {};
		
		if (legalMoves.empty()) return {emptyPath,false};
			
		else {
			
			vector<pair<Path,bool> > results(legalMoves.size());
			
			for (int i = 0; i < legalMoves.size(); i++) {
				
				pathSoFar.push_back(legalMoves.at(i));
				pair<Path,bool> result = first_tour(dim, pathSoFar);
				
				if (result.second == true) return result;
				
				else {
					
					if (i == legalMoves.size()-1) {
						
						Path emptyPath = {};
						return {emptyPath,false};
						
					}
				}	 		
			}
			
		}
		
	}
}		

// Do not edit below this line

#endif