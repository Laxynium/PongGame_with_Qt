/****************************************************************************
** Meta object code from reading C++ file 'ballbehaviour.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PongGame_with_Qt/Game/ballbehaviour.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ballbehaviour.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BallBehaviour_t {
    QByteArrayData data[5];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BallBehaviour_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BallBehaviour_t qt_meta_stringdata_BallBehaviour = {
    {
QT_MOC_LITERAL(0, 0, 13), // "BallBehaviour"
QT_MOC_LITERAL(1, 14, 13), // "ballLeftScene"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "onRightSite"
QT_MOC_LITERAL(4, 41, 4) // "Tick"

    },
    "BallBehaviour\0ballLeftScene\0\0onRightSite\0"
    "Tick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BallBehaviour[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void BallBehaviour::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BallBehaviour *_t = static_cast<BallBehaviour *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ballLeftScene((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->Tick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BallBehaviour::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BallBehaviour::ballLeftScene)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject BallBehaviour::staticMetaObject = {
    { &GameObjectController::staticMetaObject, qt_meta_stringdata_BallBehaviour.data,
      qt_meta_data_BallBehaviour,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BallBehaviour::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BallBehaviour::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BallBehaviour.stringdata0))
        return static_cast<void*>(this);
    return GameObjectController::qt_metacast(_clname);
}

int BallBehaviour::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GameObjectController::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void BallBehaviour::ballLeftScene(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
