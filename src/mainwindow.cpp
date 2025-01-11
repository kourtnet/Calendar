#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(DbManager& inputDbMgr, QWidget *parent): QMainWindow(parent), dbMgr(inputDbMgr), ui(new Ui::MainWindow)  {
    ui->setupUi(this);
    setWindowTitle("Calendar");

    initiate_connects();

    //fill lists
    updateTasksList();
    updateEventsList();
}
MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::initiate_connects() {
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::onAddTaskClick);
    connect(ui->addEventButton, &QPushButton::clicked, this, &MainWindow::onAddEventClick);
    connect(ui->deleteTaskButton, &QPushButton::clicked, this, &MainWindow::onDeleteTaskClick);
    connect(ui->deleteEventButton, &QPushButton::clicked, this, &MainWindow::onDeleteEventClick);
    connect(ui->editTaskButton, &QPushButton::clicked, this, &MainWindow::onEditTaskClick);
    connect(ui->editEventButton, &QPushButton::clicked, this, &MainWindow::onEditEventClick);
}

void MainWindow::updateTasksList() {
    QList<CalendarTask> listOfTasks;
    QString err;
    if(!dbMgr.db_select_all_tasks(err, listOfTasks)) {
        QMessageBox::critical(this, "Error", err);
    } else {
        //clear whole listview
        ui->tasksList->model()->removeRows(0, ui->tasksList->model()->rowCount());
        QList<CalendarTask>::Iterator listOfTasksIter = listOfTasks.begin();
        for(; listOfTasksIter != listOfTasks.end(); ++listOfTasksIter) {
            ui->tasksList->addItem(QString::number((*listOfTasksIter).get_id()) + " " +(*listOfTasksIter).get_name() + " " + (*listOfTasksIter).get_description() + " " + (*listOfTasksIter).get_date_time_begin().toString());
        }
    }
}

void MainWindow::updateEventsList() {
    QList<CalendarEvent> listOfEvents;
    QString err;
    if(!dbMgr.db_select_all_events(err, listOfEvents)) {
        QMessageBox::critical(this, "Error", err);
    } else {
        //clear whole listview
        ui->eventsList->model()->removeRows(0, ui->eventsList->model()->rowCount());
        QList<CalendarEvent>::Iterator listOfEventsIter = listOfEvents.begin();
        for(; listOfEventsIter != listOfEvents.end(); ++listOfEventsIter) {
            ui->eventsList->addItem(QString::number((*listOfEventsIter).get_id()) + " " +(*listOfEventsIter).get_name() + " " + (*listOfEventsIter).get_description() + " " + (*listOfEventsIter).get_date_time_begin().toString() + " " + (*listOfEventsIter).get_date_time_end().toString());
        }
    }
}

//all slots
void MainWindow::onAddTaskClick() {
    QString err;
    if(!dbMgr.db_insert_tasks(err, ui->addNameTaskLineEdit->text(), ui->addDescriptionTaskLineEdit->text(), ui->beginTaskDateEdit->dateTime())) {
        QMessageBox::critical(this, "Error", err);
    } else {
        updateTasksList();
    }
}

void MainWindow::onAddEventClick() {
    QString err;
    if(!dbMgr.db_insert_events(err, ui->addNameEventlineEdit->text(), ui->addDescriptionEventLineEdit->text(), ui->addBeginEventDateEdit->dateTime(), ui->addEndEventDateEdit->dateTime())) {
        QMessageBox::critical(this, "Error", err);
    } else {
        updateEventsList();
    }
}

void MainWindow::onDeleteTaskClick() {
    QString err;
    if(!dbMgr.db_delete_tasks(err, ui->tasksList->selectedItems().at(0)->text().split(' ').value(0).toInt())) {
        QMessageBox::critical(this, "Error", err);
    } else {
        updateTasksList();
    }
}

void MainWindow::onDeleteEventClick() {
    QString err;
    if(!dbMgr.db_delete_events(err, ui->eventsList->selectedItems().at(0)->text().split(' ').value(0).toInt())) {
        QMessageBox::critical(this, "Error", err);
    } else {
        updateEventsList();
    }
}

void MainWindow::onEditTaskClick() {
    QString err;
    if(!dbMgr.db_update_tasks(err, ui->tasksList->selectedItems().at(0)->text().split(' ').value(0).toInt(), ui->editNameTaskLineEdit->text(), ui->editDescriptionTaskLineEdit->text(), ui->editBeginTaskDateEdit->dateTime())) {
        QMessageBox::critical(this, "Error", err);
    } else {
        updateTasksList();
    }
}
void MainWindow::onEditEventClick() {
    QString err;
    if(!dbMgr.db_update_events(err, ui->eventsList->selectedItems().at(0)->text().split(' ').value(0).toInt(), ui->editNameEventlineEdit->text(), ui->editDescriptionEventLineEdit->text(), ui->editBeginEventDateEdit->dateTime(), ui->editEndEventDateEdit->dateTime())) {
        QMessageBox::critical(this, "Error", err);
    } else {
        updateEventsList();
    }
}





