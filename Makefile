TestCollatz: collatz.h TestCollatz.cpp
	g++ -Wall -g -std=c++11 -o TestCollatz TestCollatz.cpp

TestCollatzParallel: collatz.h TestCollatz.cpp
	g++ -fopenmp -Wall -g -std=c++11 -o TestCollatzParallel TestCollatz.cpp

	
TestTrade: Trade.h TestTrade.cpp
	g++ -Wall -g -std=c++11 -o TestTrade TestTrade.cpp

TestKnights: knights.h TestKnights.cpp
	g++ -O -Wall -g -std=c++11 -o TestKnights TestKnights.cpp


all: TestCollatz TestTrade TestKnights
