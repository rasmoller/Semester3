#include <osapi/PLCS/EntryGuard.h>
#include <osapi/Utility.hpp>
#include <iostream>

void EntryGuard::handleEntryInd(ENTRY_IND* m)
{
	std::cout << "Car " << m->id << " wating for entry: " << carsParked << " inside" << std::endl;
    
    // If there arent any spots left it waits with letting it in
    while(carsParked >= spots)
    {}

    carsParked++;
    // Send msg that it has opened
    m->msgQ->send(Car::ID_ENTRY_OPEN, new ENTRY_OPEN());
}

void EntryGuard::handleEntered(ENTERED* m)
{
    std::cout << "Car " << m->id << " has entered" << std::endl;
}

void EntryGuard::entryHandler(int id, osapi::Message* m)
{
    switch (id)
    {
    case ID_ENTRY_IND: // Case from test
        handleEntryInd((ENTRY_IND*) m);
        break;
    case ID_ENTERED:  // Handles Point3D ID'et
        handleEntered((ENTERED*) m);
        break;
    default:
        break;
    }
}

void EntryGuard::run()
{   
    for(;;)
    {
        unsigned long msgID;
        // Receives a message to the messageQueue
        osapi::Message* m = mq_.receive(msgID);
        entryHandler(msgID, m); // Handles message
        delete m;               // Removes message from heap

        osapi::sleep(250);
    }
}
