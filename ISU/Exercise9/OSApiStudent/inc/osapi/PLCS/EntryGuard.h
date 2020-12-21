#pragma once
#include <osapi/ThreadFunctor.hpp>
#include <osapi/MsgQueue.hpp>
#include <osapi/PLCS/Car.h>
#include <osapi/PLCS/common.h>

struct ENTRY_IND : public osapi::Message
{
    ENTRY_IND(osapi::MsgQueue* msgQ, int carID = -1) 
        : msgQ(msgQ), id(carID) {}
    osapi::MsgQueue* msgQ;
    int id;
};

struct ENTERED : public osapi::Message
{
    ENTERED(int carID = -1)
        : id(carID) {}
    int id;
};

class EntryGuard : public osapi::ThreadFunctor{
public:
    enum {
        ID_ENTRY_IND,
        ID_ENTERED
    };
    EntryGuard(int MQSize = 20)
        :mq_(MQSize){}
    osapi::MsgQueue* getMsgQueue() {return &mq_;}
private:
    void run();
    void entryHandler(int id, osapi::Message* m);
    void handleEntryInd(ENTRY_IND* m);
    void handleEntered(ENTERED* m);

    osapi::MsgQueue mq_;
};
