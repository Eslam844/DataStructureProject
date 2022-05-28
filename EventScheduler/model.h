#pragma once
#include <string>
#include <iostream>
#include "Data-structure-project-main/BinaryTree.h"
#include "Data-structure-project-main/BinaryTree.cpp"
#include "Data-structure-project-main/Event.h"
#include "Data-structure-project-main/Database.h"
#include "Data-structure-project-main/btiterator.h"
#include "Data-structure-project-main/btiterator.cpp"
#include <assert.h>
using namespace std;
class Model
{
    Database *db;
    string tableName;
public:
    BSTree<Event>* tree;
    void Insert(Event* event);
    void Delete(int index);
    void Update(int index, Event* event);
    void Clear();

    Event* At(int index);
    Model(string tableName);
    int Length();
    ~Model();
};// MODEL_H
