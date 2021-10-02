#pragma once
#include "Slot.h"
#include <functional>
#include <future>
#include <vector>
template <class T>
class Signal {
public:
    Signal() {};
    static void connect(Signal& sig, T* t, void (T::*func)(void))
    {
        sig.getSlots().push_back({ t, func });
    }
    std::vector<Slot<T>>& getSlots()
    {
        return slots;
    }

    void emit()
    {
        for (const auto& slot : slots) {
            auto fut = std::async(std::launch::async, slot.m_func);
            fut.get();
        }
    }

private:
    std::vector<Slot<T>> slots;
};

template <class T, class Arg>
class Signal1 {
public:
    Signal1<T>() {};
    static void connect(Signal1<T, Arg>& sig, T* t, void (T::*func)(const Arg& arg))
    {
        sig.getSlots().push_back({ t, func });
    }
    std::vector<Slot1<T, Arg>>& getSlots()
    {
        return slots;
    }
    void emit(const Arg& arg)
    {
        for (const auto& slot : slots) {
            auto fut = std::async(std::launch::async, slot.m_func, arg);
            fut.get();
        }
    }

private:
    std::vector<Slot1<T, Arg>> slots;
};
