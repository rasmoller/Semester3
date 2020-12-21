#pragma once
#include <osapi/ThreadFunctor.hpp>
#include <osapi/MsgQueue.hpp>
#include <osapi/PLCS/Car.h>
#include <osapi/PLCS/common.h>

// Exit guard messages
struct EXIT_IND : public osapi::Message
{
    EXIT_IND(osapi::MsgQueue* msgQ, int carID = -1)
        : msgQ(msgQ), id(carID) {}
    osapi::MsgQueue* msgQ;
    int id;
};

struct EXITED : public osapi::Message
{
    EXITED(int carID = -1)
        : id(carID) {}
    int id;
};

class ExitGuard : public osapi::ThreadFunctor{
public:
    enum {
        ID_EXIT_IND,
        ID_EXITED
    };
    ExitGuard(int MQSize = 20)
        :mq_(MQSize){}
    osapi::MsgQueue* getMsgQueue() {return &mq_;}
private:
    void run();
    void exitHandler(int id, osapi::Message* m);
    void handleExitInd(EXIT_IND* m);
    void handleExited(EXITED* m);

    osapi::MsgQueue mq_;
};