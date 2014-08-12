
#include "cv.h"
#include "cxcore.h"
#include "highgui.h"

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
