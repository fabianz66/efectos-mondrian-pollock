
#include "ManejoCamara.h"
#include "ManejoEfecto.h"
//#include "Constantes.h"
#include "qvector.h"

/*
Esta clase se encarga de manejar a las clases que detectan los colores.
Toma las imagenes de la camara desde la clase ManejoCamara y se las manda para
que se trabaje sobre ellas
*/
class ManejoPrograma
{
	private:

		//Constructor
		ManejoPrograma();

		//Clase que se encarga de tomar las imagenes de la camara
		ManejoCamara* mManejoCamara;

		//Clases que detectan los colores
		ManejoEfecto* mDetectorColorUno;
		ManejoEfecto* mDetectorColorDos;

		//Se crean las clases que detectan los colores
		void CrearDetectoresColor();

		//Vector que va a contener los resultados de una iteracion de imagenes
		QVector<IplImage*>* mVectorImagenes;

	public:

		//Funcion que devuelve la unica instancia de la clase
		static ManejoPrograma& GetInstance();

		void SetValoresColorUno(CvScalar/*min*/, CvScalar/*max*/);
		
		void SetValoresColorDos(CvScalar/*min*/, CvScalar/*max*/);
		
		//Establece los valores de erosion
		void SetValoresErosion(int /*rErosionUno*/, int /*rErosionDos*/);

		/*
		Funcion que devuelve las imagenes que se van a mostrar en el orden:
		[0] ImagenDeteccionUno [1] ImagenRecorridoUno
		[2] ImagenDeteccionDos [3] ImagenRecorridoDos
		*/
		QVector<IplImage*>* GetResultados();

		void ResetRecorridoUno();

		void ResetRecorridoDos();
};