#ifndef AUTHORISATION_H
#define AUTHORISATION_H

#include <QMainWindow>
#include "data.h"
#include "qtableviewmodel.h"
#include <QSortFilterProxyModel>
#include "statistics.h"


namespace Ui {
class authorisation;
}

class authorisation : public QMainWindow
{
    Q_OBJECT

public:
    explicit authorisation(QWidget *parent = nullptr);
    ~authorisation();
signals:
    void firstWindow();


private slots:
    void on_pushButton_clicked();

    void on_add_clicked();

    void on_del_clicked();

    void on_edit_clicked();

    void on_actionOpen_triggered();

    void on_pushButton_2_clicked();

    void on_actionSave_as_triggered();

private:
    Ui::authorisation *ui;
    QList<Data> *values;

    QTableViewModel *model;

    QSortFilterProxyModel* proxyModel;

    Statistics *window;

};

#endif // AUTHORISATION_H
