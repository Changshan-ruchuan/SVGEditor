/****************************************************************************
** Meta object code from reading C++ file 'kcanvas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../kcanvas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kcanvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KCanvas_t {
    QByteArrayData data[15];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KCanvas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KCanvas_t qt_meta_stringdata_KCanvas = {
    {
QT_MOC_LITERAL(0, 0, 7), // "KCanvas"
QT_MOC_LITERAL(1, 8, 23), // "currentShapeBorderWidth"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "width"
QT_MOC_LITERAL(4, 39, 23), // "currentShapeBorderStyle"
QT_MOC_LITERAL(5, 63, 12), // "Qt::PenStyle"
QT_MOC_LITERAL(6, 76, 5), // "style"
QT_MOC_LITERAL(7, 82, 22), // "currntShapeBorderColor"
QT_MOC_LITERAL(8, 105, 4), // "QRgb"
QT_MOC_LITERAL(9, 110, 5), // "color"
QT_MOC_LITERAL(10, 116, 16), // "currntShapeColor"
QT_MOC_LITERAL(11, 133, 13), // "shapeSelected"
QT_MOC_LITERAL(12, 147, 10), // "isSelected"
QT_MOC_LITERAL(13, 158, 19), // "canvasZoomRequested"
QT_MOC_LITERAL(14, 178, 5) // "scale"

    },
    "KCanvas\0currentShapeBorderWidth\0\0width\0"
    "currentShapeBorderStyle\0Qt::PenStyle\0"
    "style\0currntShapeBorderColor\0QRgb\0"
    "color\0currntShapeColor\0shapeSelected\0"
    "isSelected\0canvasZoomRequested\0scale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KCanvas[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       7,    1,   50,    2, 0x06 /* Public */,
      10,    1,   53,    2, 0x06 /* Public */,
      11,    1,   56,    2, 0x06 /* Public */,
      13,    1,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::QReal,   14,

       0        // eod
};

void KCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KCanvas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentShapeBorderWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->currentShapeBorderStyle((*reinterpret_cast< Qt::PenStyle(*)>(_a[1]))); break;
        case 2: _t->currntShapeBorderColor((*reinterpret_cast< QRgb(*)>(_a[1]))); break;
        case 3: _t->currntShapeColor((*reinterpret_cast< QRgb(*)>(_a[1]))); break;
        case 4: _t->shapeSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->canvasZoomRequested((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KCanvas::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KCanvas::currentShapeBorderWidth)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KCanvas::*)(Qt::PenStyle );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KCanvas::currentShapeBorderStyle)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (KCanvas::*)(QRgb );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KCanvas::currntShapeBorderColor)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (KCanvas::*)(QRgb );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KCanvas::currntShapeColor)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (KCanvas::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KCanvas::shapeSelected)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (KCanvas::*)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KCanvas::canvasZoomRequested)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KCanvas::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_KCanvas.data,
    qt_meta_data_KCanvas,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KCanvas.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int KCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void KCanvas::currentShapeBorderWidth(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KCanvas::currentShapeBorderStyle(Qt::PenStyle _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KCanvas::currntShapeBorderColor(QRgb _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KCanvas::currntShapeColor(QRgb _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KCanvas::shapeSelected(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void KCanvas::canvasZoomRequested(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
