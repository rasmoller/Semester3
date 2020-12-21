#include <osapi/PLCS/ExitGuard.h>
#include <osapi/Utility.hpp>
#include <iostream>

void ExitGuard::handleExitInd(EXIT_IND* m)
{
	std::cout << "Car " << m->id << " wating for exit" << std::endl;

    // Send msg that it has opened
    m->msgQ->send(Car::ID_EXIT_OPEN, new EXIT_OPEN());
}

void ExitGuard::handleExited(EXITED* m)
{
    carsParked--;
    std::cout << "Car " << m->id << " has exited" << std::endl;
}

void ExitGuard::exitHandler(int id, osapi::Message* m)
{
    switch (id)
    {
    case ID_EXIT_IND: // Case from test
        handleExitInd((EXIT_IND*) m);
        break;
    case ID_EXITED:   // Handles Point3D ID'et
        handleExited((EXITED*) m);
        break;
    default:
        break;
    }
}

void ExitGuard::run()
{
    for(;;)
    {
        unsigned long msgID;
        // Receives a message to the messageQueue
        osapi::Message* m = mq_.receive(msgID);
        exitHandler(msgID, m); // Handles message
        delete m;              // Removes message from heap

        osapi::sleep(50);
    }
}