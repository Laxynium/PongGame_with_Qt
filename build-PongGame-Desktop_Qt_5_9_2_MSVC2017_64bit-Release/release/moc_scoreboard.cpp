/****************************************************************************
** Meta object code from reading C++ file 'scoreboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PongGame_with_Qt/Game/scoreboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scoreboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScoreBoard_t {
    QByteArrayData data[7];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScoreBoard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScoreBoard_t qt_meta_stringdata_ScoreBoard = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ScoreBoard"
QT_MOC_LITERAL(1, 11, 10), // "someoneWon"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "isPlayer"
QT_MOC_LITERAL(4, 32, 9), // "addPoints"
QT_MOC_LITERAL(5, 42, 8), // "toPlayer"
QT_MOC_LITERAL(6, 51, 13) // "restartPoints"

    },
    "ScoreBoard\0someoneWon\0\0isPlayer\0"
    "addPoints\0toPlayer\0restartPoints"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScoreBoard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,

       0        // eod
};

void ScoreBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScoreBoard *_t = static_cast<ScoreBoard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->someoneWon((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->addPoints((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->restartPoints(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScoreBoard::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScoreBoard::someoneWon)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ScoreBoard::staticMetaObject = {
    { &QGraphicsTextItem::staticMetaObject, qt_meta_stringdata_ScoreBoard.data,
      qt_meta_data_ScoreBoard,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ScoreBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScoreBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScoreBoard.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsTextItem::qt_metacast(_clname);
}

int ScoreBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsTextItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ScoreBoard::someoneWon(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
