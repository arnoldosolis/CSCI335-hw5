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
  srand(time(NULL));
  // Scans through vector
  for (size_t i = 0; i < size_of_vector; i++)
  {
    // Inserts num
    a.push_back(rand());
    // Will increase num to order from smallest to largest
  }
  // If the values are going to be from smallest to largest
  if (smaller_to_larger == true)
  {
    // Uses quicksort algorithm to sort array
    quicksort(a, less<int>{});
  }
  // If the values are going to be from largest to smallest
  else
  {
    // Uses quicksort algorithm to sort array
    quicksort(a, greater<int>{});
  }
  return a;
}

// Verifies that a vector is sorted given a comparator
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) 
{
  // Flag to check for verification of order
  bool verified = false;
  for (int i = 0; i < input.size() - 1; i++)
  {
    if (input[i] == input[i + 1])
    {
      verified = true;
    }
    else if (less_than(input[i],input[i + 1]) == true)
    {
      verified = true;
    }
    else
    {
      verified = false;
    }
  }
  return verified;  
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
  std::cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " << comparison_type << std::endl;
  
  vector<int> input_vector;
  if (input_type == "random") {
    // Generate random vector
    input_vector = GenerateRandomVector(input_size);
    
  } 
  else 
  {
    // Generate sorted vector.
    // smallest to largest
    if (input_type == "sorted_small_to_large")
    {
      // copyies returned array into input_vector
      input_vector = GenerateSortedVector(input_size, true);
    }
    // largest to smallest
    else
    {
      // copyies returned array into input_vector
      input_vector = GenerateSortedVector(input_size, false);
    }
  }

  // Call quicksort / heapsort / mergesort using appropriate input.
  // ...
  // if comparison type is "less" then call
  if (comparison_type == "less")
  {
    // Will be used to label heapsort runtime and verification
    std::cout << "Heapsort" << std::endl;
    // new line
    std::cout << std::endl;
    // start timer
    auto begin = chrono::high_resolution_clock::now();
    // Heapsort
    heapsort(input_vector, less<int>{});
    //end timer
    auto end = chrono::high_resolution_clock::now();
    // Calls Compute Duration to print out Runtime
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << std::endl;
    // MergeSort(input_vector, less<int>{})
    // otherwise call
    // MergeSort(input_vector, greater<int>{})
    // ...
    
    std::cout << std::endl;

    std::cout << "MergeSort" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    mergeSort(input_vector, less<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << std::endl;

    std::cout << std::endl;

    std::cout << "QuickSort" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    quicksort(input_vector, less<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << std::endl;

    std::cout << std::endl;

    std::cout << "Testing Quicksort Pivot Implmenetations" << std::endl;

    std::cout << std::endl;

    std::cout << "Median of Three" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    quicksort(input_vector, less<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << std::endl;

    std::cout << std::endl;

    std::cout << "Middle" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    quicksort(input_vector, less<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << std::endl;

    std::cout << std::endl;

    std::cout << "First" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    quicksort(input_vector, less<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << std::endl;
  }
  // if comparison type is "less" then call
  if (comparison_type == "greater")
  {
    // Will be used to label heapsort runtime and verification
    std::cout << "Heapsort" << std::endl;
    // new line
    std::cout << std::endl;
    // start timer
    auto begin = chrono::high_resolution_clock::now();
    // Heapsort
    heapsort(input_vector, greater<int>{});
    //end timer
    auto end = chrono::high_resolution_clock::now();
    // Calls Compute Duration to print out Runtime
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << std::endl;
    
    std::cout << std::endl;

    std::cout << "MergeSort" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    mergeSort(input_vector, greater<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << std::endl;

    std::cout << std::endl;

    std::cout << "QuickSort" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    quicksort(input_vector, greater<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << std::endl;

    std::cout << std::endl;

    std::cout << "Testing Quicksort Pivot Implmenetations" << std::endl;

    std::cout << std::endl;

    std::cout << "Median of Three" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    quicksort(input_vector, greater<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << std::endl;

    std::cout << std::endl;

    std::cout << "Middle" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    quicksort(input_vector, greater<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << std::endl;

    std::cout << std::endl;

    std::cout << "First" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    quicksort(input_vector, greater<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << std::endl;
  }
  return 0;
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
