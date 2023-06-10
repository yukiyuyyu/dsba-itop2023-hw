#ifndef DATA_H
#define DATA_H

#include <QString>

class Data {
private:
    QString product;
    int age;
    QString gender;
    QString martialstatus;
    int fitness;
    int income;

public:
    Data();
    Data(QString product,int age, QString gender, QString martialstatus,int fitness, int income);
    QString getProduct() const;
    QString getGender() const;
    QString getMartialstatus() const;
    int getAge() const;
    int getFitness() const;
    int getIncome() const;
    void setProduct(QString value);
    void setGender(QString value);
    void setMartialstatus(QString value);
    void setAge(int value);
    void setFitness(int value);
    void setIncome(int value);
};

#endif // DATA_H
