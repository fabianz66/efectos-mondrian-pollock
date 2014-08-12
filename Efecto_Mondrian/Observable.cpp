/*
  Costa Rica Institute of Technology
  Computer Engineering

  Fab Lab Costa Rica - Lutec Project
  Mondrian Efect V1

  Fabian Zamora Ramirez
  Cartago, Agosto 2011
*/

#include "Observable.h"

Observable::Observable()
{

}

void Observable::AddObserver(Observer* rObserver)
{
    mObservers.push_back(rObserver);
}

void Observable::Notify(int rCodigo)
{
    int cant_observers = mObservers.size();
    for (int observer = 0; observer < cant_observers; observer++)
    {
        mObservers[observer]->Update(rCodigo);
    }
}

