#pragma once
#include<string>
#include<time.h>
#include <ctime>
using namespace std;
class convert {
private:
    int month = -1;
    int day = -1;
    int year = -1;
    int hour = -1;
    int minutes = -1;
    struct tm data = {};
public:
    convert(string date);
    time_t AsLong();
    string AsString();

};

