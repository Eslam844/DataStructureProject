#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStringListModel>
#include <QStringList>
#include <string.h>
#include <iostream>
#include <model.h>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Model* activeModel,Model* archiveModel,QWidget *parent = nullptr);
~MainWindow();
void updateActiveItem(string content);
void addActiveItem(string content);
void addArchiveItem(string content);
void Add();
void ClearActive();
void DeleteActive();
void ClearArchive();
void DeleteArchive();
void Update();
private:
    Model* activeModel;
    Model* archiveModel;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
