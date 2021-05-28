#include "tablemodel.h"

TableModel::TableModel(QLinkedList <Storage> *_data)
{
    _data = _data;
}

int TableModel::rowCount(int index)
{

    return _data->size();
}

int TableModel::columnCount(int index)
{
    return 4;
}

QVariant TableModel::data(QModelIndex index, int role)
{
    return 0;
}
