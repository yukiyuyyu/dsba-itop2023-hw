#include "statistics.h"
#include "ui_statistics.h"

Statistics::Statistics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Statistics)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Product" << "Percentage");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget_2->setColumnCount(2);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "Gender" << "Percentage");
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget_3->setColumnCount(2);
    ui->tableWidget_3->setHorizontalHeaderLabels(QStringList() << "Gender" << "Age");
    ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Statistics::~Statistics()
{
    delete ui;
}

void Statistics::populateTable(const QList<Data>& data)
{
    int totalVisitors = data.size();

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget_3->clearContents();
    ui->tableWidget_3->setRowCount(0);

    QMap<QString, int> productCounts;
    for (const Data& entry : data) {
        productCounts[entry.getProduct()]++;
    }

    int row = 0;
    for (auto it = productCounts.constBegin(); it != productCounts.constEnd(); ++it) {
        QString product = it.key();
        int count = it.value();
        double percentage = static_cast<double>(count) / totalVisitors * 100;

        QTableWidgetItem* productItem = new QTableWidgetItem(product);
        QTableWidgetItem* percentageItem = new QTableWidgetItem(QString::number(percentage, 'f', 2) + "%");

        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, productItem);
        ui->tableWidget->setItem(row, 1, percentageItem);

        row++;
    }

    int maleCount = 0;
    int femaleCount = 0;

    for (const Data& entry : data) {
        if (entry.getGender() == "Male") {
            maleCount++;
        } else if (entry.getGender() == "Female") {
            femaleCount++;
        }
    }

    double malePercentage = static_cast<double>(maleCount) / totalVisitors * 100;
    double femalePercentage = static_cast<double>(femaleCount) / totalVisitors * 100;

    QTableWidgetItem* maleItem = new QTableWidgetItem("Male");
    QTableWidgetItem* femaleItem = new QTableWidgetItem("Female");
    QTableWidgetItem* malePercentageItem = new QTableWidgetItem(QString::number(malePercentage, 'f', 2) + "%");
    QTableWidgetItem* femalePercentageItem = new QTableWidgetItem(QString::number(femalePercentage, 'f', 2) + "%");

    ui->tableWidget_2->insertRow(0);
    ui->tableWidget_2->insertRow(1);
    ui->tableWidget_2->setItem(0, 0, maleItem);
    ui->tableWidget_2->setItem(0, 1, malePercentageItem);
    ui->tableWidget_2->setItem(1, 0, femaleItem);
    ui->tableWidget_2->setItem(1, 1, femalePercentageItem);

    int maleAgeSum = 0;
    int maleCountAge = 0;
    int femaleAgeSum = 0;
    int femaleCountAge = 0;

    for (const Data& entry : data) {
        if (entry.getGender() == "Male") {
            maleAgeSum += entry.getAge();
            maleCountAge++;
        } else if (entry.getGender() == "Female") {
            femaleAgeSum += entry.getAge();
            femaleCountAge++;
        }
    }

    int maleAverageAge = (maleCountAge > 0) ? maleAgeSum / maleCountAge : 0;
    int femaleAverageAge = (femaleCountAge > 0) ? femaleAgeSum / femaleCountAge : 0;

    QTableWidgetItem* maleGenderItem = new QTableWidgetItem("Male");
    QTableWidgetItem* femaleGenderItem = new QTableWidgetItem("Female");
    QTableWidgetItem* maleAgeItem = new QTableWidgetItem(QString::number(maleAverageAge));
    QTableWidgetItem* femaleAgeItem = new QTableWidgetItem(QString::number(femaleAverageAge));

    ui->tableWidget_3->insertRow(0);
    ui->tableWidget_3->insertRow(1);
    ui->tableWidget_3->setItem(0, 0, maleGenderItem);
    ui->tableWidget_3->setItem(0, 1, maleAgeItem);
    ui->tableWidget_3->setItem(1, 0, femaleGenderItem);
    ui->tableWidget_3->setItem(1, 1, femaleAgeItem);
}
