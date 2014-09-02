
#include "Controller.h"

//Constructor
Controller::Controller()
{
    //Se inicia el hash de punteros a funciones
    CrearHashEventosGuiCodigo();
}

//Esta funcion es llamada por las clases Observables para indicarle que hubo una accion
void Controller::Update(int rCodigo)
{
    //Se toma la casilla correspondiente del hash y se ejecuta la funcion
    void(Controller::* evento)() = mHashEventosGuiCodigo[rCodigo];
    (this->*evento)();
}

//Se inician las ventanas
void Controller::CrearVentanas()
{

    mVentanaPrincipal = new VentanaPrincipal();
    mVentanaPrincipal->AddObserver(this);

    mVentanaAjustes = &VentanaAjustes::GetInstance();
    mVentanaAjustes->AddObserver(this);
}

//Se inicia la interfaz grafica
int Controller::IniciarPrograma(int argc, char *argv[])
{
    //Primero se debe crear la QApplication, antes de crear cualquier ventana
    QApplication a(argc, argv);
    CrearVentanas();
    mVentanaPrincipal->show();
    return a.exec();
}

//Se guardan las funciones necesarias en el hash
void Controller::CrearHashEventosGuiCodigo()
{
    mHashEventosGuiCodigo[CODIGO_INICIAR_CAPTURA] = &Controller::IniciarCaptura;
    mHashEventosGuiCodigo[CODIGO_INICIAR_VENTANA_AJUSTES] = &Controller::MostrarVentanaAjustes;
    mHashEventosGuiCodigo[CODIGO_MOSTRAR_IMAGENES_RECORRIDO] = &Controller::CambiarImagenesVentanaPrincipal;
    mHashEventosGuiCodigo[CODIGO_CAMBIO_EROSION] = &Controller::CambioValoresErosion;
    mHashEventosGuiCodigo[CODIGO_RESET_IZQ] = &Controller::ResetRecorridoIzq;
    mHashEventosGuiCodigo[CODIGO_RESET_DER] = &Controller::ResetRecorridoDer;
    mHashEventosGuiCodigo[CODIGO_CAMBIO_HSV_DER] = &Controller::HsvDerValueChanged;
    mHashEventosGuiCodigo[CODIGO_CAMBIO_HSV_IZQ] = &Controller::HsvIzqValueChanged;
    mHashEventosGuiCodigo[CODIGO_MOSTRAR_CAM_HSV] = &Controller::MostrarCamaraHsv;
}

//Se muestra la ventana ajustes
void Controller::MostrarVentanaAjustes()
{
    mVentanaAjustes->show();
}

/*
Aca se inicia la clase que maneja el programa, camara y efectos
*/
void Controller::IniciarCaptura()
{
    mManejoPrograma = &ManejoPrograma::GetInstance();
    mVentanaPrincipal->ComenzarMostrarImagenes();

    //Se forza a que se cambien los valores para los colores
    mVentanaAjustes->ErosionValueChanged();
    mVentanaAjustes->HsvDerValueChanged();
    mVentanaAjustes->HsvIzqValueChanged();
}

void Controller::CambiarImagenesVentanaPrincipal()
{
    mVentanaPrincipal->SetImagenes(mManejoPrograma->GetResultados());
}

void Controller::CambioValoresErosion()
{
    int erode_izq = mVentanaAjustes->GetErosionIzq();
    int erode_der = mVentanaAjustes->GetErosionDer();
    mManejoPrograma->SetValoresErosion(erode_izq, erode_der);
}

void Controller::ResetRecorridoIzq()
{
    mManejoPrograma->ResetRecorridoUno();
}

void Controller::ResetRecorridoDer()
{
    mManejoPrograma->ResetRecorridoDos();
}

void Controller::HsvDerValueChanged()
{
    mManejoPrograma->SetValoresColorDos(mVentanaAjustes->GetMinHsvDer(),mVentanaAjustes->GetMaxHsvDer());
}

void Controller::HsvIzqValueChanged()
{
    mManejoPrograma->SetValoresColorUno(mVentanaAjustes->GetMinHsvIzq(),mVentanaAjustes->GetMaxHsvIzq());
}

//Para poder ser utilizado como click en la ventana, no debe ser parte de la clase
void ClickVentanaHsv(int event, int x, int y, int flags, void* param)
{
    IplImage* src = (IplImage*)param;
    if(event==CV_EVENT_LBUTTONDOWN)
    {
        CvScalar pixel = cvGet2D(src,y,x);
        VentanaAjustes::GetInstance().SetClickedValues(pixel.val[0],pixel.val[1],pixel.val[2]);
    }
}

void Controller::MostrarCamaraHsv()
{
    IplImage* temp = ManejoCamara::GetInstance().GetHsvImage();
    cvShowImage("Hsv Image", temp);
    cvSetMouseCallback("Hsv Image",ClickVentanaHsv,(void*) temp);
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
