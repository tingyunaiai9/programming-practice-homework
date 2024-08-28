#include "mainwindow.h"
#include "./src/ui_mainwindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    imageButton = new QPushButton(this);
    imageButton->setIconSize(QSize(540, 360));

    imageButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    imagePaths.append(":/picture1.jpg");
    imagePaths.append(":/picture2.jpeg");
    imagePaths.append(":/picture3.jpeg");
    imagePaths.append(":/picture4.jpg");

    currentImageIndex = 0;
    imageButton->setIcon(QIcon(imagePaths[currentImageIndex]));

    connect(imageButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(imageButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked()
{
    currentImageIndex = (currentImageIndex + 1) % imagePaths.size();

    imageButton->setIcon(QIcon(imagePaths[currentImageIndex]));
}
