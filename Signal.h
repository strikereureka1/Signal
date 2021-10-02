#pragma once
#include "Slot.h"
#include <functional>
#include <vector>
class Signal {
public:
    Signal() {};
    static void connect(Signal& sig, const std::function<void(void)>& func)
    {
        sig.getSlots().push_back({ func });
    }
    std::vector<Slot>& getSlots()
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
    std::vector<Slot> slots;
};
