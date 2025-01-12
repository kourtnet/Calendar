#ifndef CALENDARENTITY_H
#define CALENDARENTITY_H

#include <QString>
#include <QDateTime>

class CalendarEntity
{
public:
    CalendarEntity(int inputId, QString inputName, QString inputDescription, QDateTime inputDateTimeBegin);
    ~CalendarEntity();
    int get_id();
    QString get_name();
    QString get_description();
    QDateTime get_date_time_begin();
    void set_id(int inputId);
    void set_name(QString inputName);
    void set_description(QString inputDescription);
    void set_date_time_begin(QDateTime inputDateTimeBegin);
protected:
    int id;
    QString name;
    QString description;
    QDateTime dateTimeBegin;
};

class CalendarTask : public CalendarEntity{
public:
    CalendarTask(int inputId, QString inputName, QString inputDescription, QDateTime inputDateTimeBegin, bool inputIsTaskCompleted = false);
    ~CalendarTask();
    bool get_is_task_completed();
    void set_is_task_completed(bool inputIsTaskCompleted);
protected:
    bool isTaskCompleted;
};

class CalendarEvent : public CalendarEntity{
public:
    CalendarEvent(int inputId, QString inputName, QString inputDescription, QDateTime inputDateTimeBegin, QDateTime inputDateTimeEnd);
    ~CalendarEvent();
    QDateTime get_date_time_end();
    void set_date_time_end(QDateTime inputDateTimeEnd);

protected:
    QDateTime dateTimeEnd;
};

#endif // CALENDARENTITY_H
