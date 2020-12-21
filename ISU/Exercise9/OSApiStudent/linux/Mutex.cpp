#include <osapi/Mutex.hpp>

namespace osapi
{
    Mutex::Mutex()
    {
        pthread_mutex_init(&mut_, NULL);
    }

    void Mutex::lock()
    {
        pthread_mutex_lock(&mut_);
    }

    void Mutex::unlock()
    {
        pthread_mutex_unlock(&mut_);
    }

    Mutex::~Mutex()
    {
        pthread_mutex_destroy(&mut_);
    }

} // namespace osapi
