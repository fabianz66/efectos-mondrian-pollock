/****************************************************************************
** Meta object code from reading C++ file 'MatchTemplateTest.h'
**
** Created: Mon Sep 22 22:32:36 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MatchTemplateTest.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MatchTemplateTest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MatchTemplateTest[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      40,   18,   18,   18, 0x08,
      64,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MatchTemplateTest[] = {
    "MatchTemplateTest\0\0BasicMatchTemplate()\0"
    "ParallelMatchTemplate()\0GPUMatchTemplate()\0"
};

void MatchTemplateTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MatchTemplateTest *_t = static_cast<MatchTemplateTest *>(_o);
        switch (_id) {
        case 0: _t->BasicMatchTemplate(); break;
        case 1: _t->ParallelMatchTemplate(); break;
        case 2: _t->GPUMatchTemplate(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MatchTemplateTest::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MatchTemplateTest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MatchTemplateTest,
      qt_meta_data_MatchTemplateTest, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MatchTemplateTest::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MatchTemplateTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MatchTemplateTest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MatchTemplateTest))
        return static_cast<void*>(const_cast< MatchTemplateTest*>(this));
    return QObject::qt_metacast(_clname);
}

int MatchTemplateTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
