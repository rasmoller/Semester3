#include <osapi/PLCS/Car.h>
#include <osapi/Utility.hpp>
#include <iostream>

void Car::handleEntryOpen(ENTRY_OPEN* m)
{
    std::cout << "Entry is open for " << id_ << std::endl;
    enG_->getMsgQueue()->send(EntryGuard::ID_ENTERED, new ENTERED(id_));
    osapi::sleep(10000);
    exG_->getMsgQueue()->send(ExitGuard::ID_EXIT_IND, new EXIT_IND(&mq_, id_));
}

void Car::handleExitOpen(EXIT_OPEN* m)
{
    std::cout << "Exit is open for " << id_ << std::endl;
    exG_->getMsgQueue()->send(ExitGuard::ID_EXITED, new EXITED(id_));
    osapi::sleep(5000);
    enG_->getMsgQueue()->send(EntryGuard::ID_ENTRY_IND, new ENTRY_IND(&mq_, id_));
}

void Car::carHandler(int id, osapi::Message* m)
{
    switch (id)
    {
    case ID_ENTRY_OPEN: // When the entry has opened for the car
        handleEntryOpen((ENTRY_OPEN*) m);
        break;
    case ID_EXIT_OPEN:  // When the exit has opened for the car
        handleExitOpen((EXIT_OPEN*) m);
        break;
    default:
        break;
    }
}

void Car::run()
{
    enG_->getMsgQueue()->send(EntryGuard::ID_ENTRY_IND, new ENTRY_IND(&mq_, id_));

    for(;;)
    {
        unsigned long msgID;
        // Receives a message to the messageQueue
        osapi::Message* m = mq_.receive(msgID);
        carHandler(msgID, m);   // Handles message
        delete m;               // Removes message from heap

        osapi::sleep(1000);
    }
}