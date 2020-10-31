#ifndef NODE_H
#define NODE_H

namespace cs273 {
    template <typename T>
    struct Node {
        Node<T>* next;
        Node<T>* prev;
        T data;

        Node<T>(T item, Node<T>* pnext = NULL, Node<T>* pprev = NULL) : data(item), next(pnext), prev(pprev) {}
    };
}

#endif