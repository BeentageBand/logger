#include <stdarg.h>
#include <stdlib.h>

#define COBJECT_IMPLEMENTATION
#include "logger-internal.h"

static void logger_log(union Logger * const this, enum LogLevel const level, uint32_t const line_num, 
        char const * const filename, char const * const msg, va_list va_args); 

void logger_override(union Logger_Class * const clazz)
{
    clazz->log = logger_log;
}

void logger_delete(union Logger * const logger) 
{
}

void logger_log(union Logger * const this, enum LogLevel const level, uint32_t const line_num, 
        char const * const filename, char const * const msg, va_list va_args) 
{
    char * formatted_msg = Formatter_format(this->formatter, level, line_num, filename, msg, va_args);
    if (NULL != formatted_msg)
    {
        LoggerHandler_log(this->handler, level, formatted_msg);
        free(formatted_msg);
    }
}

void Logger_populate(union Logger * const this, union Formatter * const formatter,  union LoggerHandler * const handler) 
{
    Object_populate(&this->Object, &Get_Logger_Class()->Class);
    this->formatter = formatter;
    this->handler = handler;
}
