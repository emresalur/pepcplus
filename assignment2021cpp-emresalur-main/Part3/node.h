#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code for the Node class goes here:

template <typename T>
class Node {

public:
  T data;
  Node<T>* next;
  Node<T>* previous;
  
  Node(T item) {
    data = item;
    next = nullptr;
    previous = nullptr;
  }
};

// (Note the 'NodeIterator' class will report lots of errors until Node exists

template<typename T>
class NodeIterator {

private:

    Node<T>* current;

public:

    NodeIterator(Node<T>* currentIn)
        : current(currentIn) {
    }

    T & operator*() {
        return current->data;
    }

    // TODO: complete the code for NodeIterator here

    NodeIterator operator++() {
      if(current != nullptr) {
        current = current->next;
      }
      return *this;
    }

    bool operator==(NodeIterator& iterator) {
      return current == iterator.current;
    }

    bool operator!=(NodeIterator& iterator) {
      return current != iterator.current;
    }

};

// do not edit below this line

#endif
