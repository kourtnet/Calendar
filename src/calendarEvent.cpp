#include "calendarEvent.h"

CalendarEvent::CalendarEvent (QString inputName, QString inputDescription, QDateTime inputDateTimeBegin, QDateTime inputDateTimeEnd) : CalendarTask (inputName, inputDescription, inputDateTimeEnd) {
	dateTimeBegin = inputDateTimeBegin;
}

CalendarEvent::~CalendarEvent() {}

QDateTime CalendarEvent::get_date_time_begin(){
	return dateTimeBegin;
}

void CalendarEvent::set_date_time_begin(QDateTime inputDateTimeBegin) {
	dateTimeBegin = inputDateTimeBegin;
}
