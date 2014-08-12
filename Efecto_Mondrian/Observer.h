/*
  Costa Rica Institute of Technology
  Computer Engineering

  Fab Lab Costa Rica - Lutec Project
  Mondrian Efect V1

  Fabian Zamora Ramirez
  Cartago, Agosto 2011
*/

#ifndef OBSERVER_H
#define OBSERVER_H

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

#endif // OBSERVER_H
