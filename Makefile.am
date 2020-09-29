 ACLOCAL_AMFLAGS = -I m4 --install
# Libraries
lib_LTLIBRARIES = liblogger-1.0.0.la
liblogger_1_0_0_la_SOURCES = \
logger/formatter.c               \
logger/formatter.h               \
logger/formatter-internal.h      \
logger/logger.c                  \
logger/logger.h                  \
logger/loggerhandler.c           \
logger/loggerhandler.h           \
logger/loggerhandler-internal.h  \
logger/logger-internal.h         \
logger/logger-level.h 

liblogger_1_0_0_la_LDFLAGS = -version-info 0:0:0
nobase_include_HEADERS = \
logger/formatter.h               \
logger/logger.h                  \
logger/loggerhandler.h           \
logger/logger-level.h 

pkgconfig_DATA = logger.pc

# Unit Tests
check_PROGRAMS = unittest
unittest_SOURCES = \
tst/logger-test.cc

unittest_CPPFLAGS = $(GMOCK_CFLAGS) $(LOGGER_CFLAGS)
unittest_LDADD = $(lib_LTLIBRARIES) $(GMOCK_LIBS) $(LOGGER_LIBS)
unittest_LDFLAGS = -no-install

EXTRA_DIST = m4/NOTES
dist_doc = README.md LICENSE