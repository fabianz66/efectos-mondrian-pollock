/*
  Costa Rica Institute of Technology
  Computer Engineering

  Fab Lab Costa Rica - Lutec Project
  Mondrian Effect V2

  Fabian Zamora Ramirez
  Cartago, Diciembre 2011
*/

#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <time.h>

//Tamano de la imagen que se muestra de la camara. La imagen original.
#define LARGO 320
#define ALTO 240
//clock_t clock(void);

/*Constantes del programa*/
enum TECLAS_ASCII {TECLA_ESC = 27,
                   TECLA_0 = 48,
                   TECLA_1 = 49,
                   TECLA_2 = 50,
                   TECLA_ENTER = 13};

/*numero de camara a utilizar*/
int num_cam = 1;

/*Este boolean indica si se debe mostrar la camara*/
bool mostrar_efecto = false;

/* Esto contiene la informacion tomada de la cam,
    contiene los frames, aca es donde pedimos el frame que esta tomando la camara */
CvCapture* cam_capture;

/*Imagenes que se utilizan en el programa*/
IplImage* imagen_fondo_inicio = cvLoadImage("../Efecto_MondrianV2/Imagenes/fondo_inicio.jpg");
IplImage* frame_original_camara;
IplImage* frame_peque_camara;
IplImage* frame_grises_camara;

/*Pinturas mondrian*/
IplImage* mondrian_1 = cvLoadImage("../Efecto_MondrianV2/Imagenes/mondrian1.jpg");
IplImage* mondrian_2 = cvLoadImage("../Efecto_MondrianV2/Imagenes/mondrian2.jpg");
IplImage* mondrian_3 = cvLoadImage("../Efecto_MondrianV2/Imagenes/mondrian3.jpg");
IplImage* mondrian_4 = cvLoadImage("../Efecto_MondrianV2/Imagenes/mondrian4.jpg");
IplImage* mondrian_5 = cvLoadImage("../Efecto_MondrianV2/Imagenes/mondrian5.jpg");
IplImage* pinturas_mondrian[5] = {mondrian_1, mondrian_2, mondrian_3, mondrian_4, mondrian_5};

/*Se crean las imagenes que se van a utilizar*/
void iniciarImagenes()
{
    frame_peque_camara = cvCreateImage(cvSize(320,240), 8, 3);
    frame_grises_camara = cvCreateImage(cvSize(320,240), 8, 3);
}

/** Carga la camara en el capture */
void iniciarCamara()
{
    //Se inicia la camara
    cam_capture = cvCreateCameraCapture(num_cam);

    //Se crean las imagenes que se van a utilizar
    iniciarImagenes();

    //Se indica que se muestre el efecto
    mostrar_efecto = true;

    //Se crea la ventana donde se muestra la imagen de la camara
    cvNamedWindow("Mondrian Effect - Cam");
}

/** Se muestra la ventana de inicio */
void mostrarVentanaInicio()
{
    cvNamedWindow("Mondrian Effect - LuTec Project");
    cvShowImage("Mondrian Effect - LuTec Project", imagen_fondo_inicio);
}

/** Se muestra la camara original */
void mostrarCamaraOriginal()
{
    //La imagen original se muestra, pero mas peque
    cvResize(frame_original_camara, frame_peque_camara);
    cvShowImage("Mondrian Effect - Cam", frame_peque_camara);
}

void mostrarEfectoMondrian()
{
    //Se crea una imagen de la imagen actual pero a escala de grises
    cvCvtColor(frame_original_camara, mImagenActualCamaraGrises, CV_RGB2GRAY);

    //Se saca la diferencia de imagenes
    cvAbsDiff( mImagenFondo, mImagenActualCamaraGrises, mImagenDiferencia);

    //Se le aplican los filtros a la imagen para borrar pixeles no deseados
    AplicarFiltrosImagenDiferencia();

    //Se rellena la imagen con el fondo de Mondrian
    cvZero(mImagenRellenaMondrian);
    RellenarImagenMondrian();

    return mImagenRellenaMondrian;

//    int num = 4;
   // if((clock()/1000)%5 == 0)
  //  {
  //      num += 1; num = num%5;
   // }*/
//    cvShowImage("Mondrian Effect - LuTec Project", pinturas_mondrian[0]);
}


int main()
{
    /* Primero se muestra la ventana de inicio */
    mostrarVentanaInicio();

    /* Ciclo principal del programa
       Aqui se muestran las ventanas
       Con la tecla ESC termina el programa */
    bool active = true;
    while(active)
    {
        char letra_tecleada = cvWaitKey(15);
        switch(letra_tecleada)
        {
            case TECLA_0:
                num_cam = 0; break;
            case TECLA_1:
                num_cam = 1; break;
            case TECLA_2:
                num_cam = 2; break;
            case TECLA_ENTER:
                iniciarCamara();break;
            case TECLA_ESC:
                active = false; break;
        }

        /* La camara se muestra una vez se halla llamado a iniciarCamara() */
        if(mostrar_efecto && active)
        {
            //Se lee la imagen de la camara
            frame_original_camara = cvQueryFrame(cam_capture);

            //Se muestra la imagen original
            mostrarCamaraOriginal();

            //Se muestra el efecto mondrian
            mostrarEfectoMondrian();
        }
    }

    /** Se libera espacio en memoria */
    cvDestroyAllWindows();
    cvReleaseCapture(&cam_capture);
    cvReleaseImage(&imagen_fondo_inicio);
    cvReleaseImage(&frame_original_camara);
    cvReleaseImage(&frame_peque_camara);
    cvReleaseImage(&frame_grises_camara);
    for(int x=0; x < 5; x++)
        cvReleaseImage(&pinturas_mondrian[x]);

    return 0;
}
