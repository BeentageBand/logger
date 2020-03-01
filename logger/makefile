SRCS=$(wildcard *.c)
LIBS=liblogger.a
INCS=$(wildcard *.h)

.PHONY : all clean $(MAKECMDGOALS:%=%.cmd)

all : install

install: $(OUT)/include/logger/ $(LIBS:%=$(OUT)/lib/%) $(INCS:%=$(OUT)/include/logger/%)
	@echo "install logger.."

clean : 
	@echo "clean all-tst"
	rm -rf *.o *.lib

$(LIBS) : $(SRCS:.c=.o)
	@echo "compiling $(LIBS)";
	$(AR) -rcs $@ $^;

$(LIBS:%=$(OUT)/lib/%): $(LIBS)
	cp -sf $(realpath $^) $@;

$(OUT)/include/logger/%.h : %.h
	cp -sf $(realpath $^) $@;

$(OUT)/include/logger : 
	-mkdir -p $@;

%.o : %.c
	$(CXX) $(CFLAGS) $(SUBDIRS:%= -I ../%) -o $@ -c $^
