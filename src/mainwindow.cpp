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
		if(error == "SUCCESS") {
			test->setText("Created");

			test->setText(dbManager.db_insert_tasks("test", "test", QDateTime::fromString("2024-12-12 23:12:12","yyyy-MM-dd HH:mm:ss")));
			test->setText(dbManager.db_insert_tasks("test", "test", QDateTime::fromString("2024-12-12 23:12:12","yyyy-MM-dd HH:mm:ss")));
			test->setText(dbManager.db_insert_tasks("test", "test", QDateTime::fromString("2024-12-12 23:12:12","yyyy-MM-dd HH:mm:ss")));
			test->setText(dbManager.db_insert_events("test", "test", QDateTime::fromString("2024-12-12 23:12:12","yyyy-MM-dd HH:mm:ss"),QDateTime::fromString("2024-12-31 23:13:00","yyyy-MM-dd HH:mm:ss")));
			test->setText(dbManager.db_insert_events("test", "test", QDateTime::fromString("2024-12-12 23:12:12","yyyy-MM-dd HH:mm:ss"),QDateTime::fromString("2024-12-31 23:13:00","yyyy-MM-dd HH:mm:ss")));
			test->setText(dbManager.db_insert_events("test", "test", QDateTime::fromString("2024-12-12 23:12:12","yyyy-MM-dd HH:mm:ss"),QDateTime::fromString("2024-12-31 23:13:00","yyyy-MM-dd HH:mm:ss")));
			test->setText(dbManager.db_delete_tasks(2));
			test->setText(dbManager.db_delete_events(3));
			test->setText(dbManager.db_update_events(1, "penis", "penis1", QDateTime::fromString("2020-01-01 01:01:01", "yyyy-MM-dd HH:mm:ss"), QDateTime::fromString("2021-02-02 02:12:12", "yyyy-MM-dd HH:mm:ss")));
			test->setText(dbManager.db_update_tasks(1, "penis", "penis1", QDateTime::fromString("2020-01-01 01:01:01", "yyyy-MM-dd HH:mm:ss")));
		} else {
			test->setText(error);
		}
	}
	test->show();
}
MainWindow::~MainWindow() {
}

