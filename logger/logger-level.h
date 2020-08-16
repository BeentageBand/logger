#ifndef LOG_LEVEL_H
#define LOG_LEVEL_H

#include <stdint.h>

enum LogLevel
{
    LOG_ERROR_LEVEL = 0,
    LOG_WARN_LEVEL,
    LOG_INFO_LEVEL,
    LOG_DEBUG_LEVEL
};

/**
 * Logger level calls
 */
#define Logger_error(logger, ...) Logger_log(logger, LOG_ERROR_LEVEL, __LINE__, __FILE__, __VA_ARGS__)
#define Logger_warn(logger, ...) Logger_log(logger, LOG_WARN_LEVEL, __LINE__, __FILE__,  __VA_ARGS__)
#define Logger_info(logger, ...) Logger_log(logger, LOG_INFO_LEVEL, __LINE__, __FILE__, __VA_ARGS__)
#define Logger_debug(logger, ...) Logger_log(logger, LOG_DEBUG_LEVEL, __LINE__, __FILE__, __VA_ARGS__)

#endif /*LOG_LEVEL_H*/
