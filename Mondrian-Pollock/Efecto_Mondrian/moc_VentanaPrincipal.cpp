/****************************************************************************
** Meta object code from reading C++ file 'VentanaPrincipal.h'
**
** Created: Tue Sep 9 16:03:20 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "VentanaPrincipal.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VentanaPrincipal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VentanaPrincipal[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      35,   17,   17,   17, 0x08,
      62,   57,   50,   17, 0x08,
      90,   17,   17,   17, 0x08,
     110,   17,   17,   17, 0x08,
     133,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VentanaPrincipal[] = {
    "VentanaPrincipal\0\0IniciarCaptura()\0"
    "GuardarFondo()\0QImage\0mSrc\0"
    "IplImageToQImage(IplImage*)\0"
    "ActualizaImagenes()\0DefaultButtonClicked()\0"
    "ValorAjustesCambiado()\0"
};

void VentanaPrincipal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VentanaPrincipal *_t = static_cast<VentanaPrincipal *>(_o);
        switch (_id) {
        case 0: _t->IniciarCaptura(); break;
        case 1: _t->GuardarFondo(); break;
        case 2: { QImage _r = _t->IplImageToQImage((*reinterpret_cast< IplImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 3: _t->ActualizaImagenes(); break;
        case 4: _t->DefaultButtonClicked(); break;
        case 5: _t->ValorAjustesCambiado(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VentanaPrincipal::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VentanaPrincipal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VentanaPrincipal,
      qt_meta_data_VentanaPrincipal, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VentanaPrincipal::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VentanaPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VentanaPrincipal::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VentanaPrincipal))
        return static_cast<void*>(const_cast< VentanaPrincipal*>(this));
    if (!strcmp(_clname, "Observable"))
        return static_cast< Observable*>(const_cast< VentanaPrincipal*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VentanaPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
