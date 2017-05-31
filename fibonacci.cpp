/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the implementation for fibonacci() as well as any
 *    other function or class implementations you may need
 * Author
 *    <your names here>
 **********************************************************************/

#include <iostream>
#include "fibonacci.h"   // for fibonacci() prototype
#include "list.h"        // for LIST
using namespace std;


/************************************************
 * FIBONACCI
 * The interactive function allowing the user to
 * display Fibonacci numbers
 ***********************************************/
void fibonacci()
{
   // show the first serveral Fibonacci numbers
   int number;
   cout << "How many Fibonacci numbers would you like to see? ";
   cin  >> number;

   // your code to display the first <number> Fibonacci numbers
   int count = 0;
   int a = 0;
   int b = 1;
   int c = 1;
   while (count < number)
   {
      // next fib
      c = a + b;
      a = b;
      b = c;
      // print result
      cout << a << endl;
      
      // update previous fibs

      
      // update count
      count++;
   }

   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;

   // your code to display the <number>th Fibonacci number
   count = 0;
   a = 0;
   b = 1;
   c = 1;
   while(count < number)
   {
      // next fib
      c = a + b;
      
      // update previous fibs
      a = b;
      b = c;
      
      // update count
      count++;
   }
   
   // print fib
   cout << a << endl;
}


