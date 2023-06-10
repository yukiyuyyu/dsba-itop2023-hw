#include "authorisation.h"
#include "ui_authorisation.h"
#include "QTableWidget"
#include "QTableWidgetItem"
#include "qtableviewmodel.h"
#include <QFileDialog>
#include <QMessageBox>
#include "add.h"
#include <QHeaderView>
#include <QSortFilterProxyModel>
#include <QTextStream>
#include <QInputDialog>
#include <QDebug>



authorisation::authorisation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::authorisation)
{
    ui->setupUi(this);

    ui->tableView->setModel(model);

    values = new QList<Data>();

    model = new QTableViewModel(this);
    model ->setValues(values);

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    ui->tableView->setModel(proxyModel);
    ui->tableView ->setSortingEnabled(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

authorisation::~authorisation()
{
    delete ui;
}

void authorisation::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}


void authorisation::on_add_clicked()
{

    QStringList productOptions;
    productOptions << "TM195" << "TM498" << "TM798";
    QString product = QInputDialog::getItem(this, "Add Row", "Product:", productOptions);
    QStringList genderOptions;
    genderOptions << "Male" << "Female";
    QString gender = QInputDialog::getItem(this, "Add Row", "Gender:", genderOptions);

    QStringList relationshipOptions;
    relationshipOptions << "Single" << "Partnered";
    QString relationship = QInputDialog::getItem(this, "Add Row", "Relationship:", relationshipOptions);


    bool ok;
    int age = QInputDialog::getInt(this, "Add Row", "Age:", 0, 0, INT_MAX, 1, &ok);
    if (!ok || age <= 0) return;

    int fitness = QInputDialog::getInt(this, "Add Row", "Fitness:", 0, 1, 5, 1,  &ok);
    if (!ok || fitness <= 0) return;

    int income = QInputDialog::getInt(this, "Add Row", "Income:", 0, 0, INT_MAX, 1, &ok);
    if (!ok || income <= 0) return;

    if (product.isEmpty() || gender.isEmpty() || relationship.isEmpty()) {
        return;
    }

    if (!productOptions.contains(product) || !genderOptions.contains(gender) || !relationshipOptions.contains(relationship)) {
        return;
    }

    Data newData(product, age, gender, relationship, fitness, income);

    model->append(newData);

    values->append(newData);
}

void authorisation::on_del_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (index.isValid()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation", "Are you sure you want to delete this row?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            int row = proxyModel->mapToSource(index).row();
            model->deleteRow(row);
        }
    }
}


void authorisation::on_edit_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (currentIndex.isValid()) {
        int row = proxyModel->mapToSource(currentIndex).row();
        Data currentData = values->at(row);

        bool ok;
        QStringList list = add::getStrings(this, &ok);
        if (ok && list.size() == 6) {
            currentData.setProduct(list[0]);
            currentData.setAge(list[1].toInt());
            currentData.setGender(list[2]);
            currentData.setMartialstatus(list[3]);
            currentData.setFitness(list[4].toInt());
            currentData.setIncome(list[5].toInt());

            model->update(row, currentData);
        }
    }
}

void authorisation::on_actionOpen_triggered()
{
    QString fileName = ":/file/CardioGoodFitness.csv";

    QFile file(fileName);

    QString data;
    QStringList rowOfData;
    QStringList rowData;
    data.clear();
    rowOfData.clear();
    rowData.clear();

    if (file.open(QFile::ReadOnly))
    {
        data = file.readAll();
        rowOfData = data.split("\n");
        file.close();
    }

    values = new QList<Data>(*values);

    for (int x = 1; x < rowOfData.size(); ++x)
    {
        rowData = rowOfData.at(x).split(";");
        if (rowData.size() == 6)
            values->append(Data(rowData[0], rowData[1].toInt(),rowData[2], rowData[3], rowData[4].toInt(), rowData[5].toInt()));
    }

    model->populate(values);
}

void authorisation::on_pushButton_2_clicked()
{
    window = new Statistics(this);
    window->populateTable(*values);  // Pass the data to populate the table
    window->show();
}


void authorisation::on_actionSave_as_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save File", "", "CSV Files (*.csv)");

    if (!filePath.isEmpty()) {
        QFile file(filePath);

        if (file.open(QIODevice::WriteOnly)) {
            QTextStream stream(&file);


            for (int row = 0; row < model->rowCount(QModelIndex()); ++row) {
                for (int col = 0; col < model->columnCount(QModelIndex()); ++col) {
                    QModelIndex index = model->index(row, col, QModelIndex());
                    QString value = model->data(index, Qt::DisplayRole).toString();
                    stream << value << ";";
                }
                stream << "\n";
            }

            file.close();

            QMessageBox::information(this, "Save Successful", "Table saved successfully.");
        } else {
            QMessageBox::critical(this, "Save Error", "Failed to save the table.");
        }
    }
}

