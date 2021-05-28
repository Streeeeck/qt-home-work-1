#include "myqlinklist.h"


MyQLinkList::MyQLinkList(QStandardItemModel *_model)
{
    model = _model;
}

void MyQLinkList::push(Storage st)
{
    this->push_back(st);
    int row = model->rowCount();
    item = new QStandardItem(QString::number(st.getId()));
    model->setItem(row, 0, item);
    item = new QStandardItem(QString::number(st.getCapacity()));
    model->setItem(row, 1, item);
    item = new QStandardItem(st.getCity());
    model->setItem(row, 2, item);
    item = new QStandardItem(st.getAddress());
    model->setItem(row, 3, item);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Capacity"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("City"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("address"));
}

void MyQLinkList::del(int _id)
{
    model->removeRows(_id,1);
    QLinkedList<Storage>::iterator it = this->begin();
    for(int i = 0;i < _id; i++) {
        ++it;
    }
    it = this->erase(it);

}

void MyQLinkList::clean()
{
    this->clear();
}

void MyQLinkList::edit(Storage st, int _id)
{
    QLinkedList<Storage>::iterator it = this->begin();
    for(int i = 0;i < _id; i++) {
        ++it;
    }
    it->setId(st.getId());
    it->setCity(st.getCity());
    it->setCapacity(st.getCapacity());
    it->setAddress(st.getAddress());
    item = new QStandardItem(QString::number(st.getId()));
    model->setItem(_id,0,item);
    item = new QStandardItem(QString::number(st.getCapacity()));
    model->setItem(_id,1,item);
    item = new QStandardItem(st.getCity());
    model->setItem(_id,2,item);
    item = new QStandardItem(st.getAddress());
    model->setItem(_id,3,item);
}

Storage MyQLinkList::getData(int _id)
{
    QLinkedList<Storage>::iterator it = this->begin();
    for(int i = 0;i < _id; i++) {
        ++it;
    }
    return Storage(it->getId(),it->getCapacity(),it->getCity(),it->getAddress());
}

QJsonArray MyQLinkList::toJSON()
{
    QJsonArray dataArray;

    QLinkedList<Storage>::iterator it = this->begin();
    while (it != this->end()) {
        QJsonObject textObject;
        textObject["address"] = it->getAddress();
        textObject["city"] = it->getCity();
        textObject["capacity"] = QString::number(it->getCapacity());
        textObject["id"] = QString::number(it->getId());
        dataArray.append(textObject);

        ++it;
    }
    return  dataArray;
}

