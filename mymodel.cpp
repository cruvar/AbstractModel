#include "mymodel.h"

MyModel::MyModel()
{

}

int MyModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED( parent )
    return m_codes.count();
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED( parent )
    return LAST;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if( !index.isValid() || m_codes.count() <= index.row() || (role != Qt::DisplayRole && role != Qt::EditRole)) {
        return QVariant();
    }
    return m_codes[ index.row() ][ Column( index.column() ) ];
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if( !index.isValid() || role != Qt::EditRole || m_codes.count() <= index.row() ) {
        return false; }

    m_codes[ index.row() ][ Column( index.column() ) ] = value;
    emit dataChanged( index, index );
    return true;
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }

    if( orientation == Qt::Vertical ) {
        return section;
    }

    switch( section ) {
    case ZoneCode:
        return trUtf8( "ZoneCode" );
    case ZoneCodeMin:
        return trUtf8( "Zone Height[min]" );
    case ZoneCodeMax:
        return trUtf8( "Zone Height[max]" );
    case Result:
        return trUtf8( "Medium Height of Zone[m]" );
    }

    return QVariant();
}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );
    if( index.isValid() ) {
        if( index.column() != Result ) {
            flags |= Qt::ItemIsEditable;
        }
    } return flags;
}

void MyModel::addRow()
{
    CodeData code;
    code[ ZoneCode ] = 0;
    code[ ZoneCodeMin ] = 0;
    code[ ZoneCodeMax ] = 0;
    code[ Result ] = 0;
    int row = m_codes.count();
    beginInsertRows( QModelIndex(), row, row );
    m_codes.append( code );
    endInsertRows();
}

void MyModel::delRow()
{
    int it = m_codes.count() - 1;
    beginRemoveRows(QModelIndex(), it, it);
    m_codes.removeAt(it);
    endRemoveRows();
}
