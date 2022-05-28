#pragma once
#include "Data-structure-project-main/BinaryTree.h"
#include "Data-structure-project-main/Event.h"
#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
Node<T>::Node()
{
    parent = NULL;
    left = right = NULL;
}

template <class T>
Node<T>::Node(T *val)
{
    value = val;
    parent = NULL;
    left = right = NULL;
}

template <class T>
BSTree<T>::BSTree(void)
{
    root = NULL;
    size = 0;
}
template<class T>
int BSTree<T>::length() { return size;}
template <class T>
bool BSTree<T>::contains(T* val)
{
    Node<T>* tmp = findNode(val);

    return (tmp != NULL);
}

template <class T>
Node<T>* BSTree<T>::findNode(T* val)
{
    Node<T>* tmp = root;

    while (tmp != NULL){
        if((!(*(tmp->value) == *val))) break;
        if (*(tmp->value) > *val)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    if(tmp == NULL) {return NULL;}
    return tmp;
}
template <class T>
T* BSTree<T>::getRoot(){
    if(root == NULL) return NULL;
    return root->value;
}
template <class T>
void BSTree<T>::insert(T* val)
{
    Node<T>* tmp = root;
    Node<T>* newNode = new Node<T>(val);
    if (root == NULL)
        root = newNode;
    else
    {
        while (true)
        {
            if (*(tmp->value) > *val)
                if (tmp->left == NULL)
                {
                    newNode->parent = tmp;
                    tmp->left = newNode;
                    break;
                }
                else
                    tmp = tmp->left;
            else
                if (tmp->right == NULL)
                {
                    newNode->parent = tmp;
                    tmp->right = newNode;
                    break;
                }
                else
                    tmp = tmp->right;
        }
    }
    size++;
}


template <class T>
void BSTree<T>::traverse(int order)
{
    if (order == 1)
        inOrder(root);
    else if (order == 2)
        preOrder(root);
    else
        postOrder(root);
}

template <class T>
void BSTree<T>::inOrder(Node<T>* start)
{
    if (start != NULL)
    {
        inOrder(start->left);
        cout << (start->value) << endl;
        inOrder(start->right);
    }
}

template <class T>
void BSTree<T>::preOrder(Node<T>* start)
{
    if (start != NULL)
    {
        cout << *(start->value) << endl;
        preOrder(start->left);
        preOrder(start->right);
    }
}

template <class T>
void BSTree<T>::postOrder(Node<T>* start)
{
    if (start != NULL)
    {
        postOrder(start->left);
        postOrder(start->right);
        cout << *(start->value) << endl;
    }
}
template <class T>
Node<T>* BSTree<T>::findparent(T* val)
{
    assert(contains(val));
    Node<T>* child = root;
    Node<T>* parent = NULL;
    if(child == NULL) return NULL;
    while (true) {
        if (*val > *(child->value)) {
            parent = child;
                child = child->right;
        }
        else if (*val < *(child->value)) {
            parent = child;
            child = child->left;
        }
        else if (*val == *(child->value)) {
            break;
        }
    }
    return parent;
}
template <class T>
Node<T>* BSTree<T>::findMin(Node<T>* start)
{
    Node<T>* minNode = start;
    if(start == NULL) return NULL;
    while (minNode->left != NULL)
    {
        minNode = minNode->left;
    }

    return minNode;
}
template <class T>
Node<T>* BSTree<T>::findMin()
{
    Node<T>* minNode = root;
    if(root == NULL) return NULL;
    while (minNode->left != NULL)
    {
        minNode = minNode->left;
    }
    return minNode;
}
template <class T>
void BSTree<T>::Remove(T* val)
{
    assert(contains(val));
    if(root == NULL) return;
    Node<T>* n = findNode(val);

    if ((n->left == NULL) && (n->right == NULL)) //deleting a leaf node
    {
        if (n == root)
        {
            root = NULL;
        }
        else
        {
            Node<T>* parent = findparent(val);
            if (*(parent->value) > *val)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        delete n;
    }
    else if ((n->left == NULL) && (n->right != NULL))
    {
        Node<T>* parent = findparent(val);
        if (n == root)
        {
            root = n->right;
        }
        else
        {
            if (*(parent->value) > *val)
                parent->left = n->right;
            else
                parent->right = n->right;
        }
        delete n;
    }
    else if ((n->left != NULL) && (n->right == NULL))
    {
        Node<T>* parent = findparent(val);
        if (n == root)
            root = n->left;
        else
        {
            if (*(parent->value) > *val)
                parent->left = n->left;
            else
                parent->right = n->left;
        }
        delete n;
    }
    else
    {
        Node<T>* minNode = findMin(n->right);
        Node<T>* parent = findparent(minNode->value);

        n->value = minNode->value;

        if (parent == n)
            parent->right = minNode->right;
        else
            parent->left = minNode->right;

        delete minNode;
    }
}
/*template <class T>
void BSTree<T>::Update(T* val) {
    Remove(val);
    insert(val);

}*/
template <class T>
void BSTree<T>::deleteBST(Node<T>* node)
{
    if (!node)
        return;
    Node<T>* currentTreeNode = node;
    Node<T>* leftTreeNode = node->left;
    Node<T>* rightTreeNode = node->right;
    delete(currentTreeNode);
    deleteBST(leftTreeNode);
    deleteBST(rightTreeNode);
}
template <class T>
BSTree<T>::~BSTree(void)
{

}
