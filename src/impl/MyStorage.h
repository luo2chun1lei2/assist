#pragma once

#include "interfaces.h"

class MyStorage:public IStorage {
public:
    virtual void save(IRelationMap *p_map);
};
