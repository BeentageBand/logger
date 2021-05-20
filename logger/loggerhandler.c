#include <stdio.h>
#define COBJECT_IMPLEMENTATION
#include "loggerhandler-internal.h"

static void loggerhandler_log(union LoggerHandler *const this,
                              enum LogLevel const level, char const *const msg);

void loggerhandler_override(union LoggerHandler_Class *const this) {
  this->log = loggerhandler_log;
}

void loggerhandler_delete(union LoggerHandler *const this) {}

void loggerhandler_log(union LoggerHandler *const this,
                       enum LogLevel const level, char const *const msg) {
  printf("%s\n", msg);
}

void LoggerHandler_populate(union LoggerHandler *const this) {
  Object_populate(&this->Object, &Get_LoggerHandler_Class()->Class);
}
