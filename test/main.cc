#include "Signal.h"
#include "SomeClass.h"
int main()
{
    SomeClass y(1);
    SomeClass y2(2);
    Signal<SomeClass> s;

    Signal<SomeClass>::connect(s, &y, &SomeClass::doSomething);
    Signal<SomeClass>::connect(s, &y2, &SomeClass::doSomething);

    std::cerr << "\n.....";
    s.emit();
    std::cerr << "\n.....";

    Signal1<SomeClass, int> s1;
    Signal1<SomeClass, int>::connect(s1, &y, &SomeClass::doSomethingMore);
    Signal1<SomeClass, int>::connect(s1, &y2, &SomeClass::doSomethingMore);

    std::cerr << "\n.....";
    s1.emit(10);
    std::cerr << "\n.....";
    return 0;
}