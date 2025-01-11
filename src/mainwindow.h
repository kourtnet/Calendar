#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtSql>
#include <QMessageBox>
#include <QList>

#include "dbManager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(DbManager &inputDbMgr, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DbManager dbMgr;
    bool initiate_Db();
    void initiate_connects();
    void updateTasksList();
    void updateEventsList();

private slots:
    void onAddTaskClick();
    void onAddEventClick();
    void onDeleteTaskClick();
    void onDeleteEventClick();
    void onEditTaskClick();
    void onEditEventClick();
};

#endif // MAINWINDOW_H

