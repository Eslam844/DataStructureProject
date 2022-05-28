#include<string>
#include<time.h>
#include<cstdlib>
#include <ctime>
#include "Event.h"

using namespace std;
Event::Event(string name, string place, string start_date, string end_date, string reminder_time) : reminder_time(convert(reminder_time)), start_date(convert(start_date)), end_date(convert(end_date)) {
    this->name = name;
    this->place = place;
    Event_time = difftime(this->end_date.AsLong(), this->start_date.AsLong());
}
string Event::getName() {
    return this->name;
}
string Event::getPlace() {
    return this->place;
}
string Event::getReminder() {
    return this->reminder_time.AsString();
}
long long Event::getEvent_time() {
    return this->Event_time;
}
string Event::getStartDate() {
    return this->start_date.AsString();
}
string Event::getEndDate() {
    return this->end_date.AsString();
}
bool Event::isDone(Event* e) {
    time_t t = time(0);
    if (t >= e->end_date.AsLong()) {
        return true;
    }
    else return false;
}
string Event::display() {
    string eventData = "The name of the event: " + getName() + "\n"
        + "The place of the event: " + getPlace() + "\n"
        + "The start date of the event since: " + getStartDate() + "\n"
        + "The end date of the event: " + getEndDate() + "\n"
        + "The reminder date of the event:" + getReminder() + "\n";
    return eventData;
}
bool Event::operator==(Event e) {
    /*if ((this->start_date.AsLong() <= e.start_date.AsLong() && this->end_date.AsLong() > e.start_date.AsLong()) || (e.start_date.AsLong() >= this->start_date.AsLong() && e.start_date.AsLong() < this->end_date.AsLong())) {
        return true;
    }*/
    if(this->reminder_time.AsLong() == e.reminder_time.AsLong()) {
        return true;
    }
    else {
        return false;
    }

    //function 3adya htkarn feha this b e w htrg3 true lw equal b3d
}
bool Event::operator <(Event e) {
    if (this->reminder_time.AsLong() < e.reminder_time.AsLong()) {
        return true;
    }
    else {
        return false;
    }
    //function 3adya htkarn feha this b e w htrg3 true lw this < e
}
bool Event::operator >(Event e) {
    if (this->reminder_time.AsLong() > e.reminder_time.AsLong()) {
        return true;
    }
    else {
        return false;
    }
    //function 3adya htkarn feha this b e w htrg3 true lw this > e
}
bool Event::operator <=(Event e) {
    if ((this->reminder_time.AsLong() < e.reminder_time.AsLong()) || (this->reminder_time.AsLong() == e.reminder_time.AsLong())) {
        return true;
    }
    else {
        return false;
    }
    //function 3adya htkarn feha this b e w htrg3 true lw this <= e
}
bool Event::operator >=(Event e) {
    if ((this->reminder_time.AsLong() > e.reminder_time.AsLong()) || (this->reminder_time.AsLong() == e.reminder_time.AsLong())) {
        return true;
    }
    else {
        return false;
    }
    //function 3adya htkarn feha this b e w htrg3 true lw this >= e
}
ostream& Event::opdefine(ostream& COUT, Event* e) {
    COUT << "Event name: " << e->name << endl << "Event place: " << e->place << endl
        << "Event start date: " << e->start_date.AsString() << endl << "Event end date: " << e->end_date.AsString() << endl
        << "Event time: " << e->getEvent_time() << endl << "Event reminder date: " << e->reminder_time.AsString() << endl
        << "------------------------------------------------------------------" << endl;
    return COUT;
}
//b3d ma t3ml l operators ht2dr tst5dm == w kda fel if conditions 3ady zyo zy ay class tany
