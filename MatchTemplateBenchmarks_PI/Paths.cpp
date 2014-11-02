
#include "Paths.h"

Paths::Paths(QObject *parent) :
    QObject(parent)
{
    mVideoPath = "resources/video_pos1.mp4";
}

/** Singleton */

Paths& Paths::getInstance()
{
    static Paths instance;
    return instance;
}

/** Getters */
char* Paths::getVideoPath()
{
    return this->mVideoPath;
}

/** Setters */
void Paths::setVideoPath(char* path)
{
    this->mVideoPath = path;
}
