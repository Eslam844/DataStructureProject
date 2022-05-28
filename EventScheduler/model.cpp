#include "model.h"

Model::Model(string tableName)
{
    this->tableName = tableName;
    this->db = new Database();
    this->tree = new BSTree<Event>();
}
void Model::Clear(){
    db->Delete(this->tableName,"");
}
void Model::Delete(int index){
    assert(index >= 0 && index < this->tree->length());
    InOrderBTIterator<Event>* iterator = new InOrderBTIterator<Event>(this->tree);
    Event *event = iterator->getByIndex(index);
    this->db->Delete(this->tableName,event->getName());
    this->tree->Remove(event);
    delete iterator;
}
void Model::Insert(Event* event){
    this->db->Insert(this->tableName,*event);
    this->tree->insert(event);
}
void Model::Update(int index, Event* event){
    assert(index >= 0 && index < this->tree->length());
    this->db->Update(this->tableName,*event);
    InOrderBTIterator<Event>* iterator = new InOrderBTIterator<Event>(this->tree);
    Event* ev = iterator->getByIndex(index);
    this->tree->Remove(ev);
    this->tree->insert(event);
    delete iterator;
}
Event* Model::At(int index){
    assert(index >= 0 && index < this->tree->length());
    InOrderBTIterator<Event>* iterator = new InOrderBTIterator<Event>(this->tree);
    Event* ev = iterator->getByIndex(index);
    delete iterator;
    return ev;
}
int Model::Length() {return this->tree->length();}
Model::~Model(){
    delete this->db;
    delete this->tree;
}
