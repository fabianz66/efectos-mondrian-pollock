/****************************************************************************
** Meta object code from reading C++ file 'VentanaAjustes.h'
**
** Created: Tue 13. Sep 19:05:01 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Efecto_Pollock/VentanaAjustes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VentanaAjustes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VentanaAjustes[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      35,   15,   15,   15, 0x0a,
      51,   15,   15,   15, 0x0a,
      73,   15,   15,   15, 0x0a,
      95,   15,   15,   15, 0x0a,
     116,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VentanaAjustes[] = {
    "VentanaAjustes\0\0MostrarImagenHsv()\0"
    "HsvBtnClicked()\0CerrarHsvBtnClicked()\0"
    "ErosionValueChanged()\0HsvIzqValueChanged()\0"
    "HsvDerValueChanged()\0"
};

const QMetaObject VentanaAjustes::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VentanaAjustes,
      qt_meta_data_VentanaAjustes, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VentanaAjustes::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VentanaAjustes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VentanaAjustes::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VentanaAjustes))
        return static_cast<void*>(const_cast< VentanaAjustes*>(this));
    if (!strcmp(_clname, "Observable"))
        return static_cast< Observable*>(const_cast< VentanaAjustes*>(this));
    return QWidget::qt_metacast(_clname);
}

int VentanaAjustes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: MostrarImagenHsv(); break;
        case 1: HsvBtnClicked(); break;
        case 2: CerrarHsvBtnClicked(); break;
        case 3: ErosionValueChanged(); break;
        case 4: HsvIzqValueChanged(); break;
        case 5: HsvDerValueChanged(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
