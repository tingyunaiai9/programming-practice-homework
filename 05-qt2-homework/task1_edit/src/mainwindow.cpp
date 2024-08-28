#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QVBoxLayout>
#include <QTextEdit>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->inputLineEdit->installEventFilter(this);
    ui->inputLineEdit->setPlaceholderText("请输入文字");
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->inputLineEdit)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Enter ||
                keyEvent->key() == Qt::Key_Return)
            {
                QString text = ui->inputLineEdit->text();
                if (!text.isEmpty())
                {
                    ui->outputTextEdit->append(text);
                    ui->inputLineEdit->clear();
                }

                return true;
            }
        }
    }

    return QMainWindow::eventFilter(obj, event);
}
