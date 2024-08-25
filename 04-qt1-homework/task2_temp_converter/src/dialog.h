#ifndef DIALOG_H
#define DIALOG_H

#include "tempconverter.h"

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

    TempConverter *tempConverter;
};
#endif // DIALOG_H
