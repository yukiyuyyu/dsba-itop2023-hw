
#include "qtableviewmodel.h"

#include <QModelIndex>
#include <QDebug>
#include <QPixmap>

    QTableViewModel::QTableViewModel(QObject *parent)
    :QAbstractListModel(parent)
{
    values = new QList<Data>();
}

int QTableViewModel::rowCount(const QModelIndex &) const
{
    return values->count();
}

int QTableViewModel::columnCount(const QModelIndex &) const
{
    return 6;
}

QVariant QTableViewModel::data( const QModelIndex &index, int role ) const
{

    QVariant value;

    switch ( role )
    {
    case Qt::DisplayRole: //string
    {
        switch (index.column()) {
        case 0: {
            value = this->values->at(index.row()).getProduct();
            break;
        }
        case 1: {
            value = this->values->at(index.row()).getAge();
            break;
        }
        case 2: {
            value = this->values->at(index.row()).getGender();
            break;
        }
        case 3: {
            value = this->values->at(index.row()).getMartialstatus();
            break;
        }
        case 4:{
            value = this->values->at(index.row()).getFitness();
            break;
        }
        case 5: {
            value = this->values->at(index.row()).getIncome();
            break;
        }
        }
    }
    break;

    case Qt::UserRole: //data
    {
        value = this->values->at(index.row()).getProduct();
    }
    break;

    default:
        break;
    }

    return value;
}

void QTableViewModel::populate(QList<Data> *newValues)
{
    beginResetModel();
    values->clear();
    values->append(*newValues);
    endResetModel();
}

void QTableViewModel::append(Data value)
{
    int idx = rowCount(QModelIndex());
    beginInsertRows(QModelIndex(), idx, idx);
    values->append(value);
    endInsertRows();
}

void QTableViewModel::update(int idx, Data value) {
    (*this->values)[idx] = value;
    QModelIndex item_idx_s = this->index(idx, 0);
    QModelIndex item_idx_e = this->index(idx, this->columnCount(QModelIndex()));
    emit this->dataChanged(item_idx_e, item_idx_s);
}

void QTableViewModel::deleteRow(int idx) {
    beginRemoveRows(QModelIndex(), idx, idx);
    values->removeAt(idx);
    endRemoveRows();
}


void QTableViewModel::setValues(QList<Data> *newValues)
{
    values = newValues;
}



QVariant QTableViewModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0: {
            return QString("Product");
        }
        case 1:{
            return QString("Age");
        }
        case 2:{
            return QString("Gender");
        }
        case 3:{
            return QString("Relationship");
        }
        case 4:{
            return QString("Fitness");
        }
        case 5:{
            return QString("Income");
        }
        }
    }

    return QVariant();
}
