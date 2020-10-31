#ifndef LIST_H
#define LIST_H

#include "Iterator.h"
#include "node.h"

namespace cs273 {
    template <typename T>
    class list {
    private:
        Node<T>* head;  //pointer to first node
        Node<T>* tail;  //pointer to last node
        int count;      //number of items in list

    public:
        typedef cs273::iterator<T> iterator;

        //Default constructor - NULL list
        list<T>();
        //Copy constructor
        list<T>(const list<T>& other);
        //Destructor
        ~list<T>();

        iterator begin() const; //Get iterator for first item
        iterator end() const;   //Get iterator for last item

        int size();     //How many items in the list?
        bool empty();   //Is this empty?

        T front();      //Get first data item
        T back();       //Get last data item

        void push_front(T item);    //Put item at front of list
        void pop_front();           //Remove first item
        void push_back(T item);     //Put item at end of list
        void pop_back();            //Remove last item
        iterator insert(iterator curr, T item); //Insert item before curr, return new item
        iterator erase(iterator i);             //remove item at curr, return next item

        //Assignment -- deep copy
        list<T>& operator=(const list<T>& other);

        //Debugging
        void print();
    };
}

#include "list.cpp"

#endif