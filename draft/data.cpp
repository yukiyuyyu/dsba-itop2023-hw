#include "data.h"

Data::Data() {}

Data::Data(QString product,int age, QString gender, QString martialstatus,int fitness, int income)
{
    this->product = product;
    this->age = age;
    this->gender = gender;
    this->martialstatus = martialstatus;
    this->fitness = fitness;
    this->income = income;
}

QString Data::getProduct() const
{
    return product;
}
QString Data::getGender() const
{
    return gender;
}
QString Data::getMartialstatus() const
{
    return martialstatus;
}
int Data::getAge() const
{
    return age;
}
int Data::getFitness() const
{
    return fitness;
}
int Data::getIncome() const
{
    return income;
}
void Data::setProduct(QString value)
{
    this->product = value;
}
void Data::setGender(QString value)
{
    this->gender = value;
}
void Data::setMartialstatus(QString value)
{
    this->martialstatus = value;
}
void Data::setAge(int value)
{
    this->age = value;
}
void Data::setFitness(int value)
{
    this->fitness = value;
}
void Data::setIncome(int value)
{
    this->income = value;
}
