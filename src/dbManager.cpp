#include "dbManager.h"

DbManager::DbManager(QString inputPath){
	path = inputPath;
	db = QSqlDatabase::addDatabase("QSQLITE"); 
	db.setDatabaseName(path);
}

DbManager::~DbManager() {}

//first we check if db exists, then we create it
bool DbManager::db_exists() {
	return QFile::exists(path);
}

//returns "Success" if db opened successfully and some error text if db didnt open for some reason
QString DbManager::db_create() {
	QString res = QString(SUCCESS_QUERY_MESSAGE);
	//send error if couldnt open for some reason, else create tables
	if (!db.open()) {
		res = db.lastError().text();	
	} else {
		QSqlQuery createTablesQuery = QSqlQuery(db);
		//create tasks table
		createTablesQuery.exec(CREATE_TASKS_TABLE_QUERY);
		//create events table
		bool ls = createTablesQuery.exec(CREATE_EVENTS_TABLE_QUERY);
		//if ls is false, that means that tables are not created, send error
		if (!ls) res = createTablesQuery.lastError().text();
	}
	return res;
}


QString DbManager::db_insert_tasks(QString name, QString description, QDateTime deadline) {
	QString res = QString(SUCCESS_QUERY_MESSAGE);
	//send error if couldnt open for some reason, else insert into table
	if (!db.open()) {
		res = db.lastError().text();
	} else {
		QSqlQuery insertTasksTableQuery = QSqlQuery(db);
		insertTasksTableQuery.prepare(INSERT_TASKS_TABLE_QUERY);
		//0 is name column
		insertTasksTableQuery.bindValue(0, name);
		//1 is description column
		insertTasksTableQuery.bindValue(1, description);
		//2 is deadline column
		insertTasksTableQuery.bindValue(2, deadline.toString("yyyy-MM-dd hh:mm:ss"));
		//exec after binding parameters
		bool ls = insertTasksTableQuery.exec();
		//if ls is false, that means that values were not inserted, send error
		if(!ls) res = insertTasksTableQuery.lastError().text();
	}
	return res;
}

QString DbManager::db_insert_events(QString name, QString description, QDateTime date_time_begin, QDateTime date_time_end) {
	QString res = QString(SUCCESS_QUERY_MESSAGE);
	//send error if couldnt open for some reason, else insert into table
	if (!db.open()) {
		res = db.lastError().text();
	} else {
		QSqlQuery insertEventsTableQuery = QSqlQuery(db);
		insertEventsTableQuery.prepare(INSERT_EVENTS_TABLE_QUERY);
		//0 is name column
		insertEventsTableQuery.bindValue(0, name);
		//1 is description column
		insertEventsTableQuery.bindValue(1, description);
		//2 is date_time_begin column
		insertEventsTableQuery.bindValue(2, date_time_begin.toString("yyyy-MM-dd hh:mm:ss"));
		//3 is date_time_begin column
		insertEventsTableQuery.bindValue(3, date_time_end.toString("yyyy-MM-dd hh:mm:ss"));
		//exec after binding parameters
		bool ls = insertEventsTableQuery.exec();
		//if ls is false, that means that values were not inserted, send error
		if(!ls) res = insertEventsTableQuery.lastError().text();
	}
	return res;
}
/*QString DbManager::db_insert_events() {

}

QString DbManager::db_insert_events(QString name, QString description, QDateTime) {

}
*/
QString DbManager::get_path(){
	return path;
}

void DbManager::set_path(QString inputPath) {
	path = inputPath;
}
