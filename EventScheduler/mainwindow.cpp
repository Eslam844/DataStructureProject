#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addform.h"
#include "updateform.h"
void MainWindow::Add(){
    AddForm* form = new AddForm(this->activeModel,this);
    form->show();
}
void MainWindow::Update(){
    int currentIndex = ui->activeEvents->currentRow();
    if(currentIndex == -1)return;
    UpdateForm* form = new UpdateForm(this->activeModel,this,currentIndex);
    form->show();
}
void MainWindow::ClearActive(){
    ui->activeEvents->clear();
    activeModel->Clear();
}
void MainWindow::DeleteActive(){
    auto currentIndex = ui->activeEvents->currentRow();
    if(currentIndex == -1) return;
    activeModel->Delete(currentIndex);
    delete ui->activeEvents->currentItem();
}
void MainWindow::ClearArchive(){
    ui->archive->clear();
    archiveModel->Clear();
}
void MainWindow::DeleteArchive(){
    auto currentIndex = ui->archive->currentRow();
    archiveModel->Delete(currentIndex);
    delete ui->archive->currentItem();
}
void MainWindow::updateActiveItem(string content) {
    DeleteActive();
    addActiveItem(content);
}
void MainWindow::addActiveItem(string content){
    ui->activeEvents->addItem(content.c_str());
}
void MainWindow::addArchiveItem(string content){
    ui->archive->addItem(content.c_str());
}
MainWindow::MainWindow(Model* activeModel,Model* archiveModel,QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->activeModel = activeModel;
    this->archiveModel = archiveModel;
    connect(ui->DeleteActive,&QPushButton::clicked,this,&MainWindow::DeleteActive);
    connect(ui->ClearActive,&QPushButton::clicked,this,&MainWindow::ClearActive);
    connect(ui->DeleteArchive,&QPushButton::clicked,this,&MainWindow::DeleteArchive);
    connect(ui->ClearArchive,&QPushButton::clicked,this,&MainWindow::ClearArchive);
    connect(ui->AddButton,&QPushButton::clicked,this,&MainWindow::Add);
    connect(ui->UpdateButton,&QPushButton::clicked,this,&MainWindow::Update);
}
MainWindow::~MainWindow()
{
    delete ui;
}

