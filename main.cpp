#include <iostream>
#include "EnterpriseRegistrySingleton.h"
#include <QTextStream>

using namespace std;

int main()
{
    QTextStream out(stdout);
    Enterprise* microsoft = new PrivateEnterprise("Microsoft",
        QList<QString>() << "Bill Gates" << "Steve Ballmer", 1000000, 100000, 5000);
    EnterpriseRegistrySingleton& singleton = EnterpriseRegistrySingleton::getInstance();
    singleton.addEnterpise(*microsoft);
    out << singleton.getEnterpriseByIndex(0).getCompanyName() << Qt::endl;
    QList<QString> owners = singleton.getEnterpriseByIndex(0).getCompanyOwners();
    for (auto& x : owners) {
        out << x << Qt::endl;
    }
    out << singleton.getEnterpriseByIndex(0).getArea() << Qt::endl;
    delete microsoft;
    return 0;
}
