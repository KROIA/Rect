#ifndef RECT_GLOBAL_H
#define RECT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RECT_LIBRARY)
#  define RECTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define RECTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RECT_GLOBAL_H
