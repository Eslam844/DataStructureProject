#pragma once
#include<string>
#include <iostream>
#include<time.h>
#include<stdlib.h>
#include <ctime>
#include "Time.h"
using namespace std;

class Event {
private:
    string name;
    string place;
    convert reminder_time;
    convert start_date;
    convert end_date;
    long long Event_time;
    static ostream& opdefine(ostream& os, Event* e);
public:
    Event();
    Event(string name, string place, string start_date, string end_date, string reminder_time);
    string getName();
    string getPlace();
    string getReminder();
    long long getEvent_time();
    bool isDone(Event* e);
    string getStartDate();
    string getEndDate();
    string display();
    bool operator ==(Event b);
    bool operator <(Event b);
    bool operator >(Event b);
    bool operator <=(Event b);
    bool operator >=(Event b);
    friend ostream& operator <<(ostream& COUT, Event* E) {
        return opdefine(COUT, E);
    }
};
