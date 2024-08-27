#include "date.h"

Date::Date(const QString &year, const QString &month, const QString &day)
    : m_year(year), m_month(month), m_day(day)
{
}

bool Date::isValidDate() const
{
    bool isNumber = true;
    int year = m_year.toInt(&isNumber);
    if (!isNumber)
        return false;
    int month = m_month.toInt(&isNumber);
    if (!isNumber)
        return false;
    int day = m_day.toInt(&isNumber);
    if (!isNumber)
        return false;

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if (month == 2)
    {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            return day <= 29;
        else
            return day <= 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return day <= 30;
    }
    else
    {
        return true;
    }
}

QString Date::toString() const
{
    return m_year + "-" + m_month + "-" + m_day;
}
