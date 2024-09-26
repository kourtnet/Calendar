#include "calendarTask.h"

CalendarTask::CalendarTask(QString inputName, QString inputDescription, QDateTime inputDateTimeEnd) {
	name = inputName;
	description = inputDescription;
	dateTimeEnd = inputDateTimeEnd;
}

CalendarTask::~CalendarTask() {}


QString CalendarTask::get_name() {
	return name;
}

QString CalendarTask::get_description() {
	return description;
}

QDateTime CalendarTask::get_date_time_end() {
	return dateTimeEnd;
}

void CalendarTask::set_name(QString inputName) {
	name = inputName;
}

void CalendarTask::set_description(QString inputDescription) {
	description = inputDescription;
}

void CalendarTask::set_date_time_end(QDateTime inputDateTimeEnd) {
	dateTimeEnd = inputDateTimeEnd;
}

