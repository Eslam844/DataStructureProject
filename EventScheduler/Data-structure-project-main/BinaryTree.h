#pragma once
#include "Data-structure-project-main/Event.h"
template <class T>
class Node
{
public:
    T *value;
    Node<T>* left, * right, *parent;
    Node();
    Node(T *val);
};

template <class T>
class BSTree
{

    Node<T>* root;
    int size;
public:
    BSTree(void);
    bool contains(T* val);
    Node<T>* findNode(T *val);
    int length();
    void insert(T *val);
    void Remove(T *val);
    T* getRoot();
    Node<T>* findparent(T* val);
    void deleteBST(Node<T>* val);
    Node<T>* findMin(Node<T>* val);
    Node<T>* findMin();
    void Update(T *val);
    void traverse(int order);
    void inOrder(Node<T>* start);
    void preOrder(Node<T>* start);
    void postOrder(Node<T>* start);
    ~BSTree(void);
};
