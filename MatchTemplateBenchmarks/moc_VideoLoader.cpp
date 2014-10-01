/****************************************************************************
** Meta object code from reading C++ file 'VideoLoader.h'
**
** Created: Tue Sep 30 16:27:56 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "VideoLoader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VideoLoader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VideoLoader[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VideoLoader[] = {
    "VideoLoader\0\0onNewImageCaptured(Mat)\0"
    "notifyWithFrame()\0"
};

void VideoLoader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VideoLoader *_t = static_cast<VideoLoader *>(_o);
        switch (_id) {
        case 0: _t->onNewImageCaptured((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 1: _t->notifyWithFrame(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VideoLoader::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VideoLoader::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_VideoLoader,
      qt_meta_data_VideoLoader, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VideoLoader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VideoLoader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VideoLoader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VideoLoader))
        return static_cast<void*>(const_cast< VideoLoader*>(this));
    return QThread::qt_metacast(_clname);
}

int VideoLoader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void VideoLoader::onNewImageCaptured(Mat _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
