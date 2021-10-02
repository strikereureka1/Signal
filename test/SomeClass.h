#pragma once

#include "Signal.h"
#include <iostream>
class SomeClass {
public:
    SomeClass(int id)
        : m_id(id)
    {
    }

    void doSomething()
    {
        std::cerr << "\nCalling the slot with id : " << m_id << "\n";
    }

private:
    int m_id;
};
