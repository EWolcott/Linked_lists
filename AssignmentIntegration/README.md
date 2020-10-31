# Benchmarking container classes #
Developed by Jude Battista
Modified by Scott Griffith
**source.cpp** contains a series of tests intended to exercise a variety of functions on your container classes.  
In its initial state, these tests execute against the stl::vector and stl::list classes, comparing their benchmarks.

## Testing your own container classes ##
Simply replace the using statements on lines 15 and 16 of **benchmark.h** with using statements that reference your containers.  
This likely takes the following form: 
``` 
using cs273::vector;  
using cs273::list;  
```

__Heads Up__ Iterators complicate things a little bit. If your vector does not have an iterator (which is not required), you will need to modify some of the code that utilizes `vector::iterator`s, that is fine. Make sure your modifications are reasonable for what the code is trying to test.

Your `list::iterator` methods still need to work as is.

This will be apparent in:
* `double Benchmark::TestVectorInsertAtHead(int vectorLength, int iterations)`
* `double Benchmark::TestVectorInsertAtMid(int vectorLength, int iterations)`
* `double Benchmark::TestVectorRemoveFromHead(int deletionCount, int vectorLength, int iterations)`
* `double Benchmark::TestVectorRemoveFromMid(int deletionCount, int vectorLength, int iterations)`
* 

## Testing sets ##
You will notice that **source.cpp** uses two different testing sets. `target` and `orderOfSearchSpace` are several orders of magnitude larger than `smallTarget` and `orderOfSmallSpace`. Some of the operations under test are computationally expensive. Passing them the smaller parameters allows the tests to execute more quickly, making the development process more fluid. Once you are convinced that your own containers work the way you want them to, you can switch to the larger parameters in order to get proportionally correct tests.
1. Lines 31-34: replace `orderOfSmallSpace` with `orderOfSearchSpace`
2. Lines 38-41: replace `orderOfSmallSpace` with `orderOfSearchSpace`
3. Lines 51-54: replace `orderOfSmallSpace` with `orderOfSearchSpace` and `smallTarget` with `target`
4. Lines 58-61: replace `orderOfSmallSpace` with `orderOfSearchSpace` and `smallTarget` with `target`  

If the default testing sets prove too slow on your machine, feel free to create smaller test sets to speed up your development cycle.