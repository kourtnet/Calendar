#include "calendarEvent.h"

CalendarEvent::CalendarEvent(QString inputName, QString inputDescription, QDateTime inputDateTimeBegin, QDateTime inputDateTimeEnd) {
    name = inputName;
    description = inputDescription;
    dateTimeBegin = inputDateTimeBegin;
    dateTimeEnd = inputDateTimeEnd;
}

CalendarEvent::~CalendarEvent() {}


QString CalendarEvent::get_name() {
    return name;
}

QString CalendarEvent::get_description() {
    return description;
}

QDateTime CalendarEvent::get_date_time_begin() {
    return dateTimeBegin;
}

QDateTime CalendarEvent::get_date_time_end() {
    return dateTimeEnd;
}

void CalendarEvent::set_name(QString inputName) {
    name = inputName;
}

void CalendarEvent::set_description(QString inputDescription) {
    description = inputDescription;
}

void CalendarEvent::set_date_time_begin(QDateTime inputDateTimeBegin) {
    dateTimeBegin = inputDateTimeBegin;
}

void CalendarEvent::set_date_time_end(QDateTime inputDateTimeEnd) {
    dateTimeEnd = inputDateTimeEnd;
}
