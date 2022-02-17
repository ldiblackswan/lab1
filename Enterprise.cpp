#include "Enterprise.h"


Enterprise::Enterprise(const QString &enterprise_name,
                       const QList<QString>& enterprise_owners,
                       double income, double area,
                       uint numberOfEmployees)
{
    m_name = enterprise_name;
    m_owners = enterprise_owners;
    m_income = income;
    m_area = area;
    m_numberOfEmployees = numberOfEmployees;
}

TransnationalEnterpise::TransnationalEnterpise(const QString &enterprise_name,
                                               const QList<QString> &enterprise_owners,
                                               double income, double area, uint numberOfEmployees) :
    Enterprise(enterprise_name, enterprise_owners, income, area, numberOfEmployees) {}

Enterprise::Type TransnationalEnterpise::getEnterpriseType() const
{
    return Type::Transnational;
}

double TransnationalEnterpise::getTaxPerMonth() const
{
    return getNumberOfEmployess() * getIncome() / getArea() * 0.5;
}

GovernmentEnterprise::GovernmentEnterprise(const QString &enterprise_name,
                                           const QList<QString> &enterprise_owners,
                                           double income, double area, uint numberOfEmployees) :
        Enterprise(enterprise_name, enterprise_owners, income, area, numberOfEmployees) {}

Enterprise::Type GovernmentEnterprise::getEnterpriseType() const
{
    return Type::Government;
}

double GovernmentEnterprise::getTaxPerMonth() const
{
    return getNumberOfEmployess() / getIncome() * getArea() * 0.3;
}

PrivateEnterprise::PrivateEnterprise(const QString &enterprise_name,
                                     const QList<QString> &enterprise_owners,
                                     double income, double area, uint numberOfEmployees) :
        Enterprise(enterprise_name, enterprise_owners, income, area, numberOfEmployees) {}


Enterprise::Type PrivateEnterprise::getEnterpriseType() const
{
    return Type::Private;
}

double PrivateEnterprise::getTaxPerMonth() const
{
    return getNumberOfEmployess() / getIncome() * getArea() * 0.8;
}
