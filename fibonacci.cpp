/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the implementation for fibonacci() as well as any
 *    other function or class implementations you may need
 * Author
 *    Nathan Bench, Jed Billman, Jeremy Chandler, Justin Chandler
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
   WholeNumber a(0);
   WholeNumber b(1);
   WholeNumber c(1);
   while (count < number)
   {
      // next fib
      c = a;
      c += b;
      
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
   WholeNumber x(0);
   WholeNumber y(1);
   WholeNumber z(1);
   while(count < number)
   {
      // next fib
      z = x;
      z += y;
      
      // update previous fibs
      x = y;
      y = z;
      
      // update count
      count++;
   }
   
   // print fib
   cout << x << endl;
}

/************************************************
 * WHOLE NUMBER :: CONSTRUCTOR
 * non-default
 ***********************************************/
WholeNumber :: WholeNumber(const int & value) throw (const char *)
{
   data.push_back(value);
}

/************************************************
 * WHOLE NUMBER :: CONSTRUCTOR
 * copy
 ***********************************************/
WholeNumber::WholeNumber(const WholeNumber & rhs)
{
   *this = rhs;
}

/************************************************
 * WHOLE NUMBER :: =
 * assignment operator
 ***********************************************/
WholeNumber & WholeNumber :: operator = (const WholeNumber & rhs)
{
   data = rhs.data;
   return *this;
}

/************************************************
 * WHOLE NUMBER :: +=
 * plus equals operator
 ***********************************************/
WholeNumber & WholeNumber :: operator += (const WholeNumber & rhs)
{
   // setup variables
   int first;
   int second;
   int sum;
   int holder = 0;
   int carry;
   List <int> result;
   List <int> local(rhs.data);
   ListIterator <int> it = data.rbegin();
   ListIterator <int> itR = local.rbegin();
   
   // Iterate through data
   while (it != data.rend() || itR != local.rend())
   {
      if (itR != local.rend())
      {
         first = *itR;
         --itR;
      }
      else
         first = 0;
      
      if (it != data.rend())
      {
         second = *it;
         --it;
      }
      else
         second = 0;
      
      // add values from this and rhs
      holder = first + second + carry;
      sum = holder % 1000;
      carry = holder / 1000;
      result.push_front(sum);
   }
   
   if (carry > 0)
      result.push_front(carry);
   
   data = result;
   return *this;
}

/************************************************
 * WHOLE NUMBER :: <<
 * insertion operator
 ***********************************************/
std::ostream & operator << (std::ostream & out, const WholeNumber & rhs)
{
   List <int> local(rhs.data);
   for (ListIterator <int> it = local.begin(); it != local.end(); ++it)
   {
      if (it != local.begin())
      {
         if (*it < 99)
            out << ",0" << *it;
         else
            out << "," << *it;
      }
      else
         if (it != NULL)
            out << *it;
   }
}


