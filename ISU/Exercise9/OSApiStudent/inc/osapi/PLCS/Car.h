#pragma once
#include <osapi/ThreadFunctor.hpp>
#include <osapi/MsgQueue.hpp>
#include <osapi/PLCS/EntryGuard.h>
#include <osapi/PLCS/ExitGuard.h>

struct EXIT_OPEN : public osapi::Message {};
struct ENTRY_OPEN : public osapi::Message {};

class EntryGuard;
class ExitGuard;
class Car : public osapi::ThreadFunctor{
public:
    enum {
        ID_ENTRY_OPEN,
        ID_EXIT_OPEN
    };
    Car(int carID = -1, EntryGuard* entry = NULL, ExitGuard* exit = NULL, int MQSize = 10)
        : id_(carID), enG_(entry), exG_(exit), mq_(MQSize) {}
    osapi::MsgQueue* getMsgQueue() {return &mq_;}
private:
    void run();
    void carHandler(int id, osapi::Message *m);
    void handleEntryOpen(ENTRY_OPEN *m);
    void handleExitOpen(EXIT_OPEN *m);

    osapi::MsgQueue mq_;
    EntryGuard*     enG_;
    ExitGuard*      exG_;
    int             id_;
};