#include "dbManager.h"

DbManager::DbManager(QString inputPath){
	path = inputPath;
	db = QSqlDatabase::addDatabase("QSQLITE"); 
}

DbManager::~DbManager() {}

//first we check if db exists, then we create it
bool DbManager::db_exists() {
	return QFile::exists(path);
}

//returns "Success" if db opened successfully and some error text if db didnt open for some reason
QString DbManager::db_create() {
	//assign path from db manager object
	db.setDatabaseName(path);
	QString res = QString("Success");
	//send error if couldnt open for some reason, else create tables
	if (!db.open()) {
		res = db.lastError().text();	
	} else {
		QSqlQuery createTablesQuery = QSqlQuery(db);
		//create tasks table
		createTablesQuery.exec(CREATE_TASKS_TABLE_QUERY);
		//create events table
		bool ls = createTablesQuery.exec(CREATE_EVENTS_TABLE_QUERY);
		//if ls is false, that mean that tables are not created, send error
		if (!ls) res = createTablesQuery.lastError().text();
	}
	return res;
}

QString DbManager::get_path(){
	return path;
}

void DbManager::set_path(QString inputPath) {
	path = inputPath;
}
