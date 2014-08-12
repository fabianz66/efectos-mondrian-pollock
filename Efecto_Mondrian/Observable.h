/*
  Costa Rica Institute of Technology
  Computer Engineering

  Fab Lab Costa Rica - Lutec Project
  Mondrian Efect V1

  Fabian Zamora Ramirez
  Cartago, Agosto 2011
*/

#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <QVector>
#include "Observer.h"
#include "Constantes.h"

class Observable
{
        public:
                Observable();
                void AddObserver(Observer*);
                void Notify(int rCodigo);
        private:
                QVector<Observer*> mObservers;
};

#endif // OBSERVABLE_H
