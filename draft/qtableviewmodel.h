#ifndef QTABLEVIEWMODEL_H
#define QTABLEVIEWMODEL_H


#include "data.h"
#include <QModelIndex>

class QTableViewModel : public QAbstractListModel
{
public:
    QTableViewModel(QObject *parent=nullptr);
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void populate(QList<Data> *newValues);
    void append(Data value);
    void update(int idx, Data value);
    void deleteRow(int idx);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void setValues(QList<Data> *newValues);
private:
    QList<Data> *values;
};

#endif // QTABLEVIEWMODEL_H
