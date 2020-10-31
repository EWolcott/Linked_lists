/* Iterator.h
* Developed by Scott Griffith and previous students in CS273
* Whitworth University - Last modified 2/28/2020
*
* Functional example of a linked list iterator
* Modeled after the stl::list::iterator
*
* Largely referenced from Pages 278-285 of
* Objects, Abstraction, Data Structures and Design using C++, Koffman, Wolfgang
*/
#ifndef _ITERATOR_H_
#define _ITERATOR_H_

//You will need to include your own List/Node headers
#include "List.h"
#include "Node.h"
//Keep around for proper exceptions
#include <stdexcept>

namespace cs273{

    //Pull in reference to templated List
    template<typename ListType>
    class list;

    //Pull in reference to templated Nope
    template <typename NodeType>
    class Node;

    template <class Type>
    class iterator {
        //Make sure List can access private elements of iterator
        friend class list<Type>;

        private:
            const list<Type>* parent;  // Pointer to originating List
            Node<Type>* current; // Node pointer

            // This must stay private! It needs a valid list to point to! 
            // Thus may only be called from within a List
            iterator(const list<Type>* prnt, Node<Type>* pos);

        public:
            iterator();

            // Dereference Overload
            // Returns the underlying data from the Node
            Type& operator*() const;

            // Access Overload
            // Bypass the interator and get to the data of the Node
            Type* operator->() const;
            
            // Incrament/Decrement Overload
            // Moves current pointer to the next/previous element in list
            // input: int for postfix (synatx magic)
            // output: iterator of next/previous position in list
            iterator<Type>& operator++(int);
            iterator<Type>& operator++();
            iterator<Type>& operator--(int);
            iterator<Type>& operator--();

            //Equal To / Not Equal To Overload
            //intput: iterator, other to compare
            //output==: true if equal, false if not
            //output!=: true if not equal, false if equal
            bool operator==(const iterator& i);
            bool operator!=(const iterator& i);
    };
}

namespace std {
    template <class T>
    struct iterator_traits<cs273::iterator<T>> {        
        typedef ptrdiff_t difference_type; //almost always ptrdiff_t
        typedef T value_type; //almost always T
        typedef T& reference; //almost always T& or const T&
        typedef T* pointer; //almost always T* or const T*
        typedef std::forward_iterator_tag iterator_category;  //usually std::forward_iterator_tag or similar
    };
}

#include "Iterator.cpp"

#endif