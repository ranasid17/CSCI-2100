#include <iostream>
using namespace std;

int main()
{
    // elts of each row of 2D array 
    int elements[] = {5, 9, 12, 11, 7, 1, 3, 9, 0, 12, 2, 21, 8, 8, 16}; //given by problem
    // num rows for 2D array 
    int numRows = 4;
    // create pointer array, points to address of array of size numRows
    int *numCols = new int [numRows]; 
    // create pointer array, points to contents of array size numRows
    int **arrPtrs = new int *[numRows]; 
    // assign number of columns for each (sub)array 
    numCols[0] = 3; numCols[1] = 2; numCols[2] = 6; numCols[3] = 4; 
    // assign numbers columns to colPtrs
    arrPtrs[0] = new int [numCols[0]]; //first row of arrPts has len(numCols[0])
    arrPtrs[1] = new int [numCols[1]]; //second "                  "(numCols[1])
    arrPtrs[2] = new int [numCols[2]]; //third "                               "
    arrPtrs[3] = new int [numCols[3]]; //fourth "                              "
    // assign elts to each [row][col] of colPtrs
    int a =0; // counter 
    for(int i=0; i<numRows; i++)
    {
        for(int j=0; j<numCols[i]; j++) 
        {
            arrPtrs[i][j] = elements[a]; 
            a = a+1;
        }
    }
    // init and store vars to query array 
    int queryRow = 0;
    int queryCol = 0; // refers to array index NOT overall row, col
    while ( queryRow >= 0 ) 
    {
        cin >> queryRow >> queryCol;
        if (queryRow < 0) // termination condition , problem provides (-1 -1) as cue to finish
        {
           break; 
        }
        else if (queryRow >= numRows) // error if attempt to query beyond 3rd (index) row 
        {
            cout << "out of bound" << endl; 
        }
        else if ( queryCol >= numCols[queryRow]) // error if attempt to query beyond a given row's numCols
        {
            cout << "out of bound" << endl; 
        }
        else // otherwise print queried [row][col] value
        {
            cout << arrPtrs[queryRow][queryCol] << endl; 
        }
    }
    // clear memory 
    delete [] numCols; 
    delete [] arrPtrs; 
    return 0;
}
