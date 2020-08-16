#ifndef LOGGERHANDLER_H
#define LOGGERHANDLER_INT_H
#define LOGGERHANDLER_IMPLEMENTATION

#include "loggerhandler.h"

static void loggerhandler_override(union LoggerHandler_Class * const loggerhandler);

union LoggerHandler_Class * Get_LoggerHandler_Class(void)
{
  static union LoggerHandler_Class clazz;
  if (0 != clazz.Class.offset) return &clazz;
  Class_populate(&clazz.Class, sizeof(clazz), NULL);
  loggerhandler_override(&clazz);
  return &clazz;
}
void LoggerHandler_log(union LoggerHandler * const loggerhandler, enum LogLevel const level, char const * const msg)
{
  return loggerhandler->vtbl->log(loggerhandler, level, msg);
}


#endif /*LOGGERHANDLER_H*/
