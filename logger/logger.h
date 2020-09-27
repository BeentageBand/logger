#ifndef LOGGER_H
#define LOGGER_H

#include "logger-level.h"
#include "loggerhandler.h"
#include "formatter.h"
#include "cobject/cobject.h"

#include <stdarg.h>

#ifdef LOGGER_IMPLEMENTATION 
#define _private
#else
#define _private const
#endif 

#ifdef __cplusplus
extern "C" {
#endif

union Logger;
union Logger_Class
{
    
    struct
    {
    struct Class Class;
    void (* _private log)(union Logger * const logger, enum LogLevel const level, uint32_t const line_num, char const * const file_name, char const * const msg, va_list const va_args);

    };
};

union Logger
{
    union Logger_Class * vtbl;
        struct
    {
      union Object Object;
      union Formatter * _private formatter;
union LoggerHandler * _private handler;

    };
};

extern union Logger_Class * Get_Logger_Class(void);

extern void Logger_populate(union Logger * const logger, union Formatter * const formatter, union LoggerHandler * const handler);

extern void Logger_log(union Logger * const logger, enum LogLevel const level, uint32_t const line_num, char const * const file_name, char const * const msg, ...);

#ifdef __cplusplus
}
#endif
#undef _private
#endif /*LOGGER_H*/