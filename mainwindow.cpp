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

        widAddRow->layout()->addWidget(new QLabel(tr("ZoneCode:")));
        widAddRow->layout()->addWidget(leSurname = new QLineEdit(widAddRow));
        widAddRow->layout()->addWidget(new QLabel(tr("Zone Height[min]")));
        widAddRow->layout()->addWidget(leName = new QLineEdit(widAddRow));
        widAddRow->layout()->addWidget(new QLabel(tr("Zone Height[max]:")));
        widAddRow->layout()->addWidget(lePatronymic = new QLineEdit(widAddRow));

        QPushButton *btnAppend = new QPushButton(tr("Add"),widAddRow);
        connect(btnAppend,&QPushButton::clicked,this,[=]{
            model->appendCode(leSurname->text(), leName->text(), lePatronymic->text());
        });
        widAddRow->layout()->addWidget(btnAppend);

        QPushButton *btnDelete = new QPushButton(tr("Delete"),widAddRow);
        connect(btnDelete,&QPushButton::clicked,model,&MyModel::removeSelected);
        widAddRow->layout()->addWidget(btnDelete);
    }
    centralWidget()->layout()->addWidget(widAddRow);
}
