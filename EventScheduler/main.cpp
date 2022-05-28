#include "mainwindow.h"
#include <QApplication>
#include "Data-structure-project-main/Event.h"
#include "Data-structure-project-main/Database.h"
#include <string.h>
#include <iostream>
#include "model.h"
#include "Data-structure-project-main/BinaryTree.h"
#include "Data-structure-project-main/BinaryTree.cpp"
#include "Data-structure-project-main/btiterator.h"
#include "Data-structure-project-main/btiterator.cpp"
using namespace std;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Database db;
    db.CreateTable("Events");
    db.CreateTable("Finished");
    Model *activeModel = new Model(ACTIVETABLENAME);
    Model *archiveModel = new Model(ARCHIVETABLENAME);
     db.SelectAll(ACTIVETABLENAME,activeModel->tree);
     db.SelectAll(ARCHIVETABLENAME,archiveModel->tree);
    MainWindow w(activeModel,archiveModel);
    InOrderBTIterator<Event>* activeIterator = new InOrderBTIterator<Event>(activeModel->tree);
    InOrderBTIterator<Event>* archiveIterator = new InOrderBTIterator<Event>(archiveModel->tree);
    for(Event* i = activeIterator->getNext();i != NULL;i = activeIterator->getNext()){
        w.addActiveItem(i->display());
    }
    for(Event* i = archiveIterator->getNext();i != NULL; i = activeIterator->getNext()){
        w.addArchiveItem(i->display());
    }
    delete activeIterator;
    delete archiveIterator;
    w.show();
    return a.exec();
}
