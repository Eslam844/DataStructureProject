#pragma once
#include "btiterator.h"
template <class T>
InOrderBTIterator<T>::InOrderBTIterator(BSTree<T>* tree)
{
    currentNode = tree->findMin();
    length = tree->length();
    currentHeight = 0;
    maxHeight = 0;
    side = 0;
}
template <class T>
T* InOrderBTIterator<T> :: reset(){
  side = 3;
  return NULL;
}
template <class T>
T* InOrderBTIterator<T>::handleLeftNode(){
    if(currentNode == NULL) return reset();
    auto tmp = currentNode->value;
    if(currentNode->parent != NULL){
    currentNode = currentNode->parent;
    currentHeight++;
    if(maxHeight <= currentHeight){
      maxHeight++;
    }
        side = 1;
    }
    else if(currentNode->right != NULL){
        currentNode = currentNode->right;
        side = 2;
    }
    return tmp;
}
template <class T>
T* InOrderBTIterator<T>::handleParentNode(){
    if(currentNode == NULL) return reset();
    T* tmp;
    if(maxHeight == currentHeight){
        tmp = currentNode->value;
        if(currentNode->right != NULL){
            currentNode = currentNode->right;
            currentHeight--;
            side = 2;
        }
        else{
            currentNode = currentNode->parent;
            currentHeight++;
            maxHeight++;
        }
    }
    else if(currentNode->right != NULL){
        currentNode = currentNode->right;
        tmp = handleRightNode();
    }
    else{
        currentHeight++;
        tmp = handleParentNode();
    }
    return tmp;
}
template <class T>
T* InOrderBTIterator<T>::handleRightNode(){
    if(currentNode == NULL) return reset();
    T* tmp;
    if(currentNode -> left != NULL){
      while(currentNode->left != NULL){
          currentHeight--;
          currentNode = currentNode->left;
       }
       tmp = handleLeftNode();
    }
    else if(currentNode -> right != NULL){
        currentNode = currentNode->right;
        currentHeight--;
        tmp = handleRightNode();
    }
    else{
      tmp = currentNode->value;
      currentNode = currentNode->parent;
      currentHeight++;
      if(currentNode->parent != NULL){
          currentNode = currentNode->parent;
          if(currentNode->parent == NULL && *tmp > *(currentNode->value)){
          reset();
          }else{
              if(currentHeight == maxHeight){
                maxHeight++;
              }
              currentHeight++;
              side = 1;
}
      }
      else{
         reset();
      }
    }
    return tmp;
}

template <class T>
T* InOrderBTIterator<T>::getNext(){
  switch(side){
    case 0:return handleLeftNode();
    case 1: return handleParentNode();
    case 2: return handleRightNode();
    case 3:
    {
      return reset();
    }
    default: return NULL;
  }
}
template <class T>
T* InOrderBTIterator<T>::getByIndex(int index){
    assert(index < length);
    T* node;
    for(int i = 0; i <= index;i++){
            node = getNext();
    }
    return node;
}
