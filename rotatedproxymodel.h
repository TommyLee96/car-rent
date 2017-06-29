#ifndef ROTATEDPROXYMODEL_H
#define ROTATEDPROXYMODEL_H

#include <QAbstractProxyModel>
class QAbstractTableModel;

// 交换行和列的代理model
class RotatedProxyModel : public QAbstractProxyModel
{
        Q_OBJECT
    public:
        RotatedProxyModel( QObject* parent );
        ~RotatedProxyModel();

        virtual QModelIndex index ( int row, int column, const QModelIndex & parent = QModelIndex() ) const;
        virtual QModelIndex mapFromSource ( const QModelIndex & sourceIndex ) const;
        virtual QModelIndex mapToSource ( const QModelIndex & proxyIndex ) const;

        virtual void setSourceModel( QAbstractTableModel* sourceModel );
        virtual int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
        virtual QModelIndex parent ( const QModelIndex & index ) const;
        virtual int rowCount ( const QModelIndex & parent = QModelIndex() ) const;

        virtual QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
        virtual bool setHeaderData ( int section, Qt::Orientation orientation, const QVariant & value, int role = Qt::EditRole );

};

#endif
