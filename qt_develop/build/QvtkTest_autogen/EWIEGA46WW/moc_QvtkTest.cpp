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
struct qt_meta_stringdata_PcdvisThread_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PcdvisThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PcdvisThread_t qt_meta_stringdata_PcdvisThread = {
    {
QT_MOC_LITERAL(0, 0, 12) // "PcdvisThread"

    },
    "PcdvisThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PcdvisThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void PcdvisThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PcdvisThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_PcdvisThread.data,
    qt_meta_data_PcdvisThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PcdvisThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PcdvisThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PcdvisThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int PcdvisThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_QvtkTest_t {
    QByteArrayData data[23];
    char stringdata0[448];
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
QT_MOC_LITERAL(4, 37, 23), // "thermal_rs_stream_close"
QT_MOC_LITERAL(5, 61, 17), // "slotPushButtonPcd"
QT_MOC_LITERAL(6, 79, 26), // "on_runScriptButton_clicked"
QT_MOC_LITERAL(7, 106, 33), // "on_resetCameraPerspective_cli..."
QT_MOC_LITERAL(8, 140, 53), // "boost::shared_ptr<pcl::visual..."
QT_MOC_LITERAL(9, 194, 6), // "viewer"
QT_MOC_LITERAL(10, 201, 16), // "on_pspup_clicked"
QT_MOC_LITERAL(11, 218, 18), // "on_pspdown_clicked"
QT_MOC_LITERAL(12, 237, 18), // "on_pspleft_clicked"
QT_MOC_LITERAL(13, 256, 19), // "on_pspright_clicked"
QT_MOC_LITERAL(14, 276, 20), // "on_pspzoomin_clicked"
QT_MOC_LITERAL(15, 297, 21), // "on_pspzoomout_clicked"
QT_MOC_LITERAL(16, 319, 6), // "lcdvis"
QT_MOC_LITERAL(17, 326, 5), // "value"
QT_MOC_LITERAL(18, 332, 18), // "updateOpenGLWidget"
QT_MOC_LITERAL(19, 351, 38), // "pcl::PointCloud<pcl::PointXYZ..."
QT_MOC_LITERAL(20, 390, 15), // "point_cloud_ptr"
QT_MOC_LITERAL(21, 406, 18), // "tempsliderReleased"
QT_MOC_LITERAL(22, 425, 22) // "tempSliderValueChanged"

    },
    "QvtkTest\0thermal_rs_signal\0\0message1\0"
    "thermal_rs_stream_close\0slotPushButtonPcd\0"
    "on_runScriptButton_clicked\0"
    "on_resetCameraPerspective_clicked\0"
    "boost::shared_ptr<pcl::visualization::PCLVisualizer>&\0"
    "viewer\0on_pspup_clicked\0on_pspdown_clicked\0"
    "on_pspleft_clicked\0on_pspright_clicked\0"
    "on_pspzoomin_clicked\0on_pspzoomout_clicked\0"
    "lcdvis\0value\0updateOpenGLWidget\0"
    "pcl::PointCloud<pcl::PointXYZRGB>::Ptr\0"
    "point_cloud_ptr\0tempsliderReleased\0"
    "tempSliderValueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QvtkTest[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   92,    2, 0x0a /* Public */,
       5,    0,   93,    2, 0x0a /* Public */,
       6,    0,   94,    2, 0x0a /* Public */,
       7,    1,   95,    2, 0x0a /* Public */,
      10,    1,   98,    2, 0x0a /* Public */,
      11,    1,  101,    2, 0x0a /* Public */,
      12,    1,  104,    2, 0x0a /* Public */,
      13,    1,  107,    2, 0x0a /* Public */,
      14,    1,  110,    2, 0x0a /* Public */,
      15,    1,  113,    2, 0x0a /* Public */,
      16,    1,  116,    2, 0x0a /* Public */,
      18,    2,  119,    2, 0x08 /* Private */,
      21,    0,  124,    2, 0x0a /* Public */,
      22,    1,  125,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 19,    9,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void QvtkTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QvtkTest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->thermal_rs_signal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->thermal_rs_stream_close(); break;
        case 2: _t->slotPushButtonPcd(); break;
        case 3: _t->on_runScriptButton_clicked(); break;
        case 4: _t->on_resetCameraPerspective_clicked((*reinterpret_cast< boost::shared_ptr<pcl::visualization::PCLVisualizer>(*)>(_a[1]))); break;
        case 5: _t->on_pspup_clicked((*reinterpret_cast< boost::shared_ptr<pcl::visualization::PCLVisualizer>(*)>(_a[1]))); break;
        case 6: _t->on_pspdown_clicked((*reinterpret_cast< boost::shared_ptr<pcl::visualization::PCLVisualizer>(*)>(_a[1]))); break;
        case 7: _t->on_pspleft_clicked((*reinterpret_cast< boost::shared_ptr<pcl::visualization::PCLVisualizer>(*)>(_a[1]))); break;
        case 8: _t->on_pspright_clicked((*reinterpret_cast< boost::shared_ptr<pcl::visualization::PCLVisualizer>(*)>(_a[1]))); break;
        case 9: _t->on_pspzoomin_clicked((*reinterpret_cast< boost::shared_ptr<pcl::visualization::PCLVisualizer>(*)>(_a[1]))); break;
        case 10: _t->on_pspzoomout_clicked((*reinterpret_cast< boost::shared_ptr<pcl::visualization::PCLVisualizer>(*)>(_a[1]))); break;
        case 11: _t->lcdvis((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->updateOpenGLWidget((*reinterpret_cast< boost::shared_ptr<pcl::visualization::PCLVisualizer>(*)>(_a[1])),(*reinterpret_cast< pcl::PointCloud<pcl::PointXYZRGB>::Ptr(*)>(_a[2]))); break;
        case 13: _t->tempsliderReleased(); break;
        case 14: _t->tempSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
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
