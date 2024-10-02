#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#define SUCCESS_QUERY_MESSAGE "SUCCESS"

#define CREATE_TASKS_TABLE_QUERY "CREATE TABLE tasks(id INTEGER PRIMARY KEY, name TEXT, description TEXT, deadline DATETIME);"
#define CREATE_EVENTS_TABLE_QUERY "CREATE TABLE events(id INTEGER PRIMARY KEY, name TEXT, description TEXT, date_time_begin DATETIME, date_time_end DATETIME);"

#define INSERT_TASKS_TABLE_QUERY "INSERT INTO tasks(name, description, deadline) VALUES(?, ?, datetime(?))"
#define INSERT_EVENTS_TABLE_QUERY "INSERT INTO events(name, description, date_time_begin, date_time_end) VALUES(?, ?, datetime(?), datetime(?))"

#define DELETE_TASKS_TABLE_QUERY "DELETE FROM tasks WHERE id=?"
#define DELETE_EVENTS_TABLE_QUERY "DELETE FROM events WHERE id=?"

#define UPDATE_NAME_TASKS_TABLE_QUERY "UPDATE tasks SET name=? WHERE id=?"
#define UPDATE_DESCRIPTION_TASKS_TABLE_QUERY "UPDATE tasks SET description=? WHERE id=?"
#define UPDATE_DEADLINE_TASKS_TABLE_QUERY "UPDATE tasks SET deadline=datetime(?) WHERE id=?"
#define UPDATE_NAME_EVENTS_TABLE_QUERY "UPDATE events SET name=? WHERE id=?"
#define UPDATE_DESCRIPTION_EVENTS_TABLE_QUERY "UPDATE events SET description=? WHERE id=?"
#define UPDATE_DATE_TIME_BEGIN_EVENTS_TABLE_QUERY "UPDATE events SET date_time_begin=datetime(?) WHERE id=?"
#define UPDATE_DATE_TIME_END_EVENTS_TABLE_QUERY "UPDATE events SET date_time_end=datetime(?) WHERE id=?"

#include <QtSql>
#include <QFile>

class DbManager {
	public:
		DbManager(QString inputPath);
		~DbManager();
		//check does database exist
		bool db_exists();
		//create all required tables
		QString db_create();
		//insert query methods
		QString db_insert_tasks(QString name, QString description, QDateTime deadline);
		QString db_insert_events(QString name, QString description, QDateTime timeBegin, QDateTime timeEnd);
		//delete query methods
		QString db_delete_tasks(int id);
		QString db_delete_events(int id);
		//update query methods
		QString db_update_tasks(int id, QString name = QString(), QString description = QString(), QDateTime deadline = QDateTime());
		QString db_update_events(int id, QString name = QString(), QString description = QString(), QDateTime date_time_begin = QDateTime(), QDateTime date_time_end = QDateTime());
		
		QString get_path();
		void set_path(QString path);

	private:
		QString path;
		QSqlDatabase db;
};

#endif
