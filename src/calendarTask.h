#ifndef CALENDAR_TASK_H 
#define CALENDAT_TASK_H

#include <QString>
#include <QDateTime>

class CalendarTask {
	public:
		CalendarTask(QString inputName, QString inputDescription, QDateTime inputDateTimeEnd);
		~CalendarTask();
		QString get_name();
		QString get_description();
		QDateTime get_date_time_end();
		void set_name(QString inputName);
		void set_description(QString inputDescription);
		void set_date_time_end(QDateTime inputDateTimeEnd);
	private:
		//name of entity
		QString name;
		//description of entity
		QString description;
		//end time for entity (end time for event, deadline for task)
		QDateTime dateTimeEnd;
};

#endif
