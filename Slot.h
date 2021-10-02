#pragma once
#include <functional>
class Slot {
public:
    Slot(const std::function<void(void)>& func)
        : m_func(func)
    {
    }

    std::function<void(void)> m_func;
};