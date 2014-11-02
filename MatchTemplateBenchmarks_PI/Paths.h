#ifndef PATHS_H
#define PATHS_H

#include <QObject>
#include <QMutex>
#include <QString>

class Paths : public QObject
{
public:

    /** Singleton */
    static Paths& getInstance();

    /** Getters */
    char* getVideoPath();

    /** Setters */
    void setVideoPath(char* path);

private:

    /** Variables */
    static Paths* m_Instance;
    char* mVideoPath;

    /** Metodos */
    explicit Paths(QObject *parent = 0);
};

#endif // PATHS_H
