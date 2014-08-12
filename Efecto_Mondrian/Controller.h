/*
  Costa Rica Institute of Technology
  Computer Engineering

  Fab Lab Costa Rica - Lutec Project
  Mondrian Efect V1

  Fabian Zamora Ramirez
  Cartago, Agosto 2011
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "ManejoCamara.h"
#include "VentanaPrincipal.h"
#include "Observer.h"

#include <QHash>
#include <QtGui/QApplication>

class Controller : public Observer
{
private:
    //Hashtable containing pointers to the functions called by the GUI
    QHash<int, void(Controller::*)()> mHashEventosGuiCodigo;

    //Class that manages the cam and cam filters
    ManejoCamara* mManejoCamara;

    //Main Window
    VentanaPrincipal* mVentanaPrincipal;

    //Initialize the instance of the main window
    void IniciarVentana();

    //Set the pointers to the hash, *See indexes at Constantes.h
    void IniciarHashEventos();

    //Starts reading from the cam
    void IniciarCaptura();


    void ActualizaImagenesCamara();
    void GuardarImagenFondo();
    void CambiarValoresAjustes();

public:
    Controller();
    int IniciarPrograma(int argc, char *argv[]);
    void Update(int numero);
};

#endif // CONTROLLER_H
