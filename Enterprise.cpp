#include "Enterprise.h"


Enterprise::Enterprise(const QString &company_name,
                       const QList<QString> company_owners,
                       double income, double area,
                       uint numberOfEmployees)
{
    m_name = company_name;
    m_owners = company_owners;
    m_income = income;
    m_area = area;
    m_numberOfEmployees = numberOfEmployees;
}

Enterprise::Type TransnationalEnterpise::getCompanyType()
{
    return Type::Transnational;
}

double TransnationalEnterpise::getTaxPerMonth()
{
    return getNumberOfEmployess() * getIncome() / getArea() * 0.5;
}

Enterprise::Type GovernmentEnterprise::getCompanyType()
{
    return Type::Government;
}

double GovernmentEnterprise::getTaxPerMonth()
{
    return getNumberOfEmployess() / getIncome() * getArea() * 0.3;
}

Enterprise::Type PrivateEnterprise::getCompanyType()
{
    return Type::Private;
}

double PrivateEnterprise::getTaxPerMonth()
{
    return getNumberOfEmployess() / getIncome() * getArea() * 0.8;
}
