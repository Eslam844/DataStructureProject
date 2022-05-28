#ifndef TASKSCHDULERINTERFACE_H
#define TASKSCHDULERINTERFACE_H
#include <windows.h>
#include <initguid.h>
#include <ole2.h>
#include <mstask.h>
#include <msterr.h>
#include <fstream>
#include <wchar.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
class TaskSchdulerInterface
{
    fstream file;
public:
    TaskSchdulerInterface();
    void schedule(string taskName,string time);
};

#endif // TASKSCHDULERINTERFACE_H
