#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {   
   int shelfWidth;
   cin >> shelfWidth; // store width of shelf for current sim 
   char action; 
   int bookID, bookWidth; 
   int count = 0; 
   while (shelfWidth != -1) {
      // suggested variables 
      list<int> bookshelf; // declare list for books on shelf 
      int total = 0; // cumulative sum of books currently on shelf 
      vector<int> widths(101,0); // designate width of known books 
      
      list<int>::iterator it; // declare iterator 
      
      cin >> action; // take in 'A', 'R', or 'E'
      while (action != 'E') { 
         if (action == 'A') { // add book case
            cin >> bookID >> bookWidth; // take in bookID + bookWidth
            bookshelf.push_front(bookID); // add book to front of list 
            widths[bookID] = bookWidth; // store bookWidth at index == ID 
            total = total + bookWidth; // update total width on shelf
            
            while (total > shelfWidth) { // check total is not too large
               int deletedID = bookshelf.back(); // store ID of tbd book 
               total = total - widths[deletedID]; // decrease total width
               bookshelf.pop_back(); // removed final book 
            }
         }
         if (action == 'R') { // remove book case 
            cin >> bookID; // take in bookID only 
            for (it = bookshelf.begin(); it != bookshelf.end(); it++) {
               if (*it == bookID) { // when correct bookID found 
                  total = total - widths[*it]; // decrease total width on shelf
                  it = bookshelf.erase(it); // remove book from shelf 
               }
            }
         }
         cin >> action; // update 'A', 'R', 'E'
      }
      // when sim ends
      count++; // increment problem count 
      cout << "PROBLEM " << count << ":"; 
      for (it = bookshelf.begin(); it != bookshelf.end(); it++) {
         cout << " " <<  *it; // print each ID on sequentially 
      }
      cout << endl;
      cin >> shelfWidth; // take in new shelf width 
   }
   return 0; 
}
