#include "list.h"
#include <iostream>
#include <algorithm>

//Default constructor. Set everything to NULL
template <typename T>
cs273::list<T>::list() : head(NULL), tail(NULL), count(0) {}

//Copy constructor -- copy all items into this list
template <typename T>
cs273::list<T>::list(const list<T>& other) : head(NULL), tail(NULL), count(0) {
    for (Node<T>*p = other.head; p != NULL; p=p->next)
        push_back(p->data);
}

//Clean up all memory
template <typename T>
cs273::list<T>::~list() {
    int i=0;
    Node<T>* p = head;
    while (p != NULL) {
        Node<T>*tmp = p;
        p = p->next;
        delete tmp;
        i++;
    }
}

//Get iterator to first item
template <typename T>
cs273::iterator<T> cs273::list<T>::begin() const {
    return iterator(this, head);    
}

//Get iterator for last item
template <typename T>
cs273::iterator<T> cs273::list<T>::end() const {
    return iterator(this, NULL);    
}

//How many items?
template <typename T>
int cs273::list<T>::size() { return count; }

//Is this list empty?
template <typename T>
bool cs273::list<T>::empty() { return size() == 0; }

//Get the front item. Throw exception if there's nothing at the front
template <typename T>
T cs273::list<T>::front() {
    if (head == NULL)
        //Nothing here, get out with exception
        throw std::invalid_argument("front: Attempt to dereference NULL iterator");
    return head->data;
}

//Get the last item. Throw exception if there's nothing at the end
template <typename T>
T cs273::list<T>::back() {
    if (tail == NULL)
        //Nothing here, get out with exception
        throw std::invalid_argument("back: Attempt to dereference NULL iterator");
    return tail->data;
}

//Put a new item at the front of the list. Throws an exception if there's no memory
template <typename T>
void cs273::list<T>::push_front(T item) {
    //New item. It's next node is the head
    Node<T>* newitem = new Node<T>(item, head, NULL);
    if (newitem == NULL) {
        std::cout << "PF: something's wrong\n";
        throw std::bad_alloc();
    }
    //If this is empty, head and tail point to the new item
    if (tail == NULL)
        tail = newitem;
    //If we have something at head, that node's prev point to the new item
    if (head != NULL)
        head->prev = newitem;

    head = newitem;
    count++;
}

//Remove the front item, throw an exception if there's nothing there.
template <typename T>
void cs273::list<T>::pop_front() {
    if (head == NULL)
        //Get out
        throw std::invalid_argument("PF: Attempt to dereference NULL iterator");

    Node<T>*tmp = head;
    //The new head is the second node (if it exists)
    head = head->next;
    //Get rid of the old head.
    delete tmp;
    if (head == NULL)
        //The list is now empty, tail should be NULL too.
        tail = NULL;
    else
        //Make sure the new head isn't pointing to a node.
        head->prev = NULL;
    count--;
}

//Add an item to the end of the list. If there's no more memory, throw an exception
template <typename T>
void cs273::list<T>::push_back(T item) {
    Node<T>* newitem = new Node<T>(item, NULL, tail);
    if (newitem == NULL) {
        //OOM exception
        std::cout << "PB: something's wrong\n";
        throw std::bad_alloc();
    }
    
    if (head == NULL)
        //If this is the first node, head and tail both point to it.
        head = newitem;
    if (tail != NULL)
        //If there's a node at the end, it points to this new tail
        tail->next = newitem;

    tail = newitem;

    count++;
}

//Remove the last item. If the list is empty, throw an exception
template <typename T>
void cs273::list<T>::pop_back() {
    if (tail == NULL)
        throw std::invalid_argument("PB: Attempt to dereference NULL iterator");

    Node<T>* tmp = tail;
    //The tail moves back one, since we're removing the current tail
    tail = tail->prev;
    delete tmp;
    if (tail == NULL)
        //If the list is empty, head needs to be NULL too
        head = NULL;
    else
        //Make sure the new tail doesn't point to anything
        tail->next = NULL;
    count--;
}

//Add a new item right before the curr parameter, and return an iterator to the new item
template <typename T>
cs273::iterator<T> cs273::list<T>::insert(iterator curr, T item) {
    Node<T>* c = curr.current;
    Node<T>* newitem = NULL;
    if (c == NULL) {
        //First node in the list
        newitem = new Node<T>(item, NULL, NULL);
        if (newitem == NULL) {
            //Out of memory. Get out
            std::cout << "I0: something's wrong\n";
            throw std::bad_alloc();
        }
        //head and tail both need to point to this singleton node.
        head = tail = newitem;
    }
    else {
        //Add an item, right before the given iterator curr
        newitem = new Node<T>(item, c, c->prev);
        if (newitem == NULL) {
            //Out of memory. Get out
            std::cout << "I1: something's wrong\n";
            throw std::bad_alloc();
        }
        if (c->prev != NULL) {
            //If the given node is not the head make sure the previous node pointers are updated to point to the new node
            c->prev->next = newitem;
            c->prev = newitem;
        }
        else {
            //We have a new head node.
            head->prev = newitem;
            head = newitem;
        }
    }
    count++;
    return iterator(this, newitem);
}

//Remove this item, and return the node that follows it
template <typename T>
cs273::iterator<T> cs273::list<T>::erase(iterator i) {
    Node<T>* tmp = i.current;
    Node<T>* ret = tmp->next;
    if (tmp->prev != NULL)
        //Make sure the previous node points to the node that follows this one.
        tmp->prev->next = tmp->next;
    if (tmp->next != NULL)
        //Make sure the next node points to the node that precedes this one
        tmp->next->prev = tmp->prev;
    delete tmp;
    count--;
    return iterator(this, ret);
}

//Copy constructor
template <typename T>
cs273::list<T>& cs273::list<T>::operator=(const list<T>& other) {
    //Deep copy of data
    for (Node<T>*p = other.head; p != NULL; p=p->next)
        push_back(p->data);

    return *this;
}

//Debugging -- output the current list
template <typename T>
void cs273::list<T>::print() {
    for (Node<T>*p = head; p!=NULL; p=p->next) {
        std::cout << p->data;
        if (p->next == NULL) std::cout << "\n"; else std::cout << ", ";
    }
}