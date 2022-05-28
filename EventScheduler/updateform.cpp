#include "updateform.h"
#include "ui_updateform.h"
#include "mainwindow.h"
#include "model.h"
#include <string>
#include<time.h>
#include <ctime>

#include <QStringListModel>
using namespace std;
UpdateForm::UpdateForm(Model *model,MainWindow* Mainwindow,int currentIndex,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UpdateForm)
{
  this->activemodel = model;
  this->mainwindow = Mainwindow;
  this->currentIndex = currentIndex;
  ui->setupUi(this);
  auto event = model->At(currentIndex);
  ui->name->setPlainText(event->getName().c_str());
  ui->place->setPlainText(event->getPlace().c_str());
  ui->startDate->setDateTime(QDateTime::fromString(QString::fromStdString(event->getStartDate()),"dd/MM/yyyy hh:mm"));
  ui->endDate->setDateTime(QDateTime::fromString(QString::fromStdString(event->getEndDate()),"dd/MM/yyyy hh:mm"));
  ui->reminderDate->setDateTime(QDateTime::fromString(QString::fromStdString(event->getReminder()),"dd/MM/yyyy hh:mm"));
  connect(ui->update,&QPushButton::clicked,this,&UpdateForm::UpdateEvent);
}
void UpdateForm::UpdateEvent() {
    string name = ui->name->toPlainText().toStdString();
    string place = ui->place->toPlainText().toStdString();
    string startdate = ui->startDate->dateTime().toString("dd/mm/yyyy hh:mm").toStdString();
    string enddate = ui->endDate->dateTime().toString("dd/mm/yyyy hh:mm").toStdString();
    string remindertime = ui->reminderDate->dateTime().toString("dd/mm/yyyy hh:mm").toStdString();
    Event* ev = new Event(name,place,startdate,enddate,remindertime);
    this->activemodel->Update(currentIndex,ev);
    this->mainwindow->updateActiveItem(ev->display());
    close();
}
UpdateForm::~UpdateForm()
{
    delete ui;
}
