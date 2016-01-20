#ifndef DEDALUS.GUI.X86_GLOBAL_H
#define DEDALUS.GUI.X86_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef DEDALUS.GUI.X86_LIB
# define DEDALUS.GUI.X86_EXPORT Q_DECL_EXPORT
#else
# define DEDALUS.GUI.X86_EXPORT Q_DECL_IMPORT
#endif

#endif // DEDALUS.GUI.X86_GLOBAL_H
