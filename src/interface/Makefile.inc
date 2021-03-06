# Modify global directives in global namespace
OBJDIRS += interface
TESTS += interface-test

# relative to $(TOP), i.e. $(LOWERC_DIR)/*.cc
INTERFACE_SRCS := interface/board.cpp interface/tile.cpp interface/menu.cpp
INTERFACE_EXECUTABLES :=

# Set makefile template specific vars
UPPERC_DIR := INTERFACE
LOWERC_DIR := interface

TEST_OBJS :=
EXECUTABLE_OBJS :=

include $(MAKEFILE_TEMPLATE)

# Directive to make the test case
interface-test: $(INTERFACE_TESTS)
	@for a in $(INTERFACE_TESTS); do \
		echo == $$a ==; \
		$(LDLIBPATH) $$a 2>$(LOGDIR)$${a#$(BINDIR)}; \
	done
