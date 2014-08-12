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

#ifndef OBSERVER_H_
#define OBSERVER_H_

using namespace std;
class Observer
{
    public:

	/*
	 * rObject puede tomar varios valores, en el caso de ManagerSms es un string que contiene el numero
	 * Al cual se a enviar un sms
	 * De la Gui a Controller toma el valor de un QVector<QString> que contiene el codigo de funcion y el nombre
	 * del campo del mensaje
	 */
	virtual void Update(int rCodigo)=0;
};

#endif /* OBSERVER_H_ */
