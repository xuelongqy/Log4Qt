#ifndef LOGGER_GLOBAL_H
#define LOGGER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LOGGER_LIBRARY)
#  define LOGGERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LOGGERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LOGGER_GLOBAL_H
