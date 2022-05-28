#include "addform.h"
#include "ui_addform.h"
#include <string>
#include<time.h>
#include <ctime>
#include <Data-structure-project-main/Event.h>
#include <exception>
using namespace std;

void AddForm::addNewEvent(){
   string name = ui->name->toPlainText().toStdString();
   string place = ui->place->toPlainText().toStdString();
   string startDate = ui->startDate->dateTime().toString("dd/MM/yyyy hh:mm").toStdString();
   string endDate = ui->endDate->dateTime().toString("dd/MM/yyyy hh:mm").toStdString();
   string reminderDate = ui->reminderDate->dateTime().toString("dd/MM/yyyy hh:mm").toStdString();
   Event* event = new Event(name,place,startDate,endDate,reminderDate);
   this->activeModel->Insert(event);
   this->mainWindow->addActiveItem(event->display());
   close();
}
AddForm::AddForm(Model* model,MainWindow* mainWindow,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddForm)
{
    this->mainWindow = mainWindow;
    this->activeModel = model;
    ui->setupUi(this);
    connect(ui->addInput,&QPushButton::clicked,this,&AddForm::addNewEvent);
}

AddForm::~AddForm()
{
    delete ui;
}
