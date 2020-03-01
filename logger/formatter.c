#include <stdio.h>
#include <string.h>
#define COBJECT_IMPLEMENTATION
#include "formatter-internal.h"

#define MSG_SIZE_LIMIT ((size_t) 1024UL)

static char * formatter_format(union Formatter * const this, enum LogLevel const level, uint32_t const line_num, 
        char const * const file_name, char const * const msg, va_list va_args);
static char const * get_level_str(enum LogLevel const level);

void formatter_override(union Formatter_Class * const clazz)
{
    clazz->format = formatter_format;
}

void formatter_delete(union Formatter * const this)
{
}

char * formatter_format(union Formatter * const this, enum LogLevel const level, uint32_t const line_num, 
        char const * const file_name, char const * const msg, va_list va_args)
{
    if (level > this->log_level) return NULL;

    char * formatted_msg = malloc(MSG_SIZE_LIMIT);
    char const * level_str = get_level_str(level);

    // TODO timestamp implementation
    int pos = sprintf(formatted_msg, "%s:%d [%s] %s:", file_name, line_num, level_str, this->facility_name);
    if (pos < 0) return NULL;

    pos = vsprintf(formatted_msg + pos, msg, va_args);
    if (pos < 0) return NULL;

    return formatted_msg;
}

char const * get_level_str(enum LogLevel const level)
{
    switch(level)
    {
        case LOG_INFO_LEVEL: return "INFO";
        case LOG_DEBUG_LEVEL: return "DEBUG";
        case LOG_WARN_LEVEL: return "WARN";
        case LOG_ERROR_LEVEL: return "ERROR";
        default: return "INFO";
    }
}

void Formatter_populate(union Formatter * const this, char const * const facility_name, 
        enum LogLevel const log_level, char const * const format)
{
    Object_populate(&this->Object, &Get_Formatter_Class()->Class);
    this->facility_name = facility_name;
    this->log_level = log_level;
    this->format = format;
}
