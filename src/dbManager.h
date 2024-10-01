#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#define SUCCESS_QUERY_MESSAGE "SUCCESS"

#define CREATE_TASKS_TABLE_QUERY "CREATE TABLE tasks(id INTEGER PRIMARY KEY, name TEXT, description TEXT, deadline DATETIME);"
#define CREATE_EVENTS_TABLE_QUERY "CREATE TABLE events(id INTEGER PRIMARY KEY, name TEXT, description TEXT, date_time_begin DATETIME, date_time_end DATETIME);"

#define INSERT_TASKS_TABLE_QUERY "INSERT INTO tasks(name, description, deadline) VALUES(?, ?, datetime(?))"
#define INSERT_EVENTS_TABLE_QUERY "INSERT INTO events(name, description, date_time_begin, date_time_end) VALUES(?, ?, datetime(?))"

#include <QtSql>
#include <QFile>
class DbManager {
	public:
		DbManager(QString inputPath);
		~DbManager();
		bool db_exists();
		QString db_create();
		QString db_insert_tasks(QString name, QString description, QDateTime deadline);
		QString db_insert_events(QString name, QString description, QDateTime timeBegin, QDateTime timeEnd);
		QString db_delete(/*?????*/);
		QString db_alter(/*??????*/);
		QString get_path(/*?????*/);
		void set_path(QString path);
	private:
		QString path;
		QSqlDatabase db;
};

#endif
