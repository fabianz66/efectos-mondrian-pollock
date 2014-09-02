#include "ManejoPrograma.h"

//Constructor
ManejoPrograma::ManejoPrograma()
{
	//Se inicializa la clase que maneja la camara
	mManejoCamara = &ManejoCamara::GetInstance();

	//Vector que contiene las imagenes de resultado de una iteracion
	mVectorImagenes = new QVector<IplImage*>();

	//Se crean las clases que van a detectar los colores y dibujar los recorridos
	CrearDetectoresColor();
}

//Funcion estatica que retorna la unica instancia de la clase
ManejoPrograma& ManejoPrograma::GetInstance()
{
	static ManejoPrograma instance;
	return instance;
}

//Se crean las instancias de la clase que va a aplicar el efecto
void ManejoPrograma::CrearDetectoresColor()
{
	//Se toma una imagen tomada de la camara para tomarla como modelo ( size, depth, channels)
	IplImage* imagen_modelo = mManejoCamara->GetImagenActualCamara();

	//
	mDetectorColorUno = new ManejoEfecto(imagen_modelo);
	mDetectorColorDos = new ManejoEfecto(imagen_modelo);

	//Los colores de las lineas no son variables
	mDetectorColorUno->SetColoresLineas(cvScalar(0,0,255),cvScalar(0,255,0),cvScalar(255,0,0));
	mDetectorColorDos->SetColoresLineas(cvScalar(25,155,255),cvScalar(111,25,0),cvScalar(255,122,70));
}


//Se establecen los colores que se desean detectar
void ManejoPrograma::SetValoresColorUno(CvScalar rMin, CvScalar rMax)
{
	mDetectorColorUno->SetValoresColorDeteccion(rMin, rMax);
}

void ManejoPrograma::SetValoresColorDos(CvScalar rMin, CvScalar rMax)
{
	mDetectorColorDos->SetValoresColorDeteccion(rMin, rMax);
}

//Se establecen los valores de erosion
void ManejoPrograma::SetValoresErosion(int rErosionUno, int rErosionDos)
{
	mDetectorColorUno->SetValorErosion(rErosionUno);
	mDetectorColorDos->SetValorErosion(rErosionDos);
}

/*
Funcion que devuelve las imagenes que se van a mostrar en el orden:
[0] ImagenDeteccionUno [1] ImagenRecorridoUno
[2] ImagenDeteccionDos [3] ImagenRecorridoDos
*/
QVector<IplImage*>* ManejoPrograma::GetResultados()
{
	//Se liberan las imagenes que puede contener el vector
	mVectorImagenes->clear();

	//
	IplImage* hsv_actual_camara = mManejoCamara->GetHsvImage();

	//
	IplImage* deteccion_uno = mDetectorColorUno->GetImagenFiltrada(hsv_actual_camara);
	IplImage* recorrido_uno = mDetectorColorUno->GetImagenRecorrido();

	//
	IplImage* deteccion_dos = mDetectorColorDos->GetImagenFiltrada(hsv_actual_camara);
	IplImage* recorrido_dos = mDetectorColorDos->GetImagenRecorrido();

	//Se ingresan las imagenes al vector
	*mVectorImagenes << deteccion_uno << recorrido_uno << deteccion_dos << recorrido_dos;

	return mVectorImagenes;
}

void ManejoPrograma::ResetRecorridoUno()
{
	mDetectorColorUno->ResetRecorrido();
}

void ManejoPrograma::ResetRecorridoDos()
{
	mDetectorColorDos->ResetRecorrido();
}
