#include "gtest/gtest.h"
#include "logger.h"

static union Logger Logger = {NULL};
static union LoggerHandler LoggerHandler = {NULL};
static union Formatter Formatter = {NULL};

static char const * const Facility_Name = "Gtest";
TEST(Logger, Populate)
{
    LoggerHandler_populate(&LoggerHandler);
    Formatter_populate(&Formatter, Facility_Name, LOG_DEBUG_LEVEL, "");
    Logger_populate(&Logger, &Formatter, &LoggerHandler);
}

TEST(Logger, log_msg)
{
    Logger_debug(&Logger, "this is a test");
}

TEST(Logger, log_msg_with_params)
{
    Logger_info(&Logger, "this is a test num = %d", 1);
}
