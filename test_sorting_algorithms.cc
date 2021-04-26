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
  // Scans through vector
  for (size_t i = 0; i < size_of_vector; i++)
  {
    // Inserts random
    a.push_back(rand());
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
      // If 2 numbers are the same they are still in order
    if (input[i] == input[i + 1])
    {
      // Set boolean flag to true   
      verified = true;
    }
      // Depending on what compartive type the user set 
    else if (less_than(input[i],input[i + 1]) == true)
    {
      // Set boolean flag to true 
      verified = true;
    }
      // if they are not in order of user comparitive input 
    else
    {
      // Set bollean flag to false  
      verified = false;
      return verified;
    }
  }
  // Returns boolean value depending on if the array is in order 
  return verified;  
}

// Computes duration given a start time and a stop time in nano seconds
long long ComputeDuration(chrono::high_resolution_clock::time_point start_time, chrono::high_resolution_clock::time_point end_time) {
  // returns the duration in ns
  return chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
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
  
  std::cout << "Running sorting algorithms: " << input_type << " " << input_size << " " << comparison_type << std::endl;

  std::cout << std::endl;
  
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

  // Created 6 duplicate input_vector so that there can be a more precise
  // measurement in runtime
  vector<int> a = input_vector;
  vector<int> b = input_vector;
  vector<int> c = input_vector;
  vector<int> d = input_vector;
  vector<int> e = input_vector;
  vector<int> f = input_vector;
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
    heapsort(a, less<int>{});
    //end timer
    auto end = chrono::high_resolution_clock::now();
    // Calls Compute Duration to print out Runtime
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(a, less<int>{}) << std::endl;
    // MergeSort(input_vector, less<int>{})
    // otherwise call
    // MergeSort(input_vector, greater<int>{})
    // ...
    // new line 
    std::cout << std::endl;

    // Wil be used to label mergesort runtime and verification 
    std::cout << "MergeSort" << std::endl;
    // new line
    std::cout << std::endl;
    // start timer 
    begin = chrono::high_resolution_clock::now();
    // MergeSort
    mergeSort(b, less<int>{});
    // end timer 
    end = chrono::high_resolution_clock::now();
    // Calls ComputeDuration function to return time counted by timer 
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    // Checks if array is in order 
    std::cout << "Verified: " << VerifyOrder(b, less<int>{}) << std::endl;

    // new line 
    std::cout << std::endl;

    // Will be used to label quicksort runtime and verification 
    std::cout << "QuickSort" << std::endl;
    // newline 
    std::cout << std::endl;
    // start timer 
    begin = chrono::high_resolution_clock::now();
    // quicksort (specifically median3)
    quicksort(c, less<int>{});
    // end timer 
    end = chrono::high_resolution_clock::now();
    // Calls ComputeDuration function to return time counted by timer 
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    // Checks if array is in order
    std::cout << "Verified: " << VerifyOrder(c, less<int>{}) << std::endl;

    // new line 
    std::cout << std::endl;

    // Label for demonstrating 3 different pivot implementations 
    std::cout << "Testing Quicksort Pivot Implementations" << std::endl;

    // new line 
    std::cout << std::endl;

    // Median of three implementations 
    std::cout << "Median of Three" << std::endl;
    // new line 
    std::cout << std::endl;
    // start timer  
    begin = chrono::high_resolution_clock::now();
    // quicksort 
    quicksort(d, less<int>{});
    // end timer 
    end = chrono::high_resolution_clock::now();
    // Calls ComputeDuration function to return time counter by timer 
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    // Checks if array is in order 
    std::cout << "Verified: " << VerifyOrder(d, less<int>{}) << std::endl;

    // new line 
    std::cout << std::endl;

    // Middle implementations 
    std::cout << "Middle" << std::endl;
    // new line 
    std::cout << std::endl;
    // start timer 
    begin = chrono::high_resolution_clock::now();
    // quicksort middle pivot
    quicksort2(e, less<int>{});
    // end timer 
    end = chrono::high_resolution_clock::now();
    // Calls ComputeDuration function to return time counter by timer 
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    // checks if array is in order 
    std::cout << "Verified: " << VerifyOrder(e, less<int>{}) << std::endl;

    // new line 
    std::cout << std::endl;

    // First index pivot point 
    std::cout << "First" << std::endl;
    // new line 
    std::cout << std::endl;
    // start timer 
    begin = chrono::high_resolution_clock::now();
    // quicksort first index pivot 
    quicksort3(f, less<int>{});
    // end timer 
    end = chrono::high_resolution_clock::now();
    // Calls ComputeDuration function to return time counter by timer 
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    // checks if array is in order 
    std::cout << "Verified: " << VerifyOrder(f, less<int>{}) << std::endl;
  }
  // Please reference above comments as they are the same for greater the 
  // only thing that changes is comparison_type that being the "greater".
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
    heapsort(a, greater<int>{});
    //end timer
    auto end = chrono::high_resolution_clock::now();
    // Calls Compute Duration to print out Runtime
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(a, greater<int>{}) << std::endl;
    
    std::cout << std::endl;

    std::cout << "MergeSort" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    mergeSort(b, greater<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(b, greater<int>{}) << std::endl;

    std::cout << std::endl;

    std::cout << "QuickSort" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    quicksort(c, greater<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(c, greater<int>{}) << std::endl;

    std::cout << std::endl;

    std::cout << "Testing Quicksort Pivot Implementations" << std::endl;

    std::cout << std::endl;

    std::cout << "Median of Three" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    quicksort(d, greater<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(d, greater<int>{}) << std::endl;

    std::cout << std::endl;

    std::cout << "Middle" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    quicksort2(e, greater<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(e, greater<int>{}) << std::endl;

    std::cout << std::endl;

    std::cout << "First" << std::endl;
    std::cout << std::endl;
    begin = chrono::high_resolution_clock::now();
    quicksort3(f, greater<int>{});
    end = chrono::high_resolution_clock::now();
    std::cout << "Runtime: " << "<" << ComputeDuration(begin, end) << ">" << " ns" << std::endl;
    std::cout << "Verified: " << VerifyOrder(f, greater<int>{}) << std::endl;
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
