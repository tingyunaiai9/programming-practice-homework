#ifndef DATEDIALOG_H
#define DATEDIALOG_H

#include "date.h"

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class DateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DateDialog(QWidget *parent = nullptr);
    Date getDate() const;

private slots:
    void dateChanged();

private:
    QLineEdit *yearEdit;
    QLineEdit *monthEdit;
    QLineEdit *dayEdit;
    QPushButton *okButton;
};

#endif // DATEDIALOG_H
