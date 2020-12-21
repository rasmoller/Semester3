#include <osapi/Utility.hpp>
#include <unistd.h>

void osapi::sleep(unsigned long msecs)
{
    usleep(msecs*1000); // milli * 1000 = micro
}
