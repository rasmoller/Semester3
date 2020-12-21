#include <osapi/Thread.hpp>
#include <osapi/PLCS/Car.h>
#include <osapi/PLCS/EntryGuard.h>
#include <osapi/PLCS/ExitGuard.h>
#include <osapi/PLCS/common.h>

int Ncars = 20;     // Number of threads
int spots = 10;     // Number of parking spots
int carsParked = 0; // Number of parked cars

int main(int argc, char** argv)
{
    // Creating objects
    EntryGuard enG;
    ExitGuard  exG;
    Car*       cars[Ncars];
    for (int i = 0; i < Ncars; i++)
        cars[i] = new Car(i + 1, &enG, &exG);

    // Creating threads
    osapi::Thread enGT(&enG);
    enGT.start();
    osapi::Thread exGT(&exG);
    exGT.start();
    osapi::Thread* carTs[Ncars];
    for (int i = 0; i < Ncars; i++)
    {
        carTs[i] = new osapi::Thread(cars[i]);
        carTs[i]->start();
    }

    // Joinning threads
    enGT.join();
    exGT.join();
    for (int i = 0; i < Ncars; i++)
        carTs[i]->join();

    return 0;
}
