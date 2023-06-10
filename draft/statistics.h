#ifndef STATISTICS_H
#define STATISTICS_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>
#include "data.h"

namespace Ui {
class Statistics;
}

class Statistics : public QMainWindow
{
    Q_OBJECT

public:
    explicit Statistics(QWidget *parent = nullptr);
    ~Statistics();

    void populateTable(const QList<Data>& data);

private:
    Ui::Statistics *ui;
    QTableView *tableView;
    QStandardItemModel *tableModel;
};

#endif // STATISTICS_H
