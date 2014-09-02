
#include "opencv/cv.h"
#include "opencv/cxcore.h"
#include "opencv/highgui.h"

class ManejoCamara
{
private:
    ManejoCamara();
    CvCapture* mCamCapture;
    IplImage* mImagenActualCamara;
    IplImage* mImagenActualCamaraHsv;

public:
    static ManejoCamara& GetInstance();
    void SetCamara(int/*numCam*/);
    IplImage* GetHsvImage();
    IplImage* GetImagenActualCamara();
};
