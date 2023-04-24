/****************************************************************************
** Meta object code from reading C++ file 'QvtkTest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "QvtkTest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QvtkTest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QvtkTest_t {
    QByteArrayData data[12];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QvtkTest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QvtkTest_t qt_meta_stringdata_QvtkTest = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QvtkTest"
QT_MOC_LITERAL(1, 9, 17), // "thermal_rs_signal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "message1"
QT_MOC_LITERAL(4, 37, 17), // "thermal_rs_stream"
QT_MOC_LITERAL(5, 55, 39), // "pcl::PointCloud<pcl::PointXYZ..."
QT_MOC_LITERAL(6, 95, 15), // "point_cloud_ptr"
QT_MOC_LITERAL(7, 111, 23), // "thermal_rs_stream_close"
QT_MOC_LITERAL(8, 135, 18), // "updateOpenGLWidget"
QT_MOC_LITERAL(9, 154, 53), // "boost::shared_ptr<pcl::visual..."
QT_MOC_LITERAL(10, 208, 6), // "viewer"
QT_MOC_LITERAL(11, 215, 38) // "pcl::PointCloud<pcl::PointXYZ..."

    },
    "QvtkTest\0thermal_rs_signal\0\0message1\0"
    "thermal_rs_stream\0"
    "pcl::PointCloud<pcl::PointXYZRGB>::Ptr&\0"
    "point_cloud_ptr\0thermal_rs_stream_close\0"
    "updateOpenGLWidget\0"
    "boost::shared_ptr<pcl::visualization::PCLVisualizer>&\0"
    "viewer\0pcl::PointCloud<pcl::PointXYZRGB>::Ptr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QvtkTest[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a /* Public */,
       7,    0,   40,    2, 0x0a /* Public */,
       8,    2,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 11,   10,    6,

       0        // eod
};

void QvtkTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QvtkTest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->thermal_rs_signal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->thermal_rs_stream((*reinterpret_cast< pcl::PointCloud<pcl::PointXYZRGB>::Ptr(*)>(_a[1]))); break;
        case 2: _t->thermal_rs_stream_close(); break;
        case 3: _t->updateOpenGLWidget((*reinterpret_cast< boost::shared_ptr<pcl::visualization::PCLVisualizer>(*)>(_a[1])),(*reinterpret_cast< pcl::PointCloud<pcl::PointXYZRGB>::Ptr(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QvtkTest::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QvtkTest::thermal_rs_signal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QvtkTest::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QvtkTest.data,
    qt_meta_data_QvtkTest,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QvtkTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QvtkTest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QvtkTest.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QvtkTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QvtkTest::thermal_rs_signal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
