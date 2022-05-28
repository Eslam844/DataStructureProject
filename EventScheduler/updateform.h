#ifndef UPDATEFORM_H
#define UPDATEFORM_H
#include "model.h"
#include "mainwindow.h"
#include <QWidget>
#include <Data-structure-project-main/Database.h>
#include <QMainWindow>
#include <QPushButton>
#include <QStringListModel>
#include <QStringList>
#include <string.h>
#include <iostream>
#include <model.h>
namespace Ui {
class UpdateForm;
}

class UpdateForm : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateForm(Model*model,MainWindow*mainwindow,int currentIndex,QWidget *parent = nullptr);
    ~UpdateForm();

private:
    int currentIndex;
    Model *activemodel;
    MainWindow *mainwindow;
    void UpdateEvent();
    Ui::UpdateForm *ui;
};

#endif // UPDATEFORM_H
