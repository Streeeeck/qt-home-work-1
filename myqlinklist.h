#ifndef MYQLINKLIST_H
#define MYQLINKLIST_H
#include <QLinkedList>
#include "storage.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>


class MyQLinkList: public QLinkedList<Storage> {
    QStandardItemModel* model;
    QStandardItem * item;
public:
    MyQLinkList(QStandardItemModel* _model);
    void push(Storage st);
    void del(int _id);
    void clean();
    void edit(Storage st, int _id);
    Storage getData(int _id);
    QJsonArray toJSON();



};

#endif // MYQLINKLIST_H
