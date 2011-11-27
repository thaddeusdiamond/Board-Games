# Modify global directives in global namespace
OBJDIRS += application
TESTS += application-test

# relative to $(TOP), i.e. $(LOWERC_DIR)/*.cc
APPLICATION_SRCS := application/application.cpp

# Set makefile template specific vars
UPPERC_DIR := APPLICATION
LOWERC_DIR := application
EXECUTABLE :=
EXECUTABLE_OBJS :=
EXTRA_TEST_OBJS :=

include $(MAKEFILE_TEMPLATE)

# Directive to make the test case
application-test: $(APPLICATION_TESTS)
	@for a in $(APPLICATION_TESTS); do \
		echo == $$a ==; \
		$(LDLIBPATH) $$a 2>$(LOGDIR)$${a#$(BINDIR)}; \
	done
