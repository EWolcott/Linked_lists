
#include <iostream>
#include <string>

#include "benchmark.h"

int main() 
{ 
    int target = 900000;
    int orderOfSearchSpace = 1000000;
    int smallTarget = 9000;
    int orderOfSmallSpace = 10000;
    int numberOfRuns = 100;
    double averageTime = 0;
    Benchmark* bench = new Benchmark();
    std::string separator = std::string(120, '=');

    std::cout << separator << std::endl; 
    averageTime = bench->TestVectorFindInt(target, orderOfSearchSpace, numberOfRuns);
    std::cout << "Finding integer " << target << " in a vector over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;
    averageTime = bench->TestListFindInt(target, orderOfSearchSpace, numberOfRuns);
    std::cout << "Finding integer " << target << " in a list over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;

    std::cout << separator << std::endl; 
    averageTime = bench->TestVectorAccessInt(target, orderOfSearchSpace, numberOfRuns);
    std::cout << "Accessing integer " << target << " in a vector over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;
    averageTime = bench->TestListAccessInt(target, orderOfSearchSpace, numberOfRuns);
    std::cout << "Accessing integer " << target << " in a list over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;

    std::cout << separator << std::endl; 
    // Note the change from orderOfSearchSpace to orderOfSmallSpace here! Inserting at the head of a vector is expensive!
    averageTime = bench->TestVectorInsertAtHead(orderOfSmallSpace, numberOfRuns);
    std::cout << "Inserting " << orderOfSmallSpace << " integers at the head of a vector over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;
    averageTime = bench->TestListInsertAtHead(orderOfSmallSpace, numberOfRuns);
    std::cout << "Inserting " << orderOfSmallSpace << " integers at the head of a list over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;

    std::cout << separator << std::endl; 
    // Note the change from orderOfSearchSpace to orderOfSmallSpace here! Inserting at the midpoint of a vector is still expensive!
    averageTime = bench->TestVectorInsertAtMid(orderOfSmallSpace, numberOfRuns);
    std::cout << "Inserting " << orderOfSmallSpace << " integers at the midpoint of a vector over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;
    averageTime = bench->TestListInsertAtMid(orderOfSmallSpace, numberOfRuns);
    std::cout << "Inserting " << orderOfSmallSpace << " integers at the midpoint of a list over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;

    std::cout << separator << std::endl; 
    averageTime = bench->TestVectorInsertAtTail(orderOfSearchSpace, numberOfRuns);
    std::cout << "Inserting " << orderOfSearchSpace << " integers at the tail of a vector over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;
    averageTime = bench->TestListInsertAtTail(orderOfSearchSpace, numberOfRuns);
    std::cout << "Inserting " << orderOfSearchSpace << " integers at the tail of a list over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;

    std::cout << separator << std::endl; 
    // Note the change from orderOfSearchSpace to orderOfSmallSpace here! Removing from the head of a vector is expensive!
    averageTime = bench->TestVectorRemoveFromHead(smallTarget, orderOfSmallSpace, numberOfRuns);
    std::cout << "Removing " << smallTarget << " integers from the head of a vector of " << orderOfSmallSpace << " over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;
    averageTime = bench->TestListRemoveFromHead(smallTarget, orderOfSmallSpace, numberOfRuns);
    std::cout << "Removing " << smallTarget << " integers from the head of a list of " << orderOfSmallSpace << " over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;

    std::cout << separator << std::endl; 
    // Note the change from orderOfSearchSpace to orderOfSmallSpace here! Removing from the midpoint of a vector is still expensive!
    averageTime = bench->TestVectorRemoveFromMid(smallTarget, orderOfSmallSpace, numberOfRuns);
    std::cout << "Removing " << smallTarget << " integers from the midpoint of a vector of " << orderOfSmallSpace << " over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;
    averageTime = bench->TestListRemoveFromMid(smallTarget, orderOfSmallSpace, numberOfRuns);
    std::cout << "Removing " << smallTarget << " integers from the midpoint of a list of " << orderOfSmallSpace << " over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;

    std::cout << separator << std::endl; 
    averageTime = bench->TestVectorRemoveFromTail(target, orderOfSearchSpace, numberOfRuns);
    std::cout << "Removing " << target << " integers from the tail of of a vector of " << orderOfSearchSpace << " over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;
    averageTime = bench->TestListRemoveFromTail(target, orderOfSearchSpace, numberOfRuns);
    std::cout << "Removing " << target << " integers from the tail of of a list of " << orderOfSearchSpace << " over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;

    std::cout << separator << std::endl; 
    averageTime = bench->TestVectorMemoryUse(orderOfSearchSpace, numberOfRuns);
    std::cout << "The difference between the first and second fill/empty cycles of " << orderOfSearchSpace << " elements from a vector over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;
    averageTime = bench->TestListMemoryUse(orderOfSearchSpace, numberOfRuns);
    std::cout << "The difference between the first and second fill/empty cycles of " << orderOfSearchSpace << " elements from a list over " << numberOfRuns << " runs averaged " << averageTime << " seconds." << std::endl;

    std::cout << separator << std::endl; 
} 