#include <iostream>
#include <string>
using namespace std;

int originalDepth(string::iterator& i) {
   int maxHeight =0; 
   while (*i != NULL) { // iter length of string 
      if (*i == 'u') { // base case
         i++; 
         return maxHeight; 
      }
      else if (*i == 'd') { // non-base case 
         i++; // adv to next char 
         int value = 1 + originalDepth(i); 
         if (value > maxHeight) {
            maxHeight = value; // replace maxHeight if needed
         }
      }
   }
   return maxHeight; 
}
int modifiedDepth(string::iterator& i) {
   int maxHeight =0; 
   int temp =0; // new var
   while (*i != NULL) { 
      if (*i == 'u') { // base case
         i++; 
         return maxHeight; 
      }
      else if (*i == 'd') { // non-base case 
         i++; 
         temp++; 
         int value = temp + modifiedDepth(i); // add subtree depth to value
         if (value > maxHeight) {
            maxHeight = value; 
         }
      }
   }
   return maxHeight; 
}

int main() {
   string inputTree; 
   cin >> inputTree; // declare and store input string 
   
   string precursor = "d"; 
   string postcursor = "u"; 
   int numLoops = 1; 
   while (inputTree != "#") {
      precursor.append(inputTree); // append input tree to init 'd'
      precursor.append(postcursor); // append input tree to terminal 'u'
      
      string::iterator it = inputTree.begin(); // init str iterator 
      int origOutput = originalDepth(it); // call func, store output 
      it = inputTree.begin(); // reset str iterator 
      int modOutput = modifiedDepth(it); // call func, stor output 
      cout << "Tree " << numLoops << ": " << origOutput << " => " << modOutput << endl; 
      numLoops++; 
      cin >> inputTree; 
   }
   return 0; 
}