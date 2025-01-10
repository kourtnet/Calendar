#ifndef CALENDAR_TASK_H 
#define CALENDAT_TASK_H

#include <QString>
#include <QDateTime>

class CalendarTask {
	public:
        CalendarTask(QString inputName, QString inputDescription, QDateTime inputDateTimeBegin);
		~CalendarTask();
		QString get_name();
		QString get_description();
        QDateTime get_date_time_begin();
        bool get_is_task_completed();
		void set_name(QString inputName);
		void set_description(QString inputDescription);
        void set_date_time_begin(QDateTime inputDateTimeBegin);
        void set_is_task_completed(bool inputIsTaskCompleted);
	private:
		//name of entity
		QString name;
		//description of entity
		QString description;
        //begin time for entity
        QDateTime dateTimeBegin;
        //is task completed
        bool isTaskCompleted;
};

#endif
