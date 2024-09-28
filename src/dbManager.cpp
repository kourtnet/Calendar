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
	db.setDatabaseName(path);
	QString res = QString("Success");
	if (!db.open()) {
		res = db.lastError().text();	
	} else {
		QSqlQuery createTablesQuery = QSqlQuery(db);
//createTablesQuery.prepare(CREATE_TABLES_QUERY);
		bool ls = createTablesQuery.exec(CREATE_TASKS_TABLE_QUERY);
		ls = createTablesQuery.exec(CREATE_EVENTS_TABLE_QUERY);
		if (!ls) res = createTablesQuery.lastError().text();
		//createTablesQuery.prepare("INSERT INTO tasks (name,description) VALUES"
	}
	return res;
}

QString DbManager::get_path(){
	return path;
}

void DbManager::set_path(QString inputPath) {
	path = inputPath;
}
