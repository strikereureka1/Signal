#pragma once
#include <functional>

template <class T>
class Slot {
public:
    Slot(T* obj, void (T::*func)(void))
        : m_obj(obj)
        , m_func(std::bind(func, obj))
    {
    }
    T* m_obj;
    std::function<void(void)> m_func;
};

template <class T, class Arg>
class Slot1 {
public:
    Slot1(T* obj, void (T::*func)(const Arg& arg))
        : m_obj(obj)
        , m_func(std::bind(func, obj, std::placeholders::_1))
    {
    }
    std::function<void(const Arg&)> m_func;
    T* m_obj;
};