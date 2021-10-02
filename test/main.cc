#include "Signal.h"
#include "SomeClass.h"
int main()
{
    SomeClass y(1);
    SomeClass y2(2);
    Signal<SomeClass> s;
    auto f = [&]() {
        y.doSomething();
    };
    auto f2 = [&]() {
        y2.doSomething();
    };
    Signal<SomeClass>::connect(s, f);
    Signal<SomeClass>::connect(s, f2);

    std::cerr << "\n.....";
    s.emit();
    std::cerr << "\n.....";
    return 0;
}