#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:

template <typename T>
class TreeNode {
public:
  T data;
  unique_ptr<TreeNode<T>> leftChild;
	unique_ptr<TreeNode<T>> rightChild;
  TreeNode<T> * parent;

  TreeNode(T dataItem) {
    data = dataItem;
    parent = nullptr;
  }

  void setLeftChild(TreeNode *child){
    leftChild.reset(child);
		leftChild->parent=this;
	}

	void setRightChild(TreeNode *child){
		rightChild.reset(child);
		rightChild->parent=this;
	}

  ostream & write(ostream & os){
		if(leftChild){
			leftChild->write(os);
		}
    os <<" " << data << " ";
		if(rightChild){
			rightChild->write(os);
		}
		return os;
	}
};

// do not edit below this line

#endif
