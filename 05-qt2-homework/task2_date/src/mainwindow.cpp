#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "datedialog.h"

#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resize(400, 300);

    createMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createMenus()
{
    QMenu *menu = menuBar()->addMenu("Menu");
    QAction *setDateAction = menu->addAction("set date");
    connect(setDateAction, &QAction::triggered, this, &MainWindow::showDateDialog);
}

void MainWindow::showDateDialog()
{
    DateDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        Date date = dialog.getDate();
        if (date.isValidDate())
        {
            QMessageBox::information(this, "Date", date.toString());
        }
        else
        {
            QMessageBox::warning(this, "Invalid Date", "The date is not valid:\n" + date.toString());
        }
    }
}
