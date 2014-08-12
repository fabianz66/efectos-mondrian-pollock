/*
 * Instituto Tecnologico de Costa Rica
 * Ingenieria en Computadores
 *
 * Algoritmos y Estructuras de Datos II
 * Prof. Andres Meseguer
 *
 * SMS (Sistema de Manejo de Suscripciones)
 *
 * Fabian Zamora Ramirez
 * Luis Alonso Murillo
 *
 * Cartago, Junio 2011
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

