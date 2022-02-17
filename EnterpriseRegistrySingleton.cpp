#include "EnterpriseRegistrySingleton.h"

EnterpriseRegistrySingleton::EnterpriseRegistrySingleton(const QList<Enterprise *> &enterprises_list) : m_enterprises(enterprises_list) {}

EnterpriseRegistrySingleton &EnterpriseRegistrySingleton::getInstance()
{
    static EnterpriseRegistrySingleton instance;
    return instance;
}

void EnterpriseRegistrySingleton::addEnterpise(Enterprise &ent)
{
    m_enterprises.append(&ent);
}

const Enterprise &EnterpriseRegistrySingleton::getEnterpriseByIndex(int index) const
{
    return *m_enterprises.at(index);
}

int EnterpriseRegistrySingleton::getRegistrySize() const
{
    return m_enterprises.size();
}
