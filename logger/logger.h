#ifndef LOGGER_H
#define LOGGER_H
#include <stdarg.h>
#include "cobject/cobject.h"
#include "formatter.h"
#include "logger-level.h"
#include "loggerhandler.h"

#ifdef __cplusplus
extern "C" {
#endif

union Logger;
union Logger_Class
{
    
    struct
    {
    struct Class Class;
    void (* _private log)(union Logger * const logger, enum LogLevel const level, uint32_t const line_num, 
            char const * const file_name, char const * const msg, va_list va_args); 
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

extern void Logger_log(union Logger * const logger, enum LogLevel const level, uint32_t const line_num, 
        char const * const file_name, char const * const msg, ...);

#define Logger_debug(logger, ...) Logger_log(logger, LOG_DEBUG_LEVEL, __LINE__, __FILE__, __VA_ARGS__)
#define Logger_info(logger, ...) Logger_log(logger, LOG_INFO_LEVEL, __LINE__, __FILE__, __VA_ARGS__)
#define Logger_warn(logger, ...) Logger_log(logger, LOG_WARN_LEVEL, __LINE__, __FILE__, __VA_ARGS__)
#define Logger_error(logger, ...) Logger_log(logger, LOG_ERROR_LEVEL, __LINE__, __FILE__, __VA_ARGS__)

#ifdef __cplusplus
}
#endif
#endif /* LOGGER_H */
