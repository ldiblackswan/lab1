#include "Enterprise.h"


Enterprise::Enterprise(const QString &company_name,
                       const QList<QString>& company_owners,
                       double income, double area,
                       uint numberOfEmployees)
{
    m_name = company_name;
    m_owners = company_owners;
    m_income = income;
    m_area = area;
    m_numberOfEmployees = numberOfEmployees;
}

TransnationalEnterpise::TransnationalEnterpise(const QString &company_name,
                                               const QList<QString> &company_owners,
                                               double income, double area, uint numberOfEmployees) :
    Enterprise(company_name, company_owners, income, area, numberOfEmployees) {}

Enterprise::Type TransnationalEnterpise::getCompanyType()
{
    return Type::Transnational;
}

double TransnationalEnterpise::getTaxPerMonth()
{
    return getNumberOfEmployess() * getIncome() / getArea() * 0.5;
}

GovernmentEnterprise::GovernmentEnterprise(const QString &company_name,
                                           const QList<QString> &company_owners,
                                           double income, double area, uint numberOfEmployees) :
        Enterprise(company_name, company_owners, income, area, numberOfEmployees) {}

Enterprise::Type GovernmentEnterprise::getCompanyType()
{
    return Type::Government;
}

double GovernmentEnterprise::getTaxPerMonth()
{
    return getNumberOfEmployess() / getIncome() * getArea() * 0.3;
}

PrivateEnterprise::PrivateEnterprise(const QString &company_name,
                                     const QList<QString> &company_owners,
                                     double income, double area, uint numberOfEmployees) :
        Enterprise(company_name, company_owners, income, area, numberOfEmployees) {}


Enterprise::Type PrivateEnterprise::getCompanyType()
{
    return Type::Private;
}

double PrivateEnterprise::getTaxPerMonth()
{
    return getNumberOfEmployess() / getIncome() * getArea() * 0.8;
}
