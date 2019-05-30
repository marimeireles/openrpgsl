/****************************************************************************
** Meta object code from reading C++ file 'playerControls.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "playerControls.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playerControls.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayerControls_t {
    QByteArrayData data[18];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayerControls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayerControls_t qt_meta_stringdata_PlayerControls = {
    {
QT_MOC_LITERAL(0, 0, 14), // "PlayerControls"
QT_MOC_LITERAL(1, 15, 4), // "play"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 5), // "pause"
QT_MOC_LITERAL(4, 27, 4), // "stop"
QT_MOC_LITERAL(5, 32, 12), // "changeVolume"
QT_MOC_LITERAL(6, 45, 6), // "volume"
QT_MOC_LITERAL(7, 52, 12), // "changeMuting"
QT_MOC_LITERAL(8, 65, 6), // "muting"
QT_MOC_LITERAL(9, 72, 8), // "setState"
QT_MOC_LITERAL(10, 81, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(11, 101, 5), // "state"
QT_MOC_LITERAL(12, 107, 9), // "setVolume"
QT_MOC_LITERAL(13, 117, 8), // "setMuted"
QT_MOC_LITERAL(14, 126, 5), // "muted"
QT_MOC_LITERAL(15, 132, 11), // "playClicked"
QT_MOC_LITERAL(16, 144, 11), // "muteClicked"
QT_MOC_LITERAL(17, 156, 26) // "onVolumeSliderValueChanged"

    },
    "PlayerControls\0play\0\0pause\0stop\0"
    "changeVolume\0volume\0changeMuting\0"
    "muting\0setState\0QMediaPlayer::State\0"
    "state\0setVolume\0setMuted\0muted\0"
    "playClicked\0muteClicked\0"
    "onVolumeSliderValueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayerControls[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    1,   72,    2, 0x06 /* Public */,
       7,    1,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   78,    2, 0x0a /* Public */,
      12,    1,   81,    2, 0x0a /* Public */,
      13,    1,   84,    2, 0x0a /* Public */,
      15,    0,   87,    2, 0x08 /* Private */,
      16,    0,   88,    2, 0x08 /* Private */,
      17,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlayerControls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlayerControls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->play(); break;
        case 1: _t->pause(); break;
        case 2: _t->stop(); break;
        case 3: _t->changeVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeMuting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setState((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 6: _t->setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setMuted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->playClicked(); break;
        case 9: _t->muteClicked(); break;
        case 10: _t->onVolumeSliderValueChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlayerControls::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerControls::play)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlayerControls::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerControls::pause)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlayerControls::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerControls::stop)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PlayerControls::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerControls::changeVolume)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PlayerControls::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerControls::changeMuting)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlayerControls::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_PlayerControls.data,
    qt_meta_data_PlayerControls,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PlayerControls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayerControls::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerControls.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PlayerControls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void PlayerControls::play()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PlayerControls::pause()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PlayerControls::stop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PlayerControls::changeVolume(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PlayerControls::changeMuting(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
