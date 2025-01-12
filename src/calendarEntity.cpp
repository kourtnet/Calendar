#include "calendarentity.h"

//CalendarEntity
CalendarEntity::CalendarEntity(int inputId, QString inputName, QString inputDescription, QDateTime inputDateTimeBegin) {
    id = inputId;
    name = inputName;
    description = inputDescription;
    dateTimeBegin = inputDateTimeBegin;
}

int CalendarEntity::get_id() {
    return id;
}

CalendarEntity::~CalendarEntity() {}

QString CalendarEntity::get_name() {
    return name;
}

QString CalendarEntity::get_description() {
    return description;
}

QDateTime CalendarEntity::get_date_time_begin() {
    return dateTimeBegin;
}

void CalendarEntity::set_id(int inputId) {
    id = inputId;
}

void CalendarEntity::set_name(QString inputName) {
    name = inputName;
}

void CalendarEntity::set_description(QString inputDescription) {
    description = inputDescription;
}

void CalendarEntity::set_date_time_begin(QDateTime inputDateTimeBegin) {
    dateTimeBegin = inputDateTimeBegin;
}

//CalendatTask
CalendarTask::CalendarTask(int inputId, QString inputName, QString inputDescription, QDateTime inputDateTimeBegin, bool inputIsTaskCompleted) : CalendarEntity(inputId, inputName, inputDescription, inputDateTimeBegin) {
    isTaskCompleted = inputIsTaskCompleted;
}

CalendarTask::~CalendarTask() {}

bool CalendarTask::get_is_task_completed() {
    return isTaskCompleted;
}

void CalendarTask::set_is_task_completed(bool inputIsTaskCompleted) {
    isTaskCompleted = inputIsTaskCompleted;
}

//CalendarEvent
CalendarEvent::CalendarEvent(int inputId, QString inputName, QString inputDescription, QDateTime inputDateTimeBegin, QDateTime inputDateTimeEnd) : CalendarEntity(inputId, inputName, inputDescription, inputDateTimeBegin){
    dateTimeEnd = inputDateTimeEnd;
}

CalendarEvent::~CalendarEvent() {}

QDateTime CalendarEvent::get_date_time_end() {
    return dateTimeEnd;
}

void CalendarEvent::set_date_time_end(QDateTime inputDateTimeEnd) {
    dateTimeEnd = inputDateTimeEnd;
}

