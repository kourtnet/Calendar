#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#define SUCCESS_QUERY_MESSAGE "SUCCESS"

#define CREATE_TASKS_TABLE_QUERY "CREATE TABLE tasks(id INTEGER PRIMARY KEY, name TEXT, description TEXT, date_time_begin DATETIME, is_completed INTEGER);"
#define CREATE_EVENTS_TABLE_QUERY "CREATE TABLE events(id INTEGER PRIMARY KEY, name TEXT, description TEXT, date_time_begin DATETIME, date_time_end DATETIME);"

#define INSERT_TASKS_TABLE_QUERY "INSERT INTO tasks(name, description, date_time_begin, is_completed) VALUES(?, ?, datetime(?), ?)"
#define INSERT_EVENTS_TABLE_QUERY "INSERT INTO events(name, description, date_time_begin, date_time_end) VALUES(?, ?, datetime(?), datetime(?))"

#define DELETE_TASKS_TABLE_QUERY "DELETE FROM tasks WHERE id=?"
#define DELETE_EVENTS_TABLE_QUERY "DELETE FROM events WHERE id=?"

#define UPDATE_NAME_TASKS_TABLE_QUERY "UPDATE tasks SET name=? WHERE id=?"
#define UPDATE_DESCRIPTION_TASKS_TABLE_QUERY "UPDATE tasks SET description=? WHERE id=?"
#define UPDATE_DATE_TIME_BEGIN_TASKS_TABLE_QUERY "UPDATE tasks SET date_time_begin=datetime(?) WHERE id=?"
#define UPDATE_IS_COMPLETED_TASKS_TABLE_QUERY "UPDATE tasks SET is_completed=? WHERE id=?"
#define UPDATE_NAME_EVENTS_TABLE_QUERY "UPDATE events SET name=? WHERE id=?"
#define UPDATE_DESCRIPTION_EVENTS_TABLE_QUERY "UPDATE events SET description=? WHERE id=?"
#define UPDATE_DATE_TIME_BEGIN_EVENTS_TABLE_QUERY "UPDATE events SET date_time_begin=datetime(?) WHERE id=?"
#define UPDATE_DATE_TIME_END_EVENTS_TABLE_QUERY "UPDATE events SET date_time_end=datetime(?) WHERE id=?"

#define SELECT_ALL_TASKS_TABLE_QUERY "SELECT * FROM TASKS ORDER BY id"
#define SELECT_ALL_EVENTS_TABLE_QUERY "SELECT * FROM EVENTS ORDER BY id"

#include <QtSql>
#include <QFile>
#include <QList>

#include "calendarEntity.h"

class DbManager {
	public:
		DbManager(QString inputPath);
		~DbManager();
		//check does database exist
		bool db_exists();
		//create all required tables
        bool db_create(QString &err);
		//insert query methods
        bool db_insert_tasks(QString &err, QString name, QString description, QDateTime dateTimeBegin, bool isCompleted = false);
        bool db_insert_events(QString &err, QString name, QString description, QDateTime dateTimeBegin, QDateTime dateTimeEnd);
		//delete query methods
        bool db_delete_tasks(QString &err, int id);
        bool db_delete_events(QString &err, int id);
		//update query methods
        bool db_update_tasks(QString &err, int id, QString name = QString(), QString description = QString(), QDateTime dateTimeBegin = QDateTime(), int isCompleted = -1);
        bool db_update_events(QString &err, int id, QString name = QString(), QString description = QString(), QDateTime dateTimeBegin = QDateTime(), QDateTime dateTimeEnd = QDateTime());
        //select all query methods for test purposes
        bool db_select_all_tasks(QString &err, QList<CalendarTask> &listOfTasks);
        bool db_select_all_events(QString &err, QList<CalendarEvent> &listOfEvents);

		QString get_path();
		void set_path(QString path);

	private:
		QString path;
		QSqlDatabase db;
};

#endif
