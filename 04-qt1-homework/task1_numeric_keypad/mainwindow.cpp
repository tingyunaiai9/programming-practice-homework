#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(600, 600);

    m_signalMapper = new QSignalMapper(this);

    // button 0
    QPushButton *button = new QPushButton(QString::number(0), this);
    button->resize(80,80);
    button->move(200, 450);
    connect(button,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    m_signalMapper->setMapping(button, 0);

    for(int i=1; i<10; i++)
    {
        button = new QPushButton(QString::number(i), this);
        button->resize(80,80);
        button->move(100+100*((i+2)%3), 450-100*((i+2)/3));

        // set map
        connect(button,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
        m_signalMapper->setMapping(button, i);
    }

    // connect signalMapper to slot
    connect(m_signalMapper,SIGNAL(mappedInt(int)),this,SLOT(numberClicked(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClicked(int number)
{
    QMessageBox::information(this,"Number clicked",QString::number(number));
}
