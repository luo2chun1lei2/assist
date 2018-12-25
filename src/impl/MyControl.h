#pragma once

#include "interfaces.h"

class MyControl:public IControl {
public:
    virtual int addElement(const char *elem_name);
	virtual int addEdge(const char *from_elem_name, const char *to_elem_name);
};
