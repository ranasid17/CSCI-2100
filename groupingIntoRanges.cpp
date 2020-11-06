# A publisher may allow a reader to select a subset of chapters to purchase. 
# Given 15 integers that are 0 or 1 indicating whether or not to include chapters 1 to 15, output the selection using shorthand for ranges of 3 or more 
# (11, 12, 13 becomes 11-13). If the input is 1 1 1 1 0 1 0 1 1 0 1 1 1 0 0, the output should be: 1-4 6 8 9 11-13. 
# If no chapters are selected, output: None For simplicity, follow every term including the last by one space (and end with newline).

#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<bool> chptList(16); // Valid chapters are 1-15. 1 means include, 0 exclude. Element 0 unused. 
   bool includeChpt;
   int sum = 0; // init var to hold sum of vector 
   
   for (int i =1; i<16; i++) {
      cin >> includeChpt; // take in input 
      chptList[i] = includeChpt; // store inputs in chptList 
      sum = sum + chptList[i]; // count num chapters to be printed
   }
   int count = 0; 
   for (int j =1; j<16; j++) {
       while ( chptList[j] == 1 && chptList[j+1] ) { // check subseq position
         count++; // incr count iff true 
         j++; // incr iterator 
       }
       if (count >= 2) { // check if range print necessary 
           cout << (j-count) << "-" << j << " "; 
       }
       else if (count == 1) {
           cout << j -1 << " " << j << " " ; 
       }
       else if ( chptList[j] == 1) { // otherwise print solitary chapter
           cout << j << " "; 
       }
       count = 0; // reset count at end of loop
       j = j-count; // reset iterator to "correct" value
   }
   if (sum == 0) { // check if no chapters to be printed
      cout << "None" << " " ; 
   }
   cout << endl; 
   return 0;
}
