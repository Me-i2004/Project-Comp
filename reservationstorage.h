#ifndef RESERVATIONSTORAGE_H
#define RESERVATIONSTORAGE_H

#include <QString>
#include <QHash>
#include <QSet>

bool saveReservationToCsv(const QString& name,
                          const QString& date,
                          const QString& time,
                          const QString& table);

QHash<QString, QSet<QString>> loadReservationsFromCsv();

bool isTableBooked(const QString& date,
                   const QString& time,
                   const QString& table);

#endif // RESERVATIONSTORAGE_H
