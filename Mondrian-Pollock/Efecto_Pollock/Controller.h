
//GUI
#include "VentanaPrincipal.h"
#include "VentanaAjustes.h"

//CODIGO
#include "ManejoPrograma.h"

//QT
#include <qhash.h>
#include <QtGui/QApplication>

/*
Clase para aplicar el patron MODEL VIEW CONTROLLER, para comunicar interfaz grafica con el codigo.
La interfaz grafica notifica a la clase Controller por medio de observer sobre eventos del Usuario y este
reacciona tomando informacion del Codigo propio del programa u modificando la interfaz GUI
*/
class Controller : public Observer
{
private:

    //Hash que guarda punteros a funciones de Controller
    QHash<int, void(Controller::*)()> mHashEventosGuiCodigo;

    //Clase que maneja la camara, y los la deteccion de color
    ManejoPrograma* mManejoPrograma;

    //Ventana donde se muestran los recorridos
    VentanaPrincipal* mVentanaPrincipal;

    //Ventana donde se puede escoger que colores detectar
    VentanaAjustes* mVentanaAjustes;

    //Inicializa las ventanas y asigna el observer a cada una para aplicar el MVC
    void CrearVentanas();

    //Se crea un hash de punteros a funciones que se van a llamar desde la interfaz grafica GUI
    void CrearHashEventosGuiCodigo();

    //Iniciar Captura
    void IniciarCaptura();

    //Se muestra la ventana de ajustes
    void MostrarVentanaAjustes();

    void CambiarImagenesVentanaPrincipal();

    void CambioValoresErosion();

    void ResetRecorridoIzq();

    void ResetRecorridoDer();

    void HsvDerValueChanged();

    void HsvIzqValueChanged();

    void MostrarCamaraHsv();

public:

    //Constructor Default
    Controller();

    //Inicia la ventana de bienvenida
    int IniciarPrograma(int argc, char *argv[]);

    //Se actualiza por medio del Patron Observer
    void Update(int rCodigo);

};
