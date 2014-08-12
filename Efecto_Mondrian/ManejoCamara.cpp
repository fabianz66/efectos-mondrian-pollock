/*
  Costa Rica Institute of Technology
  Computer Engineering

  Fab Lab Costa Rica - Lutec Project
  Mondrian Efect V1

  Fabian Zamora Ramirez
  Cartago, Agosto 2011
*/

#include "ManejoCamara.h"

//Constructor privado
ManejoCamara::ManejoCamara()
{
    mErode = 0;
    mThres1= 15;
}

//Funcion estatica que devuelve la unica instancia de la clase
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
    mCamCapture = cvCreateCameraCapture(rNumeroCam);

    //Se manda la imagen modelo para crear las demas
    mImagenActualCamara = cvQueryFrame(mCamCapture);
    CrearImagenes(mImagenActualCamara);
}

/*
Se guarda el fondo que se utilizara para crear la sustraccion de fondo
*/
void ManejoCamara::GuardarFondo()
{
    //Se convierte la imagen actual a escala de grises y se guarda en mImagenFondo
    cvCvtColor(mImagenActualCamara, mImagenFondo, CV_RGB2GRAY);
}

/*
Se crean inician las imagenes que se van a utilizar en el programa,
se recibe como parametro una imagen modelo para tomar las medidas y la profundidad default de la camara
*/
void ManejoCamara::CrearImagenes(IplImage* rModeloImagen)
{
    //Se toman las medidas de la foto
    CvSize size = cvGetSize(rModeloImagen);

    //Se inician las imagenes de un solo canal
    //Estas son imagenes a escala de grises, por lo tanto no van a utilziar los 3 canales
    mImagenFondo = cvCreateImage(size, rModeloImagen->depth , 1);
    mImagenActualCamaraGrises = cvCreateImage(size, rModeloImagen->depth , 1);
    mImagenDiferencia = cvCreateImage(size, rModeloImagen->depth , 1);

    //Se carga una imagen de fondo por default
    mImagenFondoMondrian = cvLoadImage("../Efecto_Mondrian/Imagenes/mondrian1.jpg");

    //Se crean la imagen que va a contener la cilueta rellena, de 3 canales porq va ser a color
    mImagenRellenaMondrian = cvCreateImage(size, mImagenFondoMondrian->depth , mImagenFondoMondrian->nChannels);

    //Se crean los punteros a la informacion de las imagenes que se van a utilizar para crear la imagen que se va a rellenar con la imagen de Mondrian
    pDataImagenFondoMondrian   = (uchar*)mImagenFondoMondrian->imageData;
    pDataImagenRellenaMondrian   = (uchar*)mImagenRellenaMondrian->imageData;
}

/*
Muestra lo que esta viendo la camara
*/
IplImage* ManejoCamara::GetImagenVideoCamara()
{
    //Se toma la imagen actual de la camara
    mImagenActualCamara = cvQueryFrame(mCamCapture);
    return mImagenActualCamara;
}

/*
Esta funcion se encarga de convertir la imagen que se tomo de la camara a escala de grises para compararla con la imagen que
se tenga como fondo , luego aplica los filtros y rellena la imagen
*/
IplImage* ManejoCamara::GetImagenEfectoMondrian()
{
    //Se crea una imagen de la imagen actual pero a escala de grises
    cvCvtColor(mImagenActualCamara, mImagenActualCamaraGrises, CV_RGB2GRAY);

    //Se saca la diferencia de imagenes
    cvAbsDiff( mImagenFondo, mImagenActualCamaraGrises, mImagenDiferencia);

    //Se le aplican los filtros a la imagen para borrar pixeles no deseados
    AplicarFiltrosImagenDiferencia();

    //Se rellena la imagen con el fondo de Mondrian
    cvZero(mImagenRellenaMondrian);
    RellenarImagenMondrian();

    return mImagenRellenaMondrian;
}

/*
Aplica filtros a mImagenDiferencia, para eliminar pixeles que no se deseen que hayan quedado como resultado
de la diferencia de imagenes
*/
void ManejoCamara::AplicarFiltrosImagenDiferencia()
{
    cvSmooth( mImagenDiferencia, mImagenDiferencia, CV_GAUSSIAN, 9, 9 );

    //Este filtro toma las regiones blancas mas peque;as y las reduce
    cvErode(mImagenDiferencia, mImagenDiferencia,0,mErode);

    //Aplica umbral
    //TODO explicar!!!
    cvThreshold(mImagenDiferencia, mImagenDiferencia,mThres1,255, CV_THRESH_BINARY);
}

/*
Esta funcion es la que crea la imagen rellena con la pintura.
Lo que hace es que recibe la imagen tomada de la camara rSrc, y va comparando
cuales pixeles son los blancos ( 255 || un aprox > 250 ), estos los reemplaza en otra imagen
con los pixeles en la misma posicion, de la imagen que contiene la pintura.
Los negros no los toca
*/
void ManejoCamara::RellenarImagenMondrian()
{
    //Se cambia la imagen de fondo, se genera una aleatoria
    GeneraImagenFondoMondrian();

    for( int pos_y = 0 ; pos_y < mImagenDiferencia->height ; pos_y++ )
    {
        for( int pos_x = 0 ; pos_x < mImagenDiferencia->width ; pos_x++ )
        {
            //Se toma el pixel en la posicion (pos_y, pos_x)
            CvScalar pixel = cvGet2D(mImagenDiferencia,pos_y,pos_x);
            int num_color = pixel.val[0];
            if( num_color > 250) //Se comprueba que el color sea blanco
            {
                pDataImagenRellenaMondrian[pos_y*mImagenRellenaMondrian->widthStep + pos_x*mImagenRellenaMondrian->nChannels] = pDataImagenFondoMondrian[pos_y*mImagenFondoMondrian->widthStep + pos_x*mImagenFondoMondrian->nChannels];
                pDataImagenRellenaMondrian[pos_y*mImagenRellenaMondrian->widthStep + pos_x*mImagenRellenaMondrian->nChannels+1] = pDataImagenFondoMondrian[pos_y*mImagenFondoMondrian->widthStep + pos_x*mImagenFondoMondrian->nChannels+1];
                pDataImagenRellenaMondrian[pos_y*mImagenRellenaMondrian->widthStep + pos_x*mImagenRellenaMondrian->nChannels+2] = pDataImagenFondoMondrian[pos_y*mImagenFondoMondrian->widthStep + pos_x*mImagenFondoMondrian->nChannels+2];
            }
        }
    }
}

/*
Funcion que cambia la iamgen a utilizar de fondo para rellenar la cilueta
Se cambia cuando el segundo actual es multiplo de 3, se escoje una imagen aleatoria
*/
int numero_imagen =0;
bool imagen_cambiada = false;
void ManejoCamara::GeneraImagenFondoMondrian()
{
    //Se toma el segundo actual del sistema
    int seg_actual = QTime::currentTime().second();

    //Se verifica que sea multiplo de 3
    if(seg_actual % 3 == 0 && !imagen_cambiada)
    {
        //Se convierte a string
        stringstream st;
        st << numero_imagen++;
        string nombre_imagen  = "../Efecto_Mondrian/Imagenes/mondrian"+ st.str()+".jpg";

        //Se carga la imagen de Mondrian para relleno
        IplImage* nuevo_fondo = cvLoadImage(nombre_imagen.c_str());

        //Se copia en mImagenFondoMondrian
        cvCopy(nuevo_fondo, mImagenFondoMondrian);

        //Se libera la imagen
        cvReleaseImage(&nuevo_fondo);

        //Se indica que ya se cambio la imagen por ese segundo
        imagen_cambiada = true;

        if(numero_imagen == 6)
            numero_imagen = 0;
    }else if(seg_actual % 3 != 0)
    {
        imagen_cambiada = false;
    }
}

void ManejoCamara::SetValoresErodeThres(int rErode, int rThres)
{
    mErode = rErode;
    mThres1 = rThres;
}
