/*
 * Copyright 2019 Eike Hein <hein@kde.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KIROGI_PERMISSIONS_H
#define KIROGI_PERMISSIONS_H

#include <QObject>

class Permissions : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool granted READ granted NOTIFY grantedChanged)

public:
    explicit Permissions(const QStringList &permissions, QObject *parent = nullptr);
    ~Permissions();

    bool granted() const;

    Q_INVOKABLE void request();

Q_SIGNALS:
    void grantedChanged() const;

private:
    QStringList m_permissions;
    bool m_granted;
};

#endif
