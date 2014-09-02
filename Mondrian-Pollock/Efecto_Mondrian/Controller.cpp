/*
  Costa Rica Institute of Technology
  Computer Engineering

  Fab Lab Costa Rica - Lutec Project
  Mondrian Efect V1

  Fabian Zamora Ramirez
  Cartago, Agosto 2011
*/

#include "Controller.h"

Controller::Controller()
{
    mManejoCamara = &ManejoCamara::GetInstance();
    IniciarHashEventos();
}

int Controller::IniciarPrograma(int argc, char *argv[])
{
    //Se inicia la aplicacion
    QApplication a(argc, argv);

    //Se crean las ventanas
    IniciarVentana();

    //Se ejecuta el hilo de la interfaz grafica
    return a.exec();
}

void Controller::ActualizaImagenesCamara()
{
   mVentanaPrincipal->MostrarImagenes(mManejoCamara->GetImagenEfectoMondrian(), mManejoCamara->GetImagenVideoCamara());
}

void Controller::IniciarVentana()
{
    mVentanaPrincipal = new (VentanaPrincipal);
    mVentanaPrincipal->AddObserver(this);
    mVentanaPrincipal->show();
}

void Controller::IniciarHashEventos()
{
    mHashEventosGuiCodigo[CODIGO_INICIAR_CAPTURA] = &Controller::IniciarCaptura;
    mHashEventosGuiCodigo[CODIGO_GUARDAR_IMAGEN_FONDO] = &Controller::GuardarImagenFondo;
    mHashEventosGuiCodigo[CODIGO_ACTUALIZAR_IMAGENES] = &Controller::ActualizaImagenesCamara;
    mHashEventosGuiCodigo[CODIGO_VALOR_AJUSTES_CAMBIADO] = &Controller::CambiarValoresAjustes;
}

void Controller::Update(int rCodigo)
{
    void(Controller::* evento)() = mHashEventosGuiCodigo[rCodigo];
    (this->*evento)();
}

void Controller::GuardarImagenFondo()
{
    mManejoCamara->GuardarFondo();
}

void Controller::CambiarValoresAjustes()
{
    int erode = mVentanaPrincipal->GetValorErode();
    int thres1 = mVentanaPrincipal->GetValorThres1();
    mManejoCamara->SetValoresErodeThres(erode, thres1);
}

/*
  Comienza a leer de la camara # CAMARA_UTILIZADA y la comienza a mostrar
  en la ventana
  */
void Controller::IniciarCaptura()
{
    //Set the cam we're going to use. 0 = Default Camera
    //If there's more than 1 camera, the numbers increases by one for each camera
    mManejoCamara->SetCamara(CAMARA_UTILIZADA);

    //Starts the timer that keeps updating the images
    mVentanaPrincipal->ComenzarVisualizarCamara();
}

/*
        EJECUCION DEL PROGRAMA
*/
int main(int argc, char *argv[])
{
    Controller* contro = new (Controller);
    contro->IniciarPrograma(argc, argv);
    return 0;
}
