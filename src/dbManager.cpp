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
bool DbManager::db_create(QString &err) {
	//send error if couldnt open for some reason, else create tables
	if (!db.open()) {
        err = db.lastError().text();
        return false;
	} else {
		QSqlQuery createTablesQuery = QSqlQuery(db);
		//create tasks table
        if(!createTablesQuery.exec(CREATE_TASKS_TABLE_QUERY)) {
            err = createTablesQuery.lastError().text();
            return false;
        //create events table
        } else if (!createTablesQuery.exec(CREATE_EVENTS_TABLE_QUERY)) {
            err = createTablesQuery.lastError().text();
            return false;
        }
	}
    return true;
}

bool DbManager::db_insert_tasks(QString &err, QString name, QString description, QDateTime dateTimeBegin, bool isCompleted) {
	//send error if couldnt open for some reason, else insert into table
	if (!db.open()) {
        err = db.lastError().text();
        return false;
	} else {
		QSqlQuery insertTasksTableQuery = QSqlQuery(db);
		insertTasksTableQuery.prepare(INSERT_TASKS_TABLE_QUERY);
		//0 is name column
		insertTasksTableQuery.bindValue(0, name);
		//1 is description column
		insertTasksTableQuery.bindValue(1, description);
		//2 is deadline column
        insertTasksTableQuery.bindValue(2, dateTimeBegin.toString("yyyy-MM-dd hh:mm:ss"));
        //3 is iscompleted column
        insertTasksTableQuery.bindValue(3, isCompleted);
		//exec after binding parameters
        //if ls is false, that means that values were not inserted, send error
        if(!insertTasksTableQuery.exec()) {
            err = insertTasksTableQuery.lastError().text();
            return false;
        }
	}
    return true;
}

bool DbManager::db_insert_events(QString &err, QString name, QString description, QDateTime dateTimeBegin, QDateTime dateTimeEnd) {
	//send error if couldnt open for some reason, else insert into table
	if (!db.open()) {
        err = db.lastError().text();
        return false;
	} else {
		QSqlQuery insertEventsTableQuery = QSqlQuery(db);
		insertEventsTableQuery.prepare(INSERT_EVENTS_TABLE_QUERY);
		//0 is name column
		insertEventsTableQuery.bindValue(0, name);
		//1 is description column
		insertEventsTableQuery.bindValue(1, description);
		//2 is date_time_begin column
        insertEventsTableQuery.bindValue(2, dateTimeBegin.toString("yyyy-MM-dd hh:mm:ss"));
        //3 is date_time_end column
        insertEventsTableQuery.bindValue(3, dateTimeEnd.toString("yyyy-MM-dd hh:mm:ss"));
		//exec after binding parameters
        if(!insertEventsTableQuery.exec()) {
            err = insertEventsTableQuery.lastError().text();
            return false;
        }
	}
    return true;
}

bool DbManager::db_delete_tasks(QString &err, int id) {
	//send error if couldnt open for some reason, else delete from table tasks
	if(!db.open()) {
        err = db.lastError().text();
        return false;
	} else {
		QSqlQuery deleteTasksTableQuery = QSqlQuery(db);
		deleteTasksTableQuery.prepare(DELETE_TASKS_TABLE_QUERY);
		deleteTasksTableQuery.bindValue(0, QString::number(id));

        if(!deleteTasksTableQuery.exec()) {
            err = deleteTasksTableQuery.lastError().text();
            return false;
        }
	}
    return true;
}

bool DbManager::db_delete_events(QString &err, int id) {
	//send error if couldnt open for some reason, else delete from event tasks
	if(!db.open()) {
        err = db.lastError().text();
        return false;
	} else {
		QSqlQuery deleteEventsTableQuery = QSqlQuery(db);
		deleteEventsTableQuery.prepare(DELETE_EVENTS_TABLE_QUERY);
		deleteEventsTableQuery.bindValue(0, QString::number(id));
		
        if(!deleteEventsTableQuery.exec()) {
            err = deleteEventsTableQuery.lastError().text();
            return false;
        }
	}
    return true;
}

bool DbManager::db_update_tasks(QString &err, int id, QString name, QString description, QDateTime dateTimeBegin, int isCompleted) {

	if(!db.open()) {
        err = db.lastError().text();
        return false;
	} else {
		QSqlQuery updateTasksTableQuery;
		if(name != QString()) {
			updateTasksTableQuery = QSqlQuery(db);
			updateTasksTableQuery.prepare(UPDATE_NAME_TASKS_TABLE_QUERY);
			updateTasksTableQuery.bindValue(0, name);
			updateTasksTableQuery.bindValue(1, id);
            if(!updateTasksTableQuery.exec()) {
                err = updateTasksTableQuery.lastError().text();
                return false;
            }
		}
        if(description != QString()) {
			updateTasksTableQuery = QSqlQuery(db);
			updateTasksTableQuery.prepare(UPDATE_DESCRIPTION_TASKS_TABLE_QUERY);
			updateTasksTableQuery.bindValue(0, description);
			updateTasksTableQuery.bindValue(1, id);
            if(!updateTasksTableQuery.exec()) {
                err = updateTasksTableQuery.lastError().text();
                return false;
            }
		}
        if(dateTimeBegin != QDateTime()) {
			updateTasksTableQuery = QSqlQuery(db);
            updateTasksTableQuery.prepare(UPDATE_DATE_TIME_BEGIN_TASKS_TABLE_QUERY);
            updateTasksTableQuery.bindValue(0, dateTimeBegin.toString("yyyy-MM-dd hh:mm:ss"));
			updateTasksTableQuery.bindValue(1, id);
            if(!updateTasksTableQuery.exec()) {
                err = updateTasksTableQuery.lastError().text();
                return false;
            }
		}
        if(isCompleted > -1 && isCompleted < 2) {
            updateTasksTableQuery = QSqlQuery(db);
            updateTasksTableQuery.prepare(UPDATE_IS_COMPLETED_TASKS_TABLE_QUERY);
            updateTasksTableQuery.bindValue(0, isCompleted);
            updateTasksTableQuery.bindValue(1, id);
            if(!updateTasksTableQuery.exec()) {
                err = updateTasksTableQuery.lastError().text();
                return false;
            }
        }
	}
    return true;
}

bool DbManager::db_update_events(QString &err, int id, QString name, QString description, QDateTime dateTimeBegin, QDateTime dateTimeEnd) {

	if(!db.open()) {
        err = db.lastError().text();
        return false;
	} else {
		QSqlQuery updateEventsTableQuery;
		if(name != QString()) {
			updateEventsTableQuery = QSqlQuery(db);
			updateEventsTableQuery.prepare(UPDATE_NAME_EVENTS_TABLE_QUERY);
			updateEventsTableQuery.bindValue(0, name);
			updateEventsTableQuery.bindValue(1, id);
            if(!updateEventsTableQuery.exec()) {
                err = updateEventsTableQuery.lastError().text();
                return false;
            }
		}
        if(description != QString()) {
			updateEventsTableQuery = QSqlQuery(db);
			updateEventsTableQuery.prepare(UPDATE_DESCRIPTION_EVENTS_TABLE_QUERY);
			updateEventsTableQuery.bindValue(0, description);
			updateEventsTableQuery.bindValue(1, id);
            if(!updateEventsTableQuery.exec()) {
                err = updateEventsTableQuery.lastError().text();
                return false;
            }
		}
        if(dateTimeBegin != QDateTime()) {
			updateEventsTableQuery = QSqlQuery(db);
			updateEventsTableQuery.prepare(UPDATE_DATE_TIME_BEGIN_EVENTS_TABLE_QUERY);
            updateEventsTableQuery.bindValue(0, dateTimeBegin.toString("yyyy-MM-dd hh:mm:ss"));
			updateEventsTableQuery.bindValue(1, id);
            if(!updateEventsTableQuery.exec()) {
                err = updateEventsTableQuery.lastError().text();
                return false;
            }
		}
        if(dateTimeEnd != QDateTime()) {
			updateEventsTableQuery = QSqlQuery(db);
			updateEventsTableQuery.prepare(UPDATE_DATE_TIME_END_EVENTS_TABLE_QUERY);
            updateEventsTableQuery.bindValue(0, dateTimeEnd.toString("yyyy-MM-dd hh:mm:ss"));
			updateEventsTableQuery.bindValue(1, id);
            if(!updateEventsTableQuery.exec()) {
                err = updateEventsTableQuery.lastError().text();
                return false;
            }
		}
	}
    return true;
}

bool DbManager::db_select_all_tasks(QString &err, QList<CalendarTask> &listOfTasks) {
    if(!db.open()) {
        err = db.lastError().text();
        return false;
    } else {
        QSqlQuery selectTasksTableQuery = QSqlQuery(db);
        selectTasksTableQuery.prepare(SELECT_ALL_TASKS_TABLE_QUERY);
        if(!selectTasksTableQuery.exec()) {
            err = selectTasksTableQuery.lastError().text();
            return false;
        } else {
            while(selectTasksTableQuery.next()) {
                listOfTasks.append(CalendarTask(selectTasksTableQuery.value(0).toInt(), selectTasksTableQuery.value(1).toString(), selectTasksTableQuery.value(2).toString(), selectTasksTableQuery.value(3).toDateTime()));
            }
        }
    }
    return true;
}
bool DbManager::db_select_all_events(QString &err, QList<CalendarEvent> &listOfEvents) {
    if(!db.open()) {
        err = db.lastError().text();
        return false;
    } else {
        QSqlQuery selectEventsTableQuery = QSqlQuery(db);
        selectEventsTableQuery.prepare(SELECT_ALL_EVENTS_TABLE_QUERY);
        if(!selectEventsTableQuery.exec()) {
            err = selectEventsTableQuery.lastError().text();
            return false;
        } else {
            while(selectEventsTableQuery.next()) {
                listOfEvents.append(CalendarEvent(selectEventsTableQuery.value(0).toInt(), selectEventsTableQuery.value(1).toString(), selectEventsTableQuery.value(2).toString(), selectEventsTableQuery.value(3).toDateTime(), selectEventsTableQuery.value(4).toDateTime()));
            }
        }
    }
    return true;
}

QString DbManager::get_path(){
	return path;
}

void DbManager::set_path(QString inputPath) {
	path = inputPath;
}
