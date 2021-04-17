// Homework 5
// Testing Sorting Algorithms
// Arnoldo Solis

#include "Sort.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
using namespace std;

// Test function that shows how you can time a piece of code.
// Just times a simple loop.

void TestingTiming() {
  cout << "Testing Timing" << endl;
  const auto begin = chrono::high_resolution_clock::now();
  // Time this piece of code.
  int sum = 0;
  for (int i = 1; i < 10000; ++i) sum ++;
  // End of piece of code to time.
  const auto end = chrono::high_resolution_clock::now();    
  cout << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "ns" << endl;
  cout << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms" << endl;

}

// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector) 
{
  // Use rand() to generate random integer
  vector<int> a{};
  // Creates a random seed
  srand(time(NULL));
  // Scans through vector a
  for (int i = 0; i < size_of_vector; i++)
  {
    // Inserts a random number
    a.push_back(rand());
  }
  return a;
}

// Generate and returns sorted vector of size @size_of_vector
// If smaller_to_larger is true, returns vector sorted from small to large
// Otherwise returns vector sorted from large to small
vector<int> GenerateSortedVector(size_t size_of_vector, bool smaller_to_larger) 
{
  // Creates vector a
  vector<int> a{};
  // If the values are going to be from smallest to largest
  if (smaller_to_larger == true)
  {
    // array will start from 1
    size_t num = 1;
    // Scans through vector
    for (size_t i = 0; i < size_of_vector; i++)
    {
      // Inserts num
      a.push_back(num);
      // Will increase num to order from smallest to largest
      num ++;
    }
    return a;
  }
  // If the values are going to be from largest to smallest
  else if (smaller_to_larger == false)
  {
    // arry starts from its size
    size_t num = size_of_vector;
    for (size_t i = 0; i < size_of_vector; i++)
    {
      // Inserts num
      a.push_back(num);
      // Will decrease num to order from largest to smallest
      num--;
    }
    return a;
  }
  // Empty
  else 
  {
    return a;
  }
}

// Verifies that a vector is sorted given a comparator
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) 
{
  // Flag to check for verification of order
  bool verified = false;
  // If comparator is less
  if (less_than == less<int>{})
  {
    // Scan through input
    for (int i = 0; i < input.size() - 1; i++)
    {
      // Check that vector is sorted from smallest to largest
      //less -> 1, 2, 3, 4, 5
      if (input[i] < input[i+1])
      {
        // Will set verified to true if input at index is less than input at index + 1
        verified = true;
      }
      else
      {
        // Will set verified to false if input at index is NOT less than input at index + 1
        verified = false;
      }
    }
    // returns true if order ranges from smallest to largest
    return verified;
  }
  // If comparator is greater
  else if(less_than == greater<int>{})
  {
    // Scan through input
    for (int i = 0; i < input.size() - 1; i++)
    {
      // Checks that the vector is sorted from largest to smallest
      // greater -> 5, 4, 3, 2, 1
      if (input[i] > input[i+1])
      {
        // Will set verified to true if input at index is greater than input at index + 1
        verified = true;
      }
      else
      {
        // Will set verified to false if input at index is NOT greater than input at index + 1
        verified = false;
      }
    }
    // returns true if order ranges from largest to smallest
    return verified;
  }
}

// Computes duration given a start time and a stop time in nano seconds
long long ComputeDuration(chrono::high_resolution_clock::time_point start_time, chrono::high_resolution_clock::time_point end_time) {
  const auto begin = chrono::high_resolution_clock::now();
  const auto end = chrono::high_resolution_clock::now();  
  // returns the duration in ns
  return chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
}

// Wrapper function to test the different sorting algorithms
int testSortingWrapper(int argc, char **argv) {
  const string input_type = string(argv[1]);
  const int input_size = stoi(string(argv[2]));
  const string comparison_type = string(argv[3]);
  if (input_type != "random" && input_type != "sorted_small_to_large" && input_type != "sorted_large_to_small") {
    cout << "Invalid input type" << endl;
    return 0;
  }
  if (input_size <= 0) {
    cout << "Invalid size" << endl;
    return 0;
  }
  if (comparison_type != "less" && comparison_type != "greater") {
    cout << "Invalid comparison type" << endl;
    return 0;
  }
  
  // This block of code to be removed for your final submission.
  TestingTiming();

  cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " << comparison_type << endl;
  vector<int> input_vector;
  if (input_type == "random") {
    // Generate random vector
    
  } else {
    // Generate sorted vector.

  }

  // Call quicksort / heapsort / mergesort using appropriate input.
  // ...
  // if comparison type is "less" then call 
  // MergeSort(input_vector, less<int>{})
  // otherwise call
  // MergeSort(input_vector, greater<int>{})
  // ...

  // Call quicksort with median of three as pivot / middle as pivot / first as pivot using appropriate input.
  // ...
  // if comparison type is "less" then call 
  // QuickSort(input_vector, less<int>{})
  // otherwise call
  // QuickSort(input_vector, greater<int>{})
  // ...

}

// Do not change anything below

int main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << "<input_type> <input_size> <comparison_type>" << endl;
    return 0;
  }
  
  testSortingWrapper(argc, argv);

  return 0;
}
