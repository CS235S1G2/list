/***********************************************************************
 * Header:
 *    FIBONACCI
 * Summary:
 *    This will contain just the prototype for fibonacci(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Nathan Bench, Jed Billman, Jeremy Chandler, Justin Chandler
 ************************************************************************/

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <list>

// the interactive fibonacci program
void fibonacci();

/***********************************************
* Whole Number
* A class that holds a List of numbers of 3 digits
***********************************************/
class WholeNumber
{
   public:
      // constructors
      WholeNumber() {}
      WholeNumber(WholeNumber rhs);
      WholeNumber(unsigned int value);
      // destructor
      ~WholeNumber();
      
      // operators
      WholeNumber & operator = (const WholeNumber & rhs);
      WholeNumber & operator += (const WholeNumber & rhs);
      
   private:
      std::list <int> data;
};

std::ostream & operator << (std::ostream & out, const WholeNumber & rhs)
{
   
}

WholeNumber & WholeNumber :: operator = (const WholeNumber & rhs)
{
   
}

WholeNumber & WholeNumber :: operator += (const WholeNumber & rhs)
{
   // Iterate through data
   // add values from this and rhs
   // carry values above 999
}

#endif // FIBONACCI_H

