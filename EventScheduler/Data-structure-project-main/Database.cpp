
#include "Database.h"
using namespace std;
static int callback(void* data, int argc, char** argv, char** azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}
typedef int (*sqlite3_callback)(
	void*, /* Data provided in the 4th argument of sqlite3_exec() */
	int, /* The number of columns in row */
	char**, /* An array of strings representing fields in the row */
	char** /* An array of strings representing column names */
	);
    Database::Database() {
    rc = sqlite3_open("EventScheduler.db", &db);
	if (rc) {
		try {
			throw new exception();
		}
		catch (...) {
			cout << "Error open";
		}
	}
	else {
		fprintf(stdout, "Opened database successfully\n");
	}
}
void Database::CreateTable(string tableName) {
    cout << "creatingdb" << endl;
    query = "CREATE TABLE IF NOT EXISTS " + tableName + " (" \
        "NAME TEXT NOT NULL PRIMARY KEY," \
		"PLACE TEXT NOT NULL," \
		"START_DATE TEXT NOT NULL," \
        "END_DATE CHAR(50) NOT NULL," \
        "REMINDER_DATE TEXT NOT NULL);";
    rc = sqlite3_exec(db, query.c_str(), callback, 0, &err);
    if (rc != SQLITE_OK) {
        cout << err;
	}
	else {
        cout << "Table created successfully" << endl;
	}
}
void Database::Insert(string tableName,Event event) {
    query = (string)"INSERT INTO " + tableName + " " +
        "VALUES ('" + event.getName() + "', '" + event.getPlace() + "', '" + event.getStartDate() + "','" + event.getEndDate() + "','" + event.getReminder() + "' );";
    rc = sqlite3_exec(db, query.c_str(), callback, 0, &err);
	if (rc != SQLITE_OK) {
        cout << err;
	}
	else {
        cout << "Values inserted successfully" << endl;
	}
}
void Database::SelectAll(string tableName,BSTree<Event>* model) {
    query = "SELECT * from " + tableName;
    try{
        sqlite3_prepare(db,query.c_str(),query.size(),&stmt,NULL);
        bool pending = true;
        while(pending){
            switch(sqlite3_step(stmt)){
            case SQLITE_ROW:
                {
                int colCount = sqlite3_column_count(stmt);
                string name;
                string place;
                string start_date;
                string end_date;
                string reminder_date;
                for (int i = 0; i < colCount; i++) {
                      string colName = sqlite3_column_name(stmt,i);
                      if(colName == "NAME"){
                          name = (const char*)sqlite3_column_text(stmt,i);
                      }
                      else if(colName == "PLACE"){
                          place = (const char*)sqlite3_column_text(stmt,i);
                      }
                      else if(colName == "START_DATE"){
                          start_date = (const char*)sqlite3_column_text(stmt,i);
                      }
                      else if(colName == "END_DATE"){
                          end_date = (const char*)sqlite3_column_text(stmt,i);
                      }
                      else if(colName == "REMINDER_DATE"){
                          reminder_date = (const char*)sqlite3_column_text(stmt,i);
                      }
                }
                Event* ev = new Event(name,place,start_date,end_date,reminder_date);
                model->insert(ev);
            }
                break;
            case SQLITE_DONE:
                pending = false;
                break;
            default:
                pending = false;
                break;
            }
        }
        sqlite3_finalize(stmt);
    }catch(exception ex){
        cout << ex.what() << endl;
    }
}
void Database::Delete(string tableName,string eventName)
{
    query = "DELETE from " + tableName + ((eventName == "")? ";" : " where NAME='" + eventName + "';");
    rc = sqlite3_exec(db, query.c_str(), callback, (void*)data, &err);
    if (rc != SQLITE_OK) {
        try {
            throw new exception();
        }
        catch (...) {
            cout << "Error select all";
        }
    }
}
void Database::Update(string tableName, Event event) {
    query = "UPDATE " + tableName + " SET " + "PLACE = '" + event.getPlace() + "', START_DATE = '" + event.getStartDate() + "', END_DATE = '" + event.getEndDate() + "', REMINDER_DATE = '" + event.getReminder() +  + "WHERE NAME = " + event.getName() + ";";
    rc = sqlite3_exec(db, query.c_str(), callback, (void*)data, &err);
    if (rc != SQLITE_OK) {
            try {
                throw new exception();
            }
            catch (...) {
                cout << "Error update";
            }
   }
}
Database::~Database() {
    delete data;
    delete err;
}


