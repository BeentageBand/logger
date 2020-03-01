#ifndef FORMATTER_H
#define FORMATTER_H
#include <stdarg.h>
#include "logger-level.h"
#include "cobject/cobject.h"

#ifdef __cplusplus
extern "C" {
#endif

union Formatter;
union Formatter_Class
{
    
    struct
    {
    struct Class Class;
    char * (* _private format)(union Formatter * const formatter, enum LogLevel const level, 
    uint32_t const line_num, char const * const file_name, char const * const msg, va_list va_args);
    };
};

union Formatter
{
    union Formatter_Class * vtbl;
    struct
    {
        union Object Object;
        char const * _private facility_name;
        enum LogLevel _private log_level;
        char const * _private format;
    };
};

extern union Formatter_Class * Get_Formatter_Class(void);

extern void Formatter_populate(union Formatter * const formatter, char const * const facility_name, 
        enum LogLevel const log_level, char const * const format);

extern char * Formatter_format(union Formatter * const formatter, enum LogLevel const level, 
        uint32_t const line_num, char const * const file_name, char const * const msg, va_list va_args);

#ifdef __cplusplus
}
#endif
#endif /* FORMATTER_H */