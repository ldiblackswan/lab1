#ifndef ENTERPRISEREGISTRYSINGLETON_H
#define ENTERPRISEREGISTRYSINGLETON_H
#include "Enterprise.h"


class EnterpriseRegistrySingleton
{
protected:
    EnterpriseRegistrySingleton() = default;
    EnterpriseRegistrySingleton(const QList<Enterprise* > &enterprises_list);
public:
    EnterpriseRegistrySingleton(EnterpriseRegistrySingleton& other) = delete;
    void operator= (const EnterpriseRegistrySingleton& cr) = delete;

    static EnterpriseRegistrySingleton &getInstance();

    void addEnterpise(Enterprise& ent);
    const Enterprise &getEnterpriseByIndex(int index) const;
    int getRegistrySize() const;

private:
    QList<Enterprise* > m_enterprises;
};

#endif // ENTERPRISEREGISTRYSINGLETON_H
