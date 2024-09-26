
#include <iostream>
#include "calendarTask.h"
#include "calendarEvent.h"

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	CalendarEvent ev = CalendarEvent(QString("nastyas birthday", "nastyas birthday in hinklanaya", QDateTime::fromString("2025-01-04 00:00:00"), QDateTime::fromString("2025-01-04 23:59:59"));
//CalendarTask tsk = CalendarEvent(QString("homework", "math homework", QDateTime::fromString("2025-02-23 23:00:00")));

//	std::cout<<"event\nname: "<<ev.get_name() << "\ndesrc: "<< ev.get_description()<<"\nbegining: ";//<<ev.get_date_time_begin()<< "\nend: "<<ev.get_date_time_end();
	//std::cout<<"task\nname: "<<tsk.get_name() << "\ndesrc: "<< tsk.get_description()<<"\ndeadline: "<<tsk.get_date_time_end();

}
MainWindow::~MainWindow() {
}

