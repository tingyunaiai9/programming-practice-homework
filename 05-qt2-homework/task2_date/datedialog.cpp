#include "datedialog.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QMessageBox>

DateDialog::DateDialog(QWidget *parent)
    : QDialog(parent),
      yearEdit(new QLineEdit(this)),
      monthEdit(new QLineEdit(this)),
      dayEdit(new QLineEdit(this)),
      okButton(new QPushButton(tr("OK"), this))
{
    setWindowTitle(tr("Set Date"));

    yearEdit->setPlaceholderText("year");
    monthEdit->setPlaceholderText("month");
    dayEdit->setPlaceholderText("day");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QVBoxLayout *dateLayout = new QVBoxLayout();
    dateLayout->addWidget(yearEdit);
    dateLayout->addWidget(monthEdit);
    dateLayout->addWidget(dayEdit);

    mainLayout->addLayout(dateLayout);
    mainLayout->addWidget(okButton);

    connect(okButton, &QPushButton::clicked, this, &DateDialog::dateChanged);
}

Date DateDialog::getDate() const
{
    return Date(yearEdit->text(), monthEdit->text(), dayEdit->text());
}

void DateDialog::dateChanged()
{
    accept();
}


