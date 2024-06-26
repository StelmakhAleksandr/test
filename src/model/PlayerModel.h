#pragma once

#include <QAbstractListModel>
#include <QObject>
#include <memory>

#include "player/Player.h"

class PlayerModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum class PlayerModelItemRole : int
    {
        NameRole = Qt::DisplayRole + 1,
        StrengthRole,
        Links
    };
    PlayerModel();
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    std::vector<std::shared_ptr<Player>> m_data;
};
