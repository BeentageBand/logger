#ifndef LOGGERHANDLER_H
#define LOGGERHANDLER_H

#include "logger-level.h"
#include "cobject/cobject.h"

#ifdef LOGGERHANDLER_IMPLEMENTATION 
#define _private
#else
#define _private const
#endif 

#ifdef __cplusplus
extern "C" {
#endif

union LoggerHandler;
union LoggerHandler_Class
{
    
    struct
    {
    struct Class Class;
    void (* _private log)(union LoggerHandler * const loggerhandler, enum LogLevel const level, char const * const msg);

    };
};

union LoggerHandler
{
    union LoggerHandler_Class * vtbl;
        struct
    {
      union Object Object;
      
    };
};

extern union LoggerHandler_Class * Get_LoggerHandler_Class(void);

extern void LoggerHandler_populate(union LoggerHandler * const loggerhandler);

extern void LoggerHandler_log(union LoggerHandler * const loggerhandler, enum LogLevel const level, char const * const msg);

#ifdef __cplusplus
}
#endif
#undef _private
#endif /*LOGGERHANDLER_H*/