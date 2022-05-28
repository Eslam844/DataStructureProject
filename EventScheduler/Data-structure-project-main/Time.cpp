#include<string.h>
#include<stdlib.h>
#include <ctime>
#include<sstream>
#include "Time.h"
#define DATESIZE 200
#define FORMAT "%2d/%2d/%4d %2d:%2d"
using namespace std;
convert::convert(string date) {
    sscanf_s(date.c_str(), FORMAT, &day, &month, &year, &hour, &minutes);
    data.tm_mon = month - 1;
    data.tm_mday = day;
    data.tm_year = year - 1900;
    data.tm_hour = hour;
    data.tm_min = minutes; //al mfrod ttl3 al seconds mn jan 1970 l7d al start_date bs howa bya5od al date al fe al cleander dlw2ty msh al start_date
    //cout << ctime(&start) << endl; //al mfrod ttl3 al seconds mn jan 1970 l7d al end_date bs howa bya5od al date al fe al cleander dlw2ty msh al end_date
}
time_t convert::AsLong() {
    return mktime(&data);
}
string convert::AsString() {
    char* buffer = (char*)malloc(DATESIZE);
    int readBytes = strftime(buffer, DATESIZE, "%d/%m/%Y %H:%M", &data);
    string bufferAsString = buffer;
    return bufferAsString;
}

/*al code al t7t dah bnst5dm feh istringstream w ndelo al foramt l m7tot dah w howa by2dr ygeb al second mn 1/1/1970 l7d al format al anta md5lo f da hys3dk
  shof lw 3rft twsl al date format l al format al gowa al istringstream dah yb2a 7wlna al date l seconds 5las*/
  /* struct tm tm;
      istringstream iss("Tue jan 1 00:00:00 1970");
      iss >> get_time(&tm, "%a %b %d %H:%M:%S %Y");
      time_t time = mktime(&tm);

      cout << time << endl;*/
