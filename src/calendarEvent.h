#ifndef CALENDAR_EVENT_H
#define CALENDAR_EVENT_H

#include "calendarTask.h"

class CalendarEvent : public CalendarTask {
	public:
		CalendarEvent(QString inputName, QString inputDescription, QDateTime inputDateTimeBegin, QDateTime inputDateTimeEnd);
	~CalendarEvent();
		QDateTime get_date_time_begin();
		void set_date_time_begin(QDateTime inputDateTimeBegin);
	protected:
		QDateTime dateTimeBegin;
};

#endif
