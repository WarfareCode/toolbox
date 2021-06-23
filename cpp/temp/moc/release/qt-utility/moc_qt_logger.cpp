/****************************************************************************
** Meta object code from reading C++ file 'qt_logger.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../projects/qt-utility/qt_logger.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_logger.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tool__QtLogger_t {
    QByteArrayData data[19];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tool__QtLogger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tool__QtLogger_t qt_meta_stringdata_tool__QtLogger = {
    {
QT_MOC_LITERAL(0, 0, 14), // "tool::QtLogger"
QT_MOC_LITERAL(1, 15, 14), // "message_signal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "message"
QT_MOC_LITERAL(4, 39, 12), // "error_signal"
QT_MOC_LITERAL(5, 52, 5), // "error"
QT_MOC_LITERAL(6, 58, 14), // "warning_signal"
QT_MOC_LITERAL(7, 73, 7), // "warning"
QT_MOC_LITERAL(8, 81, 13), // "status_signal"
QT_MOC_LITERAL(9, 95, 6), // "status"
QT_MOC_LITERAL(10, 102, 2), // "ms"
QT_MOC_LITERAL(11, 105, 20), // "unity_message_signal"
QT_MOC_LITERAL(12, 126, 11), // "QStringView"
QT_MOC_LITERAL(13, 138, 18), // "unity_error_signal"
QT_MOC_LITERAL(14, 157, 20), // "unity_warning_signal"
QT_MOC_LITERAL(15, 178, 19), // "unity_unknow_signal"
QT_MOC_LITERAL(16, 198, 6), // "unknow"
QT_MOC_LITERAL(17, 205, 15), // "progress_signal"
QT_MOC_LITERAL(18, 221, 5) // "state"

    },
    "tool::QtLogger\0message_signal\0\0message\0"
    "error_signal\0error\0warning_signal\0"
    "warning\0status_signal\0status\0ms\0"
    "unity_message_signal\0QStringView\0"
    "unity_error_signal\0unity_warning_signal\0"
    "unity_unknow_signal\0unknow\0progress_signal\0"
    "state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tool__QtLogger[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,
       8,    2,   68,    2, 0x06 /* Public */,
      11,    1,   73,    2, 0x06 /* Public */,
      13,    1,   76,    2, 0x06 /* Public */,
      14,    1,   79,    2, 0x06 /* Public */,
      15,    1,   82,    2, 0x06 /* Public */,
      17,    1,   85,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    9,   10,
    QMetaType::Void, 0x80000000 | 12,    3,
    QMetaType::Void, 0x80000000 | 12,    5,
    QMetaType::Void, 0x80000000 | 12,    7,
    QMetaType::Void, 0x80000000 | 12,   16,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void tool::QtLogger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtLogger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->message_signal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->error_signal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->warning_signal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->status_signal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->unity_message_signal((*reinterpret_cast< QStringView(*)>(_a[1]))); break;
        case 5: _t->unity_error_signal((*reinterpret_cast< QStringView(*)>(_a[1]))); break;
        case 6: _t->unity_warning_signal((*reinterpret_cast< QStringView(*)>(_a[1]))); break;
        case 7: _t->unity_unknow_signal((*reinterpret_cast< QStringView(*)>(_a[1]))); break;
        case 8: _t->progress_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtLogger::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtLogger::message_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtLogger::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtLogger::error_signal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtLogger::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtLogger::warning_signal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QtLogger::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtLogger::status_signal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QtLogger::*)(QStringView );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtLogger::unity_message_signal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QtLogger::*)(QStringView );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtLogger::unity_error_signal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (QtLogger::*)(QStringView );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtLogger::unity_warning_signal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (QtLogger::*)(QStringView );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtLogger::unity_unknow_signal)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (QtLogger::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtLogger::progress_signal)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject tool::QtLogger::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_tool__QtLogger.data,
    qt_meta_data_tool__QtLogger,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *tool::QtLogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tool::QtLogger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tool__QtLogger.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int tool::QtLogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void tool::QtLogger::message_signal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tool::QtLogger::error_signal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void tool::QtLogger::warning_signal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void tool::QtLogger::status_signal(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void tool::QtLogger::unity_message_signal(QStringView _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void tool::QtLogger::unity_error_signal(QStringView _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void tool::QtLogger::unity_warning_signal(QStringView _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void tool::QtLogger::unity_unknow_signal(QStringView _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void tool::QtLogger::progress_signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
