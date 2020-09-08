#include <iostream>
using namespace std;

class rectangle{
   // set private attributes
   private: 
    int width, length; 
   // define public methods 
   public: 
      // constructor
      rectangle(): width(0), length(0) { };  
      // mutators
      void setWidth (int newVal) { width = newVal; }
      void setLength (int newVal) { length = newVal; }
      // accessors 
      int getWidth() const { return width; }
      int getLength() const { return width; }
      // member function: calc perimeter of rectangle
      int perimeter() { return (width * 2) + (length * 2); }
      // member function: calc area of rectangle
      int area() { return (width * length); }
      // member function: determine if rectangle is also a square
      void Square_or_Rectangle(int width, int length){
         if (width == length) { out << "SQUARE" << endl; }
         else { cout << "RECTANGLE" << endl; }
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
      // define new object, rect from class rectangle
      rectangle rect; 
      rect.setWidth(width); // set width of rect from input width 
      rect.setLength(length); // set length of rect from input length 
      // run functions
      cout << "Output" << endl;
      rect.Square_or_Rectangle(width, length); // output if given (w, l) == square
      cout << rect.area() << endl; // output area of (w,l)
      cout << rect.perimeter() << endl; // output perimeter of (w,l) 
      cout << endl; 
   }
   return 0;
}
