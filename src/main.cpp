#include <QApplication>
#include <QMessageBox>

#include "mainwindow.h"

#define DB_FILEPATH "mdb.db"

bool initiate_Db(DbManager &dbMgr, QString &err) {
    if(!dbMgr.db_exists()) {
        qDebug() << "db doesnt exist, trying to create";
        return(dbMgr.db_create(err));
    }
    return true;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    //First we innit db. We do it in main in order to close app at the begining, if for some reason it's impossible to open or create db file
    DbManager dbMgr(DB_FILEPATH);
    QString err;
    if(!initiate_Db(dbMgr, err)) {
        QMessageBox::critical(nullptr, "Error", err);
        return -1;
    }

    //Start main window after db initiation
    MainWindow window(dbMgr);
    window.show();
    return app.exec();
}



