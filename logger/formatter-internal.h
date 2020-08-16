#ifndef FORMATTER_H
#define FORMATTER_INT_H
#define FORMATTER_IMPLEMENTATION

#include "formatter.h"

static void formatter_override(union Formatter_Class * const formatter);

union Formatter_Class * Get_Formatter_Class(void)
{
  static union Formatter_Class clazz;
  if (0 != clazz.Class.offset) return &clazz;
  Class_populate(&clazz.Class, sizeof(clazz), NULL);
  formatter_override(&clazz);
  return &clazz;
}
char const * Formatter_format(union Formatter * const formatter, enum LogLevel const level, uint32_t const line_num, char const * const file_name, char const * const msg, va_list const va_args)
{
  return formatter->vtbl->format(formatter, level, line_num, file_name, msg, va_args);
}


#endif /*FORMATTER_H*/
