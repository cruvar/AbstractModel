#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>
#include <QVariant>

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyModel();

    int rowCount(const QModelIndex& parent) const;
    int columnCount(const QModelIndex& parent) const;
    QVariant data(const QModelIndex& index, int role) const;

    bool setData(const QModelIndex& index, const QVariant& value, int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex& index ) const;

public slots:
    void addRow();
    void delRow();

private:
    void calculateAverage(int row);

    enum Column {
        ZoneCode = 0,
        ZoneCodeMin,
        ZoneCodeMax,
        Result,
        LAST };

    typedef QHash<Column, QVariant> CodeData;
    typedef QList<CodeData> Codes;
    Codes m_codes;

};

#endif // MYMODEL_H
