#pragma once
#include "sqlite3.h"
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include "Event.h"
#include "Time.h"
#include "Data-structure-project-main/BinaryTree.h"
#include "Data-structure-project-main/BinaryTree.cpp"
#define ACTIVETABLENAME "Events"
#define ARCHIVETABLENAME "Archive"
using namespace std;
class Database
{
public:
	int rc;
    string query;
	char* err = 0;
	const char* data = "Callback function called";
	sqlite3* db;
	sqlite3_stmt* stmt;
	Database();
    void CreateTable(string tableName);
    void Insert(string tableName,Event event);
    void SelectAll(string tableName,BSTree<Event>* model);
    void Update(string tableName, Event event);
    void Delete(string tableName,string eventName);
	~Database();
};




