#include "ManejoCamara.h"

int CAMARA_UTILIZADA = -1;

ManejoCamara::ManejoCamara()
{
	SetCamara(CAMARA_UTILIZADA);
}

ManejoCamara& ManejoCamara::GetInstance()
{
	static ManejoCamara instance;
	return instance;
}

/*
Comienza a leer de la camara, el numero de camara comienza en 0, siendo este la camara default de la computadora,
si se tiene alguna camara extra conectada, el numero aumenta de uno en uno,
si se desea mostrar una ventana para escojer cual camara usar se debe usar el -1 
Tambien aqui se mandan la ImagenModelo a la funcion crearImagenes para crear las imagenes que se van a utilizar
en el resto del programa
*/
void ManejoCamara::SetCamara(int rNumeroCam)
{
	//Se le indica a mCamCapture que comience a leer de la cam
	mCamCapture= cvCreateCameraCapture(rNumeroCam);
	
	//Se manda la imagen modelo para crear las demas
	mImagenActualCamara = cvQueryFrame(mCamCapture);

	//Se crea la imagen que va a contener la imagen hsv
	mImagenActualCamaraHsv = cvCreateImage(cvGetSize(mImagenActualCamara), mImagenActualCamara->depth, 3);
}

IplImage* ManejoCamara::GetHsvImage()
{
	mImagenActualCamara = cvQueryFrame(mCamCapture);

	//Se le quita el efecto espejo //numero positivo=voltear imagen horizontalmente
	cvFlip(mImagenActualCamara,mImagenActualCamara,1);

	// Covert color space to HSV as it is much easier to filter colors in the HSV color-space.
	cvCvtColor(mImagenActualCamara,mImagenActualCamaraHsv, CV_BGR2HSV);

	return mImagenActualCamaraHsv;
}

IplImage* ManejoCamara::GetImagenActualCamara()
{
	mImagenActualCamara = cvQueryFrame(mCamCapture);
	return mImagenActualCamara;
}
