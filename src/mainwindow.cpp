#include <iostream>
#include "calendarEvent.h"

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	QString time_format = "yyyy-MM-dd HH:mm:ss";
	CalendarEvent ev = CalendarEvent(QString("nastyas birthday"), QString("nastyas birthday in hinklanaya"), QDateTime::fromString("2025-01-04 00:00:00", time_format, QCalendar(QCalendar::System::Gregorian)), QDateTime::fromString("2025-01-04 23:59:59", time_format, QCalendar(QCalendar::System::Gregorian)));
CalendarTask tsk = CalendarTask(QString("homework"), QString("math homework"), QDateTime::fromString("2025-02-23 23:00:00", time_format, QCalendar(QCalendar::System::Gregorian)));

	std::cout<<"event\nname: "<<ev.get_name().toLocal8Bit().data() << "\ndesrc: "<< ev.get_description().toLocal8Bit().data()<<"\nbegining: "<<ev.get_date_time_begin().toString(time_format, QCalendar(QCalendar::System::Gregorian)).toLocal8Bit().data()<< "\nend: "<<ev.get_date_time_end().toString(time_format, QCalendar(QCalendar::System::Gregorian)).toLocal8Bit().data();
	std::cout<<"\ntask\nname: "<<tsk.get_name().toLocal8Bit().data()<< "\ndesrc: "<< tsk.get_description().toLocal8Bit().data()<<"\ndeadline: "<<tsk.get_date_time_end().toString(time_format, QCalendar(QCalendar::System::Gregorian)).toLocal8Bit().data();

}
MainWindow::~MainWindow() {
}

