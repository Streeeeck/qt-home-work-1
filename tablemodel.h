#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include <QAbstractTableModel>
#include "storage.h"
#include <QLinkedList>

class TableModel: public QAbstractTableModel
{
public:
    TableModel(QLinkedList <Storage> *_data);
    int rowCount(int index);
    int columnCount(int index);
    QVariant data(QModelIndex index, int role = Qt::DisplayRole);

private:
    QLinkedList <Storage> *_data;
};

#endif // TABLEMODEL_H
