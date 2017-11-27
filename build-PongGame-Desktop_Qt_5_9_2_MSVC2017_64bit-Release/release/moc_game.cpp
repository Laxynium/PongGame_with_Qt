/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PongGame_with_Qt/Game/game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Game_t {
    QByteArrayData data[21];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Game_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Game_t qt_meta_stringdata_Game = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Game"
QT_MOC_LITERAL(1, 5, 11), // "gameStopped"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 9), // "gameEnded"
QT_MOC_LITERAL(4, 28, 9), // "playerWon"
QT_MOC_LITERAL(5, 38, 9), // "startGame"
QT_MOC_LITERAL(6, 48, 11), // "restartGame"
QT_MOC_LITERAL(7, 60, 10), // "resizeGame"
QT_MOC_LITERAL(8, 71, 7), // "w_scale"
QT_MOC_LITERAL(9, 79, 7), // "h_scale"
QT_MOC_LITERAL(10, 87, 14), // "setKeyToMoveUp"
QT_MOC_LITERAL(11, 102, 7), // "Qt::Key"
QT_MOC_LITERAL(12, 110, 2), // "up"
QT_MOC_LITERAL(13, 113, 16), // "setKeyToMoveDown"
QT_MOC_LITERAL(14, 130, 4), // "down"
QT_MOC_LITERAL(15, 135, 13), // "isGameRunning"
QT_MOC_LITERAL(16, 149, 8), // "gameLoop"
QT_MOC_LITERAL(17, 158, 8), // "stopGame"
QT_MOC_LITERAL(18, 167, 10), // "someoneWon"
QT_MOC_LITERAL(19, 178, 8), // "isPlayer"
QT_MOC_LITERAL(20, 187, 13) // "someoneScored"

    },
    "Game\0gameStopped\0\0gameEnded\0playerWon\0"
    "startGame\0restartGame\0resizeGame\0"
    "w_scale\0h_scale\0setKeyToMoveUp\0Qt::Key\0"
    "up\0setKeyToMoveDown\0down\0isGameRunning\0"
    "gameLoop\0stopGame\0someoneWon\0isPlayer\0"
    "someoneScored"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Game[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   78,    2, 0x0a /* Public */,
       6,    0,   79,    2, 0x0a /* Public */,
       7,    2,   80,    2, 0x0a /* Public */,
      10,    1,   85,    2, 0x0a /* Public */,
      13,    1,   88,    2, 0x0a /* Public */,
      15,    0,   91,    2, 0x08 /* Private */,
      16,    0,   92,    2, 0x08 /* Private */,
      17,    0,   93,    2, 0x08 /* Private */,
      18,    1,   94,    2, 0x08 /* Private */,
      20,    1,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   14,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,

       0        // eod
};

void Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Game *_t = static_cast<Game *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameStopped(); break;
        case 1: _t->gameEnded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->startGame(); break;
        case 3: _t->restartGame(); break;
        case 4: _t->resizeGame((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: _t->setKeyToMoveUp((*reinterpret_cast< Qt::Key(*)>(_a[1]))); break;
        case 6: _t->setKeyToMoveDown((*reinterpret_cast< Qt::Key(*)>(_a[1]))); break;
        case 7: { bool _r = _t->isGameRunning();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->gameLoop(); break;
        case 9: _t->stopGame(); break;
        case 10: _t->someoneWon((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->someoneScored((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Game::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::gameStopped)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Game::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::gameEnded)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Game::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Game.data,
      qt_meta_data_Game,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Game.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Game::gameStopped()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Game::gameEnded(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
