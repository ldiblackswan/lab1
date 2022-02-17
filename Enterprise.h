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
    Enterprise(const QString& enterprise_name,
               const QList<QString>& enterprise_owners,
               double income = 0, double area = 0,
               uint numberOfEmployees = 0);
    /** Pure virtual methods*/
    virtual Type getEnterpriseType() const = 0;
    virtual double getTaxPerMonth() const = 0;
    /** Getters*/
    QString getEnterpriseName() const { return m_name; }
    QList<QString> getEnterpriseOwners() const { return m_owners; }
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

class TransnationalEnterpise : public Enterprise
{
public:
    TransnationalEnterpise(const QString& enterprise_name,
               const QList<QString>& enterprise_owners,
               double income = 0, double area = 0,
               uint numberOfEmployees = 0);
    Type getEnterpriseType() const override;
    double getTaxPerMonth() const override;
};

class GovernmentEnterprise : public Enterprise
{
public:
    GovernmentEnterprise(const QString& enterprise_name,
               const QList<QString>& enterprise_owners,
               double income = 0, double area = 0,
               uint numberOfEmployees = 0);
    Type getEnterpriseType() const override;
    double getTaxPerMonth() const override;
};

class PrivateEnterprise : public Enterprise
{
public:
    PrivateEnterprise(const QString& enterprise_name,
               const QList<QString>& enterprise_owners,
               double income = 0, double area = 0,
               uint numberOfEmployees = 0);
    Type getEnterpriseType() const override;
    double getTaxPerMonth() const override;
};

#endif // ENTERPRISE_H
