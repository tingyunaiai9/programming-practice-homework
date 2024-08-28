#ifndef DATE_H
#define DATE_H

#include <QString>

class Date
{
public:
    Date(const QString &year, const QString &month, const QString &day);

    bool isValidDate() const;
    QString toString() const;

private:
    QString m_year;
    QString m_month;
    QString m_day;
};

#endif // DATE_H
