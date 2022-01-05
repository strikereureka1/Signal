#pragma once
#include <functional>
#include <list>
#include <thread>
#define Connect(a, signal, b, slot) a.signal.connect(&b, &slot)
#define Disconnect(a, signal, b, slot) a.signal.disconnect(&b, &slot)

class Signal
{
public:
    Signal(){};
    template <class T>
    void connect(T *t, void (T::*func)(void))
    {
        std::function<void(void)> f = std::bind(func, t);
        slots.push_back(f);
    }
    template <class T, class F>
    void disconnect(T *t, F func)
    {
        slots.remove(std::bind(func, t, std::placeholders::_1));
    }
    void disconnectAll()
    {
        slots.clear();
    }
    void emit()
    {
        for (const auto &slot : slots)
        {
            auto fn = [=]()
            { slot(); };
            std::thread t(fn);
            t.detach();
        }
    }

private:
    std::list<std::function<void(void)>> slots;
};
#define Connect(a, signal, b, slot) a.signal.connect(&b, &slot)

template <class Arg>
class Signal1
{
public:
    Signal1<Arg>(){};
    template <class T, class F>
    void connect(T *t, F func)
    {
        std::lock_guard lock(mutex);
        slots.emplace_back(std::bind(func, t, std::placeholders::_1));
    }
    template <class T, class F>
    void disconnect(T *t, F func)
    {
        std::lock_guard lock(mutex);
        slots.remove(std::bind(func, t, std::placeholders::_1));
    }
    void disconnectAll()
    {
        std::lock_guard lock(mutex);
        slots.clear();
    }
    void emit(Arg arg)
    {
        std::lock_guard lock(mutex);
        for (const auto &slot : slots)
        {
            auto fn = [=]()
            { slot(arg); };
            std::thread t(fn);
            t.detach();
        }
    }

private:
    std::mutex mutex;
    std::list<std::function<void(Arg)>> slots;
};
