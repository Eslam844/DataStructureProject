#ifndef ADDFORM_H
#define ADDFORM_H
#include "model.h"
#include <QWidget>
#include "mainwindow.h"
#include <Data-structure-project-main/Database.h>
namespace Ui {
class AddForm;
}

class AddForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddForm(Model* activeModel,MainWindow* mainWindow,QWidget *parent = nullptr);
    ~AddForm();

private:
    Model* activeModel;
    MainWindow* mainWindow;
    void addNewEvent();
    Ui::AddForm *ui;
};

#endif // ADDFORM_H
