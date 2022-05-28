#ifndef BTITERATOR_H
#define BTITERATOR_H
#include"Data-structure-project-main/BinaryTree.h"
#include "Data-structure-project-main/BinaryTree.cpp"
#include <assert.h>
template<class T>
class InOrderBTIterator
{
private:
    Node<T>* currentNode;
    int side;
    int maxHeight;
    int currentHeight;
    bool secondTime;
    T* reset();
    T* handleLeftNode();
    T* handleRightNode();
    T* handleParentNode();
public:
    int length;
    InOrderBTIterator(BSTree<T>* tree);
    T* getNext();
    T* getByIndex(int index);
};

#endif // BTITERATOR_H
