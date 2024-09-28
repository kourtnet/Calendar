#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	setWindowTitle("Calendar");
	resize(800,800);
		
	QLabel *test = new QLabel("calendar", this);
	test->resize(400,100);
	DbManager dbManager = DbManager("mdb.db");
	if(dbManager.db_exists()) {
		test->setText("opened");
	} else {
		QString error = dbManager.db_create();
		if(error == "Success") {
			test->setText("Created");
		} else {
			test->setText(error);
		}
	}
	test->show();
}
MainWindow::~MainWindow() {
}

