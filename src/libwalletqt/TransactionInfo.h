#ifndef TRANSACTIONINFO_H
#define TRANSACTIONINFO_H

#include <wallet/wallet2_api.h>
#include <QObject>
#include <QDateTime>

class Transfer;

class TransactionInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Direction direction READ direction)
    Q_PROPERTY(bool isPending READ isPending)
    Q_PROPERTY(bool isFailed READ isFailed)
    Q_PROPERTY(double amount READ amount)
    Q_PROPERTY(quint64 atomicAmount READ atomicAmount)
    Q_PROPERTY(QString displayAmount READ displayAmount)
    Q_PROPERTY(QString fee READ fee)
    Q_PROPERTY(quint64 blockHeight READ blockHeight)
    Q_PROPERTY(QString hash READ hash)
    Q_PROPERTY(QDateTime timestamp READ timestamp)
    Q_PROPERTY(QString date READ date)
    Q_PROPERTY(QString time READ time)
    Q_PROPERTY(QString paymentId READ paymentId)
    Q_PROPERTY(QString destinations_formatted READ destinations_formatted)

public:
    enum Direction {
        Direction_In  =  Bitmonero::TransactionInfo::Direction_In,
        Direction_Out =  Bitmonero::TransactionInfo::Direction_Out,
        Direction_Both // invalid direction value, used for filtering
    };

    Q_ENUM(Direction)

    Direction  direction() const;
    bool isPending() const;
    bool isFailed() const;
    double amount() const;
    quint64 atomicAmount() const;
    QString displayAmount() const;
    QString fee() const;
    quint64 blockHeight() const;
    //! transaction_id
    QString hash() const;
    QDateTime timestamp() const;
    QString date() const;
    QString time() const;
    QString paymentId() const;
    //! only applicable for output transactions
    //! used in tx details popup
    QString destinations_formatted() const;
    //! Could be useful later when addressbook is implemented
    Q_INVOKABLE QList<Transfer*> transfers() const;
private:
    explicit TransactionInfo(Bitmonero::TransactionInfo * pimpl, QObject *parent = 0);
private:
    friend class TransactionHistory;
    Bitmonero::TransactionInfo * m_pimpl;
    mutable QList<Transfer*> m_transfers;
};

// in order to wrap it to QVariant
Q_DECLARE_METATYPE(TransactionInfo*)


#endif // TRANSACTIONINFO_H
