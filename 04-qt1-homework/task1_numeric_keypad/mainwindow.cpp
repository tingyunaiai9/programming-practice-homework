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

    // clear button
    button = new QPushButton("AC", this);
    button->resize(100,80);
    button->move(400, 150);
    button->setStyleSheet(
        "QPushButton {"
        "    background-color: #D3D3D3;"
        "    border-style: outset;"
        "}"
        "QPushButton:hover {"
        "    background-color: #A9A9A9;"  // 深灰色
        "}"
        "QPushButton:pressed {"
        "    background-color: #696969;"  // 暗灰色
        "}"
        );
    connect(button,SIGNAL(clicked()),this,SLOT(clearClicked()));

    // lcd number
    m_lcdNumber = new QLCDNumber(this);
    m_lcdNumber->resize(400, 80);
    m_lcdNumber->move(100, 50);
    m_lcdNumber->setDigitCount(10);
    m_lcdNumber->display(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClicked(int number)
{
    int cur_number = m_lcdNumber->intValue();
    m_lcdNumber->display(cur_number*10+number);
}

void MainWindow::clearClicked()
{
    m_lcdNumber->display(0);
}
