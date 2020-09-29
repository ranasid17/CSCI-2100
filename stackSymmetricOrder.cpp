#include <iostream>
#include <stack>
#include <string>
using namespace std;

# Goal: Given list of input names in ascending order of length, output names in 
#  symmetrical order of length 
# Ex: Jay, John, James, Jordan, Jeffrey ==> Jay, James, Jeffrey, Jordan, John
# Input: See file stackSymmetricOrder_input.txt


int main() { 
   stack<string> names; // initialize stack to store input names 
   
   int numNames; // store number of names to be ordered
   int count = 1; // store number of iterations
   while ( numNames != 0 ) 
   { 
      cin >> numNames; 
      if (numNames == 0) 
      {
         break; 
      }
      cout << "SET " << count << endl; // print iteration number 
      for (int i =1; i<=numNames; i++) // iterate through number of names given 
      { 
         string inputName;  // 
         cin >> inputName; // input current name 
         if ( (i%2) != 0 ) // when input string has odd placement 
         { 
            cout << inputName << endl; // immediately print it  
         }
         else // when input string has even placement  
         { 
            names.push(inputName); // push into stack         
         }
      }
      // after outputting odds (first half) and pushing evens (second half) 
      while ( !names.empty() ) 
      {
         cout << names.top() << endl; // print second half in reverse order
         names.pop(); // remove from stack afte printing 
      }
      count = count +1; 
   }
}
