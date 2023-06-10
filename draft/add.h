#include <QDialog>
#ifndef ADD_H
#define ADD_H


    class QLineEdit;
class QLabel;

class add : public QDialog
{
    Q_OBJECT
public:
    explicit add(QWidget *parent = nullptr);

    static QStringList getStrings(QWidget *parent, bool *ok = nullptr);

private:
    QList<QLineEdit*> fields;
};

#endif // ADD_H
