#pragma once
#include "Slot.h"
#include <functional>
#include <vector>
template <typename T>
class Signal {
public:
    Signal<T>() {};
    static void connect(Signal<T>& sig, const std::function<void(void)>& func)
    {
        sig.getSlots().push_back({ func });
    }
    std::vector<Slot<T>>& getSlots()
    {
        return slots;
    }

    void emit()
    {
        for (const auto& slot : slots) {
            slot.m_func();
        }
    }

private:
    std::vector<Slot<T>> slots;
};
