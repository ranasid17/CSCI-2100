#include <iostream>
using namespace std;

class rectangle{
   // set private attributes
   public: 
    int width, length; 
   // define public methods 
   public: 
      // constructor
      rectangle(): width(0), length(0) { };  
      // mutators
      void setWidth (int newVal) {
         width = newVal; 
      }
      void setLength (int newVal) {
         length = newVal; 
      }
      // accessors 
      int getWidth() const {
         return width; 
      }
      int getLength() const {
         return width; 
      }
      // remaining member function declarations
      int perimeter() {
         return (width * 2) + (length * 2); 
      }
      int area() {
         return (width * length); 
      }
      void Square_or_Rectangle(int width, int length){
         if (width == length) {
            cout << "SQUARE" << endl; 
         }
         else {
            cout << "RECTANGLE" << endl; 
         }
         return; 
      }
};
int main() {
   // define user vars 
   int width, length; 
   // terminate if (0,0) is input 
   while (width != 0) {
      // user input values 
      cin >> width >> length; 
      // define new object
      rectangle rect; 
      rect.setWidth(width); 
      rect.setLength(length); 
      // run functions
      cout << "Output" << endl;
      rect.Square_or_Rectangle(width, length); 
      cout << rect.area() << endl; 
      cout << rect.perimeter() << endl; 
      cout << endl; 
   }
   return 0;
}
