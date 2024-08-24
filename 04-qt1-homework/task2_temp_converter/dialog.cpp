#include "dialog.h"
#include "./ui_dialog.h"

#include <QGroupBox>
#include <QDial>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Create a TempConverter object
    tempConverter = new TempConverter(0, this);

    // QGroupBox
    QGroupBox *celsiusGroupBox = new QGroupBox(tr("Celsius"));
    QDial *celsiusDial = new QDial;
    celsiusDial->setRange(0, 100);
    celsiusDial->setSingleStep(1);
    celsiusDial->setFixedSize(200, 200);
    QLCDNumber *celsiusLcd = new QLCDNumber;
    celsiusLcd->setFixedSize(200, 50);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(celsiusDial);
    vbox->addWidget(celsiusLcd);
    celsiusGroupBox->setLayout(vbox);
    celsiusGroupBox->setFixedSize(250, 300);

    QGroupBox *fahrenheitGroupBox = new QGroupBox(tr("Fahrenheit"));
    QDial *fahrenheitDial = new QDial;
    fahrenheitDial->setRange(32, 212);
    fahrenheitDial->setSingleStep(1);
    fahrenheitDial->setFixedSize(200, 200);
    QLCDNumber *fahrenheitLcd = new QLCDNumber;
    fahrenheitLcd->setFixedSize(200, 50);

    vbox = new QVBoxLayout;
    vbox->addWidget(fahrenheitDial);
    vbox->addWidget(fahrenheitLcd);
    fahrenheitGroupBox->setLayout(vbox);
    fahrenheitGroupBox->setFixedSize(250, 300);

    // Create a main layout
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(celsiusGroupBox);
    mainLayout->addWidget(fahrenheitGroupBox);

    // Set the main layout to the dialog
    setLayout(mainLayout);
    resize(600, 350);

    connect(celsiusDial, SIGNAL(valueChanged(int)), tempConverter, SLOT(setTempCelsius(int)));
    connect(celsiusDial, SIGNAL(valueChanged(int)), celsiusLcd, SLOT(display(int)));
    connect(tempConverter, SIGNAL(tempCelsiusChanged(int)), celsiusDial, SLOT(setValue(int)));

    connect(fahrenheitDial, SIGNAL(valueChanged(int)), tempConverter, SLOT(setTempFahrenheit(int)));
    connect(fahrenheitDial, SIGNAL(valueChanged(int)), fahrenheitLcd, SLOT(display(int)));
    connect(tempConverter, SIGNAL(tempFahrenheitChanged(int)), fahrenheitDial, SLOT(setValue(int)));
}

Dialog::~Dialog()
{
    delete ui;
}
