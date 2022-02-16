#ifndef ENTERPRISE_H
#define ENTERPRISE_H
#include <QString>
#include <QList>


// Абстрактный класс компании
class Enterprise
{
public:
    enum Type { Transnational, Government, Private };
    Enterprise() = default;
    Enterprise(const QString& company_name,
               const QList<QString> company_owners,
               double income = 0, double area = 0,
               uint numberOfEmployees = 0);
    /** Pure virtual methods*/
    virtual Type getCompanyType() = 0;
    virtual double getTaxPerMonth() = 0;
    /** Getters*/
    QString getCompanyName() const { return m_name; }
    QList<QString> getCompanyOwners() const { return m_owners; };
    double getIncome() const { return m_income; }
    double getArea() const { return m_area; }
    int getNumberOfEmployess() const { return m_numberOfEmployees; }
    virtual ~Enterprise() {}
private:
    QString m_name;
    QList<QString> m_owners;
    double m_income;
    double m_area;
    uint m_numberOfEmployees;
};
#endif // ENTERPRISE_H
