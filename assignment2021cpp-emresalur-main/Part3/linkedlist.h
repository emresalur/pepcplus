#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code goes here:
template<typename T>
class LinkedList {
private:
  Node<T>* head;
  Node<T>* tail;
  int count;
  Node<T>* newNode;

public:
  LinkedList() {
    head = nullptr;
    tail = nullptr;
    count = 0;
  }
  void push_front(const T & item) {
    newNode = new Node<T>(item);
    if(head == nullptr) {
      head = newNode;
      tail = newNode;
    }
    else {
      head->previous = newNode;
      newNode->next = head;
      head = newNode;
    }
    count++;
  }

  T & front() {
    return head->data;
  }

  void push_back(const T & item) {
    newNode = new Node<T>(item);
    if(tail == nullptr) {
      head = newNode;
      tail = newNode;
    }
    else {
      tail->next = newNode;
      newNode->previous = tail;
      tail = newNode;
    }
    count++;
  }

  T & back() {
    return tail->data;
  }

  int size() {
    return count;
  }

  NodeIterator<T> begin() const {
    return NodeIterator<T>(head);
  }

  NodeIterator<T> end() const {
    return nullptr;
  }

  ~LinkedList() {
    while (head->next != nullptr) {
      Node<T>* temp = head;
      head = head->next;
      delete temp;
    }
    delete head;
  }

  void reverse() {
    Node<T> *currentNode = head;
    Node<T> *prev = NULL, *next = NULL;
    while (currentNode != NULL) {
      next = currentNode->next;
      currentNode->next = prev;
      prev = currentNode;
      currentNode = next;
    }
    head = prev;
  }
};

// do not edit below this line

#endif
