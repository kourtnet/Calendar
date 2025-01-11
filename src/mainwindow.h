#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtSql>

#include "dbManager.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(DbManager &inputDbMgr, QWidget *parent = nullptr);
    ~MainWindow();

private:
    DbManager dbMgr;
    bool initiate_Db();
};

#endif // MAINWINDOW_H

