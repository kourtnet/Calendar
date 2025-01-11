#include "mainwindow.h"
#include <qapplication.h>

MainWindow::MainWindow(DbManager& inputDbMgr, QWidget *parent): dbMgr(inputDbMgr), QMainWindow(parent)  {
	setWindowTitle("Calendar");
	resize(800,800);
}
MainWindow::~MainWindow() {
}




