
#ifndef _BENCHMARK_H_
#define _BENCHMARK_H_

#include <iostream>
#include <chrono> //Timing library

// Be sure to include your own header files!
#include <vector>
// #include <list>
//#include "..\..\ListIterator\Iterator.h"
#include "..\..\ListIterator\list.h"
//#include "Vector.h"

// Replace the STL versions of list and vector with the implementations you wish to test.
using cs273::list;
using std::vector;

/*
 * The benchmark class is designed to test two implementations of containers    
 * This code is expressly designed to work with List and Vector containers
*/
class Benchmark {
private:
    // Build a vector of len sequential integers
    // Start at 0, build up to len
    vector<int> generateSequentialIntVector(int len);
    // Build a vector of len sequential integers
    // Start at 0, build up to len
    list<int> generateSequentialIntList(int len);

public:
    // Each test method will run a number of times equal to the iterations parameter

    /*
     *  Test parameters
     *  Input:
     *  targetInt     - search value to find in container
     *  deletionCount - Number of elements to remove in test 
     *  vectorLength  - determines length of container to be tested
     *  iterations    - determine number of runs to perform
     * 
     *  Return values are average time (in seconds) of operation
     *      based on number of iterations and recorded chrono time 
     */ 
     
     
     /*
     *  Test functions for Vectors
     */

    // Search a vector of insertionCount consecutive integers for targetInt
    double TestVectorFindInt(int targetInt, int vectorLength, int iterations);
    
    // Access the targetNdx'th item in a vector of insertionCount consecutive integers for targetInt
    double TestVectorAccessInt(int targetNdx, int vectorLength, int iterations);
    
    // Since the STL vector class relies on iterators for its insert method, this 
    // test function will use assign, since it relies on integer indices
    double TestVectorInsertAtHead(int vectorLength, int iterations);
    
    // Push targetInt onto the back of a vector of insertionCount consecutive integers
    double TestVectorInsertAtTail(int vectorLength, int iterations); 
    
    // Push targetInt onto the back of a vector of insertionCount consecutive integers
    double TestVectorInsertAtMid(int vectorLength, int iterations); 
    
    // Pop the first item off a vector of insertionCount consecutive integers
    double TestVectorRemoveFromHead(int deletionCount, int vectorLength, int iterations);
    
    // Pop the last item off a vector of insertionCount consecutive integers
    double TestVectorRemoveFromTail(int deletionCount, int vectorLength, int iterations);

    // Pop the middle item off a vector of insertionCount consecutive integers
    double TestVectorRemoveFromMid(int deletionCount, int vectorLength, int iterations);

    // Uses repeated cycles of pops and pushes to test how the vector implementation uses memory
    double TestVectorMemoryUse(int vectorLength, int iterations);

    /*
     *  Test functions for lists
     */

    // Search a list of insertionCount consecutive integers for targetInt
    double TestListFindInt(int targetInt, int listLength, int iterations);
    
    // Access the targetNdx'th item in a list of insertionCount consecutive integers for targetInt
    double TestListAccessInt(int targetNdx, int listLength, int iterations);
    
    // Since the STL list class relies on iterators for its insert method, this 
    // test function will use assign, since it relies on integer indices
    double TestListInsertAtHead(int listLength, int iterations);
    
    // Push targetInt onto the back of a list of insertionCount consecutive integers
    double TestListInsertAtTail(int listLength, int iterations); 
    
    // Push targetInt onto the back of a list of insertionCount consecutive integers
    double TestListInsertAtMid(int listLength, int iterations); 
    
    // Pop the first item off a list of insertionCount consecutive integers
    double TestListRemoveFromHead(int deletionCount, int listLength, int iterations);
    
    // Pop the last item off a list of insertionCount consecutive integers
    double TestListRemoveFromTail(int deletionCount, int listLength, int iterations);

    // Pop the middle item off a list of insertionCount consecutive integers
    double TestListRemoveFromMid(int deletionCount, int listLength, int iterations);

    // Uses repeated cycles of pops and pushes to test how the list implementation uses memory
    double TestListMemoryUse(int listLength, int iterations);
};

#endif