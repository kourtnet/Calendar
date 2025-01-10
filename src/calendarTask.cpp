#include "calendarTask.h"

CalendarTask::CalendarTask(QString inputName, QString inputDescription, QDateTime inputDateTimeBegin) {
	name = inputName;
	description = inputDescription;
    dateTimeBegin = inputDateTimeBegin;
}

CalendarTask::~CalendarTask() {}


QString CalendarTask::get_name() {
	return name;
}

QString CalendarTask::get_description() {
	return description;
}

QDateTime CalendarTask::get_date_time_begin() {
    return dateTimeBegin;
}

bool CalendarTask::get_is_task_completed() {
    return isTaskCompleted;
}

void CalendarTask::set_name(QString inputName) {
	name = inputName;
}

void CalendarTask::set_description(QString inputDescription) {
	description = inputDescription;
}

void CalendarTask::set_date_time_begin(QDateTime inputDateTimeBegin) {
    dateTimeBegin = inputDateTimeBegin;
}

void CalendarTask::set_is_task_completed(bool inputIsTaskCompleted) {
    isTaskCompleted = inputIsTaskCompleted;
}

