#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#define CREATE_EVENTS_TABLE_QUERY "CREATE TABLE tasks(id INTEGER PRIMARY KEY, name TEXT, description TEXT, date_time_end DATETIME);"
#define CREATE_TASKS_TABLE_QUERY "CREATE TABLE events(id INTEGER PRIMARY KEY, name TEXT, description TEXT, date_time_begin DATETIME, date_time_end DATETIME);"
#include <QtSql>
#include <QFile>
class DbManager {
	public:
		DbManager(QString inputPath);
		~DbManager();
		bool db_exists();
		QString db_create();
		QString db_insert(int table, QString name, QString description, QDateTime timeEnd, QDateTime timeBegin = null);
		QString db_delete(/*?????*/);
		QString db_alter(/*??????*/);
		QString get_path(/*?????*/);
		void set_path(QString path);
	private:
		QString path;
		QSqlDatabase db;
};

#endif
