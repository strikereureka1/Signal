#include "Signal.h"
#include "SomeClass.h"
#include <unistd.h>

int main()
{
    SomeClass y(1);
    SomeClass y2(2);

    // Timeout t(10, true); // 10 second timeout  singleshot
    // Connect(t, timeout, y, SomeClass::listen);
    // t.start();

    Timeout t(10, false); // 10 second timeout, not singleshot
    Connect(t, timeoutWithData, y2, SomeClass::listenMore);
    t.start();

    while (1)
    {
        std::cerr << "\n.....";
        sleep(2);
    }
    return 0;
}