#include <iostream>
#include <QLabel>
#include <QtSql>
#include "calendarEvent.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	setWindowTitle("Calendar");
	resize(1200,1200);

	QLabel *test = new QLabel("calendar", this);
	test->show();
}
MainWindow::~MainWindow() {
}

