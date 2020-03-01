#ifndef LOGGER_INT_H
#define LOGGER_INT_H
#include <stdarg.h>
#include "logger.h"

static void logger_override(union Logger_Class * const logger);
static void logger_delete(union Logger * const logger);

union Logger_Class * Get_Logger_Class(void)
{
  static union Logger_Class clazz;
  if (0 != clazz.Class.offset) return &clazz;
  Class_populate(&clazz.Class, sizeof(clazz), NULL, (Class_Delete_T)logger_delete);
  logger_override(&clazz);
  return &clazz;
}
void Logger_log(union Logger * const logger, enum LogLevel const level, uint32_t const line_num, char const * const file_name, char const * const msg, ...)
{
    va_list va_args;
    va_start(va_args, msg);
    logger->vtbl->log(logger, level, line_num, file_name, msg, va_args);
    va_end(va_args);
}


#endif /* LOGGER_INT_H */
