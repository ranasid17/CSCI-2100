#include <iostream>
#include <stack>

template <typename Object>
class queue { 
private:
   // Do not use any data members other than the following two stacks 
   std::stack<Object> S1;
   std::stack<Object> S2;
   
public:
   void push(const Object& e) { // enqueue function
      S1.push(e);  
   } 
   bool empty() const { // check if empty function 
      return (S1.empty() && S2.empty());
   }
   int size() const { // check size 
      return S1.size(); 
   }
   void pop() { // dequeue function 
      while( !S1.empty() ) { 
         S2.push(S1.top()); // push into S2 what is currently on top of S1
         S1.pop(); // remove the top elt of S1
      }
      S2.pop(); // pop it from memory (this is the dequeue part) 
      while (!S2.empty() ) { // return elts from S2 to S1 to reset original order
         S1.push(S2.top()); 
         S2.pop(); 
      }
   }
   Object& front() { // return object at front of queue (?) 
      while( !S1.empty() ) { 
         S2.push(S1.top()); // push into S2 what is currently on top of S1
         S1.pop(); // remove the top elt of S1
      }
      Object& frontOfQueue = S2.top(); // store top of S2 (front of queue) 
      while (!S2.empty() ) { // return elts from S2 to S1 to reset original order
         S1.push(S2.top()); 
         S2.pop(); 
      }   
      return frontOfQueue; 
   }
   // for simplicity, we'll ignore the const version of front() 
}; // end of class queue

int main()
{
    queue <int> Q;
    std::cout<<"is it empty? -> "<<Q.empty()<<std::endl;
    Q.push(1);
    std::cout<< "--push 1 " <<std::endl;
    std::cout<< "front is " << Q.front()<<std::endl;
    std::cout<< "size is " << Q.size()<<std::endl;
    Q.push(2);
    std::cout<< "--push 2 " <<std::endl;
    std::cout<< "front is " << Q.front()<<std::endl;
    std::cout<< "size is " << Q.size()<<std::endl;
    Q.push(3);
    std::cout<< "--push 3 " <<std::endl;
    std::cout<< "front is " << Q.front()<<std::endl;
    std::cout<< "size is " << Q.size()<<std::endl;
    Q.pop();
    std::cout<< "--pop 1 " <<std::endl;
    std::cout<< "front is " << Q.front()<<std::endl;
    std::cout<< "size is " << Q.size()<<std::endl;
    Q.push(4);
    std::cout<< "--push 4 " <<std::endl;
    std::cout<< "front is " << Q.front()<<std::endl;
    std::cout<< "size is " << Q.size()<<std::endl;
    Q.pop();
    std::cout<< "--pop 2 " <<std::endl;
    std::cout<< "front is " << Q.front()<<std::endl;
    std::cout<< "size is " << Q.size()<<std::endl;
    std::cout<<"is it empty? -> "<<Q.empty()<<std::endl;
        return 0;
}
