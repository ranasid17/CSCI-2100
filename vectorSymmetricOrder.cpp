#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() 
{
   int setSize; // store size of set 
   int count =1; // store num iterations 
   
   string currentName; // var to hold current set name prior to inputting to vector 
   
   
   while ( setSize != 0)
   {
      cin >> setSize; // input size of names list 
      if (setSize == 0)
      {
         return 0; 
      }
      else { 
         cout << "SET " << count << endl; // print iteration number 
         vector<string> names(setSize); // create vector to hold input names
         vector<string>::iterator it; // initialize (fwd) iterator for names 
         int vectorSize = names.size(); // hold size of vector 
         // fill vector via iterator 
         for (it =names.begin(); it != names.end(); it++) 
         {
            cin >> currentName; // input current name
            *it = currentName; // deRef it and element to current name
         }
         // print even indexed names
         for (int i =0; i < vectorSize; i+=2) // works 
         {
            cout << names[i] << endl; 
         }
         for (int j =vectorSize-1 -(vectorSize%2); j >=0; j-=2) // this one 
         {
            cout << names[j] << endl; 
         }
      }
      count = count+1; 
   }
   return 0; 
}