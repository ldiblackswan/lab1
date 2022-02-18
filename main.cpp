#include <iostream>
#include "EnterpriseRegistrySingleton.h"
#include <QTextStream>

using namespace std;

void showInfoByType(Enterprise::Type type,
                    EnterpriseRegistrySingleton& registry,
                    QTextStream& out)
{
    switch (type) {
    case Enterprise::Type::Transnational:
        out << "Transnational companies: " << Qt::endl;
        break;
    case Enterprise::Type::Private:
        out << "Private companies: " << Qt::endl;
        break;
    case Enterprise::Type::Government:
        out << "Government companies: " << Qt::endl;
        break;
    }
    for (int i = 0; i < registry.getRegistrySize(); i++)
    {
        if (registry.getEnterpriseByIndex(i).getEnterpriseType() == type) {
            out << "Name: " << registry.getEnterpriseByIndex(i).getEnterpriseName() << Qt::endl;
            out << "Owners: ";
            for (int j = 0; j < registry.getEnterpriseByIndex(i).getEnterpriseOwners().size(); j++)
            {
                out << registry.getEnterpriseByIndex(i).getEnterpriseOwners().operator[](j);
                if (j != registry.getEnterpriseByIndex(i).getEnterpriseOwners().size() - 1)
                    out << ", ";
            }
            out << Qt::endl;
            out << "Income: " << registry.getEnterpriseByIndex(i).getIncome() << Qt::endl;
            out << "Area: " << registry.getEnterpriseByIndex(i).getArea() << Qt::endl;
            out << "The number of employees: " << registry.getEnterpriseByIndex(i).getNumberOfEmployess() << Qt::endl;
        }
    }
}

void showEnterprisesByOwner(const QString& owner,
                            EnterpriseRegistrySingleton& registry,
                            QTextStream& out)
{
    bool found = false;
    if (!owner.isEmpty()) {
        int companies_per_owner = 0;
        for (int i = 0; i < registry.getRegistrySize(); i++)
        {
            for (int j = 0; j < registry.getEnterpriseByIndex(i).getEnterpriseOwners().size(); j++)
            {
                if (owner == registry.getEnterpriseByIndex(i).getEnterpriseOwners().at(j)) {
                    if (companies_per_owner > 0)
                        out << ", " << registry.getEnterpriseByIndex(i).getEnterpriseName();
                    else
                        out << owner << " owns " << registry.getEnterpriseByIndex(i).getEnterpriseName();
                    companies_per_owner++;
                    found = true;
                }
            }
        }
    }
    if (!found)
        out << "Nothing found!";
    out << Qt::endl;
}

int main()
{
    QTextStream out(stdout);
    Enterprise* microsoft = new TransnationalEnterpise("Microsoft",
        QList<QString>() << "Bill Gates" << "Steve Ballmer", 100000000, 100000, 5000);

    Enterprise* skype = new PrivateEnterprise("Skype",
                                                       QList<QString>() << "Bill Gates", 5000000, 200000, 1000);


    Enterprise* apple = new TransnationalEnterpise("Apple",
                                                  QList<QString>() << "Tim Cook" << "Bruce Sewell",
                                              14000000, 20000, 3000);

    Enterprise* gazprom = new GovernmentEnterprise("Gazprom",
                                                  QList<QString>() << "Alexey Miller", 5000000, 50000, 10000);

    EnterpriseRegistrySingleton& singleton = EnterpriseRegistrySingleton::getInstance();

    singleton.addEnterpise(*microsoft);
    singleton.addEnterpise(*skype);
    singleton.addEnterpise(*apple);
    singleton.addEnterpise(*gazprom);

    // 1. Вывести в консоль информацию о предприятиях определённого типа.
    showInfoByType(Enterprise::Transnational, singleton, out);
    // 2. Вывести в консоль все предприятия, принадлежащие определённому владельцу.
    showEnterprisesByOwner("Bill Gates", singleton, out);
    // 3. Вывести в консоль средние показатели (доход, площадь, число сотрудников) предприятий для каждого из типов.
    delete microsoft;
    delete skype;
    delete apple;
    delete gazprom;
    return 0;
}
