# Modify global directives in global namespace
OBJDIRS += window
TESTS += window-test

# relative to $(TOP), i.e. $(LOWERC_DIR)/*.cc
WINDOW_SRCS := window/main_window.cpp

# Set makefile template specific vars
UPPERC_DIR := WINDOW
LOWERC_DIR := window
EXECUTABLE :=
EXECUTABLE_OBJS :=
EXTRA_TEST_OBJS :=

include $(MAKEFILE_TEMPLATE)

# Directive to make the test case
window-test: $(WINDOW_TESTS)
	@for a in $(WINDOW_TESTS); do \
		echo == $$a ==; \
		$(LDLIBPATH) $$a 2>$(LOGDIR)$${a#$(BINDIR)}; \
	done
