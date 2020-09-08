#include <iostream>
using namespace std;

// Input: 
// The input consists of one or more data sets. Each set starts with a line containing an integer n, 1 ≤ n ≤ 10, followed by n pairs of values, one pair per line. 
// The first value in a pair, s, is the speed in miles per hour and the second value, t, is the total elapsed time. 
// Both s and t are integers, 1 ≤ s ≤ 90 and 1 ≤ t ≤ 12. The values for t are always in strictly increasing order. 
// A value of -1 for n signals the end of the input.

// Output: 
// For each input set, print the distance driven, followed by a space, followed by the word "miles".

int main()
{
    // var to set number of rows to consider 
    int numRows; 
    while (numRows != -1) { // will input -1 when end reached
       cin >> numRows; 
       if (numRows == -1) { // exit condition
          break; 
       }
       else { // otherwise 
          // arrays to hold distance traveled for elapsed amount of time 
          int distance[numRows];
          int elapsedTime[numRows]; 
          // iteratively store distance, elapsed time into arrays 
          for(int i=0; i<numRows;i++){
             cin >> distance[i] >> elapsedTime[i];
          }
          
          int timeDifferential[numRows-1]; // array to hold time spent between measurements
          int totalDistance = 0; // var to sum total distance driven
          // NOTE: CALCULATIONS CANNOT OCCUR IN SAME FOR LOOP INPUTS ARE STORED INTO ARRAYS
          // This is because calculations require information from inputs not yet stored 
          for(int i =0; i<numRows;i++){
             // calc time spent at given mph 
             timeDifferential[0] = elapsedTime[0];
             timeDifferential[i+1] = elapsedTime[i+1] - elapsedTime[i];
             // calc total distance driven
             totalDistance = totalDistance + timeDifferential[i]*distance[i]; 
          }
          cout << totalDistance << " " << "miles" << endl;
       }
    }
    return 0;
}
