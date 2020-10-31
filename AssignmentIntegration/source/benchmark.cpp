#include "benchmark.h"
#include <iostream>

vector<int> Benchmark::generateSequentialIntVector(int len) {
    vector<int> sequentialInts = vector<int>();
    for (int ndx =0 ; ndx < len; ndx++) {
        sequentialInts.push_back(ndx);
    }
    return sequentialInts;
}

list<int> Benchmark::generateSequentialIntList(int len) {
    list<int> sequentialInts = list<int>();
    for (int ndx =0 ; ndx < len; ndx++) {
        sequentialInts.push_back(ndx);
    }
    return sequentialInts;
}

double Benchmark::TestVectorFindInt(int targetInt, int vectorLength, int iterations) {
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    //Build a vector with insertionCount elements
    vector<int> testVector = generateSequentialIntVector(vectorLength);

    // Using an index to iterate over the vector's contents.
    // Should probably be replaced with an iterator, but this way we can test the [] operator

    // Perform multiple test runs 
    for (int foo = 0; foo < iterations; foo++) {
        // Start timing
        start = std::chrono::system_clock::now();
        int bar = 0;
        while(testVector[bar] != targetInt) {
            //std::cout << ndx << std::endl;
            bar++;
        }
        // Stop timing
        end = std::chrono::system_clock::now();
        //Get the time discrepancy
        std::chrono::duration<double> elapsed_seconds = end - start;
        // Convert the time discrepancy to a double number of seconds and add it to the total
        totalTime += elapsed_seconds.count();
    }
    // Calculate the average time
    averageTime = totalTime / iterations;
    return averageTime;
}

double Benchmark::TestVectorAccessInt(int targetNdx, int vectorLength, int iterations) {
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    //Build a vector with insertionCount elements
    vector<int> testVector = generateSequentialIntVector(vectorLength);

    // Perform multiple test runs 
    for (int ndx = 0; ndx < iterations; ndx ++) {
        // Start timing
        start = std::chrono::system_clock::now();
        int placeholder = testVector[targetNdx];
        // Stop timing
        end = std::chrono::system_clock::now(); 
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalTime += elapsed_seconds.count();
    }
    averageTime = totalTime / iterations;
    return averageTime;
}

double Benchmark::TestVectorInsertAtHead(int vectorLength, int iterations){
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    //Build a vector to insert into
    vector<int> testVector;
    // Get an iterator pointing at the first element of testVector
    std::vector<int>::iterator front = testVector.begin();

    for (int foo = 0; foo < iterations; foo ++) {
        // Clear and reallocate testVector
        vector<int>().swap(testVector);

        // HEADS UP!
        //If you don't have iterators in your vector, you can modify this!
        front = testVector.begin();

        // Start timing the operation 
        start = std::chrono::system_clock::now();
        for(int bar = 0; bar < vectorLength; bar++) {

            //HEADS UP!
            //If you don't have iterators in your vector, you can modify this to use your insert(0,bar)
            // Many, many inserts            
            front = testVector.insert(front, bar);
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalTime += elapsed_seconds.count();
    }
    // Calculate the average time taken
    averageTime = totalTime / iterations;
    return averageTime;
}

double Benchmark::TestVectorInsertAtMid(int vectorLength, int iterations){
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    //Build a vector to insert into
    vector<int> testVector;

    // HEADS UP!
    //You may have to change the following if you don't have vector iterators
    // Get an iterator pointing at the first element of testVector
    std::vector<int>::iterator mid = testVector.begin();

    for (int foo = 0; foo < iterations; foo ++) {
        // Clear and reallocate testVector
        vector<int>().swap(testVector);
        // Reset the pointer to the front of the vector
        mid = testVector.begin();

        // Start timing the operation 
        start = std::chrono::system_clock::now();
        for(int bar = 0; bar < vectorLength; bar++) {
            // HEADS UP!
            //You may have to change the following if you don't have vector iterators
            // I might suggest treating mid like an index
            // Many, many inserts
            mid = testVector.insert(mid, bar);
            // Every other time we insert, we want to move mid forward one 
            if (bar % 2 == 1) {
                mid++;
            }
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalTime += elapsed_seconds.count();
    }
    // Calculate the average time taken
    averageTime = totalTime / iterations;
    return averageTime;
}

double Benchmark::TestVectorInsertAtTail(int vectorLength, int iterations){
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    //Build a vector to insert into
    vector<int> testVector;

    for (int foo = 0; foo < iterations; foo ++) {
        //Clear out vector
        testVector = vector<int>();

        // Start timing the operation 
        start = std::chrono::system_clock::now();
        for(int bar = 0; bar < vectorLength; bar++) {
            // Many, many inserts
            testVector.push_back(bar);
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalTime += elapsed_seconds.count();
    }
    // Calculate the average time taken
    averageTime = totalTime / iterations;
    return averageTime;
}

double Benchmark::TestVectorRemoveFromHead(int deletionCount, int vectorLength, int iterations){
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    //Build a vector to remove from
    vector<int> testVector;
    // Get an iterator pointing at the first element of testVector
    std::vector<int>::iterator front = testVector.begin();

    for (int foo = 0; foo < iterations; foo ++) {
        // Clear and reallocate testVector
        testVector = generateSequentialIntVector(vectorLength);
        // Get an iterator pointing to the beginning of testVector  
        front = testVector.begin();

        // Start timing the operation 
        start = std::chrono::system_clock::now();
        for(int bar = 0; bar < deletionCount; bar++) {
            // HEADS UP!
            //You may have to change the following if you don't have vector iterators
            // I might suggest erase(0)
            // Many, many erasures
            front = testVector.erase(front);
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalTime += elapsed_seconds.count();
    }
    // Calculate the average time taken
    averageTime = totalTime / iterations;
    return averageTime;
}

double Benchmark::TestVectorRemoveFromMid(int deletionCount, int vectorLength, int iterations){
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    //Build a vector to insert into
    vector<int> testVector;
    // Get an iterator pointing at the first element of testVector
    std::vector<int>::iterator mid;

    for (int foo = 0; foo < iterations; foo ++) {
        // Clear and reallocate testVector
        testVector = generateSequentialIntVector(vectorLength);
        mid = testVector.begin();
        // Reset the pointer to the midpoint of the vector
        std::advance(mid, testVector.size() / 2);
        // Start timing the operation 
        start = std::chrono::system_clock::now();
        for(int bar = 0; bar < deletionCount; bar++) {
            // HEADS UP!
            //You may have to change the following if you don't have vector iterators
            // I might suggest treating mid like an index
            // Many, many deletions
            mid = testVector.erase(mid);
            // Every other time we insert, we want to move mid forward one 
            if (bar % 2 == 1) {
                mid--;
            }
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalTime += elapsed_seconds.count();
    }
    // Calculate the average time taken
    averageTime = totalTime / iterations;
    return averageTime;
}


double Benchmark::TestVectorRemoveFromTail(int deletionCount, int vectorLength, int iterations){
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    for (int foo = 0; foo < iterations; foo ++) {
        //Make a new vector to pull from
        vector<int> testVector = generateSequentialIntVector(vectorLength);

        // Start timing the operation 
        start = std::chrono::system_clock::now();
        for(int bar = 0; bar < deletionCount; bar++) {
            // Many, many deletions
            testVector.pop_back();
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalTime += elapsed_seconds.count();
    }
    // Calculate the average time taken
    averageTime = totalTime / iterations;
    return averageTime;
}

double Benchmark::TestVectorMemoryUse(int vectorLength, int iterations ) {
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalFirstTime = 0;
    double averageFirstTime = 0;
    double totalSecondTime = 0;
    double averageSecondTime = 0;

    for (int foo = 0; foo < iterations; foo ++) {
        //Build clean vector to insert into
        vector<int> testVector = vector<int>();

        // Start timing the operation 
        start = std::chrono::system_clock::now();
        //Fill the vector up
        for(int bar = 0; bar < vectorLength; bar++) {
            testVector.push_back(bar);
        }
        //Empty the vector
        for(int bar = 0; bar < vectorLength; bar++)
        {
            testVector.pop_back();
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalFirstTime += elapsed_seconds.count();

        // Start timing the operation 
        start = std::chrono::system_clock::now();
        //Fill the vector up... again.
        for(int bar = 0; bar < vectorLength; bar++) {
            testVector.push_back(bar);
        }
        //Empty the vector... again
        for(int bar = 0; bar < vectorLength; bar++)
        {
            testVector.pop_back();
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        elapsed_seconds = end - start; 
        totalSecondTime += elapsed_seconds.count();
    }
    // Compute the average of each run and return the difference.
    averageFirstTime = totalFirstTime / iterations;
    averageSecondTime = totalSecondTime / iterations;
    return averageFirstTime - averageSecondTime;
}

double Benchmark::TestListFindInt(int targetInt, int listLength, int iterations) {
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    //Build a list with insertionCount elements
    list<int> testList = generateSequentialIntList(listLength);
    list<int>::iterator it;

    // Perform multiple test runs 
    for (int foo = 0; foo < iterations; foo++) {
        //Reset Iterator
        it = testList.begin();
        // Start timing
        start = std::chrono::system_clock::now();
        while(*it != targetInt) {
            //std::cout << ndx << std::endl;
            it++;
        }
        // Stop timing
        end = std::chrono::system_clock::now();
        //Get the time discrepancy
        std::chrono::duration<double> elapsed_seconds = end - start;
        // Convert the time discrepancy to a double number of seconds and add it to the total
        totalTime += elapsed_seconds.count();
    }
    // Calculate the average time
    averageTime = totalTime / iterations;
    return averageTime;
}

double Benchmark::TestListAccessInt(int targetNdx, int listLength, int iterations) {
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    //Build a list with insertionCount elements
    list<int> testList = generateSequentialIntList(listLength);
    // Perform multiple test runs 
    for (int ndx = 0; ndx < iterations; ndx ++) {
        // Start timing
        start = std::chrono::system_clock::now();
        list<int>::iterator it = testList.begin();
        for (int bar = 0; bar < targetNdx; bar++) {
            it++;
        }
        int placeholder = *it;
        // Stop timing
        end = std::chrono::system_clock::now(); 
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalTime += elapsed_seconds.count();
    }
    averageTime = totalTime / iterations;
    return averageTime;
}

double Benchmark::TestListInsertAtHead(int listLength, int iterations){
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    for (int foo = 0; foo < iterations; foo ++) {
        //Build a list to insert into / clear and reallocate
        list<int> testList = list<int>();

        // Start timing the operation 
        start = std::chrono::system_clock::now();
        for(int bar = 0; bar < listLength; bar++) {
            // Many, many inserts
            testList.push_front(bar);
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalTime += elapsed_seconds.count();
    }
    // Calculate the average time taken
    averageTime = totalTime / iterations;
    return averageTime;
}

double Benchmark::TestListInsertAtMid(int listLength, int iterations){
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    for (int foo = 0; foo < iterations; foo ++) {
        //Build a list to insert into / Clear and reallocate
        list<int> testList = list<int>();
        // Get an iterator pointing at the first element of testlist
        cs273::list<int>::iterator mid = testList.begin();
        // Start timing the operation 
        start = std::chrono::system_clock::now();
        for(int bar = 0; bar < listLength; bar++) {
            // Many, many inserts
            mid = testList.insert(mid, bar);
            // Every other time we insert, we want to move mid forward one 
            if (bar % 2 == 1) {
                mid++;
            }
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalTime += elapsed_seconds.count();
    }
    // Calculate the average time taken
    averageTime = totalTime / iterations;

    return averageTime;
}

double Benchmark::TestListInsertAtTail(int listLength, int iterations){
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    for (int foo = 0; foo < iterations; foo ++) {
        //Build a list to insert into
        list<int> testlist = list<int>();

        // Start timing the operation 
        start = std::chrono::system_clock::now();
        for(int bar = 0; bar < listLength; bar++) {
            // Many, many inserts
            testlist.push_back(bar);
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalTime += elapsed_seconds.count();
    }
    // Calculate the average time taken
    averageTime = totalTime / iterations;
    return averageTime;
}

double Benchmark::TestListRemoveFromHead(int deletionCount, int listLength, int iterations){
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    //Build a list to remove from
    list<int> testList;

    for (int foo = 0; foo < iterations; foo ++) {
        // Clear and reallocate testlist
        testList = generateSequentialIntList(listLength);

        // Start timing the operation 
        start = std::chrono::system_clock::now();
        for(int bar = 0; bar < deletionCount; bar++) {
            // Many, many erasures
            testList.pop_front();
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalTime += elapsed_seconds.count();
    }
    // Calculate the average time taken
    averageTime = totalTime / iterations;
    return averageTime;
}

double Benchmark::TestListRemoveFromMid(int deletionCount, int listLength, int iterations){
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    //Build a list to insert into
    list<int> testList;
    // Get an iterator pointing at the first element of testlist
    cs273::list<int>::iterator mid;

    for (int foo = 0; foo < iterations; foo ++) {
        // Clear and reallocate testlist
        testList = generateSequentialIntList(listLength);
        mid = testList.begin();
        // Point mid to the midpoint of the list
        std::advance(mid, testList.size() / 2);

        // Start timing the operation 
        start = std::chrono::system_clock::now();
        for(int bar = 0; bar < deletionCount; bar++) {
            // Many, many inserts
            mid = testList.erase(mid);
            // Every other time we insert, we want to move mid forward one 
            if (bar % 2 == 1) {
                mid--;
            }
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalTime += elapsed_seconds.count();
    }
    // Calculate the average time taken
    averageTime = totalTime / iterations;
    return averageTime;
}

double Benchmark::TestListRemoveFromTail(int deletionCount, int listLength, int iterations){
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalTime = 0;
    double averageTime = 0;

    //Build a list to insert into
    list<int> testList;

    for (int foo = 0; foo < iterations; foo ++) {
        testList = generateSequentialIntList(listLength);
        // Start timing the operation 
        start = std::chrono::system_clock::now();
        for(int bar = 0; bar < deletionCount; bar++) {
            // Many, many deletes
            testList.pop_back();
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalTime += elapsed_seconds.count();
    }
    // Calculate the average time taken
    averageTime = totalTime / iterations;
    return averageTime;
}

double Benchmark::TestListMemoryUse(int listLength, int iterations ) {
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    //Reset the total and average times;
    double totalFirstTime = 0;
    double averageFirstTime = 0;
    double totalSecondTime = 0;
    double averageSecondTime = 0;

    for (int foo = 0; foo < iterations; foo ++) {
        //Build a vector to insert into / Clear reset
        list<int> testList = list<int>();

        // Start timing the operation 
        start = std::chrono::system_clock::now();
        //Fill the vector up
        for(int bar = 0; bar < listLength; bar++) {
            testList.push_front(bar);
        }
        //Empty the vector
        for(int bar = 0; bar < listLength; bar++)
        {
            testList.pop_front();
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end - start; 
        totalFirstTime += elapsed_seconds.count();

        // Start timing the operation 
        start = std::chrono::system_clock::now();
        //Fill the vector up... again.
        for(int bar = 0; bar < listLength; bar++) {
            testList.push_front(bar);
        }
        //Empty the vector... again
        for(int bar = 0; bar < listLength; bar++)
        {
            testList.pop_front();
        }
        // Stop the timer
        end = std::chrono::system_clock::now();
        // Convert the time markers into the number of seconds elapsed
        elapsed_seconds = end - start; 
        totalSecondTime += elapsed_seconds.count();
    }
    // Compute the average of each run and return the difference.
    averageFirstTime = totalFirstTime / iterations;
    averageSecondTime = totalSecondTime / iterations;
    return averageFirstTime - averageSecondTime;
}