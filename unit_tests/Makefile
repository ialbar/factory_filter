# Ficticious targets
.PHONY: clean all obj build_and_test gcov lcov gcov doc
# Defautl target (when invoke just make in current directory)
.default: all

# Path declarations:
# Source dir must be the folder where module to be tested is found.
# Test dir must be the folder where test sources are found.
# ATTENTION: CPPUTEST_HOME must be defined as a environment variable,
# pointing to the root directory of cpputest installation.
MODULE_INCLUDE_DIR 	= ../module/include
MODULE_SOURCE_DIR 	= ../module/source
#EXAMPLE_DIR = ../module/example
TEST_DIR   = .

# VARIABLE DECLARATIONS
# Write the name of all the objects that have to be created
OBJS    = obj/main.o
OBJS   += obj/mcp_test.o
OBJS   += obj/stub_functions.o
# filter first order
OBJS   += obj/f1er.o
OBJS   += obj/f1er_highpass.o
OBJS   += obj/f1er_lowpass.o
OBJS   += obj/factory_f1er.o
OBJS   += obj/factory_f1er_high_pass.o
OBJS   += obj/factory_f1er_low_pass.o
# filter second order
OBJS   += obj/factory_f2er.o
OBJS   += obj/factory_f2er_high_pass.o
OBJS   += obj/factory_f2er_low_pass.o
OBJS   += obj/factory_f2er_band_pass.o
OBJS   += obj/f2er.o
OBJS   += obj/f2er_highpass.o
OBJS   += obj/f2er_lowpass.o
OBJS   += obj/f2er_bandpass.o
#filter nth order
OBJS   += obj/fsos.o
OBJS   += obj/factory_fsos.o
OBJS   += obj/fsos_nth_order.o
OBJS   += obj/create_filters.o


# Compiler flags (debug info, all warnings, includes)
CFLAGS  = -g3 -Wall -pedantic -fprofile-arcs -ftest-coverage -fpermissive
CFLAGS += -D ONLY_PC_TEST
CFLAGS += -I.
CFLAGS += -I$(MODULE_INCLUDE_DIR)
CFLAGS += -I$(MODULE_SOURCE_DIR)
#CFLAGS += -I$(EXAMPLE_DIR)
CFLAGS += -I$(TEST_DIR)
CFLAGS += -I$(TEST_DIR)/test_doubles/
CFLAGS += -I$(CPPUTEST_HOME)/include/

# Linker flags (includes)
LD_LIBRARIES = -L$(CPPUTEST_HOME)/cpputest_build/lib -lCppUTest -lCppUTestExt

#TARGETS
UnitTestPC: obj $(OBJS)
	g++ $(OBJS) -o UnitTestPC $(CFLAGS) $(LD_LIBRARIES)

VPATH  = .
VPATH += $(SRC_DIR)
VPATH += $(MODULE_DIR)
VPATH += $(TEST_DIR)
VPATH += $(TEST_DIR)/test_doubles/
VPATH += $(MODULE_INCLUDE_DIR)
VPATH += $(MODULE_SOURCE_DIR)


	
obj/%.o: %.cpp
	g++ -c $< -o $@ $(CFLAGS)
	
obj/%.o: %.c
	gcc -c $< -o $@ $(CFLAGS)
	
obj:
	-mkdir obj
	
clean:
	-rm -r obj
	-rm UnitTestPC.info
	-rm UnitTestPC
	
all: clean UnitTestPC 

doc: 
	cd $(SRC_DIR); doxygen Doxyfile; cd -

run: UnitTestPC
	./UnitTestPC -c

coverage: UnitTestPC run
	lcov -c -d obj -o UnitTestPC.info --rc lcov_branch_coverage=1
	genhtml UnitTestPC.info -o obj/coverage_html --rc lcov_branch_coverage=1 --legend
 
build_and_test: UnitTestPC run

build: UnitTestPC

complete: clean UnitTestPC run coverage doc
