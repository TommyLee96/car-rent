#include "rotatedproxymodel.h"

RotatedProxyModel::RotatedProxyModel( QObject* parent ): QAbstractProxyModel( parent )
{
}

RotatedProxyModel::~RotatedProxyModel()
{
}

void RotatedProxyModel::setSourceModel( QAbstractTableModel* sourceModel )
{
    QAbstractProxyModel::setSourceModel(sourceModel);
}

int RotatedProxyModel::columnCount( const QModelIndex & parent ) const
{
    if( parent.isValid() )
        return 0;

    if( sourceModel() )
        return sourceModel()->rowCount( );    /* 代理model的columnCount等于sourceModel的rowCount */
    else
        return 0;
}

QModelIndex RotatedProxyModel::parent( const QModelIndex & index ) const
{
    if( sourceModel() )
        return sourceModel()->parent(index);
    else
        return QModelIndex();
}

int RotatedProxyModel::rowCount( const QModelIndex & parent ) const
{
    if( parent.isValid() )
        return 0;

    if( sourceModel() )
        return sourceModel()->columnCount( ); /* 代理model的rowCount等于sourceModel的columnCount */
    else
        return 0;
}

QModelIndex RotatedProxyModel::mapFromSource( const QModelIndex & sourceIndex ) const
{
    if( sourceModel() )
        return sourceModel()->index( sourceIndex.column(), sourceIndex.row(), sourceIndex.parent() );
    else
        return QModelIndex();
}

QModelIndex RotatedProxyModel::mapToSource( const QModelIndex & proxyIndex ) const
{
    if( sourceModel() )
        return sourceModel()->index( proxyIndex.column(), proxyIndex.row(), proxyIndex.parent() );
    else
        return QModelIndex();
}

QModelIndex RotatedProxyModel::index( int row, int column, const QModelIndex & parent ) const
{
    if( sourceModel() )
        return sourceModel()->index( column, row, parent );
    else
        return QModelIndex();
}

QVariant RotatedProxyModel::headerData( int section, Qt::Orientation orientation, int role ) const
{
    if( orientation == Qt::Horizontal )
        return sourceModel()->headerData( section, Qt::Vertical, role );
    else
        return sourceModel()->headerData( section, Qt::Horizontal, role );
}

bool RotatedProxyModel::setHeaderData( int section, Qt::Orientation orientation, const QVariant & value, int role )
{
    if( orientation == Qt::Horizontal )
        return sourceModel()->setHeaderData( section, Qt::Vertical, value, role );
    else
        return sourceModel()->setHeaderData( section, Qt::Horizontal, value, role );
}
