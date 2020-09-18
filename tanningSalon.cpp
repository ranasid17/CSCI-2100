#include <iostream>
#include <string>
using namespace std;

int
main ()
{
  // init vars to store inputs 
  int totalBeds;		// maximum tanning beds available at one time 
  string guestList;		// hold order in which guests arrive 
  int a = 0; 
  while (totalBeds != 0) {
      cin >> totalBeds >> guestList;	// input total beds, order of guests 
      if (totalBeds ==0) { // end loop condition
         break; 
      }
      // map guestList to [1,26]
      int numericalGuest[guestList.length ()];	// array to hold num conversion of guestList 
      // convert string list to numerical list [1, 25] 
      for (int i = 0; i < guestList.length (); i++) {
          numericalGuest[i] = guestList[i] - 64;
      }
      int openBeds = totalBeds;	// set freeBeds to total beds before guests arrive 
      int currentlyTanning[guestList.length ()] = { 0 };	// create array of zeros 
      int takenBeds = 0; // number of occupied beds
      int rejectedGuests = 0; // number of guests turned away 
      int skip = 0;
      // iterate thru guest list 
      for (int i = 0; i < guestList.length(); i++) {
         for (int j = 0; j < i; j++) {
            if (currentlyTanning[j] == numericalGuest[i]) { //scan currTan for current guest
               currentlyTanning[j] == 0;	//remove from list if there
		         openBeds = openBeds + 1;	//increase open bed count
		         takenBeds = takenBeds - 1;	//decrease full bed count 
		         skip = 1;	// set to one whenever for loop removes tanner 
		      }
         }
         if (skip == 1) {
	         skip = 0;		// reset skip
	      }
	      else { // only do this if j-level for loop did nothing 
	         if (openBeds > 0 && openBeds <= totalBeds) { //if there is an open bed 
		         currentlyTanning[openBeds] = numericalGuest[i];	// move guest to it 
		         openBeds = openBeds - 1;	// decrease open beds by 1 
		         takenBeds = takenBeds + 1;	// increase full beds by 1
		      }
	         else if (openBeds == 0 && takenBeds == totalBeds) { //if there are no open beds
	            rejectedGuests = rejectedGuests + 1;	//increase turned away count 
		      }
	      }
	  }
	  if (rejectedGuests == 0 || rejectedGuests/2 ==0 ) { // if no guests turned away 
	      cout << "All customers tanned successfully." << endl;
	  }
	  else {
	     cout << (rejectedGuests/2) << " " << "customer(s) walked away." << endl;
	  }
   }
   return 0;
}
