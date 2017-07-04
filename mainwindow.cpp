#include "mainwindow.h"
#include "mymodel.h"

#include <QTableView>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    initMainWidget();
    initTable();
    initAddRowWidget();
}

void MainWindow::initMainWidget()
{
    QWidget *mainWidget = new QWidget(this);
    mainWidget->setLayout(new QVBoxLayout);
    setCentralWidget(mainWidget);
}

void MainWindow::initTable()
{
    view = new QTableView(this->centralWidget());
    view->setModel(model = new MyModel);
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    centralWidget()->layout()->addWidget(view);
}

void MainWindow::initAddRowWidget()
{
    QWidget *widAddRow = new QWidget(this->centralWidget());
    {
        widAddRow->setLayout(new QHBoxLayout);

        QPushButton *btnAdd = new QPushButton(tr("Add"),widAddRow);
        connect(btnAdd,&QPushButton::clicked,model,&MyModel::addRow);
        widAddRow->layout()->addWidget(btnAdd);

        QPushButton *btnDel = new QPushButton(tr("Delete"),widAddRow);
        connect(btnDel,&QPushButton::clicked,model,&MyModel::delRow);
        widAddRow->layout()->addWidget(btnDel);
    }
    centralWidget()->layout()->addWidget(widAddRow);
}
