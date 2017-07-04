#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTableView;
class MyModel;
class QLineEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

public slots:

private:
    void initMainWidget();
    void initTable();
    void initAddRowWidget();

    QTableView *view;
    MyModel *model;

    QLineEdit *leSurname;
    QLineEdit *leName;
    QLineEdit *lePatronymic;

};

#endif // MAINWINDOW_H
