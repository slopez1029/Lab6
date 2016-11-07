#	Author: John Gibbons
#	Date: 2016.10.26


#Add needed Test.o
prog: main.o testsuite.o
	g++ -g -Wall -std=c++11 main.o LinkedListOfInts.o testsuite.o -o prog


main.o: main.cpp 
	g++ -g -Wall -std=c++11 -c main.cpp

testsuite.o: testsuite.h testsuite.cpp
	g++ -g -Wall -std=c++11 -c testsuite.cpp

#Add needed Test.o recipe and compiler command


#DON'T delete LinkedList.o!
clean:
	rm main.o *.*~ prog
