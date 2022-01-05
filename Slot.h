#pragma once
#include <functional>

template <class T>
class Slot
{
public:
    Slot(T *obj, void (T::*func)(void))
        : m_obj(obj), m_func(std::bind(func, obj))
    {
    }
    T *m_obj;
    std::function<void(void)> m_func;
};

class Slot0
{
    virtual ~Slot0();
};

template <class T, class F>
class Slot1 : public Slot0
{
    using M_Fun = F;

public:
    Slot1(T *obj, F func)
        : m_obj(obj), m_func(func)
    {
    }
    M_Fun m_func;
    T *m_obj;
};