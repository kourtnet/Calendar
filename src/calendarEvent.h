#ifndef CALENDAR_EVENT_H
#define CALENDAR_EVENT_H

#include <QString>
#include <QDateTime>

class CalendarEvent{
	public:
        CalendarEvent(QString inputName, QString inputDescription, QDateTime inputDateTimeBegin, QDateTime inputDateTimeEnd);
        ~CalendarEvent();
        QString get_name();
        QString get_description();
        QDateTime get_date_time_begin();
        QDateTime get_date_time_end();
        void set_name(QString inputName);
        void set_description(QString inputDescription);
        void set_date_time_begin(QDateTime inputDateTimeBegin);
        void set_date_time_end(QDateTime inputDateTimeEnd);
	protected:
        //name of entity
        QString name;
        //description of entity
        QString description;
        //begin time for entity
        QDateTime dateTimeBegin;
        //is task completed
        QDateTime dateTimeEnd;
};
//
#endif
