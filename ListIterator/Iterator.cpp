#include "Iterator.h"
#include "Node.h"
#include "List.h"


template <class Type>
cs273::iterator<Type>::iterator(): parent(NULL), current(NULL) {}

template <class Type>
cs273::iterator<Type>::iterator(const list<Type>* prnt, Node<Type>* pos): parent(prnt), current(pos) {}

template <class Type>
Type& cs273::iterator<Type>::operator*() const {
    if(current == NULL) {
        throw std::invalid_argument("Attempt to dereference NULL iterator");
    }
    return current->data;
}

template <class Type>
Type* cs273::iterator<Type>::operator->() const {
    if (current == NULL){
        throw std::invalid_argument("Attempt to dereference NULL iterator");
    }
    return &(current->data);
}

template <class Type>
cs273::iterator<Type>& cs273::iterator<Type>::operator++(int) {
    if(current == NULL) {
        throw std::invalid_argument("attempt to advance past end()");
    }
    current = current->next;
    return *this;
}

template <class Type>
cs273::iterator<Type>& cs273::iterator<Type>::operator++() {
    if(current == NULL) {
        throw std::invalid_argument("attempt to advance past end()");
    }
    current = current->next;
    return *this;
}

template <class Type>
cs273::iterator<Type>& cs273::iterator<Type>::operator--(int) {
    if(current == NULL) {
        throw std::invalid_argument("attempt to decrement past begin()");
    }
    current = current->prev;
    return *this;
}

template <class Type>
cs273::iterator<Type>& cs273::iterator<Type>::operator--() {
    if(current == NULL) {
        throw std::invalid_argument("attempt to decrement past begin()");
    }
    current = current->prev;
    return *this;
}

template <class Type>
bool cs273::iterator<Type>::operator==(const iterator& i) {
    return (current == i.current) && (parent == i.parent); 
}

template <class Type>        
bool cs273::iterator<Type>::operator!=(const iterator& i) {
    return !(this->operator==(i)); 
}


