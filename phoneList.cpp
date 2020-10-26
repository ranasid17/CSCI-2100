#include <iostream>
#include <string> 
#include <vector> 
#include <algorithm> 

using namespace std;

int main() {
   // declare int to hold number of test cases 
   int numTestCases; 
   cin >> numTestCases; 
   // iterate thru all test cases 
   for (int i =0; i<numTestCases; i++) {
      // declare int to hold set size (num Phone Numbers) 
      int setSize; 
      cin >> setSize; 
      
      vector<string> numbers(setSize); // declare vector to hold incoming phone numbers 
      vector<string>::iterator it; // initialize (fwd) iterator 
      string currentNumber; // string to hold current phone number 
      
      for (it =numbers.begin(); it != numbers.end(); it++) { // iteratively fill vector 
         cin >> currentNumber; 
         *it = currentNumber; 
      }
      int size = numbers.size(); // store vector size 
      sort(numbers.begin(), numbers.end()); // sort vector in ascending order
      int count = 0; 
      for (int j =0; j<size-1; j++) { // iterate thru vector 
         string prefix = numbers[j]; // store current string 
         string comparison = numbers[j+1]; // store subsequent string 
         
         if ( comparison.compare(0, prefix.length(), prefix) == 0) {
            count++; // increase count by one if inconsistent
         }
      }
      if (count > 0) {
         cout << "NO" << endl; 
      }
      else {
         cout << "YES" << endl; 
      }
   }

}
