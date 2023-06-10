
#include "add.h"

#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>

    add::add(QWidget *parent) : QDialog(parent)
{
    QFormLayout *lytMain = new QFormLayout(this);

    QStringList labels = {"Product:", "Age:", "Gender:", "Relationship:", "Fitness:", "Income:"};

    for (int i = 0; i < 6; ++i)
    {
        QLabel *tLabel = new QLabel(labels[i], this);
        QLineEdit *tLine = new QLineEdit(this);
        lytMain->addRow(tLabel, tLine);

        fields << tLine;
    }

    QDialogButtonBox *buttonBox = new QDialogButtonBox
        ( QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
         Qt::Horizontal, this );
    lytMain->addWidget(buttonBox);

    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                        this, &add::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
                   this, &add::reject);
    Q_ASSERT(conn);

    setLayout(lytMain);
}

QStringList add::getStrings(QWidget *parent, bool *ok)
{
    add *dialog = new add(parent);

    QStringList list;

    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    if (ret) {
        foreach (auto field, dialog->fields) {
            list << field->text();
        }
    }

    dialog->deleteLater();

    return list;
}
