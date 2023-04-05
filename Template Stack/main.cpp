#include <iostream>
#include <string>
#include "stack.h"
#include <stdexcept>

using namespace std;


int main()
{
   std::cout << "Enter a test number(1-6): ";
    int test;
    std::cin >> test;
    std::cout << std::endl;
   //tests constructor, push, pop, top and empty
   if (test == 1) {
       try{
          std::cout << "\nstack1 constructor called";
          stack<int> stack1;
          if(stack1.empty()){
              cout<<"\nstack1 is empty.";
          }
          else{
              cout<<"\nstack1 is not empty";
          }
          std::cout << "\npush 10";
          stack1.push( 10 );
          std::cout << "\npush 20";
          stack1.push( 20 );
          std::cout << "\npush 30";
          stack1.push( 30 );
          std::cout << "\nstack1 top: ";
          std::cout<<stack1.top();
          std::cout << "\npop";
          stack1.pop();
          std::cout << "\nstack1 top: ";
          std::cout<<stack1.top();
          std::cout << "\npop";
          stack1.pop();
          std::cout << "\nstack1 top: ";
          std::cout<<stack1.top();
          std::cout << "\npop";
          stack1.pop();
          if(stack1.empty()){
              std::cout<<"\nstack1 is empty.";
          }
          else{
              std::cout<<"\nstack1 is not empty";
          }
          std::cout << std::endl;
       }
       catch(underflow_error & excpt){      // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
       catch(overflow_error & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
       catch(out_of_range & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
   }
   //tests top on empty stack
   if (test == 2) {
       try{
          std::cout << "\nstack2 constructor called";
          stack<int> stack2;
          std::cout << "\nstack2 top: ";
          std::cout<<stack2.top();
          std::cout << std::endl;
       }
       catch(underflow_error & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
       catch(overflow_error & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
       catch(out_of_range & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
   }
   //tests pop from an empty stack
   if (test == 3) {
       try{
          std::cout << "\nstack3 constructor called";
          stack<int> stack3;
          std::cout<<"\npop from empty stack\n";
          stack3.pop();
          std::cout << std::endl;
       }
       catch(underflow_error & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
       catch(overflow_error & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
       catch(out_of_range & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
   }
   //tests push to a full stack
   if (test == 4) {
       try{
          std::cout << "\nstack4 constructor called";
          stack<int> stack4;
          std::cout << "\npush 20 elements";
          for(int i = 1; i <=20; ++i){
              stack4.push(i);
          }
          std::cout<<"\nstack4 top: ";
          std::cout<<stack4.top();
          std::cout<<"\npush 21\n";
          stack4.push(21);
          std::cout << std::endl;
       }
       catch(underflow_error & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
       catch(overflow_error & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
       catch(out_of_range & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
   }
   //tests stack of strings
   if (test == 5) {
       try{
          std::cout << "\nstack5 constructor called";
          stack<std::string> stack5;
          std::cout << "\npush A";
          stack5.push("A");
          std::cout << "\npush B";
          stack5.push("B");
          std::cout << "\npush C";
          stack5.push("C");
          std::cout << "\nstack5 top: ";
          std::cout<<stack5.top();
          std::cout << "\npop";
          stack5.pop();
          std::cout << "\nstack5 top: ";
          std::cout<<stack5.top();
          std::cout << "\npop";
          stack5.pop();
          std::cout << "\nstack5 top: ";
          std::cout<<stack5.top();
          std::cout << "\npop";
          stack5.pop();
          if(stack5.empty()){
              std::cout<<"\nstack5 is empty.";
          }
          else{
              std::cout<<"\nstack5 is not empty";
          }
          std::cout << "\nstack5 top: \n";
          stack5.top();
          std::cout << endl;
       }
       catch(underflow_error & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
       catch(overflow_error & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
       catch(out_of_range & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
   }

   //tests stack of strings
   if (test == 6) {
       try{
          std::cout << "\nstack6 constructor called";
          stack<std::string> stack6;
          std::cout << "\npush A";
          stack6.push("A");
          std::cout << "\npush B";
          stack6.push("B");
          std::cout << "\npush C";
          stack6.push("C");
          std::cout << "\nstack5 top: ";
          std::cout<<stack6.top();
          std::cout << "\npopping two items";
          stack6.pop_two();
          std::cout << "\nstack5 top: ";
          std::cout<<stack6.top();
          std::cout << "\npopping 2 items\n";
          stack6.pop_two();
          std::cout << "\nstack5 top: ";
          std::cout<<stack6.top();
          std::cout << "\npopping two items\n";
          stack6.pop_two();
          if(stack6.empty()){
              std::cout<<"\nstack6 is empty.";
          }
          else{
              std::cout<<"\nstack6 is not empty";
          }
          std::cout << "\nstack6 top: \n";
          stack6.top();
          std::cout << std::endl;
       }
       catch(underflow_error & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
       catch(overflow_error & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
       catch(out_of_range & excpt){       // catches whatever exception is thrown
           std::cout<<excpt.what()<<std::endl;
       }
   }
    return 0;
}