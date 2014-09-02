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

#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

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

#endif /* OBSERVABLE_H_ */
