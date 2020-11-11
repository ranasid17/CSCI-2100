#include <iostream>
#include <string>
using namespace std;

/* Return the depth of the subtree rooted at the iterator position in the
input string and advance the iterator so that it ends up at the character
just beyond the 'u' that ended the subtree traversal */ 

int depth(string::iterator& i) {
   int maxHeight =0; 
   while (*i != NULL) { // iter length of string 
      if (*i == 'u') { // base case
         i++; 
         return maxHeight; 
      }
      else if (*i == 'd') { // non-base case 
         i++; // adv to next char 
         int value = 1 + depth(i); 
         if (value > maxHeight) {
            maxHeight = value; // replace maxHeight if needed
         }
      }
   }
   return maxHeight; 
}
int main() {
   string inputTree; 
   cin >> inputTree; // declare then store input string
   
   string precursor = "d"; 
   string postcursor = "u"; 
   int numLoops = 1; 
   
   while (inputTree != "#") { 
      precursor.append(inputTree); // append input tree to initial 'd'
      precursor.append(postcursor); // append input tree to terminal 'u'
      
      string::iterator it = inputTree.begin(); // init str iterator 
      
      int output = depth(it); // call function and store output 
      
      cout << "Tree " << numLoops << ": " << output << endl; 
      numLoops++; // increment loop counter
      cin >> inputTree; // take in new input 
   }
   return 0; 
}
