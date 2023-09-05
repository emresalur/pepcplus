#ifndef TREE_H
#define TREE_H

#include "treenode.h"

// TODO your code goes here:

template<typename T>
class BinarySearchTree {

private:
  unique_ptr<TreeNode<T>> root;

public:
  BinarySearchTree() {

  }

  void write(ostream & os) {
    root->write(os);
  }

  TreeNode<T>* insert(T item){
    TreeNode<T>* currentTreeNode = root.get();

    if(currentTreeNode == nullptr){
      TreeNode<T>* newNode = new TreeNode<T>(item);
      newNode->leftChild = nullptr;
      newNode->rightChild = nullptr;
      root.reset(newNode);
      currentTreeNode = newNode;
      return newNode;
    }

    while(currentTreeNode != nullptr) {

      if(item < currentTreeNode->data) {
        if(currentTreeNode->leftChild == nullptr) {
          TreeNode<T>* newNode = new TreeNode<T>(item);
          currentTreeNode->setLeftChild(newNode);
          currentTreeNode = newNode;
          return newNode;
        }
        else {
          currentTreeNode = currentTreeNode->leftChild.get();
        }
      }
      else if(currentTreeNode->data < item) {
        if(currentTreeNode->rightChild == nullptr) {
          TreeNode<T>* newNode = new TreeNode<T>(item);
          currentTreeNode->setRightChild(newNode);
          currentTreeNode = newNode;
          return newNode;
        }
        else {
          currentTreeNode = currentTreeNode->rightChild.get();
        }
      }
      else {
        return currentTreeNode;
      }
    }
    return currentTreeNode;
  }

  TreeNode<T>* find(T item) {
    TreeNode<T> *currentTreeNode = root.get();
    if(currentTreeNode == nullptr) {
      return nullptr;
    }
    while (currentTreeNode != nullptr) {
      if(item < currentTreeNode->data) {
        if(currentTreeNode->leftChild == nullptr) {
          return nullptr;
        }
        currentTreeNode = currentTreeNode->leftChild.get();
      }
      else if(item > currentTreeNode->data) {
        if(currentTreeNode->rightChild == nullptr) {
          return nullptr;
        }
        else {
          currentTreeNode = currentTreeNode->rightChild.get();
        }
      }
      else {
        return currentTreeNode;
      }
    }
    return currentTreeNode;
    }
};

// do not edit below this line

#endif
