#include "reservationstorage.h"
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QStringList>

bool saveReservationToCsv(const QString& name,
                          const QString& date,
                          const QString& time,
                          const QString& table)
{
    QString filePath = QDir::currentPath() + "/reservations.csv";
    QFile file(filePath);

    bool fileExists = file.exists();

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);

    if (!fileExists) {
        out << "Name,Date,Time,Table\n";
    }

    out << name << ","
        << date << ","
        << time << ","
        << table << "\n";

    file.close();
    return true;
}

QHash<QString, QSet<QString>> loadReservationsFromCsv()
{
    QHash<QString, QSet<QString>> bookedBySlot;

    QString filePath = QDir::currentPath() + "/reservations.csv";
    QFile file(filePath);

    if (!file.exists()) {
        return bookedBySlot;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return bookedBySlot;
    }

    QTextStream in(&file);
    bool firstLine = true;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        if (line.isEmpty()) continue;

        if (firstLine) {
            firstLine = false;
            continue;
        }

        QStringList parts = line.split(",");
        if (parts.size() < 4) continue;

        QString date = parts[1].trimmed();
        QString time = parts[2].trimmed();
        QString table = parts[3].trimmed();

        QString key = date + "|" + time;
        bookedBySlot[key].insert(table);
    }

    file.close();
    return bookedBySlot;
}

bool isTableBooked(const QString& date,
                   const QString& time,
                   const QString& table)
{
    QHash<QString, QSet<QString>> bookedBySlot = loadReservationsFromCsv();
    QString key = date + "|" + time;
    return bookedBySlot.value(key).contains(table);
}
