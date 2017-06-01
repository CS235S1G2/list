/***********************************************************************
* Header:
*    LIST
* Summary:
*    An implementation of the std::list class
* Author
*    Nathan Bench, Jed Billman, Jeremy Chandler, Justin Chandler
************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert>


// forward declarations
template <class T>            // 49
class Node;

template <class T>
class ListIterator;           // 136

template <class T>
class ListConstIterator;

/****************************************************
* LIST
* A class that holds things in a list
*****************************************************/
template <class T >
class List
{
public:
	List(): pHead(NULL), pTail(NULL), numItems(0) {};
	List(const List <T> & rhs) throw (const char *);
	~List();
   
   // operator
   List <T> & operator = (const List <T> & rhs) throw (const char *);
   
   // std container interfaces
	bool empty()         { return !pHead && !pTail && (numItems == 0); }
	int size()           { return numItems;                            }
	void clear();
   
   // list specific
	void push_back(const T & item) throw (const char *);
	void push_front(const T & item) throw (const char *);
	void remove(ListIterator<T> & it) throw (const char *);
	T & front() throw (const char *);
	T & back() throw (const char *);
   
	ListIterator <T> insert(T & item, ListIterator <T> & it) throw (const char *);
   
	// iterators
	ListIterator <T> begin()    { return ListIterator <T>(pHead); }
	ListIterator <T> rbegin()   { return ListIterator <T>(pTail); }
	ListIterator <T> end()      { return ListIterator <T>(NULL); }
	ListIterator <T> rend()     { return ListIterator <T>(NULL); }

private:
   Node <T> * pHead;
   Node <T> * pTail;
   int numItems;
};

/***********************************************
 * Node
 * A node to be used in a linked list
 **********************************************/
template <class T>
class Node
{
   public:
      // constructors
      Node(): pNext(NULL), pPrev(NULL) {}
      Node(const T & t): data(t), pNext(NULL), pPrev(NULL) {}
      
      // members
      Node <T> * pNext, * pPrev;
      T data;
};

/***********************************************
 * LIST :: CLEAR
 * clear the list
 **********************************************/
template<class T>
void List<T> :: clear()
{

}

/***********************************************
 * LIST :: PUSH BACK
 * push item to back of list
 * CITE: Brother Jones
 **********************************************/
template <class T> 
void List <T> ::push_back(const T & data) throw (const char *) 
{ 
   try 
   { 
      // create the node 
      Node <T> * pNew = new Node <T>(data); 

      // point it to the old tail 
      pNew->pPrev = pTail; 

      // now point tail to the new guy 
      if (pTail != NULL) 
         pTail->pNext = pNew; 
      else 
         pHead = pNew; // there is no tail so there is no head! 
      // finally, this is the new tail 
      pTail = pNew; 
      numItems++; 
   } 
   catch (...) 
   { 
      throw "ERROR: unable to allocate a new node for a list"; 
   } 
} 

/***********************************************
 * LIST :: PUSH FRONT
 * push item to front of list
 **********************************************/
template<class T>
void List<T>::push_front(const T & item) throw(const char *)
{

}

/***********************************************
 * LIST :: REMOVE
 * remove item from list
 **********************************************/
template<class T>
void List<T>::remove(ListIterator<T>& it) throw(const char *)
{

}

/***********************************************
 * LIST :: FRONT 
 * access front of list
 **********************************************/
template<class T>
T & List<T>::front() throw(const char *)
{
	if (pHead != NULL)
      return pHead->data;
   else
      throw "Error: unable to access data from an empty list";
}

/***********************************************
 * LIST :: BACK
 * access back of list
 **********************************************/
template<class T>
T & List<T>::back() throw(const char *)
{
   if (pTail != NULL)
      return pTail->data;
   else
      throw "Error: unable to access data from an empty list";
}

/***********************************************
 * LIST :: INSERT
 * sinsert an item into list
 **********************************************/
template<class T>
ListIterator<T> List<T>::insert(T & item, ListIterator<T> & it) throw(const char *)
{
	return ListIterator<T>();
}




/************************************************* 
* LIST ITERATOR 
* Iterate through a List, non-constant version
* CITE: Brother Jones 
************************************************/ 
template <class T> 
class ListIterator 
{ 
public: 
   // default constructor: not pointing to anything 
  ListIterator() : p(NULL) {} 

   // non-default constrictor taking a pointer as a parameter 
  ListIterator(Node <T> * p) : p(p) {} 

   // copy constructor 
  ListIterator(const ListIterator <T> & rhs) : p(rhs.p) {} 

   // assignment operator 
   ListIterator <T> & operator = (const ListIterator <T> & rhs) 
   { 
      p = rhs.p; 
      return *this; 
   } 

   // dereference operator, fetch a node 
   T & operator * () throw (const char *) 
   { 
      if (p) 
         return p->data; 
      else 
         throw "ERROR: Trying to dereference a NULL pointer"; 
   } 

   // equals operator: are the iterators the same? 
   bool operator == (const ListIterator <T> & rhs) const 
   { 
      return rhs.p == this->p; 
   } 

   // not-equals operator: are the iterators different? 
   bool operator != (const ListIterator <T> & rhs) const 
   { 
      return rhs.p != this->p; 
   } 

   // postfix increment 
   ListIterator <T> operator ++ (int postfix) 
   { 
      ListIterator <T> old(*this); 
      assert(p); 
      p = p->pNext; 
      return old; 
   } 

   // prefix increment 
   ListIterator <T> & operator ++ () 
   { 
      assert(p); 
      p = p->pNext; 
      return *this; 
   } 

   // postfix decrement 
   ListIterator <T> operator -- (int postfix) 
   { 
      ListIterator <T> old(*this); 
      assert(p); 
      p = p->pPrev; 
      return old; 
   } 

   // prefix decrement 
   ListIterator <T> & operator -- () 
   { 
      assert(p); 
      p = p->pPrev; 
      return *this; 
   } 

   // two friends who need to access p directly 
   friend ListIterator <T> List <T> ::insert(ListIterator <T> & it, 
                                             const T & data) 
      throw (const char *); 
   friend ListIterator <T> List <T> ::remove(ListIterator <T> & it) 
      throw (const char *); 

private: 
   Node <T> * p; 

}; 

/************************************************* 
* LIST CONST ITERATOR 
* Iterate through a List, the constant version
* CITE: Brother Jones 
************************************************/ 
template <class T> 
class ListConstIterator 
{ 
public: 
   // default constructor: not pointing to anything 
  ListConstIterator() : p(NULL) {} 

   // non-default constrictor taking a pointer as a parameter 
  ListConstIterator(const Node <T> * p) : p(p) {} 

   // copy constructor 
  ListConstIterator(const ListConstIterator <T> & rhs) : p(rhs.p) {} 

   // assignment operator 
   ListConstIterator <T> & operator = (const ListConstIterator <T> & rhs) 
      { 
         p = rhs.p; 
         return *this; 
      } 

   // dereference operator, fetch a node 
   // this is the only real difference between ListConstIterator and the other 
   T operator * () const { return p->data; } 

   // equals operator: are the iterators the same? 
   bool operator == (const ListConstIterator <T> & rhs) const 
   { 
      return rhs.p == this->p; 
   } 

   // not-equals operator: are the iterators different? 
   bool operator != (const ListConstIterator <T> & rhs) const 
   { 
      return rhs.p != this->p; 
   } 

   // postfix increment 
   ListConstIterator <T> operator ++ (int postfix) 
   { 
      ListConstIterator <T> old(*this); 
      assert(p); 
      p = p->pNext; 
      return old; 
   } 

   // prefix increment 
   ListConstIterator <T> & operator ++ () 
   { 
      assert(p); 
      p = p->pNext; 
      return *this; 
   } 

   // postfix decrement 
   ListConstIterator <T> operator -- (int postfix) 
   { 
      ListConstIterator <T> old(*this); 
      assert(p); 
      p = p->pPrev; 
      return old; 
   } 

   // prefix decrement 
   ListConstIterator <T> & operator -- () 
   { 
      assert(p); 
      p = p->pPrev; 
      return *this; 
   } 

private: 
   const Node <T> * p; 

};

#endif // LIST_H
